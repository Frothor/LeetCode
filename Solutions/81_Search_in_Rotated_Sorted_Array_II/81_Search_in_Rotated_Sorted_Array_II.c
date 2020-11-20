bool search(int* nums, int numsSize, int target) {
     int l = 0, m;
     numsSize--;
     while (l <= numsSize) {
        m = (l+numsSize) >> 1;
        if (nums[numsSize] == target || nums[m] == target || nums[l] == target) return true;
        if (nums[numsSize] == nums[l]) l++, numsSize--;
        else if (nums[numsSize] > target) {
            if (nums[m] < target || nums[m] > nums[numsSize]) l = m+1;
            else numsSize = m-1;
        } else {
            if (nums[m] > target || nums[m] < nums[numsSize]) numsSize = m-1;
            else l = m+1;
        }
    }
    return false;
}

//Fastest
int search(int* nums, int numsSize, int target){
        int n= numsSize;
        int lo=0,hi=n-1;
        int mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(nums[mid]==target || nums[lo] == target || nums[hi]== target)
                return true;
           
           if(nums[mid]>nums[lo] ) {
                if(nums[lo]<=target && target<nums[mid])// if t is a part of increasing sequence
                    hi=mid-1;
                else
                    lo=mid+1;
            } else  if(nums[mid] < nums[hi])
            {
                if(target>=nums[mid] && target<nums[hi])
                    lo=mid+1;
                else
                    hi=mid-1;
            } 
            else 
                hi--;
        }
        return false;
    }

// bool search(int* nums, int numsSize, int target){
//     int l=0,h= numsSize-1;
//     int mid,i ;
//     if(numsSize == 1)
//     {
//         if(target == nums[0])
//             return true;
//         else
//             return false;
//     }

//     while(l<=h)
//     {
//         mid = (l+h)/2;
//         if (target == nums[mid] || nums[l] == target || nums[h]== target)
//             return true;
//         if(nums[mid] < nums[h])
//         {
//              if(target > nums[mid] && target <= nums[h])
//                  l = mid +1;
//              else
//                  h = mid -1;       
            
//         }
            
//         else if(nums[l]< nums[mid])
//         {
//             if(target >= nums[l] && target < nums[mid])
//                 h = mid-1;
//             else
//                 l = mid +1; 

//         }
//         else 
//             h--;   
//     }
//     return false;
// }
