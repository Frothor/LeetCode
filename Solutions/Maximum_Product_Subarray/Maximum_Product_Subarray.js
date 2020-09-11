/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    var n = nums.length;
    if (!n) return 0;
    var curMax = nums[0];
    var curMin = nums[0];
    var max = nums[0];
    for (var i = 1; i < n; i++) {
        var num = nums[i];
        var minProd = curMin * num;
        var maxProd = curMax * num;
        curMax = Math.max(num, minProd, maxProd);
        curMin = Math.min(num, minProd, maxProd);
        max = Math.max(max, curMax);
    }
    return max;
};

//Fastest
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    var max = nums[0];
    var min = nums[0];
    var result = max;
    for (var i = 1; i < nums.length; i += 1) {
        var current = nums[i];
        var preMax = max
        var max = Math.max(current, Math.max(preMax * current, min * current));
        var min = Math.min(current, Math.min(preMax * current, min * current));
        result = Math.max(max, result);
    }
    return result;
};