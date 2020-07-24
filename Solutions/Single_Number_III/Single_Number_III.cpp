class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;
        for(int n: nums) xy ^= n;
        
        xy &= -xy;
        vector<int> result = {0, 0};
        for(int n: nums)
            if(xy & n) result[0] ^= n;
            else result[1] ^= n;
        return result;
    }
};

/*
Fastest:
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;
        int s = __builtin_ctz(x);
        int c = 1 << s;
        vector<int> out(2);
        for (int n : nums) out[(c & n) >> s] ^= n;
        return out;
    }
};

static const auto fast = []() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;
} ();

Another fast:
static const auto fast = []() {
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
} ();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        uint32_t xorValue = 0;
        
        for (const auto& n : nums) {
            xorValue ^= n;
        }
        
        uint32_t lastBit = xorValue & ~(xorValue - 1);
        
        int resultValues[2] = {0, 0};
        
        for (const auto& n : nums) {
            
            if (n & lastBit) {
                resultValues[0] ^= n;
            }
            else {
                resultValues[1] ^= n;
            }
        }
        
        return {resultValues[0], resultValues[1]};
    }
};
*/