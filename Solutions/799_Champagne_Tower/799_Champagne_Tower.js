//JS
var champagneTower = function (poured, query_row, query_glass) {
  const dp = Array(query_row + 2)
    .fill(null)
    .map(() => Array(query_row + 2).fill(0));

  dp[0][0] = poured;

  for (let i = 0; i <= query_row; i++) {
    for (let j = 0; j <= i; j++) {
      if (dp[i][j] > 1) {
        const excess = dp[i][j] - 1;
        dp[i + 1][j] += excess / 2;
        dp[i + 1][j + 1] += excess / 2;
      }
    }
  }

  return dp[query_row][query_glass] <= 1 ? dp[query_row][query_glass] : 1;
};

//Third fastest
var champagneTower = function(poured, query_row, query_glass) {
    let cups = [poured];
    for(let i=0; i<query_row; i++){
        let nextRow = new Array(cups.length+1).fill(0);
        for(let j=0; j<cups.length; j++){
            let extraOverFlow = Math.max(0,cups[j]-1);
            nextRow[j] += extraOverFlow/2;
            nextRow[j+1] += extraOverFlow/2;
        }
        cups = nextRow;
    }
    return Math.min(1,cups[query_glass]);
};

//Second fastest
var champagneTower = function(poured, query_row, query_glass) {
    let current = [poured];
    let row = 0;
    
    while (current.length) {
        const next = [];
        
        for (let i=0; i<current.length; i++) {
            if (query_row === row && query_glass === i) {
                return Math.min(current[i] || 0, 1);
            }
            if (current[i] > 1) {
                next[i] = (next[i] || 0) + (current[i] - 1) / 2;
                next[i + 1] = (next[i + 1] || 0) + (current[i] - 1) / 2;
            }
        }
        
        if (query_row === row) return 0;
        
        current = next;
        row++;
    }
    
    return 0;
};


//Fastest
/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_glass
 * @return {number}
 */
var champagneTower = function(poured, query_row, query_glass) {
    let cupRow = [poured]
    for (let i = 0; i < query_row; i++) {
        const nextRow = new Array(i+2).fill(0)
        for (let j = 0; j < cupRow.length; j++) {
            let overflow = Math.max(0, cupRow[j] - 1)
            nextRow[j] += overflow/2
            nextRow[j+1] += overflow/2
        }
        cupRow = nextRow
    }
    
    return Math.min(cupRow[query_glass], 1)
};