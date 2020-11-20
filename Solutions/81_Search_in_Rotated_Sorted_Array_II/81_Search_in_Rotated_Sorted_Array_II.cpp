//Third fastest
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=(int) nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            while(nums[low]==nums[mid] && nums[mid]==nums[high]){ 
                low++,high--;
                if(low>high)
                    break;
            }
            if(low>high) break;
             if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }
                else low=mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};

//Second fastest
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if(nums.size()==0) {return false;}
    int start = 0;
    int end = nums.size()-1;
    while(start<end) {
      int mid = start + (end-start)/2;
      if(target==nums[mid]){return true;}
      if(nums[mid]>nums[end]) {
        if(target>=nums[start] && target<=nums[mid]) {end=mid;}
        else {start=mid+1;}
      }
      else if(nums[mid]<nums[end])  {
        if(target>=nums[mid] && target<=nums[end]) {start=mid+1;}
        else {end=mid;}
      }
      else {
        end = end -1;
      }
    }
    // This is needed for the special case of an array with 1 element
    // Ex : num s= [4] and target = 4.
    return nums[start]==target ? true : false;
  }
};

//Fastest
class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
           int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target)
                return true;
            else if (nums[mid] == nums[hi])
                hi--;
            else if (nums[mid] <= nums[hi])
            {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
            {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        
        return false;
    }
};