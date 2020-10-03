class Solution
{

public:
    int findPairs(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;

        int count1 = 0;

        //putting all the values in hashmap
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        //handling the case when k==0
        if (k == 0)
        {
            for (auto x : mp)
            {
                if (x.second > 1)
                    count1++;
            }
            return count1;
        }

        //we are iterating over hashmap because hashmap has unique values.
        for (auto x : mp)
        {
            if (mp.count(x.first - k))
                count1++;
        }

        return count1;
    }
};

//Second fastest
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        if (k == 0)
        {
            std::unordered_map<int, int> myMap;

            for (auto e : nums)
                myMap[e]++;

            int max = 0;

            for (auto e : myMap)
            {
                if (e.second > 1)
                    max++;
            }

            return max;
        }

        std::unordered_set<int> mySet(nums.begin(), nums.end());

        int ans = 0;

        for (auto e : mySet)
        {
            if (mySet.find(e + k) != mySet.end())
                ans++;
        }
        return ans;
    }
};

//Fastest
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 1;
        int j = 0;
        int res = 0;
        while (i < nums.size() && j < nums.size())
        {
            if (nums[i] - nums[j] == k)
            {
                res++;
                i++;
                j++;
                while (i < nums.size() && nums[i] == nums[i - 1])
                    i++;
            }
            else if (nums[i] - nums[j] > k)
            {
                j++;
                if (i - j == 0)
                    i++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};