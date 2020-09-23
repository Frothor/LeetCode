class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++)
        {
            diffs[i] = gas[i] - cost[i];
        }
        int cumsum = 0, out = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cumsum += diffs[i % n];
            if (cumsum < 0)
            {
                cumsum = 0;
                out = i + 1;
            }
        }

        return out > n ? -1 : out;
    }
};

//Fastest
auto x = ([]() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
})();

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        auto index = 0;
        auto increments = 0;
        auto start = 0;
        auto tank = 0;

        while (increments < 2 * gas.size())
        {
            // At the current station
            tank += gas[index] - cost[index];
            index = (index + 1) % gas.size();
            increments++;

            if (index == start && tank >= 0)
                return index;
            if (tank <= 0)
            {
                // Start from next
                tank = 0;
                start = index;
                continue;
            }
        }
        return -1;
    }
};