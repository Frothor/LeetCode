//Third fastest
// O(n) time | (1) space
// Where n is the length of the input array

function minDominoRotations(A, B) {
    const ans = Math.min(
      countSwaps(A, B, A[0]),
      countSwaps(A, B, B[0]),
      countSwaps(B, A, B[0]),
      countSwaps(B, A, A[0])
    );
  
    return ans === Infinity ? -1 : ans;
  }
  
  function countSwaps(halfOne, halfTwo, target) {
    const n = halfOne.length;
    let swaps = 0;
  
    for (let i = 0; i < n; i++) {
      if (halfOne[i] !== target) {
        if (halfTwo[i] !== target) {
          return Infinity;
        } else {
          swaps++;
        }
      }
    }
  
    return swaps;
  }

//Second fastest
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var minDominoRotations = function(A, B) {
    let minswaps = Math.min(numswaps(A[0],A,B), numswaps(B[0],A,B))
    
    minswaps = Math.min(minswaps, numswaps(A[0],B,A))
    minswaps = Math.min(minswaps, numswaps(B[0],B,A))
    
    return minswaps === Infinity ? -1 : minswaps
};

function numswaps(target, A, B){
    let nswap = 0
    
    for(let i = 0; i < A.length; i++){
        if(A[i] !== target && B[i] !== target) return Infinity
        else if(A[i] !== target) nswap++
    }
    
    return nswap
}

//Fastest
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var minDominoRotations = function(A, B) {
    const countA = new Array(7).fill(0);
    const countB = new Array(7).fill(0);
    const same = new Array(7).fill(0);
    for(var i = 0; i < A.length; i++){
        if(A[i] === B[i]) same[A[i]]++;
        countA[A[i]]++;
        countB[B[i]]++;
    }
    
    for(var i = 1; i <= 6; i++){
        if(countA[i] + countB[i] - same[i] === A.length){
            return A.length - Math.max(countA[i], countB[i]);
        }
    }
    return -1;
};