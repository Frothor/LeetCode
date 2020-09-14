public int Rob(int[] nums) 
{
	if(nums == null || nums.Length == 0)
	{
		return 0;
	}

	int next = 0;
	int previous = 0;
	int current = 0;        

	for(int i = 0; i < nums.Length; i++)
	{
		next = Math.Max(previous + nums[i], current);
		previous = current;
		current = next;
	}

	return next;
}

//Most common
public class Solution {
    public int Rob(int[] nums) {
        if(nums.Length == 0)
        {
            return 0;
        }
        
        if(nums.Length == 1)
        {
            return nums[0];
        }
        
        var max1 = nums[0];
        var max2 = Math.Max(nums[0], nums[1]);
        
        for(int i=2;i<nums.Length;i++)
        {
            var newValue = nums[i] + max1;
            max1 = Math.Max(max1, max2);
            max2 = newValue;
        }
        
        return Math.Max(max1, max2);
    }
}

//Fastest
public class Solution {
    public int Rob(int[] nums) {
      if (nums == null) return 0;
      var n = nums.Length;
      if (n == 0) return 0;
      if (n == 1) return nums[0];
      
      var loot = new int[n];
      loot[0] = nums[0];
      loot[1] = Math.Max(loot[0], nums[1]);
      
      for (var i = 2; i < n; i++) {
        loot[i] = Math.Max(loot[i - 1], nums[i] + loot[i - 2]);
      }
      
      return loot[n - 1];
    }
}