/*
LeetCode Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int maxLen = 0;
        unordered_map<int, int> m;
        
        m.insert({0, -1});
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? count -= 1 : count += 1;
            
            if(m.find(count) != m.end()) {
                maxLen = max(maxLen, i - m.find(count)->second);
            } else {
                m.insert({count, i});
            }
            
        }
        
        return maxLen;
    }
};