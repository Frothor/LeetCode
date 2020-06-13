class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> prev(n, -1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0){
                    dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i]==dp[j]+1)
                        prev[i] = j;
                }
            }
        }
        
        int len = 0;
        int idx;
        for(int i=0; i<n; i++){
            if(dp[i]>len){
                len = max(len, dp[i]);
                len = dp[i];
                idx = i;
            }
        }
        
        vector<int> ret;
        while(idx!=-1){
            ret.push_back(nums[idx]);
            idx = prev[idx];
        }
        
        return ret;
    }
};


/*
Fastest:

class Solution {
public:
    int bSz=0, sPos=0, nSz, largest;
    vector<int> nums, sol, furthest, best=vector<int>(0);
    
    int passes(int v, int i) {
        if ( sPos==0 ) return 1;
        if ( (sPos>furthest[i]) && ((v%sol[sPos-1])==0) ) {
            furthest[i]=sPos;
            return 1;       // mark the position
        }
        return 0;
    }
    void rec(int i) {
        for ( ; i<nSz; ++i ) {
            if ( bSz>sPos && ((((long)1)<<(bSz-sPos))*nums[i])>largest ) break;
            if ( passes(nums[i],i) ) {
                sol[sPos++]=nums[i];
                rec(i+1);   // w/ num[i] in solution
                --sPos;
            }               // else, w/o num[i] in solution
        }
        if ( bSz < sPos ) {
            bSz = sPos;     // store best
            best = vector<int>(sol.begin(), sol.begin()+sPos);
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& numsOrig) {
        if ( (nSz=numsOrig.size())<=1 ) return numsOrig; 
        nums = numsOrig;
        sol = vector<int>(nSz);
        furthest = vector<int>(nSz,0);
        //
        sort (nums.begin(), nums.end());
        largest = nums.back();
        //
        rec(0);
        return best;
    }
};

Most common:

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()){
            return {};
        }
        int size = nums.size();
        vector<int> dp(size,0);
        vector<int> last(size,-1);
        vector<int> result;
        int max = -1 , start =0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < size;++i){
            for(int j = i -1 ; j >=0; j--){
                if(( nums[i]% nums[j])==0){
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1+dp[j];
                        last[i] = j;
                    }
                }
            }
        }
        for(int i = 0; i <size; ++i){
            if(max < dp[i]){
                max=dp[i];
                start=i;
            }
        }
        while(last[start]!=-1){
            result.push_back(nums[start]);
            start = last[start];
        }
        result.push_back(nums[start]);
        return result;
    }
};
*/