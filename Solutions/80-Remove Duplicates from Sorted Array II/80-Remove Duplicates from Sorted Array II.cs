//Fourth fastest
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        var i=0;
        
        for(var j=0; j<nums.Length; j++)
        {
            if(j<2 || nums[j]>nums[i-2])
            {
                nums[i++] = nums[j];     
            }
        }
        
        return i;
    }
}

//Third fastest
public class Solution {
    public int RemoveDuplicates(int[] nums) {
            if (nums.Length < 3)
            {
                return nums.Length;
            }

            int n = 0;
            int j = 0;
            var tmp = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
                if (i == 0)
                {
                    tmp[j] = nums[i];
                    j++;
                }

                if (((i + 1) < nums.Length) && (nums[i] == nums[i + 1]))
                {
                    if (i == 0)
                    {
                        tmp[1] = nums[1];
                        j++;
                        n = 2;
                    }
                    else if (n < 2)
                    {
                        tmp[j] = nums[i];
                        j++;
                        n++;
                    }
                }
                else
                {
                    n = 1;
                   if ((i + 1) < nums.Length)
                    {
                        tmp[j] = nums[i + 1];
                        j++;
                    }
                }
            }
            for (int k = 0; k < j; k++)
            {
                nums[k] = tmp[k];
            }

            return j;
    }
}

//Second fastest
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        
        int skippedItems = 0;
        int i = 2;
        
        while (i < nums.Length - skippedItems)
        {         
            if (skippedItems>0)
                swap(nums, i, i + skippedItems);
            
            if (nums[i] == nums[i-2])
               skippedItems++;
            else
               i++;
            
            
                
        }
        
        return nums.Length-skippedItems;
    }
    
    private void swap(int[] nums, int index, int newIndex)
    {
        var aux = nums[newIndex];
        nums[newIndex] = nums[index];
        nums[index] = aux;
    }
}

//Fastest
public class Solution {
    public int RemoveDuplicates(int[] nums) 
    {
       if(nums.Length == 0) return 0;

            int i = 0;

            int currCount = 0;

            for(int j = 1; j < nums.Length; j++)
            {
                if(nums[i] != nums[j])
                {
                    currCount = 0;
                }
                else
                {
                    currCount++;
                }

                if(currCount < 2)
                {
                    nums[++i] = nums[j];
                }
            }

            return i + 1;
    }
}