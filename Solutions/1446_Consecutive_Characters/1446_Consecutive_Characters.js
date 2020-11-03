var maxPower = function (s) {
  if (!s.length) return 0;
  let max = 1;
  let continueCount = 1;
  for (let i = 1; i < s.length; i++) {
    if (s[i] === s[i - 1]) {
      max = Math.max(max, ++continueCount);
    } else {
      continueCount = 1;
    }
  }
  return max;
};

//Fourth fastest
var maxPower = function(s) {
    let curCount= 1;
    let maxCount = 0;
    for(let i=0; i<s.length; i++){
        if(s[i]==s[i+1]){
            curCount++;
        } else {
            if(maxCount<curCount){
                maxCount=curCount;
            }
            curCount = 1;
        }
    }
    return maxCount;
};

//Third fastest
const maxPower = (s) => {
    let max = 0, char = s[0], freq = 1;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === char) freq++; 
        else {
            max = Math.max(max, freq);
            freq = 1;
            char = s[i];
        }
    }
    return Math.max(max, freq)
};

//Second fastest
var maxPower = function(s) {
    const a = s.split('');
    const powers = [];
    let maxPower = 0;
    let currentPower = 0;
    let j = 0;
    for(i = 0; i < a.length; i++) {
        currentPower = 1
        while(a[i] == a[i+1]) {
            ++currentPower
            ++i;
        }
        maxPower = maxPower > currentPower ? maxPower : currentPower;
    }
    
    return maxPower;
};

//Fastest
var maxPower = function(s) {
    let count = 1;
     let max = 1;
     for(let i = 0;i<s.length-1;i++){
         if(s[i]==s[i+1]){
             count++;
             if(count>max){
                 max = count;
             }
         }else{
          count = 1;
         }
     }
     return max;
 };