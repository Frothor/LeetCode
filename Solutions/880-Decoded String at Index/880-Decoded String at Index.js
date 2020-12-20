//Second fastest
//https://leetcode.com/problems/decoded-string-at-index/discuss/967895/JavaScript-solution-100-faster
var decodeAtIndex = (s, K) => {
  let [id, length, i] = [K, 0, 0];
  while (i < s.length && length < K) {
    if (isNumber(s[i]))
      length *= parseInt(s[i]);
    else
      length++;
    i++;
  }
  //length <= K;
  i--;
  while ( i >= 0 && ( length > id || isNumber(s[i]) ) ) {
    if (isNumber(s[i])) {
      length /= parseInt(s[i]);
      id = id % length ? id % length : length;
    }
    else
      length--;
    i--;
  }
  return s[i];
}

const isNumber = (char) => '0' <= char && char <= '9';

//Another
var decodeAtIndex = (s, K) => {
  let [id, length, i] = [K, 0, 0];
  while (i < s.length && length < K) {
    if (isNumber(s[i]))
      length *= parseInt(s[i]);
    else
      length++;
    i++;
  }
  //length <= K;
  i--;
  while ( i >= 0 && ( length > id || isNumber(s[i]) ) ) {
    if (isNumber(s[i])) {
      length /= parseInt(s[i]);
      id = id % length ? id % length : length;
    }
    else
      length--;
    i--;
  }
  return s[i];
}

const isNumber = (char) => '0' <= char && char <= '9';

//Fastest
var decodeAtIndex = (s, K) => {
  let [id, length, i] = [K, 0, 0];
  while (i < s.length && length < K) {
    if (isNumber(s[i]))
      length *= parseInt(s[i]);
    else
      length++;
    i++;
  }
  //length <= K;
  i--;
  while ( i >= 0 && ( length > id || isNumber(s[i]) ) ) {
    if (isNumber(s[i])) {
      length /= parseInt(s[i]);
      id = id % length ? id % length : length;
    }
    else
      length--;
    i--;
  }
  return s[i];
}

const isNumber = (char) => '0' <= char && char <= '9';