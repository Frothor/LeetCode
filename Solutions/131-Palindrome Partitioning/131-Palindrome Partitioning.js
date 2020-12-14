//Third fastest
const isPalindrome = (s, left, right) => {
    while (left < right) {
        if (s[left] !== s[right]) return false
        left++
        right--
    }
    return true
}

const recurse = (str, ptr, progress, valid) => {
    if (ptr === str.length) {
        valid.push([...progress])
    } else {
        for (let i=ptr; i<str.length; i++) {
            if (isPalindrome(str, ptr, i)) {
                let snippet = str.substring(ptr, i+1)
                progress.push(snippet)
                recurse(str, i+1, progress, valid)
                progress.pop()
            }
        }
    }
}

const partition = str => {
    let validDecomp = []
    let decompInProgress = []
    recurse(str, 0, decompInProgress, validDecomp)
    return validDecomp
}

//Second fastest
var partition = function(s) {
    const result = [];
    recurse(0, s, [], result);
    return result;
};

function recurse(start, s, currList, result) {
    if(start >= s.length) { 
        result.push(Array.from(currList));
    }
    for(let end = start; end < s.length; end++) {
        if(isPalin(s, start, end)) {
            currList.push(s.substring(start, end+1));
            recurse(end+1, s, currList, result);
            currList.pop();
        }
    }
}

function isPalin(s, low, hi) {
    while(low < hi) {
        if(s.charAt(low) != s.charAt(hi)) {
            return false;
        }
        low++;
        hi--;
    }
    return true;
}

//Fastest
var partition = function(s) { const res = new Set();
    if (s.length === 0) return [];
    
    const isPal = (start, end) => {
        while (start<=end) {
            if(s[start] !== s[end]) return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    const helper = (position, cur) => {
        if(position === s.length) {
            res.add([...cur]);
            return;
        }
        
        for(let i=position; i<s.length;i++) {
            if(isPal(position, i)) {
                cur.push(s.substring(position, i+1));
                helper(i+1, cur);
                cur.pop();
            }
        }
    }
    
    helper(0, []);
    
    return [...res];
};