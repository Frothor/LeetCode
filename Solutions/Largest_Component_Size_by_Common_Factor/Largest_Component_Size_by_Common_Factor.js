/**
 * @param {number[]} A
 * @return {number}
 */
//UnionFind - 648ms - beats 100%

var largestComponentSize = function(A) {
    const p = []
    for(let num of A) {
        const set = getFactors(num)  // get the set of all the factors
        for(let factor of set.values()) {  
            p[find(factor)] = find(num) // union the number with all the factors
        }
    }
    
    const cntMap = new Map()
    for(let num of A) {   // for all the input numbers, count the related numbers via their parents 
        const parent = find(num)
        cntMap.set(parent, (cntMap.get(parent) || 0) + 1) 
    }
    return Math.max(...cntMap.values())
    
    function find(a) {
        if(!p[a]) p[a] = a
        while(p[a] !== a) {
            p[a] = p[p[a]]
            a = p[a]
        }
        return a
    }
    
    function getFactors(number) {
        const res = new Set()  // use set to guarantee no duplicates, no need to add number itself here. 
        for (let i = 2; i * i <= number; i++) { 
            if (number % i === 0) {
                res.add(i)
                res.add(number / i)
            }
        }
        return res
    }
};

//Fastest
class DSU {
    constructor(n) {
        this.parents = new Array(n)
        for (var i = 0; i < n; i++) {
            this.parents[i] = i;
        }
    }
    
    union(x, y) {
        this.parents[this.find(x)] = this.parents[this.find(y)]; 
    }
    
    find(i) {
        if (this.parents[i] !== i) {
            this.parents[i] = this.find(this.parents[i]);
        }
        return this.parents[i];
    }
}

var largestComponentSize = function(A) {
    var max = A[0];
    for (var num of A) {
        max = Math.max(max, num)
    };
    var dsu = new DSU(max + 1); // 0 ~ n = n + 1
    for (var i = 0; i < A.length; i++) {
        var t = Math.sqrt(A[i]);
        for (var j = 2; j <= t; j++) {
            if (A[i] % j === 0) {
                dsu.union(A[i], j);
                dsu.union(A[i], A[i] / j);
            }
        }
    }
    var map = new Map();
    var res = 1;
    for (var i = 0; i < A.length; i++) {
        var root = dsu.find(A[i]);
        if (map.has(root)) {
            map.set(root, map.get(root) + 1);
        }
        else {
            map.set(root, 1);
        }
        res = Math.max(res, map.get(root));
    }
    return res;
};