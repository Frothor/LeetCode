/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 
 combination no repeating # []
 
 combination is unique
 
 n === target
 
 k is numbers
 
 1 - 9 
 
 */
var combinationSum3 = function(k, n) {
    let res = [];
    let dfs = function(a, sum, i) {
        if (a.length === k) {
            if (sum === n) res.push([...a]);
            return;
        }
        
        for (i; i <= 9; i++) {
            a.push(i);
            dfs(a, sum + i, i+1);
            a.pop();
        }
        
    }
    dfs([], 0, 1);
    return res;
};

//Fastest
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function(k, n) {
    const candidates = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    const res = [];
    helper(res, candidates, k, n);
    return res;
};

function helper(res, candidates, maxLength, target, path = [], idx = 0) {
    if (target < 0) return;
    if (path.length > maxLength) return;
    if (target === 0 && path.length === maxLength) {
        res.push(path);
        return;
    }
    for (let i = idx; i < candidates.length; i++) {
        const curr = candidates[i];
        const newTarget = target - curr;
        helper(res, candidates, maxLength, newTarget, [...path, curr], i + 1);
    }
}