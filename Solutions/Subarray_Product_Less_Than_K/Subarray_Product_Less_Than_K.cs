//Sliding window
public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k) {
    
    if(k==0) return 0;
    
    int start=0;
    int end=0;
    int p=1;
    int count=0;
    
    while(end<nums.Length)
    {
        p *= nums[end];
        
        while(start < nums.Length && p>=k)
        {
            p=p/nums[start];
            start++;
        }
        
        if(p<k)
        count+=end-start+1;
        
        end++;
        
    }
    
    return count;
}
}

//Most common
public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k) {
     
        if (nums == null || nums.Length == 0)
            return 0;
        
        int left = 0;
        var prod = 1;
        int upperBound;
        
        var count = 0;
        
        for(int right = 0; right < nums.Length; right++)
        {                    
            prod = prod * nums[right];
            while(prod >= k && left <= right)
            {                
                prod = prod/nums[left];    
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
        
    }
}

//Fastest
public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k) {
     
        if (nums == null || nums.Length == 0)
            return 0;
        
        int left = 0;
        var prod = 1;
        int upperBound;
        
        var count = 0;
        
        for(int right = 0; right < nums.Length; right++)
        {                    
            prod *= nums[right];
            while(prod >= k && left <= right)
            {                
                prod = prod/nums[left];    
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
        
    }
}