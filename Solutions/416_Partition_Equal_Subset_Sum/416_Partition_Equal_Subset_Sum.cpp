/* https://leetcode.com/problems/partition-equal-subset-sum/discuss/951553/C%2B%2BDPTop-Down-Bottom-Up-Simple-and-easy-to-understand-solution-with-explanation

Intuition -

If total sum of array elements is odd, no way is possible to get equal sum of two halves.
If sum is even,there can be different combinations possible to attain the solution so we should think if there is a way to get target sum (totalsum/2) from the array elements.
isPossible(target_sum,index) - returns if target_sum can be obtained using array elements nums[0.....index];

-> We have two possibilities whether to exclude the current element or include the current element.

Recursive Relation -

isPossible(target_sum,index) = isPossible(target_sum,index-1) || isPossible(target_sum-nums[index],index-1);

Think of base cases from your side or look at the code below :

Bottom-Up Approach :
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1) //if sum is odd
            return false;
        sum=sum/2;
        //dp[i][j] -> if sum 'i' is possible with elements from 0 to j-1
        //dp[sum+1][n]
        vector<vector<bool> > dp(sum+1,vector<bool>(n,false));
        //Sum=0 can be obtained using any number of elements
        for(int i=0;i<n;i++)
            dp[0][i]=true;
        //Sum>=0 can not be attained without any element
        for(int i=1;i<=sum;i++)
            dp[i][0]=false;
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1];
                if(i-nums[j-1]>=0){
                    dp[i][j]=dp[i][j] || dp[i-nums[j-1]][j-1];
                }
            }
        }
        return dp[sum][n-1];
        
    }
};

//Top-Down Approach :

class Solution {
public:
    bool isPossible(vector<int> &nums,vector<vector<bool> > &dp,vector<vector<bool> >& visited,int sum,int index){
        if(index<0 || sum<0)
            return false;
        if(sum==0)
            return dp[sum][index]=true;
        if(visited[sum][index])
            return dp[sum][index];
        visited[sum][index]=true;
        return dp[sum][index]=isPossible(nums,dp,visited,sum,index-1) || isPossible(nums,dp,visited,sum-nums[index],index-1);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1) //if sum is odd
            return false;
        
        //Find if there is subset with sum/2 present in the given array 'nums'
        sum=sum/2;
        vector<vector<bool> > dp(sum+1,vector<bool> (n,false));
        vector<vector<bool> > visited(sum+1,vector<bool> (n,false));
        return isPossible(nums,dp,visited,sum,n-1);
        
    }
};

//Third fastest
#include <bitset>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int maxNum = 100;
//         bitset一定要const且不能用 nums.size()
        const int len = 200;
//         0000...0001
        bitset<maxNum*len/2+1> bits(1);
        int total = 0;
        for(auto& n:nums) {
            total += n;
            bits |= bits << n;
        }
//         bitset index 左而右
        return total & 1 ? false:bits[total/2];
    }
};

//Second fastest
bool IS_HALF_POSSIBLE(vector<int>& nums, int n, int half);
class Solution {
public:
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int max = 0;
        for(int i = 0; i < n; i++) {
            max += nums[i]; 
        }
        if((max % 2) == 1) {
            return false;
        }
        else {
            return IS_HALF_POSSIBLE(nums, n, max/2);   
        }
    }
};


bool IS_HALF_POSSIBLE(vector<int>& nums, int n, int half) {
    bitset<50001> bits(1);
    sort(nums.begin(), nums.begin() + n, greater<int>());
    for(int i = 0; i < n; i++) {
        bits |= bits << nums[i];
        if(bits[half] == 1) {
            return true;
        }
    }
    return false;
}



//Fastest
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2) return false;
        sum /= 2;
        bitset<10001> dp = 1;
        for (int n : nums) {
            dp |= dp << n;
        }
        return dp[sum];
    }
};