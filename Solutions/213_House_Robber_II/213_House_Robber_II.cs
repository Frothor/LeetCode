public class Solution {
    int[,] dp;
    public int Rob(int[] nums) {
        dp = new int[nums.Length, 2];
        
        for(int i = 0; i < nums.Length; i++) {
            dp[i, 0] = -1; dp[i, 1] = -1;
        }
        
        return RobUtil(nums, 0, 0);
    }
    
    private int RobUtil(int[] nums, int index, int flag) {
        if(index >= nums.Length)
            return 0;
        
        if(index == nums.Length - 1 && flag == 1)
            return 0;
        
        if(dp[index, flag] != -1)
            return dp[index, flag];
        
        int rob = nums[index] + RobUtil(nums, index + 2, index == 0 ? 1 : flag);
        int notRob = RobUtil(nums, index + 1, flag);
        
        dp[index, flag] = Math.Max(rob, notRob);
        
        return dp[index, flag];
    }
}

//Second fastest
public class Solution {
    public static int RobExcludeLast(int[] nums, int start, int end)
        {
          
            int[] dp = new int[nums.Length + 2];
            dp[1] = 0;
            dp[2] = nums[start];

            for (int i = start + 1; i <= end; i++)
            {
                dp[i + 1] = Math.Max(nums[i] + dp[i - 1], dp[i]);
            }

            return dp[end + 1];
        }
    
        public static int RobIncludeFirst(int[] nums, int start, int end)
        {
            
            int[] dp = new int[nums.Length+1];
            dp[0] = 0;
            dp[1] = nums[start];

            for (int i = start+1; i <= end; i++)
            {
                dp[i+1] = Math.Max(nums[i] + dp[i - 1], dp[i]);
            }

            return dp[end+1];
        }
    public int Rob(int[] nums) {
        
            if (nums.Length == 0) return 0;
            if (nums.Length == 1) return nums[0];
            if (nums.Length == 2) return Math.Max(nums[0], nums[1]);
        
        var result = Math.Max(RobIncludeFirst(nums, 0, nums.Length - 2), RobExcludeLast(nums, 1, nums.Length - 1));
        return result;
    }
}

//Fastest
public class Solution {
     public int Rob(int[] nums)
            {
                int[] runningTotal = new int[nums.Length];
                if (nums.Length == 0) return 0;
                if (nums.Length == 1) return nums[0];
                if (nums.Length == 2) return Math.Max(nums[0], nums[1]);

                int arr1 = check(nums, 0, nums.Length - 2);
                int arr2 = check(nums, 1, nums.Length - 1);

                return Math.Max(arr1, arr2);
            }

            private int check(int[] nums, int st, int en)
            {
                int end = en - st + 1;
                int[] runningTotal = new int[end];

                runningTotal[0] = nums[st];
                runningTotal[1] = Math.Max(nums[st], nums[st + 1]);

                int loop = st == 0 ? end : end + 1;

                for (int i = st+2; i<loop; i++)
                {
                    runningTotal[i-st] = Math.Max(nums[i] + runningTotal[i-st-2], runningTotal[i-st-1]);
                }

                return runningTotal[runningTotal.Length - 1];
            }
}