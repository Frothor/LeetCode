var combinationSum = function (candidates, target) {
  const n = candidates.length;
  const res = [];

  backtrack([], 0, 0);

  return res;

  function backtrack(arr, start, sum) {
    if (sum >= target) {
      if (sum === target) res.push([...arr]);
      return;
    }

    for (let i = start; i < n; i++) {
      const num = candidates[i];
      arr.push(num);
      backtrack(arr, i, sum + num);
      arr.pop();
    }

    return;
  }
};

//Most common
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = function (candidates, target) {
  const result = [];

  function recurse(candidates, target, temp, start) {
    if (target === 0) {
      result.push(temp);
      return;
    }
    if (start === candidates.length) {
      return;
    }
    if (candidates[start] <= target) {
      recurse(
        candidates,
        target - candidates[start],
        temp.concat(candidates[start]),
        start,
      );
    }
    recurse(candidates, target, temp, start + 1);
  }

  recurse(candidates, target, [], 0);
  return result;
};

//Second Fastest
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  let list = [];
  helper(list, [], candidates, target, 0);
  return list;
};

let helper = function (list, tempList, candidates, target, start) {
  if (target < 0) return;
  else if (target == 0) list.push(tempList.slice());
  else {
    for (let i = start; i < candidates.length; i++) {
      tempList.push(candidates[i]);
      helper(list, tempList, candidates, target - candidates[i], i);
      tempList.pop();
    }
  }
};

//Fastest
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  candidates = candidates.sort((a, b) => a - b);
  let res = [];
  recurse(candidates, 0, target, res, []);
  return res;
};

function recurse(candidates, start, t, res, arr) {
  for (let i = start; i < candidates.length; i++) {
    let c = candidates[i];
    if (t - c === 0) {
      res.push([...arr, c]);
      return;
    }
    if (t - c < 0) break;
    recurse(candidates, i, t - c, res, [...arr, c]);
  }
}
