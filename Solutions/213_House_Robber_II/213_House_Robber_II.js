/**
 * @param {number[]} nums
 * @return {number}
 */
const rob = (nums) => {
    if (nums.length === 0)
        return 0;
    if (nums.length === 1)
        return nums[0];

    return Math.max(
        findHouses(nums.slice(1)),
        findHouses(nums.slice(0, -1))
    );
};

const findHouses = (nums) => {
    const dp = new Array(nums.length + 1).fill(0);
    
    for (let i = nums.length - 1; i >= 0; i--) {
        if (i + 2 >= nums.length)
            dp[i] = Math.max(nums[i], dp[i + 1]);
        else
            dp[i] = Math.max(dp[i + 1], nums[i] + dp[i + 2]);
    }
    
    return dp[0];
    
    /**
    * Time Complexity: O(n)
    * Space Complexity: O(n)
    **/
};

//Third fastest
var rob = function(nums) {
    if (nums.length < 2) {
        return nums[0] || 0;
    }
    
    const memo1 = [nums[0]];
    const memo2 = [0, nums[1]];
    
    for (let i=1; i<nums.length - 1; i++) {
        memo1[i] = Math.max(nums[i] + (memo1[i - 2] || 0), memo1[i - 1]);
    }
    
    for (let i=2; i<nums.length; i++) {
        memo2[i] = Math.max(nums[i] + memo2[i - 2], memo2[i - 1]);
    }
    
    return Math.max(memo1.pop(), memo2.pop());
};

//Second fastest
var rob = function(nums) {
    // return rc(nums, 0)
    return dp(nums)
};

function dp (nums) {
    if (nums.length === 0) return 0;
    const dp = [nums[0], Math.max(nums[0], nums[1] || 0)];
    const dp2 = [0, nums[1] || 0];   
    
    for (let i = 2; i < nums.length; i++) {
        dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);
        dp2[i] = Math.max(nums[i] + dp2[i - 2], dp2[i - 1]);
    }
    return Math.max(dp[dp.length - 2], dp2[dp.length - 1]);
}

function rc (nums, current, canTouchLast, cache = {}) {
    if (current >= nums.length) return 0;
    if (current === nums.length - 1) return canTouchLast === false ? 0 : nums[current];
    const key = `${current},${canTouchLast}`
    if(cache[key]) return cache[key]
    
    cache[key] = Math.max(
        nums[current] + rc(nums, current + 2, canTouchLast === undefined ? false : canTouchLast, cache),
        rc(nums, current + 1, canTouchLast === undefined ? true : canTouchLast, cache)
    );
    
    return cache[key]
}

//Fastest
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    
    function robb(nums, start, end) {
        var prevTwo = 0, prevOne = 0, max = 0;
        for(var i = start; i < end; i++) {
            /*console.log("prevTwo", prevTwo);
            console.log("prevOne", prevOne);
            console.log("max", max)
            console.log("______________")*/
            max = Math.max(prevTwo + nums[i], prevOne);
            prevTwo = prevOne;
            prevOne = max;
            // console.log(max, nums[i])
            // max = max + nums[i]
        }
        return max;
    }
    
    if(nums.length === 1) return nums[0];
    // console.log("Set 1 -> ", robb(nums, 0, nums.length - 1));
	// console.log("Set 2 -> ", robb(nums, 1, nums.length));
	return Math.max(robb(nums, 0, nums.length - 1), robb(nums, 1, nums.length));
};
