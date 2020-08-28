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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
    
    private:
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        if(root->left == nullptr && root->right == nullptr && isLeft) return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};

//Fastest
class Solution {
    public:
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        
        int v1 = sumOfLeftLeaves(root->left);
        int v2 = sumOfLeftLeaves(root->right);
        
        if(root->left){
            TreeNode*node = root->left;
            if(node->left==NULL && node->right==NULL){
                return v1+v2+root->left->val;
            }
            
        }
        
        return v1+v2;
    }
};

//DFS

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool leftSide = false) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL && leftSide) return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

//BFS

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if( root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, bool> > q;
        q.push({root, false});
        while(!q.empty()) {
            pair<TreeNode*, bool> tmp = q.front();
            q.pop();
            TreeNode* prc = tmp.first;
            bool isLeft = tmp.second;
            if(isLeft && isLeaf(prc)) ans += prc->val;
            if(prc->left) q.push({prc->left, true});
            if(prc->right) q.push({prc->right, false});
        }
        return ans;
    }
};