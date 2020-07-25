class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
    
    int findMin(vector<int>& nums, int l, int r) {
        
        if(l+1 >= r)
            return min(nums[l], nums[r]);
        
        if(nums[l] < nums[r])
            return nums[l];
        
        int mid = l + (r-l)/2;
        
        return min(findMin(nums, l, mid-1),findMin(nums, mid, r)); 
    }
};

/*
Fastest:
class Solution {
public:
    
    int get_min_using_binary_search(vector<int>& nums, int l, int h) {
        // as in duplicate numbser case array begning and ending elements might be same
        // eg : [10,1,10,10,10]
        //      [10,10,10,1,10,10]
        while(h>0 && nums[l]==nums[h]) h--;
        while(l<=h) {
            int m = (l+h)/2;
            if(m+1<nums.size() && nums[m]>nums[m+1])
                return nums[m+1];
            else if(nums[l]>nums[m])
                h = m-1;
            else
                l = m+1;
        }
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
        int ln = nums.size();
        return get_min_using_binary_search(nums, 0, ln-1);
    }
*/