public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
        int i = 0;
        var result = new List<string>();
        int n = nums.Length;
        
        
        while(i < n) {
            int s = i, e = i;
            while(e < n-1 && nums[e] + 1 == nums[e+1])
                e++;
            if(nums[s] == nums[e])
                result.Add(new String($"{nums[e]}"));
            else
                result.Add(new String($"{nums[s]}->{nums[e]}"));
            i = e + 1;
        }
        
        return result;
    }
}

//Third fastest
public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
        var ans = new List<string>();
        
        if(nums.Length == 0)
        {
            return ans;
        }
        
        int start = nums[0];
        int prev = nums[0];
        for(int i = 1; i<nums.Length ; i++)
        {
            if(nums[i] == prev + 1)
            {
                prev = nums[i];
                continue;
            }
            ans.Add(GenerateRange(start, prev));    
            start = nums[i];
            prev = nums[i];
        }
        ans.Add(GenerateRange(start, prev));
        return ans;
    }
    
    private string GenerateRange(int start, int end)
    {
        if(start == end){
            return start.ToString();
        }
        
        return String.Format("{0}->{1}", start, end);
    }
}

//Second fastest
public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
        IList<string> res=new List<string>();
        if(nums==null||nums.Length==0) return res;
        int slow=0,fast=0;
        while(fast<nums.Length)
        {
            if(fast+1<nums.Length&&nums[fast]+1==nums[fast+1]) fast++;
            else if(slow==fast){res.Add(nums[slow].ToString());slow=fast+1;fast=fast+1;}
            else {res.Add(nums[slow].ToString()+"->"+nums[fast].ToString());slow=fast+1;fast=fast+1;}
        }
        return res;        
    }
}

//Fastest
public class Solution {
    public IList<string> SummaryRanges(int[] nums) {
        
        IList<string> summary = new List<string>();
        
        for (int i = 0, j = 0; j < nums.Length; j++) {            
            // check if j + 1 extends the range [nums[i], nums[j]]
            if (j + 1 < nums.Length && nums[j] + 1 == nums[j+1])
                continue;
            
            // put the range [nums[i], nums[j]] into the list
            if (i == j)
                summary.Add(nums[i].ToString());
            else
                summary.Add(nums[i] + "->" + nums[j]);
            
            i = j + 1;
        }
        return summary;        
    }
}