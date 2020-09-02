class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        
        if(n == 0 || k < 0  || t < 0) return false;
        
        unordered_map<int,int> buckets;
        
        for(int i=0; i<n; ++i) {
            int bucket = nums[i] / ((long)t + 1);
            
			// For negative numbers, we need to decrement bucket by 1
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
			// Therefore, decrement by 1.
            if(nums[i] < 0) --bucket;
            
            if(buckets.find(bucket) != buckets.end()) return true;
            else {
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t) return true;
                if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t) return true;
                
                if(buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);
                    
                    if(nums[i-k] < 0) --key_to_remove;
                    
                    buckets.erase(key_to_remove);
                }
            }
        }
        
        return false;
    }
};

//Most commmon
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (window.size() > k)
                window.erase(nums[i - k - 1]);
            
            auto it = window.lower_bound((long)nums[i] - t);
            if (it != window.end() && *it <= (long)nums[i] + t)
                return true;
            
            window.insert(nums[i]);
        }
        
        return false;
    }
};

//Fastest
#include<cmath>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 10000) return false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < fmin(i+1+k, nums.size()); j++) {
                long difference = (long)nums[i]-(long)nums[j];
                if (abs(difference) <= t)
                    return true;
            }
        }
        return false;
    }
};