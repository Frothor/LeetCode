var bagOfTokensScore = function(tokens, P) {
    let score = 0;
    tokens = tokens.sort((a, b) => a - b);

    while (tokens.length) {

        if (tokens[0] > P) {
            return score;
        }
        while (tokens.length && tokens[0] <= P) {
            P -= tokens.shift();
            score += 1
        }

        if (tokens.length > 1 && score) {
            score -= 1;
            P += tokens.pop();
        }
    }

    return score;
};

//Third fastest
/**
 * @param {number[]} tokens
 * @param {number} P
 * @return {number}
 */
var bagOfTokensScore = function(tokens, P) {
    let score =0;
    tokens.sort((x,y)=>x-y);
    
    
    for(let l=0,r=tokens.length-1;l<=r;){
        //if(P<tokens[l] && score===0 ) break;//优化 当能量低于剩下的最小令牌且score=0时 提前退出循环
        
        if(P>=tokens[l]){//能量>=剩下的最小能量 用能量换分
            score++;
            P-=tokens[l++];
        }else if(score>=1 && tokens[r] > tokens[l]){//能量不足以换分 看看能否用分换能量
            score--;
            P+=tokens[r--]
        }else{//能量不足以换分 又无法用分换能量
            // l++
            break;
        }
    }
    
    return score;
};

//Second fastest
var bagOfTokensScore = function(tokens, P) {
    tokens.sort((a,b) => a - b); // order by power
    const score = findMaxScore(tokens, P, 0);
    return score;
  };
  
  function findMaxScore(tokens, P, score) {
    if (tokens.length === 0) return score;
  
    // three actions
    // buy
    // flip
    // do nothing
    let lessTokens = tokens;
  
    if (P >= tokens[0]) {
      let affordableIndex = 0;
      let newP = P;
      do {
        lessTokens = tokens.slice(affordableIndex + 1);
        newP = newP - tokens[affordableIndex];
        affordableIndex += 1;
      } while (newP >= tokens[affordableIndex] && affordableIndex < tokens.length);
      return Math.max(score, findMaxScore(lessTokens, newP, score + affordableIndex));
    } else if (score >= 1) {
      let removedIndex = tokens.length - 1;
      let newP = P;
      let newScore = score;
      do {
        lessTokens = tokens.slice(0, removedIndex);
        newP = newP + tokens[removedIndex];
        removedIndex -= 1;
        newScore -= 1;
      } while(newP < tokens[0] && removedIndex > 0 && newScore >= 1);
      return Math.max(score, findMaxScore(lessTokens, newP, newScore));
    }
    return score;
  }

//Fastest
/**
 * @param {number[]} tokens
 * @param {number} P
 * @return {number}
 */
var bagOfTokensScore = function(tokens, P) {
    let score = 0;
    tokens = tokens.sort((a,b) => a-b);
    
    while (tokens.length) {
        
      if (tokens[0] > P) {
        return score;
      }
        while (tokens.length && tokens[0] <= P) {
          P -= tokens.shift();
          score += 1
        }
      
        if (tokens.length > 1 && score) {
          score -= 1;
          P += tokens.pop();
        }
    }
    
    return score;
  };