# LeetCode Longest Palindrome Solution

## Solution 1
Idea:

Count the frequency of each characters using Map.
Iterate all the values and increment longestPalindrome with the even count also check if you find any odd count set isOddOccurence occurence flag to true.
Return if isOddOccurence true longestPalindrome + else longestPalindrome
Detailed Video Explanation https://www.youtube.com/watch?v=noaGOtGmCzs

```c++
class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);

        boolean isOddOccurence = false;
        int longestPalindrome = 0;
        for (Integer val : map.values()) {
            longestPalindrome += (val / 2) * 2;
            if (val % 2 == 1) 
                isOddOccurence = true;
        }

        return isOddOccurence ? longestPalindrome + 1 : longestPalindrome;
    }
}
```

Using Set

Whenever you find second character remove from set and increment longestPalindrome by 2.
In the end just check if we have odd frequency character in set by checking set.size().
```c++
class Solution {
    public int longestPalindrome(String s) {
        Set<Character> set = new HashSet<>();
        int longestPalindrome = 0;
        for (char c : s.toCharArray()) {
            if (set.contains(c)) {
                set.remove(c);
                longestPalindrome += 2;
            } else set.add(c);
        }

        return set.size() > 0 ? longestPalindrome + 1 : longestPalindrome;
    }
}
```

Time Compexity - O(n) n - length of string s.

### No need to use use Set or Map though
```c++
public int longestPalindrome(String s) {
    boolean[] flags = new boolean[128];
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if ((flags[s.charAt(i)] ^= true) == false) {
            count += 2;
        }
    }
    return count == s.length() ? count : count + 1;
}
```

[Link to original post](https://leetcode.com/problems/longest-palindrome/discuss/791027/2-Solution-or-Idea-Explained-Count-frequency-using-Map-or-Using-Set)

## Solution 2
We can include all even frequency characters in our palindrome.
We can include atmost one odd frequency characters to make a palindrome
```c++
class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int>v(255,0);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'A']++;
            if(v[s[i]-'A']%2==0)
            ans+=2;
        }
        return s.size()>ans?ans+1:ans;
 
    }
};
```

### You can turn this into bit manipulation. Here's my solution:
```C++
    static int longestPalindrome(const string& s) {
        int biggestLength = 0;
        uint64_t letters = 0;
        for (char c : s) {
            const uint64_t letterBit = 1lu << (c >= 'a' ? (32lu + c - 'a') : (c - 'A'));
            if (letters & letterBit) { // If there is already the same letter stored
                biggestLength += 2; //Add the 2 letters to the palindrome
                letters &= ~letterBit; //Reset the stored letter
            }
            else {
                letters |= letterBit; //Add the letter
            }
        }
        if (letters) ++biggestLength; //The letter at the center of the palindrome
        return biggestLength;
    }
```

[Link to original post](https://leetcode.com/problems/longest-palindrome/discuss/790888/C%2B%2B-So-easy-..)