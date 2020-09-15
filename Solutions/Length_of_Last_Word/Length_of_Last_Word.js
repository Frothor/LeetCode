/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
        let size = 0;
        for (let i = s.length - 1; i > -1; i--) {
            if (s[i] == ' ') {
                if (size == 0) continue; else break;
            }
            size++
        } 
    
    return size
}

//Most common
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    
//     if (!s.includes(" ")) {
//         return s.length;
//     }
    
//     //if (s.endsWith(" ")) {
//     //    return 0;
//     //}
    
//     var words = s.split(" ");
//     var last = words[words.length-1];
//     if (last == null) {
//         last = words[words.length-2];
//     }
//     var length = last.length;
    
//     return length;
    
    if(!s)return 0;
    s=s.trim();
    var seperate_words = s.split(" ");
    var total_word_number=seperate_words.length; // Total number of words in given string 
    return seperate_words[total_word_number-1].length;  // Returning last word's length
};

//Fastest
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let input = s.trim();
    let lastIndex = input.lastIndexOf(" ");
    let result="";
    if (input ==="") {return 0}
    else if (lastIndex+1 >= s.length) {
      result = input.substring(0, lastIndex)
    } else {
      result = input.substring(lastIndex+1,)
    }
    return result.length
};