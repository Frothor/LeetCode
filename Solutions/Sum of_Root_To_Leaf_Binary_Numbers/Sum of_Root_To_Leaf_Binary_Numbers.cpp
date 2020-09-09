class Solution {
public:
    int sumRootToLeafHelper(TreeNode* rt, int cur_val) {
        if(! rt) return 0;
        
        cur_val = (cur_val << 1) | rt->val;
        
        if(!rt->left && !rt->right)
			return cur_val;
			
        return sumRootToLeafHelper(rt->left, cur_val) + sumRootToLeafHelper(rt->right, cur_val);
    }
    
    int sumRootToLeaf(TreeNode* rt) {
        return sumRootToLeafHelper(rt, 0);
    }
};

//Most common
class Solution {
private:
    int sums(TreeNode* root, int value) {
        if(!root) return 0;
        if(!root->left && !root->right) return (value << 1) + root->val;
        return sums(root->left, (value << 1) + root->val) + sums(root->right, (value << 1) + root->val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sums(root, 0);
    }
};

//Fastest
class Solution {
public:
    int dfs(TreeNode *root,int sum)
    {
        if(!root)return 0;
        sum=sum*2+root->val;
        if(!root->left and !root->right){cout<<sum<<"\n";return sum;}
        return dfs(root->left,sum)+dfs(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
       return dfs(root,0);
    }
};