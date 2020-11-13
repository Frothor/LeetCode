var permuteUnique = function(nums) {
    let res = [], remain = [], set = new Set(nums);
    nums.forEach(num => remain[num] ? remain[num]++ : remain[num] = 1);
    
    function permute(depth, remain, cur) {
        if (depth == nums.length) {
            res.push(cur.slice());
            return;
        }
        for (let num of set) {
            if (remain[num]) {
                cur.push(num);
                remain[num]--;
                
                // move to the next depth
                permute(depth+1, remain, cur);
                
                // backtrack to previous state
                cur.pop();
                remain[num]++;
            }
        }
        return res;
    }
    return permute(0, remain, []);
};

//Third fastest
var permuteUnique = function(nums) {
    let result = [];
    
    let permutation = [];
    let visited = Array(nums.length).fill(false);
    
    nums.sort(function(a, b) {
        return a - b;
    });

    
    helper(nums, permutation, visited, result);
    
    return result;
};

const helper = function(nums, permutation, visited, result) {
    if (permutation.length === nums.length) {
        result.push(Array.from(permutation));
        return;
    }
    
    for (let i = 0; i < nums.length; i++) {
        if (visited[i] === true) {
            continue;
        }
        
        if (i > 0 && nums[i] === nums[i - 1] && !visited[i - 1]) {
            continue;
        }
        
        permutation.push(nums[i]);
        visited[i] = true;
        
        helper(nums, permutation, visited, result);
        
        permutation.pop();
        visited[i] = false;
    }
}

//Second fastest
var permuteUnique = function(nums) {
    
    let result = [];
    nums.sort();
    helper(nums, [], [], result);
    return result;
};

var helper = function(nums, cur, visited, result) {
    if (cur.length == nums.length) {
        result.push(cur);
    } else {
        for (let i = 0; i < nums.length; i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            let temp = cur;
            cur = [...cur, nums[i]];
            helper(nums, cur, visited, result);
            cur = temp;
            
            visited[i] = false;
        }
    }
}

//Fastest
var permuteUnique = function(nums) {
    const res = [];
    nums.sort();
    function dfs(curr, visited){
        if (curr.length === nums.length){
            res.push(curr.slice());
            return;
        }
        for (let i =0;i < nums.length;i++){
            if (i > 0 && nums[i] === nums[i-1] && !visited[i-1]) continue; //!!!
            if (!visited[i]){
                curr.push(nums[i]);
                visited[i] = true;
                dfs(curr,visited);
                visited[i] = false;
                curr.pop();
            }
        }
    }
    dfs([],{});
    return res;
};