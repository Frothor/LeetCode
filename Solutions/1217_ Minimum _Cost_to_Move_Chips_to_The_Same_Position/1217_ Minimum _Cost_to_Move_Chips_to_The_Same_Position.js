var minCostToMoveChips = function(position) {
    return Math.min(position.reduce((count, pos) => count + (pos & 1), 0), position.reduce((count, pos) => count + 1 - (pos & 1), 0));
};

//Third fastest
/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function(position) {
    let even = position.filter(e => e % 2 === 0).length;
    let odd = position.length - even;
    return Math.min(even, odd)
        
};

//Second fastest
/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function(position) {
    let evenCoinsSum = 0;
    let oddCoinsSum = 0;
    for (let i = 0; i < position.length; i++) {
        if (position[i] % 2 == 0) {
            evenCoinsSum++;    
        } else {
            oddCoinsSum++;    
        }
    }    
    return Math.min(evenCoinsSum, oddCoinsSum);
};

//Fastest
/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function(position) {
    let evenCoinsSum = 0;
    let oddCoinsSum = 0;
    for (let i = 0; i < position.length; i++) {
        if (position[i] % 2 == 0) {
            evenCoinsSum++;    
        } else {
            oddCoinsSum++;    
        }
    }    
    return Math.min(evenCoinsSum, oddCoinsSum);
};