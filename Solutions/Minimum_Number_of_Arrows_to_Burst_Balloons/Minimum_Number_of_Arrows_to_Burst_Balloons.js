var findMinArrowShots = function(points) {
    if (points.length === 1)
        return 1;
    
    let res = points.length;
    
    points.sort((a,b) => a[0]-b[0] || (a[1]-a[0])-(b[1]-b[0]));
    
    for (let i = 1; i < points.length; i++) {
        if (points[i-1][0] <= points[i][0] && points[i][0] <= points[i-1][1]) {
            res--;
            [points[i][0], points[i][1]] = [Math.max(points[i-1][0], points[i][0]), Math.min(points[i-1][1], points[i][1])];
        }
    }
    
    return res;
};

//Third fastest
/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    if (points.length == 0) {
      return 0;
    }
      
    points.sort((a, b) => a[1] - b[1]);
   let arrowPos = points[0][1];
   let arrowCnt = 1;
   for (let i = 1; i < points.length; i++) {
       if (arrowPos >= points[i][0]) {
           continue;
       }
       arrowCnt++;
       arrowPos = points[i][1];
   }
   return arrowCnt;
};

//Second fastest
/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    if (!points.length) return 0
    points.sort((a, b) => a[1] - b[1])
    let arrow = 1, lastEnd = points[0][1]
    for (let i = 1; i < points.length; i++) {
      let [newStart, newEnd] = points[i]
      if (lastEnd < newStart) {
        arrow++
        lastEnd = newEnd
      }
    }
    return arrow
  };

//Fastest
/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    if (points.length === 0) {
        return 0;
    }
    points.sort((a, b) => {
        return a[1] - b[1];
    })
    
    let min = points[0][0];
    let max = points[0][1];
    let arrow = 0;
    const length = points.length;
    
    for (let i = 1; i < length; i++) {
        if (points[i][0] <= max) {
            min = min > points[i][0]? min:points[i][0];
            max = max > points[i][1]? points[i][1]:max;
            continue;
        }
        arrow += 1;
        min = points[i][0];
        max = points[i][1];
    }
    
    arrow++;
    return arrow;
};