//Third Fastest
/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    if (s === null || s.length <= 10) return [];
    let a = 4;
    let aL = Math.pow(a, 10);
    let map = new Map();
    map.set("A", 0);
    map.set("T", 1);
    map.set("C", 2);
    map.set("G", 3);
    let nums = Array(s.length).fill(0);
    for (let i = 0; i < s.length; i++) {
        nums[i] = map.get(s[i]);
    }
    let set = new Set();
    let res = new Set();
    let h = 0;
    for (let i = 0; i <= s.length - 10; i++) {
        if (i !== 0) {
            h = h * a - nums[i - 1] * aL + nums[i + 9];
        } else {
            for (let j = 0; j < 10; j++) {
                h = h * a + nums[j];
            }
        }
        if (set.has(h)) {
            res.add(s.slice(i, i + 10));
        }
        set.add(h);
    }
    return [...res];
};

//Second fastest
/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    const L = 10, n = s.length;
    const seen = new Set(), result = new Set();
    
    for (let i = 0; i < n - L + 1; i ++) {
        const str = s.substring(i, i + L);
        if (seen.has(str)) {
            result.add(str);
        } else {
            seen.add(str);
        }
    }
    
    return [...result];
};

//Fastest
var findRepeatedDnaSequences = function(s) {
    let store = new Set(), result = new Set()
    for(let i = 0; i < s.length - 9; i++) {
        const str = s.substring(i, i + 10)
        if(store.has(str)) {
            result.add(str)
        } else {
            store.add(str)
        }
    }
    return Array.from(result)
};