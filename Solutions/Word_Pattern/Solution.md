# LeetCode Word Pattern Solution
## [Python] 2 hash-tables, explained

Pretty straightforward problem, where we need to just try to do what is asked. We need to check if our strings follow the pattern, so let us try to create this pattern and make sure that we do not have conflicts.

1. Split our string into **words**, so now we have list of words.
2. Check if length of **words** is equal to length of **pattern** and if not, immediatly return **False**.
3. Now, iterate one by one elements from **pattern** and **words**: let us keep two dictionaries: one is for correspondences **word -> letter** and another for **letter -> word**. Check if we already have **symb** in **d_symb**:
    a. If we do not have it, but it happen that our **word** is already occupied, we return **False**, we have a conflict.
    b. If word is not occupied, we create two connections: one for **d_symb** and one for **d_word**.
    c. Finally, if **symb** is already in our **d_symb**, but word is not the one we expect to see, we return **False**.
4. If we reached the end and did not return **False**, it means that we did not have any conflicts, so we need to return **True**.

**Complexity**: time complexity is **O(n + m)**, where n is number of symbols in **pattern** and **m** is total number of symbols in **s**. Space complexity is **O(k)**, where **k** is total length of all unique words.

```python
class Solution:
    def wordPattern(self, pattern, s):
        d_symb, d_word, words = {}, {}, s.split()
        if len(words) != len(pattern): return False
        for symb, word in zip(pattern, words):
            if symb not in d_symb:
                if word in d_word: return False
                else:
                    d_symb[symb] = word
                    d_word[word] = symb
            elif d_symb[symb] != word: return False
        return True
```

[Link to original post](https://leetcode.com/problems/word-pattern/discuss/833961/Python-2-hash-tables-explained)

## [C++] 0 ms, beats 100% | Short and Precise, Explained | One-pass tokenization

### Explanation
The key here is *bijection*, that is one-one and onto mapping. You can read about it here: https://en.wikipedia.org/wiki/Bijection.

The solution is simple: map a character in the pattern to a word in the string (in order) and map the same word to the same character. Throughout the loop over the string or pattern, ## [ensure that there exists one and only one mapping between a character in pattern and a word in string (*one-one*) **and** each character is mapped to at least one word (*onto*). That's it!

### Code
```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> pat_map (26, 0);
        unordered_map<string,int> str_map;
        int i=0, n = pattern.size();
        istringstream ss (str);
        string token;
        
        for(string token; ss >> token; ++i) {
            if(i == n || pat_map[pattern[i]-'a'] != str_map[token]) return false;
            
            // 1-based indexing since map assigns 0 as a default value for keys not found.
            pat_map[pattern[i]-'a'] = str_map[token] = i+1;
        }
        
        return i == n;
    }
};
```