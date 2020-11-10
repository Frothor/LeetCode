//Third fastest
var flipAndInvertImage = function(A) {
    for (let j = 0; j < A.length; j++) {
        imax = A[j].length-1;   // 2
        ii = Math.round(A[j].length / 2); // 3/2 1.5 2; 4/2 2 1 
        for (let i = 0; i < ii; i++) {
            let pix = A[j][i];
            A[j][i] = A[j][imax-i]
            A[j][imax-i] = pix;
        }
        for (let i = 0; i <= imax; i++) {
            A[j][i]   = 1 - A[j][i];
        }
    }
    return A;
};

//Second fastest
var flipAndInvertImage = function(A) {
    let result = []
    result = A.map((row)=>{
        let newRow = row.reverse();
        return newRow.map((e)=>1-e);
    })
    return result
};

//Fastest
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) { 
    for(let i=0;i<A.length;i++){
        A[i] = A[i].reverse().map(a => a==1 ? 0 : 1)
    }
    return A
};