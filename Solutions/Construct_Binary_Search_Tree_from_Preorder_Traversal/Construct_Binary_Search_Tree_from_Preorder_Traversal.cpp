/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBinTree(TreeNode *root, int &pval) {
        if(root==NULL) {
            root=new TreeNode(pval);
            
        } else if(pval < root->val) {
            root->left = constructBinTree(root->left, pval);
        } else if( pval > root->val) {
            root->right = constructBinTree(root->right, pval);
        }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = constructBinTree(root,preorder[0]);;
        for(int i = 1; i<preorder.size() ;i++) {
            constructBinTree(root,preorder[i]);
        }
        return root;
    }
    
};

/*
Fastest:
class Solution {
public:
    TreeNode* bst(TreeNode* root,int data){
        if(root==NULL){
            root=new TreeNode(data);
            return root;
        }
        if(root->val>data)
            root->left=bst(root->left,data);
        if(root->val<data)
            root->right=bst(root->right,data);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()<1)
            return NULL;
        TreeNode* root= new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
            root=bst(root,preorder[i]);
        return root;
    }
};
*/