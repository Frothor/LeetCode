//Fourth fastest
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let minPrice = Number.MIN_VALUE;
    let sum=0;
    
    if(prices.length <=1) {
        return 0;
    }
    
    let previousPrice = prices[0]
    for(let i = 0; i<prices.length; i++) {
        if(prices[i] < previousPrice) {
            previousPrice = prices[i];
        } else {
            sum+= prices[i] - previousPrice;
            previousPrice = prices[i];
        }
    };
    
    return sum
}

//Third fastest
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxprofit = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
};

//Second fastest
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0;
    
    for (let i = 0; i < prices.length - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    
    return profit;
};

//Fastest
function maxProfit(prices) {
  if (isAscending(prices)) {
    return prices[prices.length - 1] - prices[0];
  }

  if (isDescending(prices)) {
    return 0;
  }

  let min = -1, answer = 0;

  for (let i = 0; i < prices.length - 1; i++) {
    if (prices[i] < prices[i + 1]) {
      if (min === -1 || min > prices[i]) {
        min = prices[i];
      }
    } else if (min !== -1) {
      answer += prices[i] - min;
      min = -1;
    }
  }

  if (min !== -1 && min < prices[prices.length - 1]) {
    answer += prices[prices.length - 1] - min;
  }

  return answer;
}

function isAscending(numbers) {
  return numbers.every((number, i) => i === 0 || number >= numbers[i - 1]);
}

function isDescending(numbers) {
  return numbers.every((number, i) => i === 0 || number <= numbers[i - 1]);
}