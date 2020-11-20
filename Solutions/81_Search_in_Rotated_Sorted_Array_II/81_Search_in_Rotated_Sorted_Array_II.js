//Fourth fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    for (let i=0; i < nums.length; i++) {
    if(nums[i] === target) {
        return true;
    }
} 
return false;
};

//Third fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target)
{
    var L=nums.length;
        var left=0;
        var right=L-1;
    
    if(L>0)
   {
        var nums_l=nums[left];
        var nums_r=nums[right];
       if(target>=nums_l)
       {
          for(var i=0;i<L;i++) 
            {
                if(target==nums[i])
                {
                    return true;
                }
            }
       }
       else
       {
            for(var i=right;i>=0;i--) 
            {
                if(target==nums[i])
                {
                    return true;
                }
            }
       }
   }
    

    return false;
};

//Second fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    return nums.indexOf(target) !== -1  
  };

//Fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    if(nums.indexOf(target)>-1){return true}
    return false
};