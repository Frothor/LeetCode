# LeetCode The Idea is As They Given us Inorder and Postorder

We Know Inorder Fallow --> **Left_subtree => Root_Node => Right_subtree ** Traverse
   ans   Postorder Fallow --> **Left_subtree => Right_subtree =>Root_Node **`traverse
using Postorder_array We can Find Root_Node Which always lay in Postorder_array last Possition
After Finding That Root_Node ,First are going to devide Inorder_array Into Two Part and Postorder Array
into Two part .

```
Then We are going to use Both of the arrays left part to Figur Out Left_subtree
                     and Both of the arraysRigth Part to Figur out Right_subtree

We are going to recoursive do so until One Of the arry dose not got empty
```

Let's take an Example
```
    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>        1

                   /        \

                [4 2 5]   [6 3 7]
                [4 5 2]   [6 7 3]

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]
                [4]    [5]   [6]   [7]

    3rd Phase =>  1

               /    \
              2      3
 
            /  \    /  \             <==== Answer
 
           4    5  6    7
```		   
		  
```c++
class Solution {
public:
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};
```



# Another

## Explanation:
Inorder Traversal -> First visit the left subtree, followed by the root node, followed by the right subtree.
Left -> Root -> Right
Point of observation: The root node divides the inorder array into 2 halves, left subtree and right subtree.
Postorder Traversal -> First visit left subtree, followed by the right subtree, followed bt the root node.
Left -> Right -> Root
Point of observation: The root node is available at the end the of the postorder array.

So, as the first step, we can eaily obtain the value of the root node for the tree (or subtree) from the postorder array by accessessing the last element of the postorder array. Then, it can be observed that the root node divides the inorder array into two halves, the left and right subtree. So, for constructing the tree using postorder and inorder, we will find the find the index of root node in inorder array and then make recursive calls on the left and right subtrees.

## Approach 1

C++ Code:
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
	// variable key: 
	// in -> inorder array
	// ins -> inorder start index
	// ine -> inorder end index
	// post -> postorder array
	// posts -> postorder start index
	// poste -> postorder end index

    TreeNode* buildTreeUtil(vector<int>& in, int ins, int ine, vector<int>& post, int posts, int poste) {
        
        if(ins>ine || posts>poste) return nullptr;
        
        int rval=post[poste]; // root value
        TreeNode* root = new TreeNode(rval);
        
        int i=ins;
        while(in[i] != rval) i++;
        
        root->right = buildTreeUtil(in, i+1, ine, post, posts+i-ins, poste-1);
        root->left = buildTreeUtil(in, ins, i-1, post, posts, posts+i-(ins+1));
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return buildTreeUtil(in, 0, in.size()-1, post, 0, post.size()-1);
    }
};
```
Java Code:
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

	// variable key: 
	// in -> inorder array
	// ins -> inorder start index
	// ine -> inorder end index
	// post -> postorder array
	// posts -> postorder start index
	// poste -> postorder end index
        
    public TreeNode buildTreeUtil(int[] in, int ins, int ine, int[] post, int posts, int poste) {
        
        if(ins>ine || posts>poste) return null;
        
        int rval=post[poste]; // root value
        TreeNode root = new TreeNode(rval);
        
        int i=ins;
        while(in[i] != rval) i++;
        
        root.right = buildTreeUtil(in, i+1, ine, post, posts+i-ins, poste-1);
        root.left = buildTreeUtil(in, ins, i-1, post, posts, posts+i-(ins+1));
        return root;
        
    }
    
    public TreeNode buildTree(int[] in, int[] post) {
        return buildTreeUtil(in, 0, in.length-1, post, 0, post.length-1);
    }
}
```

## Approach 2
Note: (As given in the problem description)
You may assume that duplicates do not exist in the tree.

Since we need not worry about the presence of duplicates in the tree, we can simply create an inorder key-value index map to store all values inside Hash Map and easily access the index of any particular node in the inorder traversal of the tree.

C++ Code:
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* buildTreeUtil(vector<int>& post, int& idx, const int& si, const int& ei) {
        if (si>ei) return NULL;
        TreeNode* root = new TreeNode(post[idx]);
        int mid = mp[post[idx]];
        idx--;
        root->right = buildTreeUtil(post, idx, mid+1, ei);
        root->left = buildTreeUtil(post, idx, si, mid-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0; i<in.size(); i++) mp[in[i]]=i;
        int idx=post.size()-1;
        return buildTreeUtil(post, idx, 0, in.size()-1);
    }
};
```

Java Code:
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode buildTreeUtil(int[] post, int idx, int si, int ei, Map<Integer, Integer> mp) {
        
        if (si>ei) return null;
        TreeNode root = new TreeNode(post[idx]);

        int mid = mp.get(post[idx]);
        idx--;

        root.right = buildTreeUtil(post, idx, mid+1, ei, mp);
        root.left = buildTreeUtil(post, idx-(ei-mid), si, mid-1, mp);
        return root;
    }

    public TreeNode buildTree(int[] in, int[] post) {
        
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i=0; i<in.length; i++) mp.put(in[i], i);
        return buildTreeUtil(post, post.length-1, 0, in.length-1, mp);
        
    }
}
```