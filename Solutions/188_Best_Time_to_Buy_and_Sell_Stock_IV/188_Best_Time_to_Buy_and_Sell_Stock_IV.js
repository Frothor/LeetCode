var maxProfit = function(k, prices) {
    if(prices.length == 0) return 0;
    
    // When k becomes so much larger than the number of prices we can make transactions whenever.
    if(k > (prices.length / 2) ){
        let profit = 0;
        for(let i = 1; i < prices.length; i++){
            if(prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
    else{
        let dp = new Array(prices.length).fill(0);
        let size = prices.length;
        for(let t = 1; t <= k; t++){
            let min = prices[0];
            let max = 0;
            for(let i = 0; i < size; i++){
                min = Math.min(min, prices[i] - dp[i]);
                max = Math.max(max, prices[i] - min);
                dp[i] = max
            }
        }
        return dp.pop();   
    }
};

//Third fastest
/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
/* 
                    0    1      2                ....k
 prices[0]          0    0      0                ....0
 prices[0, 1]       0    1-0    dp[i][j-1]: if k >= len
 prices[0, 1, 2]    0    2-0.   max(dp[i][j-1], )
 ...
 prices[0...n]      0
*/
var maxProfit = function(k, prices) {
    const size = prices.length;
    if(k === 0 || size < 2) return 0;
    
    if(k >= Math.floor(size/2)) { // do as many as transactions as we want
        let sum = 0;
        for(let i = 1; i < size; i++) {
            if(prices[i] > prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    
    const balance = new Array(k+1).fill(-Infinity);
    const profit = new Array(k+1).fill(0);
    
    for(let i = 0; i < size; i++) { // for each price
        for(let j = 1; j <= k; j++) {
            balance[j] = Math.max(balance[j], profit[j-1] - prices[i]); // whether to buy at this price
            profit[j] = Math.max(profit[j], balance[j] + prices[i]); // whether to sell at this price
        }
    }
    return profit[k];
};

//Second fastest
var BestTimeToBuyAndSellStockII = function(prices) {
    let maxProfit = 0;
    for (let i = 0; i < prices.length - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            maxProfit += prices[i + 1] - prices[i];
        }
    }
    return maxProfit;
};


var maxProfit = function(k, prices) {

    if (k * 2 >= prices.length) {
        return BestTimeToBuyAndSellStockII(prices);
    }

    // DP init 
    const buy = new Array(k + 1).fill(-Number.MAX_VALUE)
    const sell = new Array(k + 1).fill(0);

    for (let i = 0; i < prices.length; i++) {
        for (let j = 1; j <= k; j++) {
            buy[j] = Math.max(buy[j], sell[j - 1] - prices[i]); // buy at the time
            sell[j] = Math.max(sell[j], buy[j] + prices[i]); // sell at the time
        }
    }
    // console.log( buy, sell );
    return sell[k];

};

//Fastest
/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    
    if ( k * 2 >= prices.length ) {
        // try to seel every time
        let ret = 0 ;
        for ( let i = 1 ; i < prices.length ; i++ ) {
            if ( prices[i] > prices[i-1] ) ret += ( prices[i] - prices[i-1] ) ;
        }
        return ret;
    }

    // DP init 
    const buy = new Array( k+1 ).fill( -Number.MAX_VALUE )
    const sell = new Array( k+1 ).fill( 0 );
    
    for ( let i = 0 ; i < prices.length ; i++ ) {
        for ( let j = 1 ; j <= k ; j++ ) {   
            buy[j] = Math.max( buy[j], sell[j-1] - prices[i]  ); // buy at the time
            sell[j] = Math.max( sell[j], buy[j] + prices[i] ); // sell at the time
        }
    }
    // console.log( buy, sell );
    return sell[k];
    
};