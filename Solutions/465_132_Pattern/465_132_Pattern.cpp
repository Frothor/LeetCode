class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        
        // no 132 pattern possible
        if(n<3) return false;
        
        // track min value in range 0 to i-1
        vector<int>minValues(n,INT_MAX);
        
        // store min values
        for(int i=1;i<n;i++)
            minValues[i] = min(minValues[i-1],nums[i-1]);
        
        stack<int>stak;
        
        // Loop through end to start
        for(int i=n-1;i>=0;i--)
        {
            // pop numbers from stack which are less or equal to minValue[i]
            // find next greater number of minValue[i]
            while(!stak.empty() && stak.top()<=minValues[i])
                stak.pop();
            
            // stack.top < nums[i] then it is a 132 pattern as stack.top > minValue[i]
            if(!stak.empty() && stak.top()< nums[i]) return true;
            
            stak.push(nums[i]);
        }
        
        return false;

    }
};

//Fastest
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // better bruteforce
        const int n = nums.size();
        if (n == 0) return false;
        vector<int> mn(n);
        stack<int> stk;
        mn[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mn[i] = min(mn[i-1],nums[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] <= mn[i]) continue;
            while (!stk.empty() && stk.top() <= mn[i]) stk.pop();
            if (!stk.empty() && stk.top() < nums[i]) return true;
            stk.push(nums[i]);
        }
        return false;
    }
};

/*
- brute force -> O(n^3)
- better brute force
 --> start at each index j, if there j < i and k > i and nums[j] > nums[i] && nums[j] < nums[k] --> return true
 --> worst case: O(n^2) if the array is sorted
- Better idea: may be O(nlogn) solution (sorting)

3 1 4 2
1 3 0 2
2 0 3 1
*/