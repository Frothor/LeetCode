//https://leetcode.com/problems/squares-of-a-sorted-array/discuss/973317/C%2B%2B-two-pointers-moving-from-both-ends
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        int l = 0, r = n - 1, idx = n - 1;
        while(l<=r){
            if(nums[l]*nums[l] < nums[r] * nums[r]){
                ans[idx--] = nums[r] * nums[r];
                r--;
            }else{
                ans[idx--] = nums[l] * nums[l];
                l++;
            }
        }
        return ans;        
    }
};

//Fourth fastest
class Solution {
public:
    // vector<int> sortedSquares(vector<int>& A) {
    //   int begin = 0, end = A.size() - 1, rend=A.size() - 1;
    //   vector<int> results(A.size());
    //   while(begin != end) {
    //     int b2 = A[begin] * A[begin];
    //     int e2 = A[end] * A[end];
    //     if (b2 >= e2) {
    //       results[rend--] = b2;
    //       begin++;
    //     } else {
    //       results[rend--] = e2;
    //       end--;
    //     }
    //   }
    //   results[rend--] = A[begin] * A[begin];
    //   return results;
    // }
  
    //Old Solution:
    vector<int> sortedSquares(vector<int>& A) {
      int pos_start = 0;
      for (; pos_start < A.size(); ++pos_start) {
        if (A[pos_start] >= 0) {
          break;
        }
      }
      int neg = pos_start - 1;
      int pos = pos_start;
      vector<int> squares;
      while(neg >= 0 || pos < A.size()) {
        if (neg < 0) {
          squares.push_back(A[pos] * A[pos]);
          pos++;
          continue;
        }
        if (pos == A.size()) {
          squares.push_back(A[neg] * A[neg]);
          neg--;
          continue;
        }
        if (-1 * A[neg] < A[pos]) {
          squares.push_back(A[neg] * A[neg]);
          neg--;
        } else {
          squares.push_back(A[pos] * A[pos]);
          pos++;
        }
      }
      return squares;
    }
};

//Third fastest
class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n);
        int l = 0, r = a.size()-1;
        for(int i = n-1; i >= 0; i--) {
            if(a[l] * a[l] >= a[r] * a[r]) {
                ans[i] = a[l] * a[l];
                l++;
            } else {
                ans[i] = a[r] * a[r];
                r--;
            }
        }
        return ans;
    }
};

//Second fastest
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n);
        int l = 0;
        int r = n-1;
        int k = n-1;
        int ll = nums[l] * nums[l];
        int rr = nums[r] * nums[r];
        while(l <= r) {
            if (ll > rr) {
                res[k] = ll;
                if (++l <= r) {
                    ll = nums[l] * nums[l];
                }
            } else {
                res[k] = rr;
                if (--r >= l) {
                    rr = nums[r] * nums[r];
                }
            }
            k--;
        }
        
        return res;
    }
    
    vector<int> sortedSquares_binary_search(vector<int>& nums) {
        int n = nums.size();
        const auto itr = lower_bound(nums.begin(), nums.end(), 0);
        int m = distance(nums.begin(), itr);
        
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        
        vector<int> res(n);
        int i = m-1;
        int j = m;
        int k = 0;
        while(i >= 0 && j < n) {
            if (nums[i] < nums[j]) {
                res[k] = nums[i];
                i--;
            } else {
                res[k] = nums[j];
                j++;
            }
            k++;
        }
        
        while(i >= 0) {
            res[k++] = nums[i--];
        }
        
        while(j < n) {
            res[k++] = nums[j++];
        }
        
        return res;
    }
};

//Fastest
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0, r = A.size()-1;
        vector<int> result;
        while(l <= r){
            if(abs(A[l]) < abs(A[r])){
                result.push_back(A[r] * A[r]);
                r--;
            }else{
                result.push_back(A[l] * A[l]);
                l++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};