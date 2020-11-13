//Fourth fastest
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let result = []
    recursion(queue = [], nums)
    function recursion(queue, array){
        
        if(array.length === 0) return result.push(queue)
        
        for(let i = 0; i < array.length; i++){
            let arr = [...array]
            let q = [...queue]
            q.push(arr[i])
            arr.splice(i,1)
            recursion(q, arr)
        }
    }
    return result
};

//Third fastest
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let permutations = []
    if (nums.length === 0 || nums.length === 1) {
        permutations.push(nums)
        return permutations
    }
    let permuter = (array, permutation = []) => {
        if (array.length === 0) {
            permutations.push(permutation)
            return
        } 
        for (var i = 0; i < array.length; i++) {
            let copy = array.slice()
            let newArray = copy.splice(i, 1)
            permuter(copy, permutation.concat(newArray))
        }
    }
    permuter(nums)
    return permutations
};

//Second fastest
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const res = [];
    const backtrack = (path) => {
      if(path.length === nums.length){
        res.push(path);
        return ;
      }
      nums.forEach(n => {
        if(path.includes(n)){return ;}
        backtrack(path.concat(n));
      });
    };
    backtrack([]);
    return res;
  };

//Fastest
var permuteHelper = function(nums, startIndex, result) {
    if (startIndex === nums.length - 1) {
        result.push([
            ...nums
        ]);
    } else {
        const start = nums[startIndex];
        for (let i = startIndex; i < nums.length; i++) {
            const current = nums[i];
            
            nums[i] = start;
            nums[startIndex] = current;

            permuteHelper(nums, startIndex + 1, result);

            nums[i] = current;
            nums[startIndex] = start;
        }
    }
};

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];

    permuteHelper(nums, 0, result);

    return result;
};