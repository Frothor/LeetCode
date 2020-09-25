/*
It is possible to sort faster than O(n*Log(n)). It is similar to "Counting sort", but instead of counting we can build Trie (Prefix tree) with single pass O(n). And than traverse this Tree in special order (from digit '9' to digit '0'), also O(n). This approach significantly reduces number of comparisons, becase all numbers are already splitted into "Buskets". For example all numbers in busket '2' are definetely smaller than any number in busket '4'.
*/

//O(n*Log(n)) complexity:
public class Solution: IComparer<string>
{
	public string LargestNumber(int[] nums)
	{
		var result = nums.Select(n => n.ToString())
                         .OrderByDescending(s => s, this)
                         .Aggregate((a, b) => a + b);

		return result.Length > 0 && result[0] != '0' ? result : "0";
	}

    public int Compare(string x, string y)
    {
        return (x + y).CompareTo(y + x);
    }
}

//O(N)
public class Solution
{
    public string LargestNumber(int[] nums)
    {
        var root = new Trie();
        foreach(var n in nums)
        {
            root.Add(n);
        }

        var stack = new Stack<Trie>();
        var sb = new StringBuilder();
        dfs(root, sb, stack);

        while(stack.Count > 0)
        {
            stack.Pop().Append(sb);
        }

        return sb.ToString();
    }

    private void dfs(Trie node, StringBuilder sb, Stack<Trie> stack)
    {
        if(node.Count > 0)
        {
            while(stack.Count > 0 && node.CompareTo(stack.Peek()) < 0)
            {
                stack.Pop().Append(sb);
            }

            stack.Push(node);
        }

        for(int i=9;i>=0;i--)
        {
            var next = node.Children[i];
            if(next != null)
            {
                dfs(next, sb, stack);
            }
        }
    }

    class Trie: IComparable<Trie>
    {
        public Trie[] Children = new Trie[10];
        public int Count;
        public string Number;

        private void Add(int n)
        {
            var node = this;
            var s = n.ToString();
            foreach (var c in s)
            {
                node = node.Children[c-'0'] ??= new Trie();
            }

            node.Number = s;
            node.Count++;
        }

        public int CompareTo(Trie other)
        {
            var a = Number + other.Number;
            var b = other.Number + Number;
            return string.Compare(a, b, StringComparison.Ordinal);
        }

        public void Append(StringBuilder sb)
        {
            if (sb.Length == 0 && Number == "0")
            {
                sb.Append(Number);
                return;
            }

            while(Count-- > 0) sb.Append(Number);
        }
    }
}

//Fastest
public class Solution {
    public string LargestNumber(int[] nums) {
        var strNums = nums.Select(n => n.ToString()).ToArray();
        Array.Sort(strNums, (a, b) => string.Compare(b + a, a + b, StringComparison.Ordinal));
        
        StringBuilder sb = new StringBuilder();
        
        foreach(var w in strNums)
            sb.Append(w);
        string ans = sb.ToString().TrimStart('0');
        return ans==""?"0":ans;
        
    }
}