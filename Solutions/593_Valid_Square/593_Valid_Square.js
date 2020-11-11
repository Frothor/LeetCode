var validSquare = function(p1, p2, p3, p4) {
    let map = new Map();
    let arr = [p1, p2, p3, p4];
    let largest = 0;
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            let dist = countDistance(arr[i],arr[j]);
            map.set(dist, map.get(dist) + 1 || 1);
            largest = Math.max(largest, map.get(dist));
        }
    }
    
    return map.size === 2 && largest === 4;
};

function countDistance (p1, p2) {
    return Math.pow((p1[0] - p2[0]),2) + Math.pow((p1[1] - p2[1]),2);
}

//Third fastest
var validSquare = function(p1, p2, p3, p4) {
    const a12 = Math.sqrt(Math.pow(p1[0] - p2[0], 2) + Math.pow(p1[1] - p2[1], 2));
    const a13 = Math.sqrt(Math.pow(p1[0] - p3[0], 2) + Math.pow(p1[1] - p3[1], 2));
    const a24 = Math.sqrt(Math.pow(p2[0] - p4[0], 2) + Math.pow(p2[1] - p4[1], 2));
    const a34 = Math.sqrt(Math.pow(p3[0] - p4[0], 2) + Math.pow(p3[1] - p4[1], 2));
    const a14 = Math.sqrt(Math.pow(p1[0] - p4[0], 2) + Math.pow(p1[1] - p4[1], 2));
    const a23 = Math.sqrt(Math.pow(p2[0] - p3[0], 2) + Math.pow(p2[1] - p3[1], 2));
    
    const set = [...new Set([a12, a13, a24, a34, a14, a23])];
    if (set.length !== 2 || !set[0] || !set[1]) {
        return false;
    }
    return true
};

//Second fastest
var validSquare = function(p1, p2, p3, p4) {
    var points = [p1,p2,p3,p4];
    [p1, p2, p3, p4] = points.sort((a, b) => {
      var x = a[0] - b[0];
      var y = a[1] - b[1];
      if (x === 0) {
        return y;
      }
      return x;
    });
    
    var degree1 = calcDegree(p1, p2, p3);    
    var degree2 = calcDegree(p2, p4, p1);
    var degree3 = calcDegree(p3, p1, p4);
    var degree4 = calcDegree(p4, p3, p2);
    
    // console.log({degree1, degree2, degree3, degree4});
    var len1 = calcLength(p1,p2);
    var len2 = calcLength(p1,p3);
    var len3 = calcLength(p2,p4);
    var len4 = calcLength(p3,p4);
      // console.log({len1, len2,len3,len4})
  
    return degree1 === 90 && degree2 === 90 && degree3 === 90 && degree4 === 90 && len1 === len2 && len2 === len3 && len3 === len4;
  };
  
  function calcLength(p1, p2) {
    return Math.sqrt(Math.pow(p1[0]-p2[0],2) + Math.pow(p1[1]-p2[1], 2));
  }
  
  function calcDegree(p1, p2, p3) {
    return Math.round(Math.abs((Math.atan2(p2[1]-p1[1], p2[0]-p1[0]) * (180 / Math.PI) - Math.atan2(p3[1]-p1[1], p3[0]-p1[0]) * (180 / Math.PI))))%180;
  }

//Fastest
/**
 * @param {number[]} p1
 * @param {number[]} p2
 * @param {number[]} p3
 * @param {number[]} p4
 * @return {boolean}
 */
var validSquare = function(p1, p2, p3, p4) {
    let count = {}
    let init = false
    let points = [p1, p2, p3, p4]
    for (let i = 0; i < points.length - 1; i++) {
        for (let j = i + 1; j < points.length; j++) {
            let dist = Math.pow(points[i][0] - points[j][0], 2) + Math.pow(points[i][1] - points[j][1], 2)
            if (!count[dist]) count[dist] = 1
            else count[dist]++
        }
    }
    let numKeys = 0
    let smol
    let larg
    let inited = false
    for (let key in count) {
        key = parseInt(key)
        if (++numKeys > 2) return false
        else if (!inited) {
            smol = larg = key
            inited = true
        } 
        else if (key < smol) smol = key
        else if (key > larg) larg = key
    }
    return 2 * smol === larg && numKeys === 2
};