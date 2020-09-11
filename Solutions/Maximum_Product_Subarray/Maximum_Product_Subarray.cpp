class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =  nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        int result = nums[0];
        
        for(int i=1; i<n; i++) {
            if(nums[i] > 0) {
                dp1[i] = max(dp1[i-1] * nums[i], nums[i]);
                dp2[i] = dp2[i-1] * nums[i];
            } else {
                dp1[i] = dp2[i-1] * nums[i];
                dp2[i] = min(dp1[i-1] * nums[i], nums[i]);
            }
            result = max(result, dp1[i]);
        }
        
        return result;
    }
};

//Better
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
		// empty array case
		if (nums.size() == 0)
			return 0;
			
	    // maxSub and minSub will hold the products till nums[i]
        int maxSub = nums[0];   
        int minSub = nums[0];
        int maxProductSub = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++)
        {
            // element is negative so we swap max and min
            // because when multiplying negative with a negative, number becomes positive so minimum negative number will become the maximum number
            if (nums[i] < 0)
                swap(minSub, maxSub);
      
            // update all the sub values
			maxSub = max(maxSub * nums[i], nums[i]); 
            minSub = min(minSub * nums[i], nums[i]); 
            // choose max product to be the max between the maxProduct till now and maxSub
			maxProductSub = max(maxProductSub, maxSub); 
        }
		
        return maxProductSub;
    }
   
};

//Fastest
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0], ma=nums[0], mi=nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]<0)
                swap(ma, mi);
            
            ma = max(ma*nums[i], nums[i]);
            mi = min(mi*nums[i], nums[i]);
            res = max(res, ma);
        }
        return res;
    }
};