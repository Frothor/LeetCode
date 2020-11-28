//Second fastest
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = (int)s.length();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};

//Another
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(n == 0 || n < k)
            return 0;
        if(k <= 1)
            return n;
        
        unordered_map<char, int> freq;
        for(char ch : s)
            freq[ch]++;

        int l = 0;
        while (l < n && freq[s[l]] >= k)
            l++;
        
        if(l >= n-1)
            return l;

        int ls1 = longestSubstring(s.substr(0, l), k);
        while(l < n && freq[s[l]] < k) 
            l++;

        int ls2;
        if(l < n)
            ls2 = longestSubstring(s.substr(l), k);
        else
            ls2 = 0;
        

        return max(ls1, ls2);
    }
};

//Fastest
class Solution {
public:
    int longestSubstring(string s, int &k) {
        int m[26] = {0}, idx[26] = {0} ;
        unordered_set<char> less;
        int len = s.length();
        int i =0 , br;

        if (len < k) {
            return 0;
        }
        for (i = 0; i < s.length(); i++) {
            m[s[i]-'a']++;
            idx[s[i] - 'a'] = i;
        }
        for ( i =0; i < 26; i++) {
            if (m[i] != 0 && m[i] < k) {
                br = idx[i];
                break;
            }
        }
        if (i == 26) {
            return s.length();
        }
        

        int r1 = longestSubstring(s.substr(0,br), k);
        int r2 = longestSubstring(s.substr(br+1, len-br+1), k);
        return r1>r2? r1:r2;
        return 0;
    }
};