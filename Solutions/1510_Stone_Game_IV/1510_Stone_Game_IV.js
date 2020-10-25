// DP problem
var winnerSquareGame = function(n) {

//             //////////////////////////////////
//     1. Define an array that Alice will win or loss (T/F)
//             //////////////////////////////////

    const res = new Array(n+1).fill(false);
    let k = 1;
    
    for (let i = 1; i <= n; i++) {

//             //////////////////////////////////
//     2. if it is square number, obviously, Alice win
//             //////////////////////////////////
        
        if (k*k === i) {
            res[i] = true;
            k++;
            continue;
        }

//             //////////////////////////////////
//     3. after Alice removes j*j (1 <= j < k) stones, find whether res[i-j*j] is T/F (= Bob win/loss)
//        if j exists that res[i-j*j] = false, it means that Bob will lose the game with the remaining i-j*j stones => Alice wins
//        otherwise, Alice lose 
//             //////////////////////////////////

        let AliceWin = false;
        for (let j = 1; j < k && j*j <= i; j++) {
            if (!res[i-j*j]) {
                AliceWin = true;
                break;
            }
        }
        res[i] = AliceWin;
    }
    
    return res[n];
};

//Third fastest
var winnerSquareGame = function(n) {
    return game(n, new Array(1e5))
  };
  
  const game = function(n, dp) {
    if (dp[n] !== undefined) return dp[n]
    for (let i = Math.floor(Math.sqrt(n)); i > 0; i--) {
      const s = i * i
      if (n === s || !game(n - s, dp)) {
        return dp[n] = true
      }
    }
    return dp[n] = false
  }

//Second fastest
var winnerSquareGame = function(n) {
    return game(n, {})
  };
  
  const game = function(n, dp) {
    if (dp[n] !== undefined) return dp[n]
    for (let i = Math.floor(Math.sqrt(n)); i > 0; i--) {
      const s = i * i
      if (n === s || !game(n - s, dp)) {
        return dp[n] = true
      }
    }
    return dp[n] = false
  }

//Fastest
var winnerSquareGame = function(n) {
    const dp = Array(n+1).fill(false);
    for(let i=1;i<=n;i++){
        const end = Math.sqrt(i);
        for(let j=1;j<=end;j++){
            const k = i - j*j;
            if(dp[k] === false) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
};