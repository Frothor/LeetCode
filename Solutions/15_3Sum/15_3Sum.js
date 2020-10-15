var threeSum = function(nums) {
    nums.sort((a, b) => a - b);
    const result = [];
    
    for(let i = 0; i < nums.length; i++) {
        let low = i+1, high = nums.length-1, sum = 0;
        
        while(low < high) {
            sum = nums[i] + nums[low] + nums[high];
            
            if(sum === 0) {
                result.push([nums[i], nums[low], nums[high]]);
                while(nums[low+1] === nums[low]) low++;
                while(nums[high-1] === nums[high]) high--;
                low++;
                high--;
            } else if(sum < 0) low++;
            else high--;
        }
        while(nums[i+1] === nums[i]) i++;
    }
    return result;    
};

//Third fastest
var threeSum = function(nums) {
   
    let newNums = nums.slice().sort((a, b) => a-b)
    let result = []
    
    for(let i =0; i< newNums.length - 2 ;i ++){
        let j = i+1
        let k  = newNums.length -1
        
        if(i > 0 && newNums[i] === newNums[i-1]) continue
        
        while(j < k){
            let sum = newNums[i] + newNums[j] + newNums[k]
            
            if(sum < 0){
                j++
            }else if(sum > 0){
                k--
            }else{
                result.push([newNums[i], newNums[j], newNums[k]])
                while(newNums[j] === newNums[j+1]) j++
                while(newNums[k] === newNums[k-1]) k--
                j++
                k--
            }
        }
            
    }
    return result
};


//Second fasstest
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var result = [] 
    if (nums.length < 3) return result;
    nums.sort((a,b) => a-b);
    
    for (var i=0; i<nums.length; i++) {
        var end = nums.length-1;
        var start = i+1;
        if (i> 0 && nums[i] === nums[i-1]) continue;
        while (start < end) {
            if (end < nums.length -1 && nums[end] == nums[end+1]) {
                    end--;
                    continue;
            }
            if (nums[i] + nums[start] + nums[end] === 0) {
                result.push([nums[i], nums[start],nums[end]]); 
                start++;
                end--;
            }
            else if (nums[i] + nums[start] + nums[end] < 0) {
                start++;
            } else {
                end --;
            }
        }
    }
    return result;
};

//Fastest
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let output = [];

    nums.sort(function(a, b) { return a - b; });
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] > 0) {
            return output;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (let j = i + 1, k = nums.length - 1; j < k;) {
            if (nums[i] + nums[j] + nums[k] === 0) {
                output.push([nums[i], nums[j], nums[k]]);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            } else if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            } else {
                j++;
            }
        }
    }

    return output;
};