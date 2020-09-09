/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const v1 = version1.split('.').map(Number);
    const v2 = version2.split('.').map(Number);
    const maxLen = Math.max(v1.length, v2.length)
    
    for(let i = 0; i < maxLen; i++) {
        const curr1 = v1[i] || 0;
        const curr2 = v2[i] || 0;
        if(curr1 === curr2) continue;
        return curr1 > curr2 ? 1 : -1;
    }
    return 0;
};

//Fastest
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
// var compareVersion = function(version1, version2) {
//     const v1Arr = version1.split('.');
//     const v2Arr = version2.split('.');
    
//     const n = Math.max(v1Arr.length, v2Arr.length);
    
//     while(v2Arr.length < n) {
//         v2Arr.push('0');
//     }
//     while(v1Arr.length < n) {
//         v1Arr.push('0');
//     }
    
//     for(let i = 0; i < n; i++) {
//         if(parseInt(v1Arr[i]) < parseInt(v2Arr[i])) {
//             return -1;
//         }
//         if(parseInt(v1Arr[i]) > parseInt(v2Arr[i])) {
//             return 1;
//         }
//     }
//     return 0;
// };

var compareVersion = function(version1, version2) {
    let p1 = 0, p2 = 0;
    
    while(p1 < version1.length || p2 < version2.length) {
        const p1Val = getVal(version1, p1)
        const p2Val = getVal(version2, p2);
        if(p1Val[0] < p2Val[0]) {
            return -1;
        }
        if(p1Val[0] > p2Val[0]) {
            return 1;
        }
        p1 = p1Val[1];
        p2 = p2Val[1];
    }
    return 0;
};

const getVal = (version, p) => {
    if(p > (version.length - 1)) {
        return [0, p];
    }

    let valStr = '';
    while(version[p] !== '.' && p < version.length) {
        valStr+=version[p];
        p++;
    }

    return [parseInt(valStr), p + 1];
}