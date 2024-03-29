# LeetCode Repeated Substring Pattern
## [C++] O(N) time | One-liner without KMP, Explained | Beats 99%

### Explanation
The key here is to double the string, that is, append the string to itself. In this way, the pattern would be duplicated.
On removing the first and the last characters, if there exists some pattern, we would still be able to find the original string somewhere in the middle, taking some characters from the first half and some from the second half.

For example,

### Example 1.
```
s = "abab"
s+s = "abababab"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "bababa"

This new string, "bababa" still contains the original string, "abab".
Thus there exists some repeated pattern in the original string itself.
```

### Example 2.
```
s = "aba"
s+s = "abaaba"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "baab"

This new string, "baab" does not contain the original string, "aba".
This implies that there does not exist any pattern in the original string itself.
```

### Code
```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};
```

**PS** The average-case (and not worst-case) time complexity of find() is O(N). For worst-case O(N) time complexity, we'll have to use KMP. Refer to this for more details: https://stackoverflow.com/a/8869689

[Link to original post](https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99)

