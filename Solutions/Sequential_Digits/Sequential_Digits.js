var sequentialDigits = function(lowBound, upBound) {
    let q = new Queue();
    for(let i = 1; i <= 9; i++) q.enqueue(i);

    let res = [];
    
    while(!q.isEmpty()) {
        let f = q.dequeue();

        if(f <= upBound && f >= lowBound)
            res.push(f);
        
        if(f > upBound) break;
        
        let lastDigit = f % 10;
        
        if(lastDigit < 9)
            q.enqueue(f * 10 + (lastDigit + 1));
        
    }
    
    return res;
};

//Fastest
/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
var sequentialDigits = function(low, high) {
    const a = [1,2,3,4,5,6,7,8,9,0];
    const ones = [1,1,1,1,1,1,1,1,1,1];
    const seq = [];

    let l = (''+low).length;
    let start = +a.slice(0, l).join('');
    let step = +ones.slice(0, l).join('');
    
    while (start <= high) {
        if (low <= start) {
            seq.push(start);
        }
        
        start+=step;
        
        if(start % 10 === 0) {
            l++;
            start = +a.slice(0, l).join('');
            step = +ones.slice(0, l).join('');
        }
    }
    
    return seq;
};