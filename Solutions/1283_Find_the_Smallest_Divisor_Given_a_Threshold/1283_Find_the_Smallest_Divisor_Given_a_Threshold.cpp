class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sums = 0;
        int maxV = INT_MIN;
        for(auto i: nums) {
            sums += i;
            maxV = max(maxV, i);
        }
        int left = 1, right = maxV+1; //[)
        //if( sums < (long long) threshold ) return -1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if( getSum(nums, mid) > threshold ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
private:
    int getSum(const vector<int>& nums, int d){
        int ans = 0;
        for(auto i: nums)
            ans += ceil(float(i) /d);
        return ans;
    }
};

//Third fastest
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int tmp = f1(nums, mid);
            if (tmp > threshold)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
private:
    int f1(vector<int>& nums, int divisor)
    {
        int result = 0;
        for (const auto& num : nums)
        {
            int tmp = num / divisor;
            result += (num % divisor == 0 ? tmp : tmp + 1);
        }
        return result;
    }
};


//Second fastest
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
	
		cin.tie(0);
		cout.tie(0);
		ios_base::sync_with_stdio(false);
	
        // lower bound binary search
        int n = nums.size(); //size of the input array
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low < high){
            // do this to avoid overflow problems.
            int mid = low + (high-low)/2;
            
            int sum = 0;
            
            for(int i=0;i<n;i++){
                double q = (double)(nums[i]) / mid;
                if(q - (int)q == 0.0) sum += (int)q; // if quotient is an integer, it is the answer Ex. 10/2 = 5.
                else sum += (int)(q+1); // if quotient is float, we need to take integer higher than this, so 7/3=3.
            }
            
			// if divisor is too small
            if(sum > threshold){
                low = mid+1;
            }
            else high = mid;   // found a valid divisor, but should look for better.
            
            
        }
        return high; // the mimumum divisor satisfhying the solution criteria.
    }

};

//Fastest
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // lower bound binary search
        
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(false);
        
        int n = nums.size();
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low < high){
            
            int mid = low + (high-low)/2;
            
            int sum = 0;
            
            for(int i=0;i<n;i++){
                double q = (double)(nums[i]) / mid;
                if(q - (int)q == 0.0) sum += (int)q;
                else sum += (int)(q+1);
            }
            
            if(sum > threshold){
                low = mid+1;
            }
            else high = mid;   
            
            
        }
        return high;
    }
};