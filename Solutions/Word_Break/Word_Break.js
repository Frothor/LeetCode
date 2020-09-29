var wordBreak = function (s, wordDict) {
  const dp = Array(s.length).fill(false);

  for (let i = 0; i < s.length; i++) {
    for (const word of wordDict) {
      let slice = s.slice(i + 1 - word.length, i + 1);

      if (word === slice && ((i - word.length < 0) || dp[i - word.length])) {
        dp[i] = true;
      }
    }
  }
  return dp[dp.length - 1];
};

/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function (s, wordDict) {
  var wd = {};
  var mxl = 0;
  wordDict.forEach((w) => {
    mxl = Math.max(w.length, mxl);
    wd[w] = true;
  });

  var canBreak = new Array(s.length).fill(false);

  if (wd[s[0]]) {
    canBreak[0] = true;
  }

  for (var i = 1; i < s.length; i++) {
    for (var j = i; j >= Math.max(i - mxl + 1, 0); j--) {
      var word = s.slice(j, i + 1);
      canBreak[i] = (wd[word] == true) && (j > 0 ? canBreak[j - 1] : true);
      if (canBreak[i]) {
        break;
      }
    }
  }

  return canBreak[s.length - 1];
};

//Fastest
function wordBreak(s, dict) {
  const dictHashMap = dict.reduce((map, word) => {
    if (!map.has(word[0])) {
      map.set(word[0], []);
    }

    map.get(word[0]).push(word);

    return map;
  }, new Map());

  const cache = new Map();

  function traverse(s, start = 0) {
    if (start === s.length) {
      return true;
    }

    if (!dictHashMap.has(s[start])) {
      return false;
    }

    const possibleWords = dictHashMap.get(s[start]);
    let canBeDecoded = false;

    for (let i = 0; i < possibleWords.length; i++) {
      if (s.startsWith(possibleWords[i], start)) {
        const cacheKey = s.substring(start + possibleWords[i].length);

        if (cache.get(cacheKey) === undefined) {
          cache.set(cacheKey, traverse(s, start + possibleWords[i].length));
        }

        canBeDecoded = canBeDecoded || cache.get(cacheKey);
      }
    }

    return canBeDecoded;
  }

  return traverse(s);
}
