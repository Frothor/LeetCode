var removeCoveredIntervals = function (intervals) {
  intervals.sort((a, b) => {
    if (a[0] == b[0]) return b[1] - a[1];
    else return a[0] - b[0];
  });
  let remove = 0;
  for (let i = 0; i < intervals.length - 1; i++) {
    if (intervals[i][1] >= intervals[i + 1][1]) {
      remove++;
      intervals[i + 1] = intervals[i];
    }
  }
  return intervals.length - remove;
  // Time Complexity: O(nlog(n))
  // Space Complexity: O(1)
};

//Most common
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function (intervals) {
  intervals.sort((a, b) => {
    if (a[0] == b[0]) return b[1] - a[1];
    else return a[0] - b[0];
  });
  let remove = 0;
  for (let i = 0; i < intervals.length - 1; i++) {
    if (intervals[i][1] >= intervals[i + 1][1]) {
      remove++;
      intervals[i + 1] = intervals[i];
    }
  }
  return intervals.length - remove;
};

//Second fastest
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function (intervals) {
  let numCoverages = 0;
  for (let i = 0; i < intervals.length; i++) {
    for (let j = 0; j < intervals.length; j++) {
      if (i === j) continue;
      let a = intervals[i][0];
      let b = intervals[i][1];
      let c = intervals[j][0];
      let d = intervals[j][1];
      if (c <= a && b <= d) {
        numCoverages++;
        break;
      }
    }
  }
  return intervals.length - numCoverages;
};

//Fastest
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function (intervals) {
  intervals.sort((a, b) => a[0] - b[0]);
  let count = intervals.length;
  let max = intervals[0][1];
  let maxStart = intervals[0][0];
  for (let i = 1; i < intervals.length; i++) {
    if (max >= intervals[i][1]) {
      count--;
    } else if (intervals[i][0] === maxStart) {
      count--;
      max = intervals[i][1];
    } else {
      max = intervals[i][1];
      maxStart = intervals[i][0];
    }
  }
  return count;
};
