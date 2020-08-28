// O(nlogn) time | O(n) space,
// where: n - length of the intervals array.
var findRightInterval = function(intervals) {
    // E.g. [[3,4], [2,3], [1,2], [5,6]] -> [[1,2], [2,1], [3,0], [5,3]]
    const sortedIntervals = intervals.map((interval, idx) => [interval[0], idx]).sort((a, b) => a[0] - b[0]);
	return intervals.map(([_, endTime]) => getLowerBound(sortedIntervals, endTime));
};

// O(logn) time | O(1) space.
function getLowerBound(sortedIntervals, endTime) {
    let leftIdx = 0;
    let rightIdx = sortedIntervals.length - 1;
    let lastMatch = -1;
    
    while (leftIdx <= rightIdx) {
        const middleIdx = Math.floor((leftIdx + rightIdx) / 2);
        const [startTime, idx] = sortedIntervals[middleIdx];
        if (startTime >= endTime) {
            // We found an interval with a startTime greater than or equal to the endTime.
            // Update lastMatch and keep looking for a better candidate in the left half.
            lastMatch = idx;
            rightIdx = middleIdx - 1;
        } else {
            // Candidate not found, keep looking for it in the right half.
            leftIdx = middleIdx + 1;
        }
    }
    
    return lastMatch;
}

//Fastest
/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
let bs = (arr,ub) => {
    let start = 0,
        end = arr.length-1;
    while(start <= end){
        let mid = ~~((start+end)/2);
        if(arr[mid][0] >= ub) end = mid-1;
        else start = mid+1
    }
    return start;
}
var findRightInterval = function(intervals) {
    let temp  = intervals.map((e,i) => [e[0],i]);
    temp.sort((a,b)=>a[0]-b[0]);
    return intervals.map(ele => {
        let res = bs(temp,ele[1]);
        if(res == intervals.length) return -1;
        return temp[res][1];
    })
};

//Another
var findRightInterval = function(intervals) {
    
    let result = new Array(intervals.length);
    
    function binarySearch(intervals, iThval) {
        
        let start = 0, end = intervals.length - 1;
        
        let index = -1;
        
        while (start <= end) {
            
            let mid = Math.floor((start + end) / 2);
            
            let jThval = intervals[mid];
            
            if (jThval[0] >= iThval[1] && iThval[2] != jThval[2]) {
                
                index = jThval[2];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
        
    for (let i = 0; i < intervals.length; i++) {
        result[i] = -1;
        intervals[i].push(i);
    }
        
    intervals.sort((n1, n2) => {
        return n1[0] - n2[0];
    });
    
    for (let i = 0; i < intervals.length; i++) {
            
        result[intervals[i][2]] = binarySearch(intervals, intervals[i]);
    }
    
    return result;
};