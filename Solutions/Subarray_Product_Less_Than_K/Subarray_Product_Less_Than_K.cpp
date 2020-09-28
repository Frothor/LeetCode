//Sliding window
class Solution
{

public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {

        if (k == 0)
            return 0;

        int start = 0;
        int end = 0;
        int p = 1;
        int count = 0;

        while (end < nums.size())
        {
            p *= nums[end];

            while (start < nums.size() and p >= k)
            {
                p = p / nums[start];
                start++;
            }

            if (p < k)
                count += end - start + 1;

            end++;
        }

        return count;
    }
};

//Fastest
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &a, int k)
    {

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int p = 1;

        int st = 0, e = 0, ans = 0;

        while (e < a.size())
        {
            p = p * a[e];

            while (st <= e and p >= k)
            {
                p = p / a[st];
                st++;
            }

            ans += (e - st + 1);

            e++;
        }

        return ans;
    }
};