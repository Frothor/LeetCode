var pancakeSort = function(a, len, arr=[], max=a.length) {
    while(max>1){
        flip(a.indexOf(max));
        max--;  
    }
    function flip(indx){
        if(indx){
            for(let q=0; q<indx/2; q++){
                [[a[q], a[indx-q]] = [a[indx-q], a[q]]];
            };
            arr.push(indx+1);
        }
        len=max-1;
        for(let q=0; q<len/2; q++){
            [[a[q], a[len-q]] = [a[len-q], a[q]]];
        };
        arr.push(max);
    }
    return arr;
};


/**
 * @param {number[]} A
 * @return {number[]}
 */
var pancakeSort = function(A) {
    let res = [];
    let curr = A.length;
    while (curr > 0) {
        const idx = A.indexOf(curr);
        if (idx != curr - 1) {
            res.push(idx + 1);
            flip(idx, A);
            res.push(curr);
            flip(curr - 1, A);
        }
        curr--;
    }
    return res;
};

const flip = (i, A) => {
    for(let j = 0; j <= Math.floor(i / 2); j++) {
        [A[i - j], A[j]] = [A[j], A[i - j]];
    }
};


//Fastest
/**
 * @param {number[]} A
 * @return {number[]}
 */

var pancakeSort = function (A) {
    const flip = (arr, i) => {
        let left=0
        let right =i
        while(left<right){
            temp = arr[right]
            arr[right]=arr[left]
            arr[left]=temp
            left++
            right--
        }
    }
    const findMax = (arr, i) => {
        let mInd = 0
        let isSorted = true, last = arr[0]
        for (let j = 0; j <= i; j++) {
            if (A[j] > A[mInd]) {
                mInd = j
            }
            if (isSorted && A[j] < last) isSorted = false
            last = A[j]
        }
        return [mInd, isSorted]
    }

    if (!A || A.length <=1 ) { return [] }
    let results = []
    let iterInd = A.length - 1

    // dont iterate over the zero index. It is sorted by the prior sort
    while (iterInd > 0) {
        let [maxInd, isSorted] = findMax(A, iterInd)
        // skip iterations if the items are sorted
        if(isSorted) return results
        // flip so the largest index is on top
        flip(A, maxInd)
        results.push(maxInd+1)
        // flip so the largest index is in place
        flip(A, iterInd)
        results.push(iterInd+1)

        iterInd--
    }
    return results
};