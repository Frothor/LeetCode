/**
 * @param {number[]} arr
 * @param {number} start
 * @return {boolean}
 */
var canReach = function(arr, start) {

    function callDFS(idx) {
        if(arr[idx] === 'seen' || idx < 0 || idx >= arr.length) return false;
        if(!arr[idx]) return true;
        const move = arr[idx]; arr[idx] = 'seen';
        return callDFS(idx - move) || callDFS(idx + move);
    }
    return callDFS(start);
};

//Third fastest
var canReach = function(arr, start) {
    const visited = new Set();
    return jump(arr, start);
    
    function jump(arr, start) {
        const n = arr.length;
        if (start < 0 || start >= n) return false;
        if (arr[start] === 0) return true;
        if (visited.has(start)) {
            return false;
        } else {
            visited.add(start);
        }

        return jump(arr, start + arr[start]) || jump(arr, start - arr[start]);
    }
};


//Second fastest
var canReach = function(arr, start, indexes = []) {
    
    if(arr[start] === 0)
        return true;
    else if(indexes.includes(start))
        return false;
    
    indexes.push(start);
    
    let newStart = start - arr[start];    
    if(newStart >= 0)
        if(canReach(arr, newStart, indexes))
            return true;
    
    newStart = start + arr[start];
    if(newStart < arr.length)
        if(canReach(arr, newStart, indexes))
            return true;
    
    return false;
    
};

//Fastest
var canReach = function(arr, start) {
    function find0(input, i) {
        let visited = {};
        function jump(input, jumpTo) {
        //console.log(jumpTo);
        if (input[jumpTo] == 0) return true;
        if (jumpTo < 0 || jumpTo > input.length) return false;
        if (visited[jumpTo]) return false;

        visited[jumpTo] = true;

        return (
             jump(input, jumpTo + input[jumpTo]) || jump(input, jumpTo - input[jumpTo])
        );
  }

  return jump(input, i);
    }
    
    return find0(arr, start)
};