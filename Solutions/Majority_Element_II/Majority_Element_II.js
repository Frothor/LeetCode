/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function (nums) {
  if (!nums.length) return [];

  const dupes = new Set();
  const hash = {};
  const value = Math.floor(nums.length / 3);

  for (var i = 0; i < nums.length; i++) {
    if (hash[nums[i]]) {
      hash[nums[i]]++;
    } else {
      hash[nums[i]] = 1;
    }

    if (hash[nums[i]] > value) dupes.add(nums[i]);
  }

  return (dupes.size) ? [...dupes] : [];
};

//Most common
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function (nums) {
  let el1 = Number.MAX_VALUE;
  let el2 = Number.MAX_VALUE;
  let ct1 = 0;
  let ct2 = 0;

  for (let i = 0; i < nums.length; i++) {
    if (el1 == nums[i]) {
      ct1++;
      continue;
    }
    if (el2 == nums[i]) {
      ct2++;
      continue;
    }
    if (ct1 == 0) {
      el1 = nums[i];
      ct1++;
      continue;
    }
    if (ct2 == 0) {
      el2 = nums[i];
      ct2++;
      continue;
    }
    ct1--;
    ct2--;
  }

  //     console.log("el1",el1);
  //     console.log("ct1",ct1);
  //     console.log("el2",el2);
  //     console.log("ct2",ct2);

  let arr = [];
  ct1 = 0;
  ct2 = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] == el1) ct1++;
    if (nums[i] == el2) ct2++;
  }
  if (ct1 > Math.floor(nums.length / 3)) {
    arr.push(el1);
  }
  if (ct2 > Math.floor(nums.length / 3)) {
    arr.push(el2);
  }
  // console.log(arr);
  return arr;
};

//Fastest
var majorityElement = function (nums) {
  let num1 = 0, num2 = 0, count1 = 0, count2 = 0, result = [];

  for (let each of nums) {
    if (num1 === each) {
      count1 += 1;
    } else if (num2 === each) {
      count2 += 1;
    } else if (count1 === 0) {
      count1 = 1;
      num1 = each;
    } else if (count2 === 0) {
      count2 = 1;
      num2 = each;
    } else {
      count1--;
      count2--;
    }
  }

  count1 = 0;
  count2 = 0;

  for (let each of nums) {
    if (each === num1) {
      count1++;
    } else if (each === num2) {
      count2++;
    }
  }

  if (count1 > nums.length / 3) {
    result.push(num1);
  }
  if (count2 > nums.length / 3) {
    result.push(num2);
  }

  return result;
};
