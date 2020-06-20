#define p 10000007

vector<int> roll;

class Solution {
    bool match(string s, int len, int size, string& ans){
        unordered_map<int,vector<int>> m;
        int hash = 0;
        for(int i=0; i<size; i++)
            hash = (hash*26 + (s[i] - 'a'))%p;
        
        m[hash].push_back(0);
        //Rolling hash -> sliding window
        for(int j=size; j<len; j++){
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;
            hash = (hash*26 + (s[j]-'a'))%p;
            if(m.find(hash)!=m.end()){
                for(auto start: m[hash]){
                    string temp = s.substr(start, size);
                    string curr = s.substr(j-size+1, size);
                    if(temp.compare(curr)==0){
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j-size+1);
        }
        return false;
    }
public:
    string longestDupSubstring(string S) {
        int len = S.length();
        if(len==0)
            return "";
        //Storing all roling hash values
        roll.resize(len); //Allocating fixed space to array
        roll[0] = 1;
        
        for(int i=1; i<len; i++)
            roll[i] = (roll[i-1] * 26) % p;
        
        int low=1, high=len, mid;
        string ans = "", temp;
        while(low <= high){
            temp = "";
            mid = low + (high-low)/2;
            bool isMatch = match(S, len, mid, temp);
            if(isMatch){
                if(temp.size()>ans.size())
                    ans=temp;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        
        return ans;
    }
};


/*
https://xingxingpark.com/Leetcode-1044-Longest-Duplicate-Substring/

BinarySearch + Rabin-Karp

ban: (1 * 26 * 26 + 0 * 26 + 13) % 31 = 7
ana: (0 * 26 * 26 + 13 * 26 + 0) % 31 = 28
nan: (13 * 26 * 26 + 0 * 26 + 13) % 31 = 28
ana: (0 * 26 * 26 + 13 * 26 + 0) % 31 = 28

我们可以观察到，ana与nan拥有相同的哈希值，但是它们确实是不同的字符串。因为这种哈希值的计算过程中，有重复计算的部分，所以我们可以rolling这部分的内容，优化时间。同时，哈希值的空间大小也是明显优于那些超长字符串的。

需要说明的是，这个方法会有false positive的可能，因为hash function有collision的产生。但当modulus很大时，概率是极低的。
*/

/*
Other:
class Solution {
public:
    string longestDupSubstring(string S) {
        int n = S.length();
        int left = 1;
        int right = n;
        while(left<=right)
        {
            int len = left + (right-left) / 2;
            if(search(len, S, n) != -1)
                left = len + 1;
            else
                right = len - 1;
        }
        int start = search(left - 1, S, n);
        return S.substr(start, left - 1);
    }
    int search(int len, string s, int n)
    {
        long modulus = (long)pow(2, 34);
        long value = 0;
        unordered_set<long> sets;
        for(int i = 0; i < len; i++) {
            value = value * 26 + s[i] - 'a';
            value = value % modulus;
        }

        sets.insert(value);

        // prepass, cache the remainder
        long aL = 1;
        for (int i = 0; i < len; ++i) {
            aL = (aL * 26) % modulus;
        }
        
        for(int i = 1;i <= n-len; i++) {
            value = value * 26 - (s[i-1] - 'a') * aL + modulus + s[i+len-1] - 'a';
            value = value % modulus;
            if(sets.count(value)) {
                return i;
            }
            else {
                sets.insert(value);
            }
        }
        return -1;
    }
};
*/