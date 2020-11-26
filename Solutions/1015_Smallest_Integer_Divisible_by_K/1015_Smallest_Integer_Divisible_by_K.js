//https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/786612/JavaScript-Clean-Solution-Beat-100
var smallestRepunitDivByK = function(K) {
    if(!(K%2) || !(K%5)) return -1; // short circuit
    
    let len = 0, val = 0, loop = 100000;
    
    while(loop--) {
        val = (val*10 + 1) % K; 
        len++
        if(!val) return len;
    }
};

//Third fastest
var smallestRepunitDivByK = function(K) {
    var remainder = 0;
    for(var i = 1; i <= K; i++)
        {
            remainder = (remainder * 10 + 1) % K;
            if(remainder === 0)
                {
                    return i;
                }
        }
    return -1;
    
};

//Second fastest
var smallestRepunitDivByK = function(K) {
    let r = 0;
    for (let i = 0; i < K + 1; i++) {
        r = (r*10+1) % K;
        if (r === 0) return i + 1;
    }
    return -1
};

//Fastest
var smallestRepunitDivByK = function(K) {
    if(!(K%2) || !(K%5)) return -1; // short circuit
    
    let len = 0, val = 0, loop = 100000;
    
    while(loop--) {
        val = (val*10 + 1) % K; 
        len++
        if(!val) return len;
    }
};

