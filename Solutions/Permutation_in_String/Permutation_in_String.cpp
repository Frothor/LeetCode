class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int s1map[26] = {0};
        int s2map[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
            if (s1map[i] == s2map[i])
                count++;
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a', l = s2[i] - 'a';
            if (count == 26)
                return true;
            s2map[r]++;
            if (s2map[r] == s1map[r])
                count++;
            else if (s2map[r] == s1map[r] + 1)
                count--;
            s2map[l]--;
            if (s2map[l] == s1map[l])
                count++;
            else if (s2map[l] == s1map[l] - 1)
                count--;
        }
        return count == 26;
    }
};

/*
Most common: class Solution {
public:
    bool check(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
            
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        int a[26]={0},b[26]={0};
        for(auto c:s1)
            a[c-'a']++;
        int k=0;
        for(int i=0;i<=s2.length();i++)
        {
            if(i>=s1.length())
            {
                if(check(a,b))
                {
                    k=1;
                    break;
                    
                }
                if(i>=s2.length())
                    break;
                b[s2[i-s1.length()]-'a']--;
                b[s2[i]-'a']++;
                
            }
            else
            {
                b[s2[i]-'a']++;
            }
        }
        if(k)
            return true;
        return false;
        
        
    }
};


Fastest:
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return 0;
        }

        vector<int> m1(26,0), m2(26,0);
        int same = 0;
        int cnt = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (m1[i] == m2[i]) {
                same++;        
            }
        }
        
    
        for (int i = s1.size(); i < s2.size(); i++) {
            if (same == 26) {
                return true;
            }
            
            char l = s2[i - s1.size()] - 'a';
            char r = s2[i] - 'a';
            
            m2[l]--;
            if (m1[l] == m2[l]) {
                same++;
            } else if (m1[l] == m2[l] + 1) {
                same--;
            }
            
            m2[r]++;
            if (m1[r] == m2[r]) {
                same++;
            } else if (m1[r] == m2[r] - 1) {
                same--;
            }
        }    
         
        return same == 26;
    }
};
*/