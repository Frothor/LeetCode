/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const rotate = function(nums, k) {
    nums.unshift(...nums.splice(-(k % nums.length), k % nums.length));
};

//Third fastest
var rotate = function(nums, k) {
    const stack = [];
     k %= nums.length
     while(k--){
         stack.push(nums.pop())
     }
     nums.unshift(...stack.reverse())
 };


//Second fastest
var rotate = function(nums, k) {
    // 1. compute true num of rotations by modding.
    // 2. swap first values with k - i - i value to achieve constant space
    
    const trueRotationNum = k % nums.length;    
    
    
    nums.slice(nums.length-trueRotationNum).concat(nums.slice(0,nums.length - trueRotationNum)).forEach((val,i)=> {
       nums[i] = val;                                                                     
    });
};

//Fastest
var rotate = function(nums, k) {
    k %= nums.length;
      let cutOff = nums.length - k - 1
    let result = []
    for(let i=cutOff + 1; i<nums.length;i++){
        result.push(nums[i])
    }
    for(let i=0; i<=cutOff;i++){
        result.push(nums[i])
    }
      for(let i=0; i<result.length;i++){
          nums[i] = result[i]
      }
    
  };