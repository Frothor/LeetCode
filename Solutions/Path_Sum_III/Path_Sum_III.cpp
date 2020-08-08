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
    int DFS(TreeNode *root,int sum){
        return root?(root->val==sum) + DFS(root->left,sum-root->val) + DFS(root->right,sum-root->val):0;
    }
    int pathSum(TreeNode* root, int sum) {
        return root? DFS(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum):0;
    }
};


//Another DFS
class Solution {
public:
    void util(TreeNode* root, int curr, int sum, int& ans) {
        if(root == NULL) return;
        curr += root->val;
        if(curr == sum) ans++;
        util(root->left, curr, sum, ans);
        util(root->right, curr, sum, ans);
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        if(root == NULL) return 0;
        pathSumx(root, sum, ans);
        return ans;
    }
    void pathSumx(TreeNode* root, int sum, int& ans) {
        int curr = 0;
        if(root == NULL) return;
        util(root, curr, sum, ans);
        pathSumx(root->left, sum, ans);
        pathSumx(root->right, sum, ans);
        return;
    }
};

//Another DFS
class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int>& nums, int &res) 
    {
        if(root)
        {
            int val = root->val;
            vector<int> cpy = nums;
            
            dfs(root->left, sum, nums, res);            
            for(int i = 0; i < nums.size(); i++)
                res += (nums[i] += val) == sum;
            
            dfs(root->right, sum, cpy, res);
            for(int i = 0; i < cpy.size(); i++)
                res += (cpy[i] += val) == sum;
            
            for(int i = 0; i < cpy.size(); i++)
                nums.push_back(cpy[i]);
            
            res += val == sum;
            nums.push_back(val);
        }
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        vector<int> nums;
        int res = 0;
        dfs(root, sum, nums, res);
        return res;
    }
};

//Another
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }else{
            return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        }
    }
    int dfs(TreeNode* root, int sum){
        if(!root){
            return 0;
        }
        if(root->val == sum){
            return 1+dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
        }else{
            return dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
        }
    }
}

//Fastest
class Solution {
private:
    void pathSum(int sum, TreeNode *root, std::unordered_map<int, int> &presum, int &cnt, const int target) {
        if (!root) return;
        
        sum += root->val;
        if (presum.count(sum - target)) {
            cnt += presum[sum - target];
        }
        presum[sum]++;
        
        pathSum(sum, root->left, presum, cnt, target);
        pathSum(sum, root->right, presum, cnt, target);
        
        presum[sum]--;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        
        std::unordered_map<int, int> mem;
        mem[0] = 1;
        int cnt = 0;
        pathSum(0, root, mem, cnt, sum);
        
        return cnt;
    }
};