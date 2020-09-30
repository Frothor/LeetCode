/*
The trick is to swap each number with the one at it's actual position.

Test Case:
Input = [5,3,4,2,1]

Explanation :

Try to swap values to reach [1,2,3,4,5],
This is possible in O(n) as the maximum swaps could be just n 🤷🏽‍♂️
Lastly just itreate and find the missing
*/
var firstMissingPositive = function (nums) {
  let i = 0;
  while (i < nums.length) {
    //calculating the actualPosition where the element should be
    let actualPosition = nums[i] - 1;

    if (
      nums[i] != i + 1 &&
      // don't swap if actualPosition is out of array
      !isNaN(nums[actualPosition]) &&
      //case for duplicate element at swapping position [1,1]
      nums[i] != nums[actualPosition]
    ) {
      //swap and move the number to actual position
      [nums[i], nums[actualPosition]] = [nums[actualPosition], nums[i]];
    } else i++;
  }
  i = 0;
  //find the missing one ;D
  while (nums[i] == i + 1) i++;
  return i + 1;
};

//Most common
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {
  // idea is to use the vval in the arr to mark which 'bucket' in a temp with size of N as empty

  let temp = Array(nums.length).fill(1);

  for (let num of nums) {
    // minus 1 because array starts at 0
    if (temp[num - 1]) {
      temp[num - 1] = -1;
    }
  }
  for (let index in temp) {
    if (temp[index] > 0) {
      return parseInt(index) + 1;
    }
  }

  return nums.length + 1;
};

//Second fastest
/**
 * @param {number[]} nums
 * @return {number}
 */

// O(n) time | O(1) space
var firstMissingPositive = function (nums) {
  if (!nums.includes(1)) return 1;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] <= 0 || nums[i] > nums.length) nums[i] = 1;
  }

  for (let i = 0; i < nums.length; i++) {
    const idx = Math.abs(nums[i]);
    nums[idx] = -Math.abs(nums[idx]);
  }

  console.log(nums);
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] > 0) return i;
  }

  return nums.length === 1 ? 2 : nums.length;
};

// O(n) time | O(n) space
// var firstMissingPositive = function(nums) {
//   let hash = {};
//   let solved = false;

//   for (let i = 0; i < nums.length; i++) {
//     if (!hash[nums[i]]) hash[nums[i]] = true;
//   }

//   let i = 1;
//   while (!solved) {
//     if (hash[i] === undefined) {
//       solved = true;
//       return i;
//     } else {
//       i++;
//     }
//   }
// };

// O(n ^ 2) time | O(1) space
// var firstMissingPositive = function(nums) {
//   let small = 1;
//   let i = 0;
//   while (i < nums.length ) {
//     if (nums.includes(small)) {
//       small++;
//       i++;
//     } else {
//       return small;
//     }
//   }
//   return small;
// };

//Fastest
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {
  let i = 0;
  let temp = null;
  while (i < nums.length) {
    if (nums[i] < i + 1 && nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
      temp = nums[i];
      nums[i] = nums[temp - 1];
      nums[temp - 1] = temp;
    } else i++;
  }
  let index = nums.findIndex((num, index) => num != index + 1) + 1;
  return index == 0 ? nums.length + 1 : index;
};
