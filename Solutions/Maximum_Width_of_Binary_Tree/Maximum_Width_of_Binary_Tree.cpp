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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int result = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result, end-start+1);
            
            for(int i = 0; i < count; i++){
                pair<TreeNode*, int> p = q.front();
                int idx = p.second - start;
                q.pop();
                if(p.first->left)
                    q.push({p.first->left, 2*idx+1});
                if(p.first->right)
                    q.push({p.first->right, 2*idx+2});
            }
        }
        
        return result;
    }
};


/*
Fastest:
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        if (root)
            q.push({root, 1});
        
        while (!q.empty()) {
            int cnt = q.size();
            unsigned long long left = q.front().second, right;
            for (int i = 0; i < cnt; i++) {
                TreeNode* n = q.front().first;
                right = q.front().second;
                q.pop();
                if (n->left != nullptr) {
                    q.push({n->left, 2*right});
                }
                if (n->right != nullptr) {
                    q.push({n->right, 2*right+1});
                }
            }
            //cout << right << " " << left << "\n";
            ans = max(ans, (int)(right - left + 1));
        }
        
        return ans;
    }
};
*/