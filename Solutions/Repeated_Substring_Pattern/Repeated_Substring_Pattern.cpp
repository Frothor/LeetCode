//Fastest
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n < 2) return false;
        if (n == 2) return s[0] == s[1];    
            
        string_view v(s);
        
        vector<int> divisors;
        
        int sqrtN = sqrt(n);
        
        for (int i = 2; i <= sqrtN; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);    
            }
        }
        
        divisors.push_back(1);
        
                for (int l : divisors) {
    
                    string_view tmp = v.substr(0, l);
                    string_view first = v.substr(0, l);
                    
                    int firstHash = hash<string_view>{}(tmp);
                    int currHash = firstHash;
                    int start = l;
                    while (start != n && currHash == firstHash) {
                        tmp = v.substr(start, l);
                        currHash = hash<string_view>{}(tmp);
                        start += l;    
                    }
                    if (start == n && currHash == firstHash) {
                        //cout << l << endl;
                        return true;    
                    }    
                }     
               
         
        return false;
    }
};

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();