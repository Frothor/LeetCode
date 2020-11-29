public class Solution {
    public bool CanPartition(int[] nums) {
        if(nums.Length == 0 || nums.Length == 1)
            return false;
        int sum = 0;
        foreach(var n in nums)
            sum += n;
        
        if(sum%2 != 0)
            return false;
        
        int target = sum/2;
        
        var dp = new bool[target+1];
        
        if(nums[0] <= target)
            dp[nums[0]] = true;
        
        for(int i = 1; i<nums.Length; i++){
            int num = nums[i];
            for(int j = target; j>=0; j--){
                if(num <= j)
                    dp[j] |= dp[j-num];
                else
                    break;
            }
            if(dp[target])
                return true;
        }
        
        return dp[target];
    }
}

//Fourth fastest
public class Solution {
    public bool CanPartition(int[] nums) {
        if(nums == null || nums.Length == 0) return false;
        int sum=0;
        for(int i=0;i<nums.Length;i++)
        {
            sum += nums[i];
        }
        
        if(sum%2 != 0) return false;
        int subSetSum = sum/2;
        
        bool?[,] memo = new bool?[nums.Length+1, subSetSum+1];
        
        return dfs(nums, subSetSum, nums.Length-1, memo);
    }
    
    private bool dfs(int[] nums, int subSetSum, int n, bool?[,] memo)
    {
        if(subSetSum == 0)
        {
            return true;
        }
        
        if(subSetSum < 0 || n == 0)
        {
            return false;
        }
        
        if(memo[n, subSetSum] != null)
        {
            return memo[n, subSetSum].Value;
        }
        
        bool value = dfs(nums, subSetSum - nums[n], n-1, memo) || dfs(nums, subSetSum, n-1, memo);
        memo[n, subSetSum] = value;
        
        return value;
    }
}

//Third fastest
public class Solution {
    bool?[,] memo;
    public bool CanPartition(int[] nums) {
        var sum = 0;
        for(int i=0; i<nums.Length; i++) {
            sum = sum + nums[i];
        }
        if(sum % 2 == 1) {
            return false;
        }
        memo = new bool?[nums.Length,(sum/2)+1];
        return FindSum(nums, 0, sum/2);
    }
    
    private bool FindSum(int[] nums, int startIndex, int targetSum) {
        if(targetSum == 0) {
            return true;
        }
        if(startIndex == nums.Length) {
            return false;
        }
        if(memo[startIndex, targetSum].HasValue) {
            return memo[startIndex, targetSum].Value;
        }
        if(targetSum >= nums[startIndex] && FindSum(nums, startIndex+1, targetSum-nums[startIndex])) {
            memo[startIndex,targetSum] = true;
            return true;
        }
        var result = FindSum(nums, startIndex+1, targetSum);
        memo[startIndex, targetSum] = result;
        return result;
    }
}

//Second fastest
public class Solution {
        public bool CanPartition(int[] nums)
        {
            var sum = nums.Sum();
            if (sum % 2 != 0) return false;
            sum /= 2;
            var mem = new bool?[nums.Length + 1, sum + 1];
            return Dfs(nums, 0, sum, mem);
        }

        private bool Dfs(int[] nums, int i, int target, bool?[,] mem)
        {
            if (target == 0) return true;
            if (i == nums.Length || target < 0) return false;
            if (mem[i, target] != null) return (bool) mem[i, target];
            mem[i, target] = Dfs(nums, i + 1, target - nums[i], mem) || Dfs(nums, i + 1, target, mem);
            return (bool) mem[i, target];
        }
}

//Fastest
public class Solution {
    public bool CanPartition(int[] nums) 
    {        
        var arrayTotal = nums.Sum();
        if(arrayTotal%2 != 0) return false;
        var target = arrayTotal/2;
        var cache = new int[target+1, nums.Length];
        return subsetSum(nums, target, 0, 0, cache);
    }
    
    private bool subsetSum(int[] nums, int target, int sumTillNow, int startPos, int[,] cache)
    {
        if(sumTillNow == target) return true;
        if(startPos == nums.Length) return false;
        if(cache[sumTillNow,startPos] != 0) {
          return cache[sumTillNow,startPos] == 2;  
        } 
        
        var result = false;
        if(nums[startPos] + sumTillNow <= target) 
        {
            result = subsetSum(nums, target, sumTillNow+nums[startPos], startPos+1, cache);
        }
        
        result = result || subsetSum(nums, target, sumTillNow, startPos+1, cache);        
        
        if(result) {
            cache[sumTillNow,startPos] = 2;
        }
        else cache[sumTillNow,startPos] = 1;
        return result;
    }
}