var rob = function(nums) {
    return nums.reduce((acc, cur) => [acc[1], Math.max(acc[1], acc[0] + cur)], [0, 0])[1];
};

//Most common
/**
 * @param {number[]} nums
 * @return {number}
 */
function rob(nums) {
    let prev = 0;
    let curr = 0;
    let temp;
    for (num of nums) {
        temp = curr;
        curr = Math.max(prev + num, curr);
        prev = temp;
    }
    return curr;
}


//Fastest
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let len = nums.length;
    if(!len){
        return 0
    }
    if(len == 1){
        return nums[0];
    } 
    
    if(len == 2){
        return Math.max(nums[0], nums[1])
    }
    if(len == 3){
        return Math.max(nums[1], nums[0] + nums[2])
    }
    let dp = [];
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);
    dp[2] = Math.max(nums[1], nums[0] + nums[2]);
    let max = Math.max(dp[0], dp[1], dp[2]);
    for(let i=3;i<nums.length;i++){
        dp[i] = Math.max(dp[i-2] + nums[i], dp[i-3] + nums[i])
        max = Math.max(dp[i], max)
    }
    return max
};