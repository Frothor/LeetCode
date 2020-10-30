//Most common
public class Solution
{
    public int FindNumberOfLIS(int[] nums) 
    {
        if(nums == null || nums.Length == 0)
        {
            return 0;
        }
        
        if(nums.Length == 1)
        {
            return 1;
        }
        
        int[] LISLength = new int[nums.Length];
        int[] count = new int[nums.Length];
        
        // Each num is LIS of length 1
        for(int i = 0; i < nums.Length; i++)
        {
            LISLength[i] = 1;
            count[i] = 1;
        }
        
        int maxLength = 0;
        for(int i = 1; i < nums.Length; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(LISLength[j] + 1 > LISLength[i])   
                    {
                        LISLength[i] = LISLength[j] + 1;
                        count[i] = count[j];
                    }
                    
                    else if(LISLength[j] + 1 == LISLength[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            
            maxLength = Math.Max(maxLength, LISLength[i]);
        }
        
        int LISCount = 0;
        for(int i = 0; i < nums.Length; i++)
        {
            if(LISLength[i] == maxLength)
            {
                LISCount += count[i];
            }
        }
        
        return LISCount;
    }
}

//Another most common
public class Solution {
    public int FindNumberOfLIS(int[] nums) {
        var n = nums.Length;
        if(n <= 1)
            return n;
        
        var lengths = Enumerable.Repeat(1, n).ToArray();
        var counts = Enumerable.Repeat(1, n).ToArray();

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                {
                    if (lengths[i] <= lengths[j]) 
                    {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } 
                    else if (lengths[i] == lengths[j] + 1) 
                    {
                        counts[i] += counts[j];
                    }
                }
        }
        
        int maxLen = lengths.Max(), numMaxLen = 0;
        for(int i = 0; i < n; i++)
            if(lengths[i] == maxLen)
                numMaxLen += counts[i];
        return numMaxLen;
    }
}

//Third fastest
public class Solution 
{
    public int FindNumberOfLIS(int[] nums) 
    {
        if ((nums == null) || (nums.Length <= 1))
            return nums?.Length ?? 0;
        
        var dp = new int[nums.Length]; // dp[i] = length of longest ending in nums[i]
        var counts = new int[nums.Length];       // count[i] = number of longest ending in nums[i]

        var lisLength = 0;
        for(var j = 0; j < nums.Length; j++)
        {
            dp[j] = counts[j] = 1;
            for(var i = 0; i <= j; i++)
            {
                if (nums[j] > nums[i])
                {
                    if (dp[i] >= dp[j])
                    {
                        dp[j] = Math.Max(dp[i] + 1, dp[j]);
                        counts[j] = counts[i];
                    }
                    else if (dp[i] + 1 == dp[j]) 
                    {
                        counts[j] += counts[i];
                    }
                }
            }           
            //if (dp[j] > lisLength)
            //    lisSB.Append($"{nums[j]}({(j < excludedIdx ? j : j+1)}),");

            lisLength = Math.Max(lisLength, dp[j]);
        }
              
        //Console.WriteLine($"{lisLength} - {string.Join(",", counts.Select(i=>i.ToString()))}");
        
        var result = 0;
        for(var idx = 0; idx < counts.Length; idx++)
        {           
            if (dp[idx] == lisLength)
                result = result + counts[idx];
        }
        
        return result;
    }
    
    //Console.WriteLine($"{string.Join(",", nums.Select(i=>i.ToString()))} - {lisLength}  - {string.Join(",", lis.Select(i=>i.ToString()))}");
    //Console.WriteLine($"{string.Join(",", nums.Select(i=>i.ToString()))} - {lisLength} - {lis}");
}

//Second fastest
public class Solution {
    public int FindNumberOfLIS(int[] nums) {
        var n = nums.Length;
        if(n <= 1)
            return n;
        
        var lengths = Enumerable.Repeat(1, n).ToArray();
        var counts = Enumerable.Repeat(1, n).ToArray();

        //adding number at i to some subsequence ending at j
        for(int i = 1; i < nums.Length; i++)
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                    if(lengths[i] <= lengths[j])
                    {
                        // if we have equal or lesser length of subsequences at i than j, before appending i to the end of j, 
                        lengths[i] = lengths[j] + 1;// length will be increased 
                        counts[i] = counts[j];// however counts will be the same
                    }
                    else if(lengths[i] == lengths[j] + 1) //but if length of inc subsequence at i was already as it was appended 
                        // to the subsequence ending at j, counts will be added, since it's another path of equal length.
                        counts[i] += counts[j];
        
        int maxLen = lengths.Max(), numMaxLen = 0;
        for(int i = 0; i < n; i++)
            if(lengths[i] == maxLen)
                numMaxLen += counts[i];
        return numMaxLen;
        
        /*
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                {
                    if (lengths[i] <= lengths[j]) 
                    {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } 
                    else if (lengths[i] == lengths[j] + 1) 
                    {
                        counts[i] += counts[j];
                    }
                }
        }
        */

    }
}

//Fastest
public class Solution {
    public int FindNumberOfLIS(int[] nums) {
       int N = nums.Length;
        if (N <= 1) return N;
        int[] lengths = new int[N]; //lengths[i] = length of longest ending in nums[i]
        int[] counts = new int[N]; //count[i] = number of longest ending in nums[i]
        Array.Fill(counts, 1);

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < j; ++i) if (nums[i] < nums[j]) {
                if (lengths[i] >= lengths[j]) {
                    lengths[j] = lengths[i] + 1;
                    counts[j] = counts[i];
                } else if (lengths[i] + 1 == lengths[j]) {
                    counts[j] += counts[i];
                }
            }
        }

        int longest = 0, ans = 0;
        foreach (int length in lengths) {
            longest = Math.Max(longest, length);
        }
        for (int i = 0; i < N; ++i) {
            if (lengths[i] == longest) {
                ans += counts[i];
            }
        }
        return ans;
    }
}