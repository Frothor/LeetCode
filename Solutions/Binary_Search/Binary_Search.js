//Most common
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */


const search = (nums, target) => {
    return bs(nums, target, 0, nums.length - 1);
};

const bs = (nums, target, startIdx, lastIdx) => {
    const midIdx = Math.floor((lastIdx - startIdx) / 2) + startIdx; 
    if(nums[midIdx] === target) {
            return midIdx;
        }
    while(startIdx < lastIdx) {
        if(target > nums[midIdx]) {
            return bs(nums, target, midIdx + 1, lastIdx);   
        } else {
            return bs(nums, target, startIdx, midIdx - 1);
        }  
    }
    return -1;
}





// const search = (nums, target) => {
//     return bs(nums, target, 0, nums.length - 1);
// };

// const bs = (nums, target, startIdx, lastIdx) => {
//     const midIdx = Math.floor((lastIdx - startIdx) / 2) + startIdx; 

//     if(nums[midIdx] === target) {
//         return midIdx;
//     }
    
//     if(startIdx >= lastIdx) {
//        return -1;
//     }
    
//     if(target > nums[midIdx]) {
//         return bs(nums, target, midIdx + 1, lastIdx);   
//     } else {
//         return bs(nums, target, startIdx, midIdx - 1);
//     }   
// }

// start: 3 | last: 5 | midIdx: 1

// [-1,0,3,5, 9 ,12] | 2

// [9,12] | 2

// [9] | 9



//Second fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    return findElement(nums, target);
};

function findElement(nums, target, start = 0, len = nums.length - 1) {
    const middle = Math.floor((start + len) / 2);
    const number = nums[middle];
    
    if (number === target) {
        return middle;
    } else if (start >= len) {
        return -1;
    }
    
    return target > number ?
        findElement(nums, target, middle + 1, len) :
        findElement(nums, target, start, middle - 1);
}

//Fastest
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

function search(nums, target) {
    return binarySearch(nums, target);
}

function binarySearch(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left <= right) {
        let middle = parseInt(left + (right - left) / 2);
        if (nums[middle] === target) return middle;
        else if (target < nums[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    return -1;
}