/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */


var merge = function(intervals) {
    let output = [];
    let curElement = intervals.shift();

    let start = curElement[0];
    let end = curElement[1];

    while(intervals.length > 0) {
        // get element from beginning
        curElement = intervals.shift();
        if (end >= curElement[0]) {
            end = Math.max(end, curElement[1]);
        } else {
            output.push([start, end]);
            start = curElement[0];
            end = curElement[1];
        }
    }
    output.push([start, end]);

    return output;
};

var insert = function(intervals, newInterval) {
    let niStart = newInterval[0];
    const sizeInterval = intervals.length;
    
    if (sizeInterval === 0)  {
        intervals.push(newInterval);
        return intervals;
    }

    if (niStart < intervals[0][0]) {
        intervals.unshift(newInterval);
        return merge(intervals)
    } else if (niStart > intervals[sizeInterval - 1][0]) {
        intervals.push(newInterval);
        return merge(intervals)
    }

    let i=0;
    while(intervals[i][0] < niStart && niStart > intervals[i + 1][0]) {i++;}
    
    intervals.splice(i + 1, 0, newInterval);
    return merge(intervals);
    
};

//Fastest
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {
    const result = [];
    const [newStart, newEnd] = newInterval;
    let lastEnd = -Infinity;
    let isInserted = false;
  
  
    for (let interval of intervals) {
      if (!isInserted) {
        if (newStart <= interval[0]) {
          result.push(newInterval);
          lastEnd = newEnd;
          isInserted = true;
        } else if (newStart <= interval[1]) {
          if (newEnd > interval[1]) {
            interval[1] = newEnd;
          }
  
          isInserted = true;
        }
      }
  
      if (interval[0] > lastEnd) {
        result.push(interval);
        lastEnd = interval[1];
      } else if (interval[1] > lastEnd) {
        result[result.length - 1][1] = interval[1];
      }
    }
    
    if(!isInserted) result.push(newInterval);
    return result;
  };