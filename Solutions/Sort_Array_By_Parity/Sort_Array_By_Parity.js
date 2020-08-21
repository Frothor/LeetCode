//Most common

/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    for (let i = 0, j = 0;i < A.length; i++) {
        if (A[i] % 2 === 0) {
            [A[i], A[j]] = [A[j], A[i]]
            j++;
        }
    }
    return A;
};

//Fastest
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    const even = [];
    const odd = [];
    
    for (let i = 0; i < A.length; i ++) {
        if (A[i] % 2 === 0) {
            even.push(A[i]);
        } else {
            odd.push(A[i]);
        }
    }
    return [...even,...odd];
};