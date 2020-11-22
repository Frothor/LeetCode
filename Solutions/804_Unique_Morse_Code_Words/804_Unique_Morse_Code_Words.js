//Fourth fastest
//https://leetcode.com/problems/unique-morse-code-words/discuss/652411/JavaScript-concat-fcn-to-build-strings-store-in-set
let uniqueMorseRepresentations = (words) => {
    const ca = 'a'.charCodeAt(0);
    let morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    let record = new Set();
    for (let i in words){
        let trans = "";
        for (let c of words[i])
            trans = trans.concat(morse[c.charCodeAt(0)-ca]);
        record.add(trans);
    }
    return record.size;
};

//Third fastest
/**
 * @param {string[]} words
 * @return {number}
 */
const createDict = () => {
    const morseAlphabet = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    const alphabet = new Array(26).fill(1).map((_, ind) => String.fromCharCode(ind+97));
    return alphabet.reduce((prev, curr, i) => ({...prev, [alphabet[i]]: morseAlphabet[i]}), {});
}

const dict = createDict();

const parseToMorse = (raw) => [...raw].reduce((prev, curr) => prev + dict[curr], '');

const uniqueMorseRepresentations = (words) => {
    return new Set(words.reduce((prev, curr) => [...prev, parseToMorse(curr)], [])).size;
};

//Second fastest
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    const ca = 'a'.charCodeAt(0);
   let morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
   let record = new Set();
   for (let i in words){
       let trans = "";
       for (let c of words[i])
           trans = trans.concat(morse[c.charCodeAt(0)-ca]);
       record.add(trans);
   }
   return record.size;
};

//Fastest
const morseCodes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
const letters = 'abcdefghijklmnopqrstuvwxyz'.split('');
const morse = {};
letters.forEach((letter, i) => {
   morse[letter] = morseCodes[i];
});
/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    const result = {};
    for (const word of words) {
        const mapped = [];
        for (let i = 0; i < word.length; i++) {
            mapped.push(morse[word[i]]);
        }
        result[mapped.join('')] = 1;
    }
    return Object.keys(result).length;
};