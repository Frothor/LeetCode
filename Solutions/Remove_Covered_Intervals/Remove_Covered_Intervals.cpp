class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &I)
    {
        sort(I.begin(), I.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = I.size();
        int i = 0;
        while (i < I.size())
        {
            // cout << I[i][0] << endl;
            int j = i + 1;
            while (j < I.size() && I[j][1] <= I[i][1])
            {
                ans--;
                j++;
            }
            // cout << j << endl;
            i = j;
        }
        return ans;
    }
};

//Second fastest
bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0])
    {
        if (a[0] < b[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (a[1] < b[1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);

        int left = intervals[0][0];
        int right = intervals[0][1];
        //cout << left << " " << right;
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (left <= start && end <= right)
            {
                cnt++;
            }
            else
            {
                left = start;
                right = end;
            }
        }
        return intervals.size() - cnt;
    }
};

//Fastest
class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1])
            return a[1] < b[1];

        return a[0] > b[0];
    }
    int removeCoveredIntervals(vector<vector<int>> &in)
    {

        int n = in.size();
        //sort(in.begin(),in.end(),compare);
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    if (in[j][0] <= in[i][0] && in[j][1] >= in[i][1])
                    {
                        c++;
                        break;
                    }
            }
        }
        return n - c;
    }
};