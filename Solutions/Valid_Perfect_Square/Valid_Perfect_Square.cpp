class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0) return true;
        
        int left = 1;
        int right = num;
        
        while(left <= right){
            long long mid = left + (right - left)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid > num)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return false;
    }
};

/*Other solutions:
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l=0, r = num/2;
        while(l <= r){
            double mid = l + (r-l)/2;
            //cout << mid << endl;
            if(mid==num/mid) return true;
            if(mid> num/mid){
                r = mid-1;
            }
            else l = mid+1;
        }
        return false;
    }
};
*/