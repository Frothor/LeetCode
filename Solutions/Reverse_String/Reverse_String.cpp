class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start=0, end=n-1;
        while(start < end){
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
};

/*
Fastest
static int n = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=0;i<len/2;i++) {
            char k = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = k;
        }
        
        return;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int l =s.size();
     for(int i=0;i<l/2;i++)
     {
         char c = s[i];
         s[i]=s[l-1-i];
         s[l-i-1]=c;
     }
    }
};
*/