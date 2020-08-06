class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};

//Most common
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> Ret={};
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0)nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            else {
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
                Ret.push_back(abs(nums[i]));
            }
        }
        return Ret;
    }
};

//Fastest
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        vector<int> res;
        for (int num : nums) {
            int ind = abs(num)-1;
            if(nums[ind]<0) res.push_back(ind+1);
            else nums[ind]*=-1;
        }
        return res;
    }
};
