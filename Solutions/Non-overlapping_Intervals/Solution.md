# LeetCode Non-overlapiing Intervals

## Solution 1: Very Easy 4 liner Explained | O(n*logn); O(1)
The idea is to sort the intervals by their end. In such a way, we know which interval ends first so any interval which comes after (and overlaps) could also overlap other intervals, so we remove it. If the next interval doesn't overlap, then we update our end. 2 intervals overlap if the end of the former (interval[k][1]) is bigger than the start of the latter (interval[k+1][0]), so we only keep the end of the intervals (I will keep it in 'r')
```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0, r = INT_MIN;                                                          // Initially we create a dummy interval with end INT_MIN
        sort(intervals.begin(), intervals.end(), [](auto x, auto y){return x[1] < y[1];}); // With a lambda function we sort the intervals by their end (interval[1]).
        for(auto x: intervals) x[0] >= r ? r = x[1] : ans++;                               // If the start of the current interval is bigger or equal than the end of our last one, we update our end, else we have an overlap so we update our answer.
        return ans;                                                                        // return answer
    }
};
```

[Link to original post](https://leetcode.com/problems/non-overlapping-intervals/discuss/792788/C%2B%2B-or-Very-Easy-4-liner-Explained-or-O(n*logn)-O(1))