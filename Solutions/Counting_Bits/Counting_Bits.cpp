class Solution {
public:
    vector<int> countBits(int num) {
        int i = 0, b = 1;
        vector<int> dp(num+1, 0);
        while(b <= num){
            while(i < b && i + b <= num){
                dp[i+b] = dp[i] + 1;
                i++;
            }
            i=0;
            b <<= 1;
        }
        
        return dp;
    }
};

/*
Fastest:

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=1;i<=num;i++) {
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};
*/