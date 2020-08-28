class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // support variables
        int len = intervals.size();
        vector<int> res(len);
        pair<int, int> pos[len];
        auto endOfPos = pos + len;
        // populating and sorting the map of positions
        for (int i = 0; i < len; i++) pos[i] = {intervals[i][0], i};
        sort(pos, endOfPos);
        // finding the matching right interval
        for (int i = 0; i < len; i++) {
            auto p = lower_bound(pos, endOfPos, intervals[i][1], [](auto it, int val){return it.first < val;});
            res[i] = p == endOfPos ? -1 : p->second;
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    static bool comp(const vector<int>& a,const vector<int>& b) {
        return a[0] <= b[0];
    }
    
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> res(n);
        if (n == 0) return res;
        
        for(int i = 0;i<n;i++) {
            res[i] = nums[i][1];
            nums[i][1] = i;
        }
        sort(nums.begin(), nums.end(), comp);
        
        for(int i = 0;i<n;i++) {
            int end = res[i];
            
            int l = 0, r = n-1, mid, resI = -1;
            while(l <= r) {
                mid = l + (r-l)/2;
                if (nums[mid][0] >= end) {
                    resI = nums[mid][1];
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            res[i] = resI;
        }
        return res;
    }
    
};

//Another solution
class Solution {
public:
    int bs(vector<vector<int>>& in, int v) {
        int l=0,n=in.size(),h=n-1;
        
        while(l<=h) {
            int m = l + (h-l)/2;
            
            if(in[m][0] < v) {
                l=m+1;
            }
            else {
                h=m-1;
            }
        }
        
        return l<n ? l : -1;
    }
    
    
    vector<int> findRightInterval(vector<vector<int>>& in) {
        
        int n = in.size();
        vector<int> ans (n, -1); 
        
	// Store the index of each interval along side
	// the start and end points.
	// Will help post-sorting.
        for(int i=0; i<n; ++i) {
            in[i].push_back(i);
        }
        
	// Sort in non-decreasing order with respect to the start points.
	// If start points are equal use, end points.
        sort(in.begin(), in.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        
        for(int i=0; i<n; ++i) {
            int ix = in[i][2];
            int px = bs(in, in[i][1]);
            if(px != -1)
                ans[ix] = in[px][2];
        }
        
        return ans;
    }
};