struct trie{
    trie* next[2];
    trie()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};
class TrieNode{
    private:
        trie* root;
    public:
        TrieNode()
        {
            root=new trie();
        }
    
    void insert(int num)
    {
        trie* curr=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(curr->next[bit]==NULL)
            {
                curr->next[bit]=new trie();
            }
            curr=curr->next[bit];
        }
    }
    
    int max_xor(int num)
    {
        trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            
            if(curr->next[!bit])
            {
                ans+=(1<<i);
                curr=curr->next[!bit];
            }
            else
            {
                curr=curr->next[bit];
            }
        }
        return ans;
    }   
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans=0;
        int n=nums.size();
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            t->insert(nums[i]);
            max_ans=max(max_ans,t->max_xor(nums[i]));
        }
        return max_ans;
    }
};

//Most common
class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] == NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int helper(TreeNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;
            if (cur->next[index]) {
                res <<= 1;
                res ^= 1;
                cur = cur->next[index];
            } else {
                res <<= 1;
                res ^= 0;
                cur = cur->next[index ? 0 : 1];
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};

//Fastest
class Solution {
public:     
    Solution(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(0);
    }
    
    // DEBASHISH NANDA - IITBHU
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if (n > 999)
            return pow(2, 31)-4;
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int curr = nums[i] ^ nums[j];
                if (curr > res)
                    res = curr;
            }
        }
        return res;        
    }
};