//Third fastest
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var smallestRangeII = function(A, K) {
        const N = A.length;
        A.sort((a, b) => a-b);
        let ans = A[N-1] - A[0]; 
    
        for (let i = 0; i < A.length - 1; i++) {
            const h = Math.max(A[N-1] - K, A[i] + K); 
            const l = Math.min(A[0] + K, A[i+1] - K);
            ans = Math.min(ans, h - l);
        }
        return ans;
};

// high is min of (the maxElement - K or current + K)
// low is max of (the first element + K or current - K)
// largest range.

//Second fastest
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var smallestRangeII = function(A, K) {
        const N = A.length;
        A.sort((a, b) => a-b);
        let ans = A[N-1] - A[0]; 
    
        for (let i = 0; i < A.length - 1; i++) {
            const a = A[i], b = A[i+1];
            const high = Math.max(A[N-1] - K, a + K); 
            const low = Math.min(A[0] + K, b - K);
            ans = Math.min(ans, high - low);
        }
        return ans;
};

// high is min of (the maxElement - K or current + K)
// low is max of (the first element + K or current - K)
// largest range.

//Fastest
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var smallestRangeII = function(A, K) {
    if (A.length === 1) return 0
    A.sort((a,b) => a-b);
    let ans = A[A.length - 1] - A[0];
    for (let i = 0; i < A.length - 1; i++) {
        let max = Math.max(A[A.length - 1] - K, A[i] + K);
        let min = Math.min(A[0] + K, A[i + 1] - K)
        ans = Math.min(ans, max -min)
    }
    return ans
};