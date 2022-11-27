public class Solution {
    public int[] TwoSum(int[] nums, int target) 
    {        
        Dictionary<int, int> intStore = new Dictionary<int, int>();    
        for (int i=0; i<nums.Length; i++) {
            if (intStore.ContainsKey(target-nums[i]))
            {
                return new int[] {intStore[target-nums[i]], i};
            }
            
            intStore[nums[i]] = i;
        }
        return null;
    }
}

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
            var dictionary = new Dictionary<int, int>();
            for (var i = nums.Length - 1; i >= 0; i--)
            {
                var num = nums[i];
                
                var diff = target - num;

                if (dictionary.ContainsKey(diff))
                {
                    return new[] {i , dictionary[diff]};
                }

                dictionary[num] = i;
            }
            throw new ArgumentException("Can't find pair with sum " + target);
    }
}

// Clever one
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var dicnums = new Dictionary<int, int>();
        for (int i = 0, j; i < nums.Length; i++) {
            if (dicnums.TryGetValue(target - nums[i], out j))
                return new[] {i, j};
            dicnums[nums[i]] = i;
        }
        throw new ArgumentException("No solution found.");
    }
}