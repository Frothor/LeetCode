//Third fastest
var removeDuplicates = function(nums) {
    let j = 0;
    for (let num of nums) {
        if (j < 2 || num > nums[j - 2]) {
            nums[j] = num;
            j++;
        }
    }
    
    return j;
};

//Second fastest
var removeDuplicates = function (nums) {
  /* for(var i = 0; i < nums.length; ++i) {
    if(nums[i] == nums[i + 2])
      nums.splice(i--, 1)
  }
  return nums.length */


  /**
   * @param {number[]} nums
   * @return {number}

   */

  let n = nums.length
  if (n < 3) return n
  let j = 1
  for (let i = 2; i < n; i++) {
    if (nums[i] != nums[j - 1]) 
      nums[++j] = nums[i]
  }
  return j + 1

};

//Fastest
var removeDuplicates = function(nums) {
    if(!nums.length) return nums.length;
    
    let i = 0;
    let twiceEqual = false;
    for(let j = 1; j < nums.length; j++) {
        if(nums[i] === nums[j] && !twiceEqual) {
            twiceEqual = true;
            i++;
            nums[i] = nums[j];                      
        } else if(nums[i] !== nums[j]) {
            i++;
            nums[i] = nums[j];
            twiceEqual = false;
        }
    }
    return i + 1;
};