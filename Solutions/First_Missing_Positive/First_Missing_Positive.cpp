class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (l + 1 == nums[l])
                l++;
            else if (r + 1 == nums[r] || nums[r] <= 0 || nums[r] >= nums.size() || nums[nums[r] - 1] == nums[r])
                r--;
            else
                swap(nums[r], nums[nums[r] - 1]);
        }
        while (l < nums.size() && l + 1 == nums[l])
            l++;
        return l + 1;
    }
};

//Fastest
class Solution
{
public:
    // O(nlogn) time, O(n) space
    int firstMissingPositive1(vector<int> &nums)
    {
        unordered_set<int> hash_set;

        for (int x : nums)
            hash_set.insert(x);

        hash_set.insert(0);

        nums.resize(0);

        for (int x : hash_set)
            nums.push_back(x);

        int N = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < N; ++i)
        {
            if (nums[i] + 1 > 0 && (i == N - 1 || nums[i + 1] != nums[i] + 1))
                return nums[i] + 1;
        }

        return 1;
    }

    // O(n) time, O(n) space)
    int firstMissingPositive2(vector<int> &nums)
    {
        const int N = nums.size();

        vector<int> available(N + 1, 1);

        for (int x : nums)
        {
            if (x < 0 || x > N)
                continue;
            available[x] = 0;
        }

        for (int i = 1; i < N + 1; ++i)
        {
            if (available[i])
                return i;
        }

        return N + 1;
    }

    int firstMissingPositive(vector<int> &nums)
    {
        const int N = nums.size();

        for (int &x : nums)
        {
            if (x <= 0 || x > N)
                x = INT_MAX;
        }

        // Partition around 0
        // nums[0, i) are all -1
        // after this operation all numbers have MSB == 0
        int i = 0, j = 0;
        while (j < N)
        {
            if (nums[j] == INT_MAX)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }

        // for each number x in range [1...N]
        //      set MSB of nums[x] as 1
        // MASK == INT_MAX == 01111...
        const int MASK = ((unsigned int)((int)-1)) >> 1;
        while (i < N)
        {
            int idx = (nums[i] & MASK) - 1;
            nums[idx] |= (1 << 31);
            ++i;
        }

        // if MSB of any number is 0 it is still available
        for (int i = 0; i < N; ++i)
        {
            if ((nums[i] & ~MASK) == 0)
                return i + 1;
        }

        return N + 1;
    }
};