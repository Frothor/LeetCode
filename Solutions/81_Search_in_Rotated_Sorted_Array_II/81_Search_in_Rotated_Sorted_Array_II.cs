//Fourth fastest
public class Solution {
    public bool Search(int[] nums, int target) {
        int end  = nums.Length-1;
        int start = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < nums[end]){
                if(nums[mid] < target && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
            else if(nums[mid] > nums[end]){
                if(nums[start] <= target && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else
                end--;
        }
        return false;
    }
}

//Another
public class Solution {
    public bool Search(int[] nums, int target) 
    {
        int left = 0, right = nums.Length - 1;
		while(left <= right)
		{
			int middle = left + (right - left)/2;
			if(nums[middle] == target)
				return true;
			
			if(nums[left] < nums[middle])
			{
				if(target >= nums[left] && target < nums[middle])
					right = middle - 1;
				else
					left = middle + 1;
			}
			else if(nums[left] > nums[middle])
			{
				if(target > nums[middle] && target <= nums[right])
					left = middle + 1;
				else
					right = middle - 1;
			}
			else 
			{
				left++;
			}
		}
		return false;    
    }
}

//Third fastest
public class Solution {
    public bool Search(int[] nums, int target) {
        if (nums.Length == 0) return false;
        return Search(nums, target, 0, nums.Length - 1);
    }

    private bool Search(int[] nums, int target, int l, int r) {
        if (l > r) return false;
        
        if (l == r)
            return nums[l] == target;

        if (nums[l] < nums[r])
            return Binary(nums, target, l, r);

        var mid = (l+r) / 2;

        if (nums[l] == nums[r])
            return Search(nums, target, l, mid) || Search(nums, target, mid+1, r);

        if (nums[mid] == target)
            return true;

        if (nums[mid] < target)
        {
            if (nums[l] <= nums[mid])
                return Search(nums, target, mid+1, r);

            if (nums[mid] < nums[r] && target <= nums[r])
                return Search(nums, target, mid+1, r);

            return Search(nums, target, l, mid-1);
        } else { // target < mid
            if (nums[mid] <= nums[r])
                return Search(nums, target, l, mid-1);

            if (nums[l] < nums[mid] && nums[l] <= target)
                return Search(nums, target, l, mid-1);
            
            return Search(nums, target, mid+1, r); 
        }
    }
    
    private bool Binary(int[] nums, int target, int l, int r) {
        while (l <= r) {
            var mid = (l+r) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return false;
    }
}

//Second fastest
public class Solution {
    public bool Search(int[] nums, int target) {
        
        if(nums.Length == 0)
        {
            return false;
        }
        
        int p1 = 0;
        int p2 = nums.Length - 1;
        
        while((nums[p1] <= target || nums[p2] >= target) && p1 <= p2)
        {
            if(nums[p1] == target || nums[p2] == target)
            {
                return true;
            }
            else if(p1 == p2){
                return false;
            }
            p1++;
            p2--;

        }
        return false;
    }
}

//Fastest
public class Solution {
    public bool Search(int[] nums, int target) {
        if(nums.Length==0 || nums==null) return false;
        int l=0, r = nums.Length-1, mid =0; 
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]== target) return true;
            else if(nums[l]<nums[mid]){
                if(nums[l]<=target && nums[mid]>target){
                    r=mid-1;
                    
                }else l=mid+1;
            }else if(nums[l]> nums[mid]){
                if (nums[r]>=target && nums[mid]<target) l=mid+1;
                else r=mid -1;
            }else l++;
        }
        return false;
    }
}