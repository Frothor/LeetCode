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
    bool helper(TreeNode* root, int n, int i, vector<int>& arr){
        if(!root)
            return false;
        else if(i == n)
            return false;
        else if(root->val != arr[i])
            return false;
        else if(!root->left && !root->right && i == n-1)
            return true;
        
        return (helper(root->left, n, i + 1, arr) || helper(root->right, n, i + 1, arr));
    }
    
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
            int n = arr.size();
            int i = 0;
            return helper(root, n, i, arr); 
    }
};


/*
Another solution: 
*/
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    bool check(TreeNode* node, vector<int>& arr, int idx) {
        if (node == NULL) return false;
        if (node->val != arr[idx]) return false;
        if (idx + 1 == arr.size())
            return node->left == NULL && node->right == NULL;
        return check(node->left, arr, idx+1) || check(node->right, arr, idx+1);
    }

    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return check(root, arr, 0);
    }
}
*/