//Third fastest
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> win;
        int lo=INT_MAX;
        win.push_back(nums[0]);
        int n=nums.size();
        for (int i=1; i<n; i++){
            if (nums[i]>lo) return true;
            if (win.size()==1){
                if (nums[i]<=win[0]) win[0]=nums[i];
                else win.push_back(nums[i]), lo=min(lo, nums[i]);
            } else {
                if (nums[i]>win[0]) {
                    win[1]=nums[i];
                    lo=nums[i];
                } else win={nums[i]};
            }
        }
        return false;
    }
};

//Second fastest
class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    // int n = nums.size();
    // if (n < 3) return false;
    // for (int i = 0; i < n; i++) {
    //   for (int j = i + 1; j < n; j++) {
    //     if (nums[j] > nums[i]) {
    //       for (int k = j + 1; k < n; k++) {
    //         if (nums[k] > nums[j]) return true;
    //       }
    //     }
    //   }
    // }
    // return false;
    int first = INT_MAX;
    int second = INT_MAX;
    for (int num: nums) {
      if (num <= first) {
        first = num;
      } else if (num <= second) {
        second = num;
      } else {
        return true;
      }
    }
    return false;
  }
};

//Fastest
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int one = INT_MAX;
        int two = INT_MAX;
        
        for( int i = 0; i < nums.size(); i++) {
            if(nums[i] <= one) {
                one = nums[i];
            }else if (nums[i] <= two) {
                two = nums[i];
            }else{
                return true;
            }
        }
        
        return false;
    }
};