//Second fastest - DFS
public class Codec
{
    private const char Left = (char)10001, Right = (char)10002, Return = (char)10003, Null = (char)10004;

    public string serialize(TreeNode root)
    {
        StringBuilder data = new StringBuilder();
        SerializeRecursive(root, data);
        return data.ToString();
    }
    
    private void SerializeRecursive(TreeNode node, StringBuilder data)
    {
        if(node is null) data.Append(Null);
        else
        {
            data.Append((char)node.val);
            
            data.Append(Left);
            SerializeRecursive(node.left, data);
            
            data.Append(Right);
            SerializeRecursive(node.right, data);
        }
        data.Append(Return);
    }

    public TreeNode deserialize(string data)
    {
        int index = 0;
        return DeserializeRecursive(data, ref index);
    }
    
    private TreeNode DeserializeRecursive(string data, ref int index)
    {
        char val = data[index];
        index++;
        TreeNode node = val is Null ? null : new TreeNode((int)val);
        while(true)
        {
            char next = data[index];
            index++;
            if(next is Return) return node;
            if(next is Left) node.left = DeserializeRecursive(data, ref index);
            if(next is Right) node.right = DeserializeRecursive(data, ref index);
        }
        
        return node;
    }
}

//Another second fastest
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root)
    {
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        StringBuilder sb = new StringBuilder();
        
        while (queue.Count > 0)
        {
            TreeNode node = queue.Dequeue();
            if (node == null)
            {
                sb.Append("N.");
            }
            else
            {
                sb.Append(node.val.ToString());
                sb.Append(".");
                queue.Enqueue(node.left);
                queue.Enqueue(node.right);
            }
        }
        
        return sb.ToString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        
        string[] arr = data.Split('.');
        if (arr.Length == 2) return null;
        Queue<TreeNode> queue = new Queue<TreeNode>();
        TreeNode root = null;
        
        int i = 0;
        while (i < arr.Length - 1)
        {
            if (queue.Count == 0)
            {
                TreeNode node = new TreeNode(Convert.ToInt32(arr[i]));
                queue.Enqueue(node);
                if (root == null) root = node;
                i++;
            }
            else
            {
                TreeNode node = queue.Dequeue();
                if (arr[i] == "N")
                {
                    node.left = null;
                }
                else
                {
                    node.left = new TreeNode(Convert.ToInt32(arr[i]));
                    queue.Enqueue(node.left);
                }
                
                i++;
                
                if (arr[i] == "N")
                {
                    node.right = null;
                }
                else
                {
                    node.right = new TreeNode(Convert.ToInt32(arr[i]));
                    queue.Enqueue(node.right);
                }
                
                i++;
            }
        }
        
        return root;
    }
}

//Fastest
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) 
    {
        var output = new StringBuilder();
        Serialize(root, output);
        return output.ToString();
    }
    
    private void Serialize(TreeNode node, StringBuilder output)
    {
        output.Append(node != null ? node.val.ToString() : string.Empty);
        output.Append(",");
        
        if (node != null)
        {
            Serialize(node.left, output);
            Serialize(node.right, output);
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) 
    {
        var values = data.Split(",");
        var idx = 0;
        return Deserialize(values, ref idx);
    }
    
    private TreeNode Deserialize(string[] values, ref int index)
    {
        if (string.IsNullOrEmpty(values[index]))
        {
            index++;
            return null;
        }
        var node = new TreeNode(int.Parse(values[index]));
        index++;
        
        node.left = Deserialize(values, ref index);
        node.right = Deserialize(values, ref index);
        return node;
    }
}
