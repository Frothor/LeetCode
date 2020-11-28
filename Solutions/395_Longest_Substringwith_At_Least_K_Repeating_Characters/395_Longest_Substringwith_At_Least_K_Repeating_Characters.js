//Third fastest
//Split by regex javascript solution -> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/408410/Split-by-regex-javascript-solution-56-ms
var longestSubstring = function(s, k) {
    var max = 0;
    
    var find = function (str) {
        var map = new Map();
        for (var i = 0; i < str.length; i++) {
            map.set(str[i], (map.get(str[i]) || 0) + 1);
        }
        
        var split = [];
        for (var [key, count] of map) {
            if (count < k) {
                split.push(key);
            }
        }
        
        if (split.length === 0) {
            if (str.length > max) {
                max = str.length;
            }
            return;
        }
        
        var substr = str.split(new RegExp("[" + split.join("") + "]+"))
        for (var i = 0; i < substr.length; i++) {
            if (substr[i].length >= k && substr[i].length > max) {
                find(substr[i]);
            }
        }
    };
    
    find(s);
    
    return max;
};

//Second fastest
var longestSubstring = function(s, k) {
    let result = 0;
    let maxUnique = 0;
    const countMap = new Array(26).fill(0);
    // count number of unique letters
    for (let i=0; i<s.length; i++) {
        if (countMap[s.charCodeAt(i)-97] == 0) {
            countMap[s.charCodeAt(i)-97]++;
            maxUnique++;
        }
    }
    for (let currentUnique=1; currentUnique<=maxUnique; currentUnique++) {
        // reset count map
        countMap.fill(0);
        let windowStart=0;
        let windowEnd=0;
        let index=0;
        let unique=0;
        let atLeastK=0;
        while (windowEnd < s.length) {
            // expand sliding window
            if (unique <= currentUnique) {
                index=s.charCodeAt(windowEnd)-97;
                if (countMap[index]==0) {
                    unique++;
                }
                countMap[index]++;
                if (countMap[index]==k) {
                    atLeastK++;
                }
                windowEnd++;
            } else {
                // shrink sliding window
                index=s.charCodeAt(windowStart) - 97;
                if (countMap[index]==k) {
                    atLeastK--;
                }
                countMap[index]--;
                if (countMap[index]==0) {
                    unique--;
                }
                windowStart++;
            }
            if (unique == currentUnique && unique == atLeastK) {
                result = Math.max(windowEnd-windowStart, result);
            }
        }
    }
    return result;
};

//First fastest
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87739/Java-Strict-O(N)-Two-Pointer-Solution

const CODE_A = 'a'.charCodeAt(0);

function longestSubstringWithTargetUniqueNum(s, k, targetUniqueNum) {
    const map = new Array(26).fill(0);
    let unique = 0;
    let noLessThanK = 0;
    let begin = 0, end = 0;

    let ret = 0;

    while (end < s.length) {
        const idxEnd = s[end].charCodeAt(0) - CODE_A;
        if (map[idxEnd] === 0) {
            unique++;
        }
        map[idxEnd]++;

        if (map[idxEnd] === k) {
            noLessThanK++;
        }
        end++;

        while (unique > targetUniqueNum) {
            const idxBegin = s[begin].charCodeAt(0) - CODE_A;
            if (map[idxBegin] === k) {
                noLessThanK--;
            }

            map[idxBegin]--;

            if (map[idxBegin] === 0) {
                unique--;
            }

            begin++;
        }

        if (unique === targetUniqueNum && noLessThanK === unique) {
            // here, end has been incremented by "end++". So current "end" is next "end", and we don't need to add 1
            const diff = end - begin;
            if (diff > ret) {
                ret = diff;
            }
        }
    }

    return ret;
}

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function (s, k) {
    let ret = 0;
    for (let i = 1; i <= 26; i++) {
        const curRet = longestSubstringWithTargetUniqueNum(s, k, i);
        if (curRet > ret) {
            ret = curRet;
        }
    }
    // console.log(ret);
    return ret;
};

// longestSubstring('aaabb', 3); // 3
// longestSubstring('ababbc', 2); // 5