class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1])
                    l = mid+2;
                else if(nums[mid] == nums[mid-1])
                    r = mid-2;
                else
                    return nums[mid];
            } else {
                if(nums[mid] == nums[mid-1])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        
        return nums[l];
    }
};

/*
Faster Solution:
//Xor solution will gice solution but not taking advantage of 
//sorted array and the xor solution will be O(n)
//use binary search 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        } 
        if (nums[0]!=nums[1]) {
            return nums[0];
        }
        int n=nums.size();
        if (nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }
        int left=0;
        int right=nums.size()-1;
        while (left<=right) {
            int mid=left+(right-left)/2;
            if (nums[mid]!=nums[mid+1] && nums[mid] != nums[mid-1]) {
                return nums[mid];
            }
            //element has only one single non duplicate
            //even-odd size zone
            if (mid%2==0 and nums[mid]==nums[mid+1]) {
                //mid%2==0, means even index, so left size has even number of elements
                left=mid+1;
            } else if (mid%2==1 and nums[mid]==nums[mid-1]) {
                //mid%2==1 means odd index, so left size has even number of elements
                //including mid
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        return -1;
    }
};

Fastest:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x = x^nums[i];
        }
        return x;
    }
};
static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
*/