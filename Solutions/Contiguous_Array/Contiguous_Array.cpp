class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int maxLen = 0;
        unordered_map<int, int> m;
        
        m.insert({0, -1});
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? count -= 1 : count += 1;
            
            if(m.find(count) != m.end()) {
                maxLen = max(maxLen, i - m.find(count)->second);
            } else {
                m.insert({count, i});
            }
            
        }
        
        return maxLen;
    }
};

/*
Most common:

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int sum_left[n];
        int min_val, max_val, max_len = 0;
        if(nums[0]==0)
            sum_left[0]=-1;
        else
            sum_left[0]=1;
        min_val = sum_left[0];
        max_val = sum_left[0];
        for(int i=1;i<n;i++){
            sum_left[i] = sum_left[i-1] + ((nums[i]==0)? -1 : 1);
            if(min_val>sum_left[i])
                min_val = sum_left[i];
            if(max_val<sum_left[i])
                max_val = sum_left[i];
        }
        int hash[max_val-min_val+1];
        memset(hash, -1, sizeof(hash));
        for(int i=0;i<n;i++){
            if(sum_left[i]==0){
                max_len = i+1;
            }
            
            if(hash[sum_left[i]-min_val] == -1)
                hash[sum_left[i]-min_val] = i;
            
            else if(max_len < (i - hash[sum_left[i]-min_val])){
                max_len = i - hash[sum_left[i]-min_val];
            }
        }
        return max_len;
    }
};

Fastest:
class Solution {
public:
    Solution() {ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
    
    int findMaxLength(const vector<int>& nums) {
        const int len = nums.size();
        if(!len) return 0;
        char arr[len];
        int ret = 0, mn=(nums[len-1]<<1)-1, mx=mn;
        for(int i = len-1, s = 0;i>=0;--i) {
            char curVal = (nums[i]<<1)-1; // 1 is mapped to 1, 0 is mapped to -1
            s += curVal;
            arr[i] = curVal;
            if(s > mx) mx = s;
            else if(s < mn) mn = s;
        }
        
        unsigned short * const hash = new unsigned short[mx-mn+1]();
        // unsigned char hash[mx-mn+1];
        // memset(hash, 0, len_1+1);
        // cout << mx << ' ' << mn;
        // for(int i = len_1, s = 0;i>=0;--i) {
        //     s += nums[i];
        //     const int tmp = s-k;
        //     ret += !tmp;
        //     if(tmp >= mn && tmp <= mx)
        //         ret += hash[tmp - mn];
        //     ++hash[s-mn];
        // }
        
        for(int i = len-1, s = 0;i>=0;--i) {
            s += arr[i];
            // ret += !s;
            // ret += hash[s];
            // ++hash[s-mn];
            if(!s) ret = len - i;
            unsigned short largest_S_ind = hash[s-mn];
            ret = max(ret, largest_S_ind-i);
            // cout << ret;
            if(!largest_S_ind)
                hash[s-mn] = i;
        }
        return ret;
    }
};
*/