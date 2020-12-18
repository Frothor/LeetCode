//https://leetcode.com/problems/4sum-ii/discuss/851832/Javascript-easy-and-faster-than-98.36
var fourSumCount = function(A, B, C, D) {
    if (!A || !B || !C || !D) return [];
    // cuadratic solution... counter, reduced from sum_of_two
    let memory = new Map();
    for (let i of A) {
        for (let j of B) {
            memory.set(-(i + j), memory.get(-(i + j)) + 1 || 1);
        }
    }
    // look in the map if we have seen the complement of this sum
    let output = 0;
    for (let m of C) {
        for (let n of D) {
            output += memory.has(m + n)? memory.get(m + n): 0;
        }
    }
    return output;
};

//Little faster
var fourSumCount = function(A, B, C, D) {
    const len = A.length
    // sum1 => count of sum1
    const map1 = new Map()
    
    
    for (const valA of A.values()) {
        for (const valB of B.values()) {
            const sum = valA + valB
            map1.set(sum, 1 + (map1.get(sum) ?? 0))
        }
    }
    
    let result = 0
    for (const valC of C.values()) {
        for (const valD of D.values()) {
            const sum2 = valC + valD
            const sum1ShouldBe = -sum2
            const count1 = map1.get(sum1ShouldBe) ?? 0
            result += count1
        }
    }
    
    
    return result
};

//Fastest
var fourSumCount = function(A, B, C, D) {
    let tuples = 0;
    let map1 = new Map();
    for(var i = 0; i < A.length; i++){
        for(var j = 0; j < A.length; j++){
            if(map1.has(A[i] + B[j])){
                map1.set(A[i] + B[j], map1.get(A[i] + B[j]) + 1);
            }else{
                map1.set(A[i] + B[j], 1);
            }
        }
    }
    for(var i = 0; i < C.length; i++){
        for(var j = 0; j < D.length; j++){
            if(map1.has(-(C[i] + D[j]))){
                tuples += map1.get(-(C[i] + D[j]));
            }
        }
    }
    
    return tuples;
};