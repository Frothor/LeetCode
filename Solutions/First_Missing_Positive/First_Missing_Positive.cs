//Most common
public class Solution {
    public int FirstMissingPositive(int[] nums) {
            int missingNumber = 1;
            nums = nums.OrderBy(n => n).ToArray();
            foreach (var item in nums.OrderBy(n => n)) if (missingNumber == item) missingNumber++;

            return missingNumber;
    


public class Solution {
    public int FirstMissingPositive(int[] nums) {
        Array.Sort(nums);
        nums = nums.Distinct().ToArray();
        int missing = 1;
        for(int i = 0; i < nums.Length; i++) {
            if(nums[i] > 0){
                if(nums[i] == missing)
                   missing++;
                else
                    return missing;
            }
        }
        return missing;
    }
}

//Second fastest
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int len = nums.Length;
            for (int i = 0; i < len; i++)
            {
                if (nums[i] < 0 || nums[i] > len)
                {
                    nums[i] = 0;
                }
            }

            for (int i = 0; i < len; i++)
            {
                int index = Math.Abs(nums[i]);
                if (index > 0 && index <= nums.Length)
                {
                    if (nums[index - 1] > 0)
                    {
                        nums[index - 1] = nums[index - 1] * -1;
                    }
                    else if (nums[index - 1] == 0)
                    {
                        nums[index - 1] = -1 * (nums.Length + 1);
                    }

                }

            }

            for (int i = 0; i < len; i++)
            {
                if (nums[i] >= 0)
                {
                    return i + 1;
                }
            }

            return nums.Length + 1;
    }
}

public class Solution {
public int FirstMissingPositive(int[] nums)
        {
for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] <= 0)
                    nums[i] = int.MaxValue;
            }
            for (int i = 0; i < nums.Length; i++)
            {
                var index = Math.Abs(nums[i]) - 1;
                if (index >= 0 && index < nums.Length && nums[index] > 0)
                {
                    nums[index] = -1 * nums[index];
                }
            }
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                    return i + 1;
            }
            return nums.Length + 1;
        }
}