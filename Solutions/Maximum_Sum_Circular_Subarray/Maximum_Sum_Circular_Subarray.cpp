class Solution {
    int kadane(vector<int>& v){
        int n = v.size();
        int max_curr = v[0], max_global = v[0];
        for(int i=1; i<n; i++){
            max_curr = max(v[i], max_curr + v[i]);
            if(max_curr > max_global)
                max_global = max_curr;
        }
        return max_global;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 1){
            return A[0];
        }
        int max_kadane = kadane(A);
        int max_wrap = 0;
        for(int i=0; i<n; i++){
            max_wrap += A[i];
            A[i] = -A[i];
        }
        
        max_wrap = max_wrap + kadane(A);
        
        return max_wrap > max_kadane && max_wrap != 0 ? max_wrap : max_kadane;
    }
}; 

/*
Most common:
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        int max_so_far = v[0];
        int max_end_here = v[0];
        int totalsum = v[0];
        int min_so_far = v[0];
        int min_end_here = v[0];
        for(int i=1;i<v.size();i++){
            totalsum +=v[i];
            max_end_here = max(max_end_here + v[i],v[i]);
            max_so_far = max(max_end_here,max_so_far);
            min_end_here = min(min_end_here + v[i],v[i]);
            min_so_far = min(min_so_far,min_end_here);
        }
        if(max_so_far < 0){//means all element are negative
            return max_so_far;
        }
        return max(max_so_far,(totalsum - min_so_far));
    }
};

static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();


Fastest:
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = A[0];
        int mx = A[0];
        int acc = A[0];
        for (int i = 1; i < A.size(); ++i) {
            sum += A[i];
            acc = max(0, acc)+A[i];
            mx = max(mx, acc);
        }
        int mn = A[0];
        acc = A[0];
        for (int i = 1; i < A.size(); ++i) {
            acc = min(0, acc)+A[i];
            mn = min(mn, acc);
        }
        if (sum == mn) {
            return mx;    
        }
        return max(sum-mn, mx);
    }
};

Another:
static const auto io_sync_off = [](){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     return nullptr;
}();
class Solution {
public:
    int solve(vector<int> &v){
        int csum = v[0];
        int ans= v[0];
        for(int i=1;i<v.size();i++){
            csum = max(csum+v[i],v[i]);
            ans=max(ans,csum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& A) {
         int a1 = solve(A);
        //  cout<<a1;
        int sum = 0;
        int cnt = 0;
         for(int i=0;i<A.size();i++){
             sum+=A[i];
             if(A[i]<0)cnt++;
             A[i]=(-1)*A[i];
         }
        if(cnt==A.size()) return a1;
        int a2 = solve(A);
        return max(a1,a2+sum);
    }
};
*/