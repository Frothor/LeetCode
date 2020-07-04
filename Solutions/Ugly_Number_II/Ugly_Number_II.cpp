class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> nums{1};
        static int i2 = 0;
        static int i3 = 0;
        static int i5 = 0;
        
        while(nums.size() < n){
            const int next2 = nums[i2] * 2;
            const int next3 = nums[i3] * 3;
            const int next5 = nums[i5] * 5;
            const int next = min(next2, min(next3, next5));
            if(next == next2) ++i2;
            if(next == next3) ++i3;
            if(next == next5) ++i5;
            nums.push_back(next);
        }
        
        return nums[n-1];
    }
};

/*
Fastest:
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> result(1,1);
        static int i =0;
        static int j =0;
        static int k = 0;
        while(result.size()<n)
        {
            result.push_back(min(result[i]*2, min(result[j]*3, result[k]*5)));
            if(result.back() == result[i]*2)
                i++;
            if(result.back() == result[j]*3)
                j++;
            if(result.back() == result[k]*5)
                k++;
        }
        return result[n-1];
    }
};

*/