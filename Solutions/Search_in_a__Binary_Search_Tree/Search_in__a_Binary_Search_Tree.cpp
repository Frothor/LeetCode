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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) 
            return root; 
        else if(root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }
};

/*
Fastest:
static auto __io_speed_up = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;  
}();

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val==val)
            return root;
        
        if(val<root->val)
            return searchBST(root->left,val);
        
        return searchBST(root->right,val);
    }
};
*/