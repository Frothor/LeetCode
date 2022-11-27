class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(m.find(complement) != m.end()) {
                result.push_back(i);
                result.push_back(m[complement]);
                return result;
            }
            m[nums[i]] = i;
        }
        
        return result;
    }
};