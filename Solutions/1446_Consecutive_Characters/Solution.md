# LeetCode Easy 1446. Consecutive Characters Solution
## Overview
This problem is very similar to [674. Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/), and the only difference is that we need a substring with the same characters instead of an increasing one. Therefore, similar methods can be applied. Below, a similar and simple approach is introduced.

## Approach #1: One Pass
### Intuition and Algorithm

Recall the problem, we need to find "the maximum length of a non-empty substring that contains only one unique character".

In other words, we need to find the Longest Substring with **the same characters**.

We can iterate over the given string, and use a variable `count` to record the length of that substring.

When the next character is the same as the previous one, we increase `count` by one. Else, we reset `count` to 1.

With this method, when reaching the end of a substring with the same characters, `count` will be the length of that substring, since we reset the `count` when that substring starts, and increase `count` when iterate that substring.

Therefore, the maximum value of `count` is what we need. Another variable is needed to store the maximum while iterating.

### Java
```java
class Solution {
    public int maxPower(String s) {
        int count = 0;
        int maxCount = 0;
        char previous = ' ';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == previous) {
                // if same as previous one, increase the count
                count++;
            } else {
                // else, reset the count
                count = 1;
                previous = c;
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
}
```

### Python#
```python
class Solution:
    def maxPower(self, s: str) -> int:
        count = 0
        max_count = 0
        previous = None
        for c in s:
            if c == previous:
                # if same as previous one, increase the count
                count += 1
            else:
                # else, reset the count
                previous = c
                count = 1
            max_count = max(max_count, count)
        return max_count
```

### Complexity Analysis

Let ***N*** be the length of `s`.

* Time Complexity: ***O(N)***, since we perform one loop through `s`.

* Space Complexity: ***O(1)***, since we only have two integer variables `count` and `max_count(maxCount)`, and one character variable `previous`.