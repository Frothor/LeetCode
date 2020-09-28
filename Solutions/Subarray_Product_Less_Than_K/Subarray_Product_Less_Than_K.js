/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    let anchor = 0;
    let p = 1;
    let count = 0;
    
    for (let i = 0; i < nums.length; i++) {
        p *= nums[i];
        
        while (anchor <= i && p >= k) {
            p /= nums[anchor];
            anchor++;
        }
        
        count += (i - anchor + 1);
    }
    
    return count;
};