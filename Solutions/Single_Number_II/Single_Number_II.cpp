class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int bits[32] = {0};
        
        for(int i=0; i<32; i++){
            for(int n: nums){
                bits[i] += n >> i & 1;
                bits[i] %= 3;
            }
        }
        
        for(int i=0; i<32; i++){
            result |= (bits[i] << i);
        }
        return result;
    }
};

/*
Fastest:
static int x = [](){ios::sync_with_stdio(false),cin.tie(NULL); return 0;}();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      
        int ones = 0;
        int twos = 0;
        
        for(auto i:nums)
        {
            ones = (ones^i) & (~twos);
            twos = (twos^i) & (~ones);
        }
        return ones;
    }
};

Another:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for(auto &n:nums){
            two |= one & n;
            one = one ^ n;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
*/