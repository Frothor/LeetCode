/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function (timeSeries, duration) {
  if (timeSeries.length === 0) return 0;
  let res = duration;
  for (let i = 1; i < timeSeries.length; i++) {
    res += Math.min(timeSeries[i] - timeSeries[i - 1], duration);
  }
  return res;
};

//Fastest
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function (ts, dur) {
  let res = 0;
  for (let i = 0; i < ts.length; i++) {
    if (i > 0 && ts[i] <= ts[i - 1] + dur - 1) {
      res += ts[i] - ts[i - 1];
    } else {
      res += dur;
    }
  }
  return res;
};
