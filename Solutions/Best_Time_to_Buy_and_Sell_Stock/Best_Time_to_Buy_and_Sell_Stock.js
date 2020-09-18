var maxProfit = function(prices) {
    let dif = 0
    let min = Infinity
    for(let price of prices){
        min = Math.min(price, min)
        if(min < price) dif = Math.max(dif, (price - min))
    }
    return dif
};

//Fastest
/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    let buyPrice = Infinity, maxProfit = 0;
    for (let i = 0; i < prices.length - 1; i++) {
        if (prices[i + 1] > prices[i]) {
            buyPrice = Math.min(buyPrice, prices[i]);
            maxProfit = Math.max((prices[i+1] - buyPrice), maxProfit)
        } 
    }
    return maxProfit
};