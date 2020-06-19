class Solution {
    int prime = 1000001;
    vector<int> power;
    
    string rabin_karp(string& s, int len){
        if(len == 0)
            return "";
        int n = s.length();
        int curr = 0;
        unordered_map<int, vector<int>> hash;
        
        for(int i=0; i<len; i++)
            curr = (curr * 26 + (s[i]-'a')) % prime;
        
        hash[curr] = {0};
        
        for(int i = len; i<n; i++){
            curr = ((curr - power[len-1] * (s[i-len] - 'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i]-'a')) % prime;
            
            if(hash.find(curr) == hash.end())
                hash[curr] = {i-len+1};
            else {
                for(int index: hash[curr]){
                    string str = s.substr(i-len+1, len);
                    if(s.substr(index, len) == str)
                        return s.substr(index, len);
                }
                hash[curr].push_back({i-len+1});
            }
        }
        
        return "";
    }
public:
    string longestDupSubstring(string S) {
        int n = S.length();
        int l = 0, r = n-1;
        
        power = vector<int>(n);
        power[0] = 1;
        for(int i=1; i<n; i++)
            power[i] = (power[i-1] * 26) % prime;
        
        string res;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            string curr = rabin_karp(S, mid);
            if(curr.length() > res.length()){
                res = curr;
                l = mid+1;
            }
            else
                r = mid;
        }
        
        return res;
    }
};