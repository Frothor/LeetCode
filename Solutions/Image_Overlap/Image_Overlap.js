const largestOverlap = (A, B) => {
    const length = A.length;
    let max = 0;
    for(let rowOffset = -length; rowOffset < length; rowOffset++)
        {
            for(let colOffset = -length; colOffset < length; colOffset++)
                {
                    max= Math.max(max, getOverlap(rowOffset,colOffset));     
                }
        }
    return max;
    
    
    function getOverlap(rowOffset, colOffset)
    {
        let res = 0;
        
        for(let i = 0; i< length; i++)
            {
                let offsetI = i+rowOffset;
                if(offsetI < 0 || offsetI >= length)
                    continue;
                
                for(let j= 0; j<length; j++)
                    {
                        
                        let offsetJ = j+colOffset 
                        
                        if(offsetJ < 0 || offsetJ >= length) continue;
                         
                        if(A[offsetI][offsetJ] == B[i][j])
                            res+=A[offsetI][offsetJ]; 
                        
                    }
            }
        
        return res;
    }
};


//Most common
/**
 * @param {number[][]} A
 * @param {number[][]} B
 * @return {number}
 */
var largestOverlap = function(A, B) {
    let max = 0; // max count of overlapped cells;
	
    for (let r = 0; r < A.length; r++) { // shift by Y
        for (let s = 0; s < A[0].length; s++) { // shift by X
            const overlap1 = checkOverlap(A, B, r, s); // move B relative to A
            const overlap2 = checkOverlap(B, A, r, s); // move A relative to B
            max = Math.max(overlap1, overlap2, max); // update max
        }        
    }
    
    return max;
    
    function checkOverlap (A, B, y, x) {
        let overlap = 0;

        for (let i = 0; i < A.length - y; i++) { // loop by delta Y
            for (let j = 0; j < A[0].length - x; j++) { // loop by delta X 
                if (B[y+i][x+j] === A[i][j] && B[y+i][x+j] === 1) overlap++;
            }        
        }
        return overlap;
    }
};

//Fastest
/**
 * @param {number[][]} A
 * @param {number[][]} B
 * @return {number}
 O(n^4) time complexity and O(1) space
 */
var largestOverlap = function(A, B) {
    let max = 0; // max count of overlapped cells;
	
    for (let r = 0; r < A.length; r++) { // shift by Y
        for (let s = 0; s < A[0].length; s++) { // shift by X
            const overlap1 = checkOverlap(A, B, r, s); // move B relative to A
            const overlap2 = checkOverlap(B, A, r, s); // move A relative to B
            max = Math.max(overlap1, overlap2, max); // update max
        }        
    }
    
    return max;
    
    function checkOverlap (A, B, y, x) {
        let overlap = 0;

        for (let i = 0; i < A.length - y; i++) { // loop by delta Y
            for (let j = 0; j < A[0].length - x; j++) { // loop by delta X 
                if (B[y+i][x+j] === A[i][j] && B[y+i][x+j] === 1) overlap++;
            }        
        }
        return overlap;
    }
};