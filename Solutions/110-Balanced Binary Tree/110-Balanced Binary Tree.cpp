//Third fastest
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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    
    int getHeight(TreeNode* root) {
        if (!root)
            return 1;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if (left != -1 && right != -1 && abs(left - right) <= 1) {
            return max(left, right) + 1;
        }
        
        return -1;
    }
    
};

//Second fastest
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
      bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return height(root) != -1;
    }
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        if(lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1){
            return -1;
        }
        return 1 + max(lHeight, rHeight);
    }
};

//Fastest
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
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
    
    std::pair<bool, int> helper(TreeNode* node) {
        if (!node) {
            return std::pair<bool, int>(true, 0);
        }
        auto left = helper(node->left);
        auto right = helper(node->right);
        auto balance = left.first && right.first && (abs(left.second - right.second) <= 1);
        auto height = max(left.second, right.second) + 1;
        return std::pair<bool, int>(balance, height);
    }
};