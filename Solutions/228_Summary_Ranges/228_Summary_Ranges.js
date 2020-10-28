const summaryRanges = nums => {
    let res = [];
    
    for(let end = 0, start = 0; end < nums.length; end++, start = end)
        {
            while(nums[end] === nums[end+1] -1)
                    end++;
            
            if(end !== start)
                res.push(nums[start] + '->' + nums[end])
            else res.push(""+nums[end]);
            
        }
    
    return res;
};

//Third fastest
var summaryRanges = function(nums) {
    // loop the array
    // define a var (startPos) for the start position of increment
    // loop while arr[i]+1==arr[i+1] increment i
    // else add to result array as 2->4 and set startPos to i+1
    
    let startPos=0;
    let result=[];
    let bFound=false;
    for (let i=0; i<nums.length; i++){
        bFound=false;
        startPos=i;
        while(nums[i] + 1 === nums[i+1] && i+1<nums.length){
            i++;
            bFound=true;
        }
        if (bFound){
            result.push(nums[startPos] + '->'+ nums[i]);
        }else{
            result.push(nums[i].toString());
        }
    }
    return result;
}

//Second fastest
var summaryRanges = function (nums) {
    let answer = [];
    let prev = nums[0];
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] + 1 !== nums[i + 1]) {
        if (prev !== nums[i]) {
          answer.push(`${prev}->${nums[i]}`);
        } else {
          answer.push(`${nums[i]}`);
        }
        prev = nums[i + 1];
      }
    }
    return answer;
  };

//Fastest
var summaryRanges = function(nums) {
    let len = nums.length;
    if(len == 0) return [];
    if(len == 1) return ["" + nums[0]];
    
    var res = [];
    var start = 0;
    
    for(var i = 0; i < len - 1;i++){
        if(nums[i + 1] - nums[i] != 1){
            if(start == i){
                res.push("" + nums[i])
            }else{
                res.push(nums[start] + '->' + nums[i]);
            }
            start = i + 1;
        }
    }
    
    if(start == len - 1){
        res.push("" + nums[len - 1]);
    }else{
        res.push(nums[start] + '->' + nums[len - 1]);
    }
    
    return res;
    
};