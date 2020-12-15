//Third fastest
/**
 * @param {number[]} A
 * @return {number[]}
 */
const sortedSquares = (A) => {
    
    let start = 0;
  let end = A.length - 1;
  const res = new Array(A.length);

  for (let i = A.length - 1; i >= 0; i--) {
    const s = A[start] * A[start];
    const e = A[end] * A[end];
    if (s > e) {
      res[i] = s;
      start++;
    } else {
      res[i] = e;
      end--;
    }
  }

  return res;

// https://leetcode-cn.com/problems/squares-of-a-sorted-array/solution/977you-xu-shu-zu-de-ping-fang-shuang-zhi-zhen-jie-/
    
    /*
    let res=[]
    A.forEach(item =>{
        res.push(item * item);
    });
    
    return res.sort((a,b) =>a-b)
    
    /*
    let sortedArr=[];
   A.forEach(item =>{
      sortedArr.push(item * item);
        
    });
    
    return sortedArr.sort((a, b) => a-b);*/
};

//Second fastest
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    let length = A.length
    for (let i = 0; i < length; i++) {
        A[i] *= A[i]
    }
    
    return (A.sort((a,b) => a-b));
};

//Fastest
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    let results = A.map(num => {
        return Math.pow(num, 2);
    });
    

    return results.sort((a, b) => a - b);
};