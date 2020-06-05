class Solution {
    vector<int> w_cum;
    int sum;
public:
    Solution(vector<int>& w) {
        sum = 0;
        for(int e: w){
            sum += e;
            w_cum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int idx = rand() % sum;
        return binSearch(idx + 1);        
    }
    
    int binSearch(int val){
        int l = 0;
        int r = w_cum.size()-1;
        
        while(l < r){
            int mid = l + (r - l)/2;
            if(w_cum[mid] < val)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/*
Fastest:
class Solution {
    vector<int> mW;
    
public:
    Solution(vector<int>& w) {
        std::ios_base::sync_with_stdio(false); 
        cin.tie(nullptr); cout.tie(nullptr);
        
        mW.reserve(w.size());
        int sum = 0;
        for (auto v : w) {
            sum += v;
            mW.push_back(sum);
        }
    }
    
    int pickIndex() {
        int val = rand() % mW.back();
        
        auto it = upper_bound(mW.begin(), mW.end(), val);
        return it - mW.begin();
    }
};

static int _ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> nums;
    int sum = 0;
    Solution(vector<int>& w) {
        for(int x : w) {
            sum += x;
            nums.push_back(sum);
        }
    }
    
    int pickIndex() {
        auto upper = upper_bound(nums.begin(),nums.end(),rand()%sum);
        return upper-nums.begin();
    }
};
*/