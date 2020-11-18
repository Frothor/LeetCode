var merge = function(intervals) {
    if (intervals.length <= 1) return intervals;
    const ans = [];
    intervals.sort((a, b) => a[0] - b[0]);
    
    for (let interval of intervals) {
        if (ans.length == 0 || interval[0] > ans[ans.length-1][1]) {
            ans.push(interval);
        } else {
            ans[ans.length-1][1] = Math.max(ans[ans.length-1][1], interval[1]);
        }
    }
    
    return ans;
};

//Fourth fastest
var merge = function(intervals) {
    intervals.sort((a, b) => {
        return a[0] - b[0];
    });
    let res = [];
    let [st, en] = intervals[0];
    for(let i = 1; i < intervals.length; i++) {
        let [s, e] = intervals[i];
        if(s > en) {
            res.push([st, en]);
            [st, en] = [s, e];
        } else {
            en = Math.max(en, e);
        }
    }
    res.push([st, en]);
    return res;
};

//Third fastest
var merge = function(intervals) {
    if(!intervals || !intervals.length) return []
    
    const res = []
    const n = intervals.length
    
    intervals.sort((a, b) => a[0] - b[0])
    
    let tmp = intervals[0]
    
    for(let i = 1; i < n; i++) {
        if(tmp[1] >= intervals[i][0]) {
            tmp[1] = Math.max(tmp[1], intervals[i][1])
        }
        else {
            res.push(tmp)
            tmp = intervals[i]
        }
    }
    
    res.push(tmp)
    
    return res
};

//Second fastest
var merge = function(intervals) {    
    if (!intervals.length) { return []; }
    
    intervals.sort(function(a, b) { return a[0] - b[0] });
    
    var result  = [];
    var current = intervals.shift();
    var interval;
    
    while (intervals.length) {
        interval = intervals.shift();
        
        if (interval[0] > current[1]) {
            result.push(current);
            current = interval;
        } else if (interval[1] > current[1]) {
            current[1] = interval[1];
        } 
    }
    
    result.push(current);
    
    return result;
};

//Fastest
var merge = function(intervals) {
    // [[1,3],[2,6],[5,10],[15,18]]
    // temp: [1,3], [1,6], [1, 10]
    // newIntervals: [[1,10]]
    if (!intervals.length) { return intervals }
    
    intervals.sort((a,b) => a[0]-b[0])
    let temp = intervals[0]
    const newIntervals = [temp]
    
    for (let i=1; i<intervals.length; i++) {
        if (intervals[i][0] <= temp[1]) {
            temp = [Math.min(temp[0], intervals[i][0]), Math.max(temp[1], intervals[i][1])]
            newIntervals.pop()
            newIntervals.push(temp)
        }
        else {
            temp = intervals[i]
            newIntervals.push(intervals[i])
        }
    }
    
    return newIntervals
};