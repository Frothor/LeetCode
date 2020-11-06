//Third fastest
const smallestDivisor = (nums, threshold) => {
  // Use 10e6 as the max
  let left = 1, right = 10e6;
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    let sum = 0;
    for (let i = 0; i < nums.length; ++i) {
      sum += Math.ceil(nums[i] / mid);
    }
    sum > threshold ? (left = mid + 1) : (right = mid);
  }
  return left;
};

//Another
var smallestDivisor = function(nums, threshold) {
    // let min = Number.MAX_VALUE;
    
    let low = 0,
        high = 10e6;
    
    while (low < high) {
        let mid = Math.floor((low + high) / 2);
        
        let sum = divide(nums, mid);
        if (sum <= threshold) {
            // min = Math.min(min, mid);
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
};

var divide = function(nums, divisor) {
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += Math.ceil(nums[i] / divisor);
    }
    return sum;
}

//Second fastest
var smallestDivisor = function(nums, threshold) {
    // divisor of 1 gives largest value ... sum of entire array
    // increase divisor value to reduce sum until threshold
    
    // https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/discuss/446376/JavaC%2B%2BPython-Binary-Search
    
    
    // sum > threshold - divisor to small ... Need to set start to mid + 1
    // sum <= threshold - divisor is big enough

    let start = 1, end = 1e6;
    
    while(start < end) {
        let mid = Math.floor((start+end)/2);
        let sum = getSum(mid);
        
        if(sum > threshold) start = mid + 1;
        else end = mid;
    
    }
    
    return start;

/*
    let start = 1;
    let end = 10e6;
    let result = 1;
    let resultSum = +Infinity;
    
    while(start <= end) {
        let mid = Math.floor((start+end)/2);
        let sum = getSum(mid);
        
        if(sum == threshold) return mid;
        
        
        if(sum > threshold) {
            start = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
        
    }
    
    return result;
*/
    
/*
    // Brute Force
    let max = Math.max(...nums, threshold)
    for(let i = 1; i < max ; i++) {
        let sum = 0;
        for(let num of nums) {
            sum += Math.ceil(num/i);
//            let result = Math.round(num/i);
//            sum += (result == 0 ? 1 : result);
        }

        if(sum <= threshold) return i;
    }
*/
    function getSum(i) {
        let sum = 0;
        for(let num of nums) {
            sum += Math.ceil(num/i);
        }
        
        return sum;
    }
    
    
};

//Fastest
/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
// binary search，这样只用算一半的sum
var smallestDivisor = function(nums, threshold) {
    let left = 0, right = 10e6;
    while (left < right) {
      const mid = Math.floor((left + right) / 2); // 从中间劈开 找mid做divisor 算算看
      let sum = 0;
      for (let i = 0; i < nums.length; ++i) {
        sum += Math.ceil(nums[i] / mid); // 计算下当前的答案 （sum of ceil(remainders))
      }
      sum > threshold ? // 看下当前sum跟threshold的比较
        (left = mid + 1) : // 如果比threshold大，还不满足条件，再往右找更大的divisor
        (right = mid); // 小于等于threshold了，可以往左找找有没有更小的满足条件的divisor
    }
    return left; // 直到不能再往左了，返回当前最小的 即 left
  };