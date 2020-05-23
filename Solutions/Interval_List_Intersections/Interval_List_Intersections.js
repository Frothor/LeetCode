/**
 * @param {number[][]} A
 * @param {number[][]} B
 * @return {number[][]}
 */
var intervalIntersection = function(A, B) {
    let result = [];
    let i = 0;
    let j = 0;
    
    while(i < A.length && j < B.length){
        const [aStart, aEnd] = A[i];
        const [bStart, bEnd] = B[j];
        const start = Math.max(aStart, bStart);
        const end = Math.min(aEnd, bEnd);
        
        if(start <= end) result.push([start, end]);
        
        if(aEnd < bEnd)
            i++;
        else
            j++;
    }
    
    return result;
};


/*
Fastest:

var intervalIntersection = function(A, B) {
    const intersection = [];
    
    let i = j = 0;
    
    while (i < A.length && j < B.length) {
        const min = Math.max(A[i][0], B[j][0]);
        const max = Math.min(A[i][1], B[j][1]);
        
        if (min <= max) intersection.push([min, max]);
        
        A[i][1] > B[j][1] ? j++ : i++; 
    }
    
    return intersection;
};

Most common:
var intervalIntersection = function(A, B) {
  // swap A, B if A[0][0] > B[0][0]
  // traversing A, B at the same time
  // A[i], B[j]
  // 
  // ----        i++
  //       ---  
  // ----  -----  j++  record intersect
  //  --   -----
  // 
  // ----        i++. record intersect
  //     ----

  if (!Array.isArray(A) || !Array.isArray(B) || !A.length || !B.length) {
    return [];
  }
  
  const result = [];
  
  let i = 0;
  let j = 0;
  
  while (i < A.length && j < B.length) {
    if (A[i][0] > B[j][0]) {
      let temp = A;
      A = B;
      B = temp;
      temp = i;
      i = j;
      j = temp;
    }
    if (A[i][1] < B[j][0]) {
      i++;
    } else if (A[i][1] >= B[j][1]){
      const intersect = [Math.max(A[i][0], B[j][0]), Math.min(A[i][1], B[j][1])];
      result.push(intersect);
      A[i][0] = B[j][1] + 1;
      j++;
    } else {
      const intersect = [Math.max(A[i][0], B[j][0]), Math.min(A[i][1], B[j][1])];
      result.push(intersect);
      i++;
    } 
  }
  
  return result;
};
*/