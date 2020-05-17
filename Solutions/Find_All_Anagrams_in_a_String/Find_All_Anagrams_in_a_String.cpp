class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int l = p.length();
        
        vector<int> ans;
        vector<int> vs(26, 0);
        vector<int> vp(26, 0);
        
        for(char c: p) ++vp[c - 'a'];
        for(int i = 0; i < n; i++){
            if(i >= l)
                --vs[s[i-l] - 'a'];
            ++vs[s[i] - 'a'];
            if(vs == vp)
                ans.push_back(i+1 - l);
        }
        
        return ans;
    }
};

/*
Fastest:
class Solution {
    
public:
    
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    vector<int> findAnagrams(string& s, string& p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        vector<int> ar(26, 0);
        for(auto c : p) {
            ++ar[c - 'a'];
        }
        int count = m, currLen = 0, start = 0;
        for(int i = 0;i<n;i++) {
            
            if (ar[s[i] - 'a']-- > 0) --count;
            
            while (count == 0) {
                currLen = i - start + 1;
                if (currLen == m) {
                    res.push_back(start);
                }
                if (ar[s[start++] - 'a']++ == 0)
                    ++count;
            }
            
        }
        return res;
    }
};

Another:
class Solution {
    
public:
    
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    vector<int> findAll(string& s, string& p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        vector<int> ar(26, 0);
        for(auto c : p) {
            ++ar[c - 'a'];
        }
        int count = m, currLen = 0, start = 0;
        for(int i = 0;i<n;i++) {
            
            if (ar[s[i] - 'a']-- > 0) --count;
            
            while (count == 0) {
                currLen = i - start + 1;
                if (currLen == m) {
                    res.push_back(start);
                }
                if (ar[s[start++] - 'a']++ == 0)
                    ++count;
            }
            
        }
        return res;
    }
    
    vector<int> findAnagrams(string& s, string& p) {
        return findAll(s, p);
//         int m = p.size();
//         int n = s.size();
        
//         if (n < m || m == 0) 
//             return {};
//         vector<int> umap(26, 0);
        
//         for(auto a : p) {
//             ++umap[a - 'a'];
//         }
        
//         int counter = p.size();
//         vector<int> res;
        
//         int start = 0, end = 0, minLen = INT_MAX, LEFT;
        
//         while(end < n) {
//             if (umap[s[end] - 'a'] > 0) {
//                 --counter;
//             }
//             --umap[s[end] - 'a'];
            
//             while (counter == 0) {
//                 // cout<<start<<" "<<end<<" "<<counter<<"\n";
//                 if ((end - start + 1) == m) {
//                     res.push_back(start);
//                 }
                
//                 if (umap[s[start] - 'a'] == 0) {
//                     ++counter;
//                 }
//                 ++umap[s[start] - 'a'];
//                 ++start;
//             }
            
//             ++end;
//         }
        
//         return res;
    }
};
*/