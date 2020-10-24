/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    // sanity check
    if (nums.length < 3) return false;

    let N2 = []; // potential candidates, number 2
    let N1 = [nums[0]]; // the smallest number, number 3

    for (let i=1;i<nums.length;i++) { 
        N1.push(Math.min(N1[N1.length-1], nums[i]));
    }

    for (let i=nums.length-1;i>=0;i--) { // number 3
        if (nums[i] > N1[i]) {
            // remove useless N2 candidates
            while (N2.length!=0 && N2[N2.length-1] <= N1[i]) N2.pop();
            // found a pattern
            if (N2.length!=0 && N2[N2.length-1] < nums[i]) return true;
            N2.push(nums[i]);
        }
    }
    return false;
}

//Third fastest
var find132pattern = function(nums) {
    if (!nums || nums.length < 3)
        return false;
    
    const LEN = nums.length;
    let mins = [nums[0]];
    for(let i = 1 ;i < LEN; i++) 
        mins[i] = Math.min(mins[i - 1], nums[i]);
    
    let stack = [];
    for(let i = LEN - 1 ; i > 0; i--) {
        while(stack.length > 0 && stack[stack.length - 1] <= mins[i])
            stack.pop();
        
        if(stack.length > 0 && stack[stack.length - 1] < nums[i])
            return true;
        
        stack.push(nums[i]);
    }
    
    return false;
};

//Second fastest
var find132pattern = function(nums) {
    if(!nums || nums.length<3) return false;
    
    const stack = [];
    
    for(let i=0;i<nums.length;i++) {
        if(!stack.length || stack[stack.length-1][0]>nums[i]) {
            stack.push([nums[i], nums[i]]);
        } else if (nums[i]>stack[stack.length-1][0]) {
            const last = stack.pop();
            
            if(nums[i]<last[1]) {return true;}
            else {
                last[1] = nums[i];
                
                while(stack.length && last[1]>stack[stack.length-1][1]) {
                    stack.pop();
                }
                
                if(stack.length && stack[stack.length-1][0]<last[1]) return true;
                
                stack.push(last);
            }
        }
    }
    
    return false;
};

//Fastest
var find132pattern = function(nums) {
    let stack=[]
    let s3=Number.NEGATIVE_INFINITY
    for(let i=nums.length-1; i>=0; i--) {
        if(nums[i] < s3) return true
        while(stack.length>0 && stack[stack.length-1] < nums[i]) {
            s3=stack.pop()
        }
        stack.push(nums[i])
    }
    
    return false
};