//https://leetcode.com/problems/decode-string/discuss/245538/Javascript-using-Regex.
/**
 * @param {string} s
 * @return {string}
 */
function decodeString1(s) {
    return s.replace(/(\d+\[\w+\])/gi, function(item) {
        var match = /(\d+)\[(\w+)\]/.exec(item);
        var repeat = parseInt(match[1]);
        var pattern = match[2];
        
        var result = "";
        while(repeat-- > 0) {
            result += pattern;
        }
        return result;
    });
};

var decodeString = function(s) {
    while(/\d+\[\w+\]/gi.test(s)) {
        s = decodeString1(s);
    }
    return s;
};

//Fourth fastest
var decodeString = function (s) {
    const ans = [];
  
    for (const char of s) {
      if (char === ']') {
        let cur = ans.pop();
        let str = '';
  
        while (cur !== '[') {
          str = cur + str;
          cur = ans.pop();
        }
  
        let num = '';
        cur = ans.pop();
        while (!isNaN(cur)) {
          num = cur + num;
          cur = ans.pop();
        }
  
        ans.push(cur);
        ans.push(str.repeat(Number(num)));
      } else {
        ans.push(char);
      }
    }
  
    return ans.join('');
  };

//Third fastest
/**
 * @param {string} s
 * @return {string}
 */

/*
The pattern could begin with a number K, followed by opening brace '[', followed by a string
    - Then it could be immediately closed by a ']'
    - Or, there could be another nested pattern     K[string K[string]] 

- If there is a nested pattern, we have to decode the innermost pattern first
    - Push each character into the stack until we meet a ']'
    - Once we meet a ']', we start decoding the pattern 
    
    
1) 2 Stacks, one for numbers, one for substring
2) If we see a number, push into numberStack
3) When we meet an opening bracket, 
    
    
    // approach: stack
    // loop thru string
    // if s[i] is a number, add that to the numStack
    // if "[", you know its the start of a current string of letters
    ///if "]", the current string ends and is repeated for numstack.pop() times
    // add above to a strStack
    
    
    s = "3[a]2[bc]"
    
    currNum = '3'
    
*/

var decodeString = function(s) {
    
    let numStack = []
    let stringStack = []
    let currString = ''
    let currNum = ''
    
    for (let i = 0; i < s.length; i++) {
        let element = s[i]
        
        // Is a number
        if (isNaN(element) === false) {
            currNum += element
        }
            
        // We know the number just ended. 
        else if (element === '[') {
            numStack.push(Number(currNum))
            currNum = ''
            stringStack.push(currString)
            currString = ''
        }
        
        else if (element === ']') {
            let count = numStack.pop()
            currString = stringStack.pop() + currString.repeat(count)
        }
        
        // We are dealing with a string
        else {
            currString += element
        }        
    }
    
    return currString
};

//Second fastest
var decodeString = function(s) {
    // base case ""
       //if (s.length == 0) return "";
      
       let index = 0, sb = '';
       while (index < s.length) {
           let c = s.charAt(index);
           if (isNaN(c)) {
               sb += c;
               index++;
           } else if (!isNaN(c)) {
               let end = index;
               while (!isNaN(s.charAt(end))) end++;
               let num = parseInt(s.substring(index, end));
               index = end;
               let open = 1;
               end++;
               while (end < s.length && open !== 0) {
                   if (s.charAt(end) == '[') open++;
                   else if (s.charAt(end) == ']') open--;
                   end++;
               }
               let encoded = decodeString(s.substring(index+1, end-1));
               for (let i = 0; i < num; i++) sb += encoded;
               index = end;
           }
       }
   //console.log(sb)
       return sb;
  
};

decodeString("3[a2[c]]")


//Fastset
var decodeString = function(s) {
    // base case ""
       if (s.length == 0) return "";
      
       let index = 0, sb = '';
       while (index < s.length) {
           let c = s.charAt(index);
           if (isNaN(c)) {
               sb += c;
               index++;
           } else if (!isNaN(c)) {
               let end = index;
               while (!isNaN(s.charAt(end))) end++;
               let num = parseInt(s.substring(index, end));
               index = end;
               let open = 1;
               end++;
               while (end < s.length && open !== 0) {
                   if (s.charAt(end) == '[') open++;
                   else if (s.charAt(end) == ']') open--;
                   end++;
               }
               let encoded = decodeString(s.substring(index+1, end-1));
               for (let i = 0; i < num; i++) sb += encoded;
               index = end;
           }
       }
       return sb;
  
};
