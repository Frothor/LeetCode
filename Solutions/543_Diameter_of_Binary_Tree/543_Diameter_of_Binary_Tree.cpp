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
    int help(TreeNode* root, int &h) {
        if(root == nullptr) 
            return 0;
        
        int left = help(root->left, h);
        int right = help(root->right, h);
        
        h = max(left + right, h);
        
        return max(left, right) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        help(root, d);
        return d;
    }
};

//Second fastest
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        if (root == 0)
            return 0;
        dfs(root, result);
        return result;
    }
    
    int dfs(TreeNode* root, int& result);
};

int Solution::dfs(TreeNode* node, int& result) {
    if (node == 0)
        return -1;
    if (node->left == 0 && node->right == 0) {
        return 0;
    }
    
    int left_height = dfs(node->left, result) + 1;
    int right_height = dfs(node->right, result) + 1;
    result = max(result, (left_height + right_height));
    return max(left_height, right_height);
}

//Fastest
class Solution {
public:
    // time O(N)checked every node. space O(h) depth of DFS
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0; 
        dfs(root); 
        return ans; 
    }
private: 
    int ans; 
    int dfs(TreeNode*root) {
        if(!root) return -1; 
        int l=dfs(root->left)+1;   // l is all edges on the left for root node
        int r=dfs(root->right)+1; 
        ans= max(ans, l+r); 
        return max(l, r); // the edge includes the one from root to root->right or root->left
    }
};