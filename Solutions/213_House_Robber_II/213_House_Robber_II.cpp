class Solution {
public:
    int rob(vector<int>& nums) {
        if (size(nums) <= 1) return empty(nums) ? 0 : nums.front();
        if (size(nums) == 2) return max(nums[0], nums[1]);

        auto robHouses = [&nums](int start, int end) {
            int first = nums[start];
            int second = max(nums[start], nums[start + 1]);
            for (int i = start + 2; i <= end; ++i) {
                int curr = max(second, first + nums[i]);
                first = second;
                second = curr;
            }
            return second;
        };

        return max(robHouses(0, size(nums) - 2),
                   robHouses(1, size(nums) - 1));
    }
};

//Fastest
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(rob1(nums, 0, nums.size() - 2), rob1(nums, 1, nums.size() - 1));
    }
    
    int rob1(vector<int>& nums, int start, int end) {
        if (start > end) {
            return 0;
        }
        
        vector<int> dp(end - start + 2, 0);
        for (int i = 1; i < dp.size(); i++) {
            int candidate1 = i - 2 >= 0 ? dp[i - 2] : 0;
            int candidate2 = i - 3 >= 0 ? dp[i - 3] : 0;
            dp[i] = max(candidate1, candidate2) + nums[start + i - 1];
        }
        
        return max(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};