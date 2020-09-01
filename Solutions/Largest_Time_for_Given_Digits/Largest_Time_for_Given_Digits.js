var largestTimeFromDigits = function(A) {
    const convert = (h, m) => (parseInt(h) * 60) + parseInt(m)
    
    const isValid = (h, m) => parseInt(h) <= 23 && parseInt(m) <= 59
    
    let permutations = []
    
    let max = 0
     
    const check = (permutation) => {
        let h = permutation[0]+''+permutation[1]
        let m = permutation[2]+''+permutation[3]
        
        if (isValid(h, m)) {
            if (!max || convert(max[0], max[1]) < convert(h, m)) max = [h, m]
        }
    }
    
    const permute = (array, index) => {
        if (index == array.length) check([...array])
        for (let i = index; i < array.length; i++) {
            [array[index], array[i]] = [array[i], array[index]]
            permute(array, index+1);
            [array[index], array[i]] = [array[i], array[index]]
        }
    }
    
    permute(A, 0)
   
    return max ? max[0]+':'+max[1] : ''
};

//Most common
/**
 * @param {number[]} A
 * @return {string}
 */
var largestTimeFromDigits = function(A) {
    var mapDigitToCount = {};
    var string = "";
    var numsGreaterThan4 = 0;
    var numsGreaterThan5 = 0;
    var numsLessThan4 = 0;
    
    for (var i = 0; i < 10; i++) {
        mapDigitToCount[i] = 0;
    }
    
    for (var i = 0; i < A.length; i++) {
        mapDigitToCount[A[i]]++;
        
        if (A[i] > 4) numsGreaterThan4++;
        if (A[i] > 5) numsGreaterThan5++;
        if (A[i] < 4) numsLessThan4++;
    }
    
    console.log(numsGreaterThan4);
    var highest;
    if (numsGreaterThan5 >= 2 && numsLessThan4 <= 2) {
        highest = 1;
    } else {
        highest = 2;
    }
    var idx = 0;
    
    while (idx < 4 && highest >= 0) {
        if (mapDigitToCount[highest] > 0) {
            string += highest;
            if (string.length == 2) string += ":";
            idx++;
            mapDigitToCount[highest]--;
            
            if (idx == 1) {
                if (string[idx - 1] == 2) {
                    highest = 3;
                } else {
                    highest = 9;
                }
            } else if (idx == 2) {
                highest = 5;
            } else if (idx == 3) {
                highest = 9;
            } else {
                return string;
            }
        } else {
            highest--;
        }
    }
    
    return "";
};

//Fastest
var largestTimeFromDigits = function(A) {
    for (const a of A) {
        if (a < 0) return '';
    }

    let maxCandid = [];
    let max = -1;
    for (let i = 0; i < 4; i++) {
        for(let j = 0; j < 4; j++) {
            if (j == i) continue;
            for(let k = 0; k < 4; k++) {
                if (k == j || k == i) continue;

                const candidate = [A[i], A[j], A[k], A[6-(i+j+k)]];
                // console.log(candidate);
                const hour = candidate[0] * 10 + candidate[1];
                const min = candidate[2] * 10 + candidate[3];
                let valid = false;
                if (hour < 24 && min < 60) valid = true;

                if (valid) {
                    const val = candidate[0] * 1000 + candidate[1] * 100 + candidate[2] * 10 + candidate[3];
                    // console.log(val);
                    if (max < val) {
                        max = val;
                        maxCandid = candidate.slice();
                        // console.log(maxCandid);
                    }
                }
            }
        }
    }
    
    if (maxCandid.length === 0) return '';

    return `${maxCandid[0]}${maxCandid[1]}:${maxCandid[2]}${maxCandid[3]}`;
};