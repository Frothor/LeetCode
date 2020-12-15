//Linq
public class Solution {
    public int[] SortedSquares(int[] A) {
        return A.Select(a => a * a).OrderBy(b => b).ToArray();
    }
}

//Fourth fastest
public class Solution 
{
    public int[] SortedSquares(int[] nums) 
    {
        var n = nums.Length;
        var right = 0;
        
        while(right < n && nums[right] < 0)
        {
            right++;
        }
        
        var left = right - 1;
        
        var ans = new int[n];
        var i = 0;
        
        while(left >= 0 && right < n)
        {
            var leftQ = nums[left]*nums[left];
            var rightQ = nums[right]*nums[right];
            
            if(leftQ < rightQ)
            {
                ans[i] = leftQ;
                left--;
            }
            else
            {
                ans[i] = rightQ;
                right++;
            }
            i++;
        }
        
        while(left >= 0)
        {
            ans[i++] = nums[left]*nums[left];
            left--;
        }
        
        while(right < n)
        {
            ans[i++] = nums[right]*nums[right];
            right++;
        }
        
        return ans;
    }
}

//Third fastest
public class Solution {
    public int[] SortedSquares(int[] nums) {
                    var result = new int[nums.Length];
            var lo = 0;
            var hi = nums.Length - 1;
            var i = nums.Length - 1;
            while (lo <= hi)
            {
                var start = nums[lo] * nums[lo];
                var end = nums[hi] * nums[hi];
                if (start > end)
                {
                    result[i--] = start;
                    lo++;
                }
                else
                {
                    result[i--] = end;
                    hi--;
                }
            }

            return result;
    }
}

//Second fastest
public class Solution {
    public int[] SortedSquares(int[] nums) {
        int[] output = new int[nums.Length];
        int left = 0;
        int right = nums.Length-1;
        int current = nums.Length-1;
        
        while(current >= 0)
        {
            if(Math.Abs(nums[left]) < Math.Abs(nums[right]))
            {
                output[current] = nums[right] * nums[right];
                right--;
            }
            else
            {
                output[current] = nums[left] * nums[left];
                left++;
            }
            current--;
        }
        
        return output;
    }
}

//Fastest
public class Solution {
    public int[] SortedSquares(int[] A) {
        int i = 0;
        int j = A.Length - 1;
        
        while(j-1>=0)
        {
            if(A[j-1] * A[j-1] > A[j] * A[j])
                break;
            j--;
        }
        
        i = j-1;
        
        int[] res = new int[A.Length];
        int index = 0;
        while(i >= 0 && j < A.Length)
        {
            if(A[i] * A[i] < A[j] * A[j])
            {
                res[index] = A[i] * A[i];
                i--;
            }
            else
            {
                res[index] = A[j] * A[j];
                j++;
            }
            index++;
        }
        
        while(i >= 0)
        {
            res[index] = A[i] * A[i];
            i--;
            index++;
        }
        
        while(j < A.Length)
        {
            res[index] = A[j] * A[j];
            j++;
            index++;
        }
        
        return res;
    }
}