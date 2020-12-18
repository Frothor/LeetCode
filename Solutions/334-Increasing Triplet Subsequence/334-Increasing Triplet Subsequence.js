//https://leetcode.com/problems/increasing-triplet-subsequence/discuss/79098/Simple-JavaScript-solution
function increasingTriplet(nums) {

  var m; // mininum
  var m2; // sec mininum

  for (var i = 0; i < nums.length; i++) {
    var n = nums[i];
    if (m === undefined || n <= m) {
      m = n;
    } else /* n > m */ {
      if (m2 === undefined || n <= m2) {
        m2 = n;
      } else {
        return true;
      }
    }
  }
  return false;
}

//Third fastest
var increasingTriplet = function(nums) {
    let n1 = Infinity, n2 = Infinity;
    
    for (let n3 of nums) {
        if (n3 > n2 && n2 > n1) {
            return true
        } else if (n1 >= n3) {
           n1 = n3;        
        } else if (n2 >= n3) {
            n2 = n3;
        }
    }
    
    return false; 
};

//Second fastest
const increasingTriplet = nums => {
    if (nums.length < 3) return false;
    let firstNum = Infinity;
    let secNum = Infinity;
  
    for (let currNum of nums) {
      if (currNum > secNum && currNum > firstNum) return true;
  
      if (currNum > firstNum) secNum = currNum;
      else firstNum = currNum;
    }
    return false;
  }

//Fastest
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
    //     let min1;
    //     let min2;
    //     for(let num of nums){
    //         if(!min1 || num <= min1 ){
    //             min1 = num;
    //         }else if(!min2 || num <= min2){
    //             min2 = num;
    //         }else return true;
    //     }
        
    //     return false;
        
        for (var m, m2, i = 0; i < nums.length; i++) {
        if (m === undefined || nums[i] <= m) m = nums[i];
        else if (m2 === undefined || nums[i] <= m2) m2 = nums[i];
        else return true;
      }
      return false;
    };
    