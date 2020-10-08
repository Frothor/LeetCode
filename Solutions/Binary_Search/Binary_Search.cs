public class Solution {
    public int Search(int[] nums, int target) {
        int l = 0, r = nums.Length-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return -1;
    }
}

//Third fastest
public class Solution {
    public int Search(int[] nums, int target) {
        int num = -1;
        for(int x = 0;x < nums.Length;x++){
            if(nums[x] == target){
                num = x;
                break;
            }
        }
        return num;
    }
}

//Second fastest
public class Solution {
    public int Search(int[] nums, int target) {
        
        int start = 0;
        int end = nums.Length - 1;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;            
            }
        }
        
        return -1;
        
    }
}

//Fastest
public class Solution {
    public int Search(int[] nums, int target) {
        return Search(nums, target, 0, nums.Length - 1);
        }

        /// <summary>
        /// A binary search algorithm that works on an ORDERED array,
        /// and finds the needle by iteratively cutting away half.
        /// Time Complexity: O(log N) where N is the size of the array.
        /// Space Complexity: O(N) as we have recursion. 
        /// </summary>
        /// <param name="nums">The container holding the elements to search. Must be sorted.</param>
        /// <param name="target">The value to search for</param>
        /// <param name="start">Initially, 0</param>
        /// <param name="end">Initially, the size of the array</param>
        /// <returns>Returns the index of the found item.</returns>
        private static int Search(int[] nums, int target, int start, int end)
        {
            if ((nums == null) || (nums.Any() == false) || (start > end))
                return -1;

            int middle = (start + end) / 2;

            if (target == nums[middle])
                return middle;

            if (target < nums[middle]) // Search in the left side
                return Search(nums, target, start, middle - 1);

            return Search(nums, target, middle + 1, end); // Search in the right side
        }
}