/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function (pattern, str) {
    const patternAry = pattern.split('');
    const strAry = str.split(' ');
    const helper = input => {
        let rule = '';
        let elements = [];
        for (let i = 0; i < input.length; i++) {
            if (!elements.includes(input[i])) elements.push(input[i]);
            rule += input.indexOf(input[i]);
        }
        return rule;
    }
    return helper(patternAry) === helper(strAry);
};

//Fastest
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function (pattern, str) {
  var arr = str.split(' ');
  if (arr.length !== pattern.length) {
    return false;
  }
  var map = new Map();
  var map2 = new Map();
  for (var i = 0; i < pattern.length; i++) {
    map.set(pattern[i], arr[i]);
    map2.set(arr[i], pattern[i]);
  }
  for (var j = 0; j < pattern.length; j++) {
    if (map.get(pattern[j]) !== arr[j]) {
      return false;
    }
    if (map2.get(arr[j]) !== pattern[j]) {
      return false;
    }
  }
  return true;
};

//Another one
var wordPattern = function(pattern, str) {
    const words = str.split(/\s+/);
    const map = new Map();
    
    if(words.length !== pattern.length) return false;
    if(new Set(words).size !== new Set(pattern).size) return false;
    
    for(let i = 0; i < pattern.length; i++) {
        if(map.has(pattern[i]) && 
           map.get(pattern[i]) !== words[i]) return false;
        map.set(pattern[i], words[i]);
    }
    return true;
};