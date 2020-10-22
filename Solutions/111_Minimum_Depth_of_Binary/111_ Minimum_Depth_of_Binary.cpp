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

//Most common
class Solution {
public:
    int helper(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left)
            return 1 + helper(root->right);
        if(!root->right)
            return 1 + helper(root->left);
        return 1 + min(helper(root->right), helper(root->left));
    }        
    
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};

//Third fastest
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right){
            return minDepth(root->right) + 1;
        }
        if(root->right == NULL && root->left){
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

//Second fastest
class Solution {
public:
    int ans=INT_MAX;
    void calc(TreeNode* root, int dep=0)
    {
        if(root==NULL)
            return ;
        if(root->left)
            calc(root->left,dep+1);
        if(root->right)
            calc(root->right,dep+1);
        if(!root->left && !root->right)
        {
            ans=min(ans,dep+1);
            return;
        }
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        calc(root);
        return ans;
    }
};

//Fastest
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        
        if(root->left && root->right)
            return min(lh, rh)+1;
        
        return max(lh, rh) + 1;
       
    }
};