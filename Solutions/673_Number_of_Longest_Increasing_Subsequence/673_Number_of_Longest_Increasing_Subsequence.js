//Third fastest
var findNumberOfLIS = function(nums) {
    if(nums.length ===0) return 0;
    const n = nums.length;
    const dp = Array(n).fill(1);
    const count = Array(n).fill(1);
    //dp[i] is the number of the longest LIS for S[:i]
    for(let i = 0;i<n;i++) {
        let maxLen=1;
            let maxNum=1;
        for(let j = 0;j<i;j++) {
            
            if(nums[j]<nums[i]) {
                
           
                if(dp[j]+1>dp[i]) {
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                } else if(dp[j]+1===dp[i]) {
                    count[i] += count[j];
                }
            }
        }
    }
    
    let len = 0,res = 0;
   for(let i = 0;i<n;i++) {
       if(dp[i]>len) {
           len = dp[i];
           res = count[i];
       } else if(dp[i] ===len) { //[2,2,2,2,2]
        
           res +=count[i]
       }
   }
    return res;
    
};

//Second fastest
var findNumberOfLIS = function(nums) {
    if(!nums || nums.length === 0){
        return 0;
    } //edge case, don't start
    if(nums.length === 1){
        return 1;
    } //edge case, only one item
    
    //begin real algo
    
    const N = nums.length; //shorthand
    const len = new Array(N);
    const cnt = new Array(N); //two arrays with length equal to the length of original array
    let maxLen = 0, ans = 0; //more instantiation
    
    for(let i = 0; i < N; i++){ //loop array length
        len[i] = 1;
        cnt[i] = 1; //point to the index, make one
        for(let j = 0; j < i; j++){ //second loop, loop only numbers BEFORE i
            if(nums[j] < nums[i]){ //the big thing is to count numbers less than the endpoint
                if(len[j] + 1 > len[i]){ // if the length stored in one of the previous numbers is equal or greater than where we currently are...
                    len[i] = len[j] + 1; //we can simply update the value stored in the outer tracker, and implement it, because we've added one more number in the series
                    cnt[i] = cnt[j];
                }else if(len[j] + 1 === len[i]){
                    cnt[i] += cnt[j];
                }
            }
        }
        //once we have finished evaluating, we examine how len[i] matches up to out current maxLen
        if(len[i] === maxLen){
            ans += cnt[i];
        }else if(len[i] > maxLen){ //if we beat this number
            maxLen = len[i]; //we update
            ans = cnt[i];
        }  
    }
    return ans; //end
};

//Fastest
var findNumberOfLIS = function(nums) {
    if(nums == null)
        return 0;
    
    if(nums.length <= 1)
        return nums.length;
    
    let dp = [], cnt = [], max = 0, maxCnt = 0;
    
    for(let i = 0;i < nums.length;i++){
        dp[i] = 1;
        cnt[i] = 1;
        
        for(let j = 0;j < i;j++){
            if(nums[j] < nums[i]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(dp[i] === dp[j]+1){
                    cnt[i] += cnt[j];
                }
            }                
        }
        if(max < dp[i]){
            maxCnt = cnt[i];
            max = dp[i];
        }
        else if(max === dp[i])
            maxCnt += cnt[i];
    }
    
    return maxCnt;
};