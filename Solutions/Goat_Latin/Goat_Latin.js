//Vowels in set
const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    return S.split(' ').map(
        (word, i) => `${vowels.has(word[0]) ? word : word.slice(1) + word[0]}ma${"a".repeat(i+1)}`
    ).join(' ')
};

//Vowels with regex
/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    return S.split(' ').map(
        (word, i) => `${/[aeiou]/i.test(word[0]) ? word : word.slice(1) + word[0]}ma${"a".repeat(i+1)}`
    ).join(' ')
};

//Fastest
/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    const vowels = { 'a': 1,'e': 1, 'i': 1, 'o': 1, 'u': 1 };
    return S.split(' ').map((w, i) => {
        if (vowels[w[0].toLowerCase()]) {
          return w + 'ma' + 'a'.repeat(i + 1);
        } else {
          return w.slice(1) + w[0] + 'ma' + 'a'.repeat(i + 1);
        }
    }).join(' ')
  };

//Most common
const toGoatLatin = S => {
    const vowelArr = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    const ADD_STR = 'ma'
    let count = 0
    return S
      .split(' ')
      .map(words => {
        if (!vowelArr.includes(words[0])) {
          words = words.slice(1) + words[0]
        }
        count += 1
        return words + ADD_STR + 'a'.repeat(count)
      })
      .reduce((acc, cur) => acc + cur + ' ', '')
      .slice(0, -1)
  }