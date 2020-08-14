class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(255, 0);
        int ans=0;
        for(char c : s){
            v[c] +=1;
            v[c-'A']++;
            if(v[c-'A']%2==0)
            ans+=2;
        }
        return s.size()>ans?ans+1:ans;
    }
};

//Another equally fast
class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char,int> table;
        for(auto& c:s)
        {
            table[c]++;
        }
        int res = 0;
        int Odd = 0;
        for(auto& p:table)
        {
            if(p.second % 2 == 0)
            {
                res += p.second;
            }
            else
            {
                Odd = 1;
                res += p.second - 1;
            }
        }
        
        return res + Odd;
    }
};

//Fastest
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(256,0);
        
        for(char ch : s) freq[ch]++;
        bool flag = false;
        int len  = 0;
        for(int x : freq){
            if(x&1) {
                flag = true;
                len+= x-1;
            }
            else len+=x;
        }
        
        
        
        return len+flag;
    }
};