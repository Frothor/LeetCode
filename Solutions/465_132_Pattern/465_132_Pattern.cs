//Most common
using System;
using System.Collections.Generic;

public class Solution 
{
    public bool Find132pattern(int[] nums)
    {
        if (nums.Length < 3)
            return false;
        var stack = new Stack<int> ();
        var min = new int[nums.Length];
        min[0] = nums[0];
        for (var i = 1; i < nums.Length; i++)
            min[i] = Math.Min(min[i - 1], nums[i]);
        for (var j = nums.Length - 1; j >= 0; j--)
        {
            if (nums[j] <= min[j]) continue;
            while (stack.Count != 0 && stack.Peek() <= min[j])
                stack.Pop();
            if (stack.Count != 0 && stack.Peek() < nums[j])
                return true;
            stack.Push(nums[j]);
        }
        return false;
    }
}

//Third fastest
public class Solution {
    public bool Find132pattern(int[] nums) {
        int n = nums.Length;
        Stack<int> st = new Stack<int>();
        var minVal = new int[n];
        minVal[0] = nums[0];
        for(int i = 1; i < n; i++) 
            minVal[i] = Math.Min(minVal[i-1], nums[i]);
        
        for(int j = n-1; j > 0; j--) {
            while(st.Count != 0 && nums[st.Peek()] < nums[j]){
                if(nums[st.Peek()] > minVal[j-1])
                    return true;
                st.Pop();
            }
            st.Push(j);
        }
        return false;
    }
}

//Second fastest
public class Solution {
    public bool Find132pattern(int[] nums) {
        if (nums.Length < 3)
        {
            return false;
        }
        int curMin = Int32.MaxValue;
        var min = new int[nums.Length];

        for (int i = 0; i < nums.Length; i++)
        {
            curMin = Math.Min(curMin, nums[i]);
            min[i] = curMin;
        }

        Stack<int> stack = new Stack<int>();
        for (int j = nums.Length - 1; j >= 0; j--)
        {
            if (nums[j] > min[j])
            {
                while (stack.Count > 0 && stack.Peek() <= min[j])
                {
                    stack.Pop();
                }
                if (stack.Count > 0 && stack.Peek() < nums[j])
                {
                    return true;
                }
                stack.Push(nums[j]);
            }
        }
        return false;
    }
}

//Fastest
public class Solution {
    public bool Find132pattern(int[] nums)
        {
            if (nums == null || nums.Length < 3) return false;
            Stack<int> st = new Stack<int>();

            var minSoFar = new int[nums.Length];
            minSoFar[0] = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                minSoFar[i] = Math.Min(minSoFar[i - 1], nums[i]);
            }

            for (int i = nums.Length - 1; i >= 0; i--)
            {
                while (st.Count > 0 && st.Peek() <= minSoFar[i])
                {
                    st.Pop();
                }

                if (st.Count > 0 && st.Peek() < nums[i]) return true;

                st.Push(nums[i]);
            }
            
            return false;
        }
    
    public bool Find132pattern_ON2(int[] nums)
        {
            if (nums == null || nums.Length < 3) return false;
            int minI = nums[0];
            for (int j = 1; j < nums.Length; j++)
            {
                for (int k = j + 1; k < nums.Length; k++)
                {
                    if (minI < nums[k] && nums[k] < nums[j]) return true;
                }
                minI = Math.Min(minI, nums[j]);
            }
            return false;
        }
}