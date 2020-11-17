/**
 * @param {number} p
 * @param {number} q
 * @return {number}
 */
var mirrorReflection = function (p, q) {
    while (p % 2 == 0 && q % 2 == 0) {
        p /= 2;
        q /= 2;
    }
    if (p % 2 == 1 && q % 2 == 0) return 0;
    if (p % 2 == 1 && q % 2 == 1) return 1;
    else return 2;
};

//Fastest
/**
 * @param {number} p
 * @param {number} q
 * @return {number}
 */
var mirrorReflection = function(p, q) {
    if (q === p)    return 1
    if (q === 0)    return 0
    
    
    function getGCD(m, n) {
        if (m === 0)    return n
        // ensure m <= n
        if (m > n)  return getGCD(n, m)
        
        const remainder = n % m
        return getGCD(remainder, m)
    }
    // normalize p and q so that
    // they are relatively prime
    const gcd = getGCD(p, q)
    p /= gcd
    q /= gcd
    
    
    if (p % 2 === 1) {
        // x is odd, y is odd
        if (q % 2 === 1)    return 1
        // x is odd, y is even
        else return 0
    } else {
        // x is even
        return 2
        // x and y cant be even at the same time
    }
};