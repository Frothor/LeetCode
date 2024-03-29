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
    TreeNode *Tree(vector<int>& in, int inStart, int inEnd,vector<int>& po,int poStart,int poEnd){
        if(inStart > inEnd || poStart > poEnd)
            return nullptr;
        
        TreeNode *node = new TreeNode(po[poEnd]);
        int SI = inStart;  
        
        while(node->val != in[SI])
            SI++;
        
        node->left  = Tree(in,inStart,SI-1,po,poStart,poStart+SI-inStart-1);
        node->right = Tree(in,SI+1,inEnd,po,poStart+SI-inStart,poEnd-1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};

/*
Fastest:
class Solution {
public:
    unordered_map<int,int> m;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        int rootIndex=postorder.size()-1;
        return buildUtil(inorder,postorder,0,inorder.size()-1,rootIndex);
    }
    
    TreeNode* buildUtil(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int &rootIndex)
    {
        if(inleft > inright)
            return NULL;
        
        int val = postorder[rootIndex];
        TreeNode *node = new TreeNode(val);
        rootIndex--;
        
        /* If this node has no children then return */
        if(inleft==inright)
            return node;
        //else find index of this node in inonrder traversal
        int pivot=m[val];
        
        /* Using index in Inorder traversal, construct  left and right subtress */
        node->right = buildUtil(inorder, postorder, pivot + 1, inright, rootIndex); 
        node->left = buildUtil(inorder, postorder, inleft, pivot - 1, rootIndex); 
  
        return node; 
    }
};

*/