/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
  if (t.length <= s.length) {
    return;
  }

  let sasci = 0;
  let tasci = 0;
  let sLen = s.length;

  for (let i = 0; i < sLen; i++) {
    sasci += s.charCodeAt(i);
    tasci += t.charCodeAt(i);
  }

  tasci += t.charCodeAt(sLen);

  return String.fromCharCode(tasci - sasci);
};

//Fastest
var findTheDifference = function (s, t) {
  const n = t.length;
  let c = t.charCodeAt(n - 1);

  for (let i = 0; i < n - 1; i++) {
    c ^= s.charCodeAt(i);
    c ^= t.charCodeAt(i);
  }

  return String.fromCharCode(c);
};
