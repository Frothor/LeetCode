public class Solution {
    public void Rotate(int[] nums, int k) {
        if(k == 0)
            return;
        
        k %= nums.Length;
        int cutOff = nums.Length - k - 1;
        var res = new List<int>();
        
        for(int i = cutOff + 1; i < nums.Length; i++)
            res.Add(nums[i]);
        
        for(int i = 0; i <= cutOff; i++)
            res.Add(nums[i]);
        
        for(int i = 0; i < nums.Length; i++)
            nums[i] = res[i];
    }
}

//Third fastest
public class Solution {
    public void Rotate(int[] nums, int k) {
        int[] aux = new int[nums.Length];
        int newValueK = k >= nums.Length ? k % nums.Length : k;
        for (int i = 0; i < nums.Length; i++)
        {
            int originIndex = i - newValueK;
            if (originIndex < 0)
            {
                originIndex = nums.Length + originIndex;
            }
            
            aux[i] = nums[originIndex];
        }
        
        for (int i = 0; i < nums.Length; i++)
        {
            nums[i] = aux[i];
        }
    }
}

//Second fastest
public class Solution {
    public void Rotate(int[] nums, int k) {
        int newValueK = k >= nums.Length ? k % nums.Length : k;
        int counter = 0;
        
        for (int i = 0; counter < nums.Length; i++) 
        {        
            int current = i;     
            int aux = nums[i]; // 1
            
            do //1.  1,2,3,4
            {
                int newIndex = i + newValueK; // 4
                if (newIndex >= nums.Length)
                {
                    newIndex = newIndex - nums.Length; // 0
                }

                var oldValue = nums[newIndex]; // 1
                nums[newIndex] = aux; // 3,2,1,4
                aux = oldValue; // 3
                i = newIndex; // 2
                counter++;
            } while (i != current);
        }
    }
}

//Fastest
public class Solution 
{
    public void Rotate(int[] nums, int k) 
    {
        k %= nums.Length;
        Reverse(nums, 0, nums.Length - 1);
        Reverse(nums, 0, k - 1);
        Reverse(nums, k, nums.Length - 1);
    }
    
    private void Reverse(int[] nums, int start, int end)
    {
        while (start < end)
        {
            var temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            
            start++;
            end--;
        }
    }
}