//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/305434/Simple-JavaScript-solution-(60-ms-faster-than-98.89)
/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    
    let n = time.length;      
    
    if (n < 2) {
        return 0;
    }
    
    let seconds = new Array(60);  // remainder = duration % 60
    
    for (let i = 0; i < 60; i++) {
        seconds[i] = 0;
    }

    for (let i = 0; i < n; i++) {
        seconds[time[i] % 60]++;
    }
    
    let pairs = 0;
    
    if (seconds[0] > 0) {
        pairs += seconds[0] * (seconds[0] - 1) / 2
    }

    if (seconds[30] > 0) {
        pairs += seconds[30] * (seconds[30] - 1) / 2
    }
    
    for (i = 1; i < 30; i++) {
        if (seconds[i] > 0 && seconds[60-i] > 0) {
            pairs += seconds[i] * seconds[60-i];
        }
    }
 
    return pairs;
};

//Another
/**
 * @param {number[]} time
 * @return {number}
 */
var numPairsDivisibleBy60 = function(time) {
    let numPairs = 0;
    
    const timeHash = {};
    
    
    for (const t of time) {
        if (t % 60 === 0) {
            if (timeHash[0]) numPairs += timeHash[0];
        } else {
            if (timeHash[60 - t % 60]) numPairs += timeHash[60 - t % 60];
        }
        
        !timeHash[t % 60] ? timeHash[t % 60] = 1 : timeHash[t % 60]++;
    }
    
    return numPairs;
};