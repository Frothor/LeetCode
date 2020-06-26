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
#define ll long long
class Solution {
    ll ans = 0;
    void dfs(TreeNode* root, ll val){
        if(!root)
            return;
        val *= 10;
        val += root->val;
        if(!root->left && !root->right){
            ans+=val;
            return;
        }
        dfs(root->left, val);
        dfs(root->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root, 0);
        return ans;
    }
};

/*
Fastest:
class Solution {
public:
    void sumNumbersHelper(TreeNode* root, int cur, int& res) {
        if(root==nullptr)
            return;
        cur=cur*10+root->val;
        if(root->left==nullptr && root->right==nullptr) {
            res+=cur;
            return;
        }
        sumNumbersHelper(root->left, cur, res);
        sumNumbersHelper(root->right, cur, res);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        sumNumbersHelper(root, 0, res);
        return res;
    }
};
*/