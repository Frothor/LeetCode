public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var len = nums.Length;
        nums = nums.OrderBy(x => x).ToArray<int>();
        List<IList<int>> result = new List<IList<int>>();
        for(int i=0;i<len;i++)
        {
            if (nums[i] > 0 ) break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int start=i+1,last=len-1;
            while(start<last)
            {
                if(nums[start]+nums[last]+nums[i] > 0)
                    last--;
                else if(nums[start]+nums[last]+nums[i] < 0)
                    start++;
                else //if(nums[start]+nums[last]+nums[i] == 0)
                {
                    result.Add(new List<int>{nums[i],nums[start++],nums[last--]});
					// Increment start prv value is same to avoid duplicates in the result.
                    while(start<last && nums[start-1]==nums[start]) start++;
                }
            }
        }
        return result;
    }
}

//Fourth fastest
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        
        if(nums == null)
            throw new ArgumentException("Array cannot be null");
        if(nums.Length == 0)
            return new List<IList<int>>();
        
        var list = new List<IList<int>>();
        Array.Sort(nums);
        
        int? prev = null;
        for(int i = 0; i< nums.Length; i++) {
            
            if(nums[i] > 0)
                break; 
            
            if(prev.HasValue && prev.Value == nums[i])
                continue;
            
            int sum = 0 - nums[i];  
            
            int lo = i + 1;
            int high = nums.Length -1;
            while (lo < high) {
                int twoSum = nums[lo] + nums[high];
                if(twoSum == sum){
                    list.Add(new List<int>(){ nums[i], nums[lo++], nums[high--]});
                    while(lo < high && nums[lo] == nums[lo-1]){
                        lo++;
                    }
                }
                else if(twoSum > sum) {
                    high--;
                }
                else {
                    lo++;
                }
            }
            
            
            prev = nums[i];
        }
        
        return list;
    }
    
    
}

//Third fastest
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> res = new List<IList<int>>();
        if(nums.Length==0 || nums==null) return res;
        Array.Sort(nums);
         for(int i=0;i<nums.Length && nums[i]<=0 ;i++){
             if(i==0  || nums[i-1]!=nums[i]) 
                  func(i,nums,res);
             }
           
        return res;
    }
    
    private void func(int i,int[] nums,IList<IList<int>> res) {
        int l=i+1;
        int h=nums.Length-1;
        while(l<h) {
            int sum = nums[i] + nums[l]+nums[h];
            if(sum>0) h--;
            else if(sum<0) l++;
            else if(sum==0) {
                res.Add(new List<int>(){nums[i],nums[l++],nums[h--]});
                   while(l<h && nums[l]==nums[l-1]) {
                    l++;
               }
            }
        }
    }
    
    
}

//Second fastest
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> result = new List<IList<int>>();
        for (int i=0; i<nums.Length-2; i++){
            if (i>0 && nums[i] == nums[i-1])
                continue;
            int target = 0-nums[i];
            int l=i+1, r=nums.Length-1;
            while (l < r){
                if (nums[r]+nums[l] > target)
                    r--;
                else if (nums[r]+nums[l] < target)
                    l++;
                else{
                    result.Add(new List<int>(){nums[i], nums[r], nums[l]});
                    l++;
                    while(nums[l] == nums[l-1] && l<r) l++;
                }
            }
        }
        return result.ToList();
    }
}

//Fastest
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
             IList<IList<int>> result = new List<IList<int>>();
            if (nums.Length < 3)
                return result;

            Array.Sort(nums);
            var length = nums.Length;
            for (var i = 0; i < length - 2; i++)
            {
                if (nums[i] > 0)
                    break;
                //skip for the duplicated numbers
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                var second = i + 1;
                var third = length - 1;
                while (second < third)
                {
                    var sum = nums[i] + nums[second] + nums[third];
                    if (sum == 0)
                    {
                        result.Add(new List<int> {nums[i], nums[second], nums[third]});
                        while (second < third && nums[second] == nums[second + 1])
                            second++;
                        while (second < third && nums[third] == nums[third - 1])
                            third--;

                        second++;
                        third--;
                    }
                    else if (sum < 0) second++;
                    else third--;
                }
            }
            return result;

    }
}