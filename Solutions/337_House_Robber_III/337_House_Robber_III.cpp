//Third fastest
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int l=0;
        int r =0;
        return tryrob(root, l, r);
    }
    
    int tryrob(TreeNode* node, int& l, int& r)
    {
        if(node == nullptr) return 0;
        
        int ll=0,rr=0,lr=0,rl =0;
        l = tryrob(node->left, ll, lr);
        r = tryrob(node->right, rl, rr);
        
        return max(node->val + ll+lr+rl+rr, l+r);
    }
};

//Second fastest
class Solution {
public:
    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
};

//Fastest
class Solution {
public:
    pair<int, int> dfs(TreeNode* node) {
        if (node == NULL)
            return make_pair(0,0);
        
        pair<int, int> l = dfs(node->left);
        pair<int, int> r = dfs(node->right);
        
        int steal = node->val + l.second + r.second;
        int n_steal = l.first + r.first;
        return make_pair(max(steal, n_steal), n_steal);
    };
    
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
};