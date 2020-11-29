//Third fastest
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    if (nums.length === 1) return false
    const target = nums.reduce((a, c) => a + c) / 2
    if (target % 1 !== 0) return false
    let dp = Array(target + 1).fill(false)
    dp[0] = true
    for (let i = 1; i <= nums.length; i++) {
        for (let j = target; j >= nums[i - 1]; j--) {
            dp[j] = dp[j] || dp[j - nums[i - 1]]
        }
    }
    return dp[target]
};

//Second fastest
/**
 * @param {number[]} nums
 * @return {boolean}
 */
const canPartition = function(nums) {
    const sumA = nums.reduce((acc, curr) => acc + curr, 0);

    if (sumA % 2) return false; 
    let row = 1n << BigInt(sumA / 2 );

    for (const weight of nums) row = row | (row >> BigInt(weight))
     /*
     check the the column corresponding to my target by bitwise ANDing
     it with just 1,so if the first bit is 1,
     it will return true, otherwise false
     */
    return row & 1n;
};

//Fastest
/**
 * @param {number[]} nums
 * @return {boolean}
 */
const canPartition = (nums) => {
    let sum = 0n;
    let bits = 1n;
    for (const num of nums) {
        let tmp = BigInt(num);
        sum += tmp;
        bits |= bits << tmp;
    }
    let one = sum % 2n == 0n;
    let two = bits >> (sum >> 1n);
    return one && (two % 2n == 1n);
};