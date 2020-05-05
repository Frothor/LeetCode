/*
LeetCode First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> m;
        
        for(int i=0; i<s.size(); i++) m[s[i]]++;
           
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int arr[26] = {0};
        int i=0;
            
        for(; i<s.size(); i++) 
            arr[s[i] - 'a']++;
           
        for (i = 0; i < s.size(); i++)
            if (arr[s[i] - 'a'] == 1) 
                return i;
            
        return -1;
    }
};
*/

/*
Quicker solution:

class Solution {
public:
    int arr[26]={0};
    int i=0;
    
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(s=="")return -1;
        
        for(;i<s.size();i++)
            arr[s[i]-'a']++;
        
        for(i=0;i<s.size();i++)
            if(arr[s[i]-'a']==1)return i;
        
        
        return -1;
    }
};


Another: 
class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // Best approach----------faster than 90.47%
        // Using hashtable, We know ki max size of the tbale can be 26 as characters are there
        int arr[26] = {0};
        // Note: above means '= {0}' will initialize all garbage with 0, which is 
        // ***IMPORTANT***
        int i = 0;
        for (; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        
        for (i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == 1) return i;
        }
        return -1;
        
        // still not that much fast------faster than 33.82%
        // converting below code to O(n) complexity
        // using hashmaps
        // unordered_map<char, int> m;
        // for (auto x : s) m[x]++;
        // // record all elements and their frequencies
        // for (int i = 0; i < s.size(); i++) {
        //     if (m[s[i]] == 1) {
        //         // check if current frequency of the element is 1 then it's the first 
        //         // non repeating character hence return its index
        //         return i;
        //     }
        // }
        // if control reaches here means every element came twice hence, return -1;
        return -1;
        
        
        // O(n^2) approach:---------- faster than 27.90%
        // // checking edge case
        // if (s.size() == 0) return -1;
        // // Brute force
        // int j = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     for (j = 0; j < s.size(); j++) {
        //         if (i == j) continue;
        //         if (s[i] == s[j]) break;
        //     }
        //     if (j == s.size()) return i;
        // }
        // return -1;
    }
*/