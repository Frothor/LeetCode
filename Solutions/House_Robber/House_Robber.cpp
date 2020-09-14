//O(n) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        // dp[i] --> max money which he rob till ith house
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        // if he rob the ith house then max value is dp[i-2](max value till i-2 house) + nums[i] 
        // else dp[i-1](max value till i-1 house)
        for(int i=2;i<n;++i) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

//O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int dp[n];
        int a=nums[0]; // (i-2)th
        int b=max(nums[0],nums[1]); // (i-1)th 
        for(int i=2;i<n;++i) {
            int c=b;
            b=max(b, a+nums[i]);
            a=c;
        }
        return max(a,b);
    }
};

//One liners
int rob(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [pp = 0](int p, int n) mutable { return max(pp + n, (pp = p)); });
}

//To make the code more descriptive:
int rob(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [prevPrevMax = 0](int prevMax, int n) mutable { return max(prevPrevMax + n, (prevPrevMax = prevMax)); });
}

int rob(vector<int>& nums) {
    int a = 0, b = 0;
    for (int n : nums)
        a = exchange(b, max(a + n, b));
    return b;
}