//Most common
public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        int a = Int32.MaxValue;
        int b = Int32.MaxValue;
        
        for(int i=0; i<nums.Length; i++){
            if(nums[i] < a)
                a= nums[i];
            else if(a < nums[i] && b > nums[i])
                b = nums[i];
            else if(nums[i] > b)
                return true;
        }
        
        return false;
    }
}

//Third fastest
public class Solution {
    /*public bool IncreasingTriplet(int[] arr) {
        if(arr==null || arr.Length<3)
            return false;
        
        int n = arr.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        
        for(int i=0; i<n; i++)
            left[i]=int.MaxValue;
        
        for(int i=0; i<n; i++)
            right[i]=int.MinValue;
        
        for(int i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1] || arr[i]>left[i-1])
                left[i] = Math.Min(arr[i-1], left[i-1]);
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]<arr[i+1] || arr[i]<right[i+1])
                right[i]=Math.Max(arr[i+1], right[i+1]);
        }
        
        for(int i=1; i<n-1; i++)
        {
            if(left[i]<arr[i] && arr[i]<right[i])
                return true;
        }
        
        return false;
    }*/
    
    public bool IncreasingTriplet(int[] arr) {
        if(arr==null || arr.Length<3)
            return false;
        
        int n = arr.Length;
        int f_num=int.MaxValue;
        int s_num=int.MaxValue;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=f_num)
                f_num=arr[i];
            else if(arr[i]<=s_num)
                s_num=arr[i];
            else
                return true;
        }
        
        return false;
    }
}

//Second fastest
public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        
        // Calculate max1 array
        var max1 = new int[nums.Length];
        max1[0] = nums[0];
        for(var i = 1; i < nums.Length; i++)
        {
            max1[i] = Math.Min(nums[i], max1[i - 1]);
        }
        
        // Calculate max2 array
        var max2 = new int[nums.Length];
        Array.Fill(max2, int.MaxValue);
        for(var i = 1; i < nums.Length; i++)
        {
            if(nums[i] > max1[i -1])
            {
                max2[i] = Math.Min(nums[i], max2[i - 1]);
            } 
            else 
            {
                max2[i] = max2[i - 1];
            }
        }
        
        // Last pass to find the first number
        // that larger than what specified in max2
        for(var i = 1; i < nums.Length; i++)
        {
            if(nums[i] > max2[i - 1])
            {
                return true;
            }
        }
        return false;
    }
}

//Fastest
public class Solution {
    public bool IncreasingTriplet(int[] nums) {
        int[] seq = new int[3];
        Array.Fill(seq,Int32.MaxValue);
        for(int i=0; i<nums.Length; i++)
        {
            for(int j=0; j<seq.Length; j++)
            {
                if(nums[i] <= seq[j])
                {
                    seq[j] = nums[i];
                if(j+1 == seq.Length)
                    return true;
                    break;
                }
            }
        }
        return false;
    }
}