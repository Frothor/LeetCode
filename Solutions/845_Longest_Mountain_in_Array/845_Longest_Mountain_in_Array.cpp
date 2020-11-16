//Third fastest
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int foot = 0, peak = 0, ans = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i-1] < A[i]) {
                if (peak != i - 1) {
                    foot = i - 1;
                }
                peak = i;
            } else if (A[i-1] > A[i]) {
                if (peak > foot) {
                    ans = max(ans, i - foot + 1);
                }
            } else {
                peak = foot = i;
            }
        }
        return ans;
    }
};

//Second fastest
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int m = A.size(), i = 0, mx = 0;
        while (i + 1 < m) { // 注意这里的循环条件
            while (i + 1 < m && A[i] >= A[i + 1]) {
                ++i;
            }
            int peak = i;
            while (peak + 1 < m && A[peak + 1] > A[peak]) {
                ++peak;
            }
            int j = peak;
            while (j + 1 < m && A[j] > A[j + 1]) {
                ++j;
            }
            if (peak > i && j > peak) {
                mx = max(mx, j - i + 1);
            }
            i = j;
        }
        return mx;
    }
};

//Fastest
class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        int n = A.size();
        
        vector<int> inc(n, 1), dec(n, 1);
        
        for(int i = 1; i < n; i++){
            if(A[i] > A[i-1]) inc[i] = inc[i-1] + 1;
        }
        
        for(int i = n-2; i >= 0; i--){
            if(A[i] > A[i+1]) dec[i] = dec[i+1] + 1;
        }
        
//         for(int x : inc) cout<<x<<" ";
//         cout<<endl;
        
//         for(int x : dec) cout<<x<<" ";
//         cout<<endl;
        
        int res = 0;
        
        for(int i = 1; i < n-1; i++){
            if(inc[i] > 1 && dec[i] > 1)
            res = max(res, inc[i] + dec[i] -1);
        }
        return res < 3 ? 0 : res;
    }
};