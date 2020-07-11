class Solution {
private:
    void find_subsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& sub, int i){
        result.push_back(sub);
        for(int j = i; j<nums.size(); j++){
            sub.push_back(nums[j]);
            find_subsets(nums, result, sub, j+1);
            sub.erase(sub.end()-1);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0)
            return result;
        
        sort(nums.begin(), nums.end());
        vector<int> sub;
        find_subsets(nums, result, sub, 0);
        
        return result; 
    }
};

/*
Most common:
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        sort(nums.begin(),nums.end());
        vector<int> sub;
        subset(nums,ans,sub,0);
        return ans;
        
        
            
    }
    void subset(vector<int>& nums, vector<vector<int>> &ans,vector<int> sub,int start)
    {
        ans.push_back(sub);
        for(int i=start;i<nums.size();i++)
        {
            sub.push_back(nums[i]);
            subset(nums,ans,sub,i+1);
            sub.pop_back();
        }
    }
};

Fastest:
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < pow(2, n); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    v.push_back(nums[j]);
                }
            }
            results.push_back(move(v));
        }
        return results;
    }
};

*/