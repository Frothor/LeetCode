/*
LeetCode Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.resize(n);
        
        int prod = 1;
        for(int i = 0; i < n; i++){
            ans[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= prod;
            prod *= nums[i];
        }
        return ans;
    }
};