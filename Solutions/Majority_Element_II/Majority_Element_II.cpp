
//Boyer–Moore majority vote algorithm
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int x = -1;
        int y = -1;

        int countx = 0;
        int county = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (x == nums[i])
                countx++;

            else if (y == nums[i])
                county++;

            else if (countx == 0)
            {
                x = nums[i];
                countx = 1;
            }
            else if (county == 0)
            {
                y = nums[i];
                county = 1;
            }
            else
            {
                county--;
                countx--;
            }
        }

        int count = nums.size() / 3;
        countx = 0;
        county = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (x == nums[i])
            {
                countx++;
            }
            else if (y == nums[i])
            {
                county++;
            }
        }

        vector<int> v;

        if (countx > count)
        {
            v.push_back(x);
        }

        if (county > count)
        {
            v.push_back(y);
        }

        return v;
    }
};

//Fastest
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int element1, element2;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (element1 == nums[i])
            {
                count1 = count1 + 1;
            }
            else if (element2 == nums[i])
            {
                count2 = count2 + 1;
            }
            else if (count1 == 0)
            {
                element1 = nums[i];
                count1 = count1 + 1;
            }
            else if (count2 == 0)
            {
                element2 = nums[i];
                count2 = count2 + 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int val1 = 0;
        int val2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == element1)
            {
                val1++;
            }
            else if (nums[i] == element2)
            {
                val2++;
            }
        }
        int n = nums.size() / 3;
        vector<int> v;
        if (val1 > n)
        {
            v.push_back(element1);
        }
        if (val2 > n)
        {
            v.push_back(element2);
        }
        return v;
    }
};