# LeetCode Medium 131. Palindrome Partitioning Solution
## Overview
The aim to partition the string into all possible palindrome combinations. To achieve this, we must generate all possible substrings of a string by partitioning at every index until we reach the end of the string. Example, abba can be partitioned as `["a","ab","abb","abba"]`. Each generated substring is considered as a potential candidate if it a [Palindrome](https://en.wikipedia.org/wiki/Palindrome).

Let's look at a few approaches to implement this idea.

## Approach 1: Backtracking
### Intuition

The idea is to generate all possible substrings of a given string and expand each possibility if is a potential candidate. The first thing that comes to our mind is [Depth First Search](https://en.wikipedia.org/wiki/Depth-first_search). In Depth First Search, we recursively expand potential candidate until the defined goal is achieved. After that, we backtrack to explore the next potential candidate.

[Backtracking](https://en.wikipedia.org/wiki/Backtracking) incrementally build the candidates for the solution and discard the candidates (backtrack) if it doesn't satisfy the condition.

The backtracking algorithms consists of the following steps:

* *Choose*: Choose the potential candidate. Here, our potential candidates are all substrings that could be generated from the given string.

* *Constraint*: Define a constraint that must be satisfied by the chosen candidate. In this case, the constraint is that the string must be a *palindrome*.

* *Goal*: We must define the goal that determines if have found the required solution and we must backtrack. Here, our goal is achieved if we have reached the end of the string.

### Algorithm

In the backtracking algorithm, we recursively traverse over the string in depth-first search fashion. For each recursive call, the beginning index of the string is given as `start`.

1. Iteratively generate all possible substrings beginning at \text{start}start index. The \text{end}end index increments from \text{start}start till the end of the string.

2. For each of the substring generated, check if it is a palindrome.

3. If the substring is a palindrome, the substring is a potential candidate. Add substring to the `currentList` and perform a depth-first search on the remaining substring. If current substring ends at index `end`, `end+1` becomes the `start` index for the next recursive call.

4. Backtrack if `start` index is greater than or equal to the string length and add the `currentList` to the result.

### Implementation

#### C++
```c++
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList);
                // backtrack and remove the current substring from currentList
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
```

### Java
```java
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<List<String>>();
        dfs(0, result, new ArrayList<String>(), s);
        return result;
    }

    void dfs(int start, List<List<String>> result, List<String> currentList, String s) {
        if (start >= s.length()) result.add(new ArrayList<String>(currentList));
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                currentList.add(s.substring(start, end + 1));
                dfs(end + 1, result, currentList, s);
                // backtrack and remove the current substring from currentList
                currentList.remove(currentList.size() - 1);
            }
        }
    }

    boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) return false;
        }
        return true;
    }
}
```

### Complexity Analysis

* Time Complexity : ***O(N ⋅ 2^N)***, where ***N*** is the length of string ***s***. This is the worst-case time complexity when all the possible substrings are palindrome.

Example, if = s = `aaa`, the recursive tree can be illustrated as follows:

![sketch1](images/sketch1.png)

Hence, there could be ***2^N*** possible substrings in the worst case. For each substring, it takes ***O(N)*** time to generate substring and determine if it a palindrome or not. This gives us time complexity as ***O(N ⋅ 2^N)***

* Space Complexity: ***O(N)***, where ***N*** is the length of the string ***s***. This space will be used to store the recursion stack. For s = `aaa`, the maximum depth of the recursive call stack is 3 which is equivalent to ***N***.

## Approach 2: Backtracking with Dynamic Programming
### Intuition

This approach uses a similar Backtracking algorithm as discussed in Approach 1. But, the previous approach performs one extra iteration to determine if a given substring is a palindrome or not. Here, we are repeatedly iterating over the same substring multiple times and the result is always the same. There are [Overlapping Subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblems) and we could further optimize the approach by using dynamic programming to determine if a string is a palindrome in constant time. Let's understand the algorithm in detail.

### Algorithm

A given string ***s*** starting at index ***start*** and ending at index ***end*** is a palindrome if following conditions are satisfied :

1. The characters at ***start*** and ***end*** indexes are equal.
2. The substring starting at index ***start+1*** and ending at index ***end−1*** is a palindrome.

![palindrome_dp](iamges/palindrome_dp.png)

Let ***N*** be the length of the string. To determine if a substring starting at index ***start*** and ending at index ***end*** is a palindrome or not, we use a 2 Dimensional array ***dp*** of size ***N⋅N*** where,

***dp[start][end]=true*** , if the substring beginning at index ***start*** and ending at index ***end*** is a palindrome.

Otherwise, ***dp[start][end] ==false***.

Also, we must update the ***dp*** array, if we find that the current string is a palindrome.

### Implementation

#### C++
```c++
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
```

#### Java
```java
class Solution {
    public List<List<String>> partition(String s) {
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        List<List<String>> result = new ArrayList<>();
        dfs(result, s, 0, new ArrayList<>(), dp);
        return result;
    }

    void dfs(List<List<String>> result, String s, int start, List<String> currentList, boolean[][] dp) {
        if (start >= s.length()) result.add(new ArrayList<>(currentList));
        for (int end = start; end < s.length(); end++) {
            if (s.charAt(start) == s.charAt(end) && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.add(s.substring(start, end + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.remove(currentList.size() - 1);
            }
        }
    }
}
```

### Complexity Analysis

* Time Complexity : ***O(N ⋅ 2^N)***, where N is the length of string ss. In the worst case, there could be ***2^N*** possible substrings and it will take ***O(N)*** to generate each substring using substr as in *Approach 1*. However, we are eliminating one additional iteration to check if substring is a palindrome or not.

* Space Complexity: ***O(N⋅N)***, where ***N*** is the length of the string ***s***. The recursive call stack would require ***N*** space as in *Approach 1*. Additionally we also use 2 dimensional array ***dp*** of size ***N⋅N***.

This gives us total space complexity as ***O(N⋅N) + O(N) = O(N⋅N)***