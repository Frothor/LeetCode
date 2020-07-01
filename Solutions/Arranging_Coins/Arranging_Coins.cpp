class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(8*(long long)n+1)-1)/2;
    }
};

/*
Fastest:
class Solution {
public:
    int arrangeCoins(int n) {
        int left=0;
        int right=n;
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            long long curr=((long long)(mid)*(mid+1))/2;
            
            if(curr<=n)
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};

Most common:
class Solution {
public:
    int arrangeCoins(int n) 
    {
    int left = 0, right = n;
    while (left <= right)
    {
        long mid, curr;
        mid = left + (right - left)/2;
        curr = (1 + mid) * mid / 2;
        if (curr == n) return mid;
        if (curr < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
    }
};
*/