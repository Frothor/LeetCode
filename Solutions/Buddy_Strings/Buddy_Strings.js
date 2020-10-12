var buddyStrings = function(A, B) {
    if(A.length != B.length) return false;
    const diff = [];
    
    for(let i = 0; i < A.length; i++) {
        if(A[i] != B[i]) diff.push(i);
        if(diff.length > 2) return false;
    }
    if(!diff.length) return A.length != [...new Set(A)].length;
    const [i, j] = diff; 
    return A[i] == B[j] && B[i] == A[j];
};

//Third fastest
/**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
    if(A.length !== B.length || A.length === 0) return false;
    
    if(A === B) {
      const set = new Set();
      for(let str of A) {
        if(set.has(str)) return true;
        set.add(str);
      }
      return false
    }
    
    let difA = '';
    let difB = '';
    for(let i = 0; i < A.length; i++) { 
      if(A[i] !== B[i]) {
        difA += A[i];
        difB += B[i];
        if(difA.length > 2) return false;
      }
    }
    
    return difA[0] === difB[1] && difA[1] === difB[0];
  };

  //Second fastest
  /**
 * @param {string} A
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
    if(A.length != B.length) return false;
    const diff = [];
    
    for(let i = 0; i < A.length; i++) {
        if(A[i] != B[i]) diff.push(i);
        if(diff.length > 2) return false;
    }
    if(!diff.length) return A.length != [...new Set(A)].length;
    const [i, j] = diff; 
    return A[i] == B[j] && B[i] == A[j];
};

//Fastest
/**
 * @param {string} Ahttps://leetcode.com/problems/buddy-strings/submissions/
 * @param {string} B
 * @return {boolean}
 */
var buddyStrings = function(A, B) {
    if (A.length != B.length) {
        return false;
    }
    
    if (A == B) {
        let s = new Set();
        for (let i = 0; i < A.length; i++) {
            s.add(A.charAt(i));
        }
        return s.size < A.length;
    }
    
    let diff = [];
    for (let i = 0; i < A.length; i++) {
        if (A.charAt(i) != B.charAt(i)) {
            diff.push(i);
        }
    }
    
    return diff.length == 2 && A.charAt(diff[0]) == B.charAt(diff[1]) && A.charAt(diff[1]) == B.charAt(diff[0]);
};