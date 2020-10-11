//Most common
/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    const map = new Map(); // character frequency map
    for (let ch of s) {
        if (!map.has(ch)) {
            map.set(ch, 0);
        }
        map.set(ch, map.get(ch) + 1);
    }
            
    const seq = [];
    const setSeq = new Set();
    for (let i = 0; i < s.length; i += 1) {
        const ch = s[i];
        // update frequency
        if (map.get(ch) > 1) {
            map.set(ch, map.get(ch) - 1);
        } else {
            map.delete(ch);
        }
        
        // check if character i is smaller than character i-1 (last) and another occurrence of character i-1 exists later in the string. If so delete character i-1.
        if (setSeq.has(ch)) {
            // already exists in seq, ignore
            continue;
        }
        while ((seq.length > 0) && (ch < seq[seq.length - 1]) && map.has(seq[seq.length - 1])) {
            const last = seq.pop();
            setSeq.delete(last);
        }
        seq.push(ch);
        setSeq.add(ch);
    }
    
    return seq.join('');
};

//Third fastest
/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    const posCnt = new Array(26).fill(0);
    for(let i = 0; i < s.length; i++) {
        const pos = s.charCodeAt(i) - 97;
        posCnt[pos] = i;
    }
    const visited = new Set();
    let res = [];
    for(let i = 0; i < s.length; i++) {
        const cur = s.charCodeAt(i) - 97;
        if(!visited.has(cur)) {
            while(res.length > 0 && res[res.length - 1] > cur && posCnt[res[res.length - 1]] > i) {
                visited.delete(res.pop());
            }
            res.push(cur);
            visited.add(cur);
        }
    }
    return res.reduce((str, c) => {
        return str + String.fromCharCode(c + 97);
    }, '');
};

//Second fastest
/**
 * @param {string} s
 * @return {string}
 */

//  This is 1081's solution 
var removeDuplicateLetters = function(s) {
    let last = {}, stk = []
    s.split('').forEach((c, i) => last[c] = i)
    s.split('').forEach((c, i) => {
      if (!stk.includes(c)) {
        while (stk.length &&
          stk[stk.length - 1].charCodeAt() > c.charCodeAt() &&
          last[stk[stk.length - 1]] > i) {
          stk.pop()
        }
        stk.push(c)
      }
    })
    return stk.join('')
  };
  
  //  The 1081's solution is easy to understand
  var removeDuplicateLetters2 = function(s) {
    if (s.length == 0) return '';
    let cnt = {};
    s.split('').forEach(c => {
      cnt[c] = ~~cnt[c] + 1;
    });
  
    let minChar = String.fromCharCode('z'.charCodeAt() + 1);
    let minIdx = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < s.length; i++) {
      if (minChar > s[i]) {
        minChar = s[i];
        minIdx = i;
      }
  
      cnt[s[i]] = cnt[s[i]] - 1;
      if (cnt[s[i]] == 0) {
        let ss = s.substring(minIdx + 1);
        while (ss.match(minChar)) {
          ss = ss.replace(minChar, '');
        }
  
        return minChar + removeDuplicateLetters(ss);
      }
    }
  
    return '';
  };

//Fastest
var removeDuplicateLetters = function(s) {
    const stack = [];
    const seen = new Set();
    const lastOcurrence = {};
    
    for(let i = 0; i < s.length; i++)
        lastOcurrence[s[i]] = i;
    
    for(let i = 0; i < s.length; i++){
        const ch = s[i];
        if(!seen.has(ch)){
            while(stack.length > 0){
               const ls = stack[stack.length-1];
                if(ch < ls && lastOcurrence[ls] > i){
                    stack.pop();
                    seen.delete(ls);
                }else{
                    break;
                }
            }
            stack.push(ch);
            seen.add(ch);
        }
    }
    
    
    return stack.join("");
};