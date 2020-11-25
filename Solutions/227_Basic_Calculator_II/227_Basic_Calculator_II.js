//https://leetcode.com/problems/basic-calculator-ii/discuss/597084/Javascript-stack-O(N)
/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
  let stack = [];
  let num = '';
  let sign = null
  // we loop till the full length of the array to account for last sign
  for(let i = 0; i <= s.length; i++){    
    const curr = s[i];
    //handle space
    if(curr === ' ') continue;
    //if char is a number
    if(!isNaN(curr)) num+=curr;
    //if we have a  sign + - / *
    if(isNaN(curr)){
      num = Number(num)
      switch(sign){
        case '+':
        case null:
          //we push the initial number into the stack
          stack.push(num)
          break;
        case '-':
          //we push any values after the subtraction sign as negative
          stack.push(-num)
          break; 
        case '*':
          //we pop the stack then multiply and push back
          stack.push(stack.pop()*num)
          break;
        case '/':
          //we pop the stack then devide and push back
          stack.push(parseInt(stack.pop()/num, 10))
          break;           
      }
      // sign becomes current sign
      sign = curr;
      // we reset num
      num = '';
    }
  }
  //we reduce the array adding positive and negative numbers
  return stack.reduce((a,b)=>{
    return a+b
  },0)
};

//Third fastest
var calculate = function(s) {
    const stack = []
    let num = 0
    let operator = '+'
    let i = 0
    
    while (i < s.length) {
        const char = s[i]
                
        if (isDigit(char)) {
            let curr = 0
            while (i < s.length && isDigit(s[i])) {
                curr *= 10
                curr += +s[i]
                i++
            }
            
            if (operator === '+') {
                stack.push(curr)
            } else if (operator === '-') {
                stack.push(-curr)
            } else if (operator === '/') {
                stack.push(Math.trunc(stack.pop() / curr))
            } else if (operator === '*') {
                stack.push(stack.pop() * curr)
            }
            
            continue
        }
        
        if (char !== ' ') operator = char
        i++
        continue
    }
    
    let result = 0
    while (stack.length) {
        result += stack.pop()
    }
    return result
};

const isDigit = char => char >= '0' && char <= '9'

//Second fastest
var calculate = function(s) {
    s = s.replace(/\s+/g,'');
    var stack = []
    var num = 0
    var sign = '+';
        
    for(var i = 0;i < s.length;i++){
        let c = s[i];
        // console.log(stack);
        if(c >=0 && c <= 9){
            num = num * 10 + c * 1;
        }
        if(['+','-','*','/'].indexOf(c) > -1 || i == s.length - 1){
            if(sign == '+'){
                stack.push(num);
            }else if(sign == '-'){
                stack.push(-num);
            }else if(sign == '*'){
                stack.push(stack.pop() * num)
            }else if(sign == '/'){
                stack.push((stack.pop() / num) >> 0);
            }
            sign = c;
            num = 0;
        }
    }
    
    return stack.reduce((accu,cur) => accu + cur,0);
};

//Fastest
var calculate = function(s) {
    if (s.length === 0) {
       return 0;
   }
   
   s = s.replace(/\s+/g, "");

   let op = '+';
   let stack = [];
   let n = "";
   
   for (let i=0; i <= s.length; i++) {
       let c = s[i]
        
       if(c >= '0' && c <= '9') {
           n += c;
       } else {
           if (op === '+') {
               stack.push(parseInt(n));
           } else if (op === '-') {
               stack.push(parseInt(-n))
           } else if (op === '*') {
               stack.push(stack.pop() * parseInt(n));
           } else if (op === '/') {
               stack.push(Math.trunc(stack.pop() / parseInt(n)));
           }
       
           op = c;
           n = "";  
       }
   }
   // return the sum of the stack.
   return stack.reduce((a,b) => a+b, 0); 
};