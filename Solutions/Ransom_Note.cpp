/*
LeetCode  Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26];
        for(int i = 0; i<26; i++)
            count[i] = 0;
        
        for(char i:magazine)
            ++count[i-'a'];
        for(char i:ransomNote){
            --count[i-'a'];
            if(count[i-'a']<0) return false;
        }
        return true;
    }
};