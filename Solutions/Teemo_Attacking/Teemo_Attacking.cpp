class Solution
{
public:
    int findPoisonedDuration(vector<int> &s, int d)
    {
        // support variables
        int res = 0, len = s.size() - 1;
        // edge case
        if (len == -1)
            return res;
        // computing the overall poison for all attacks but last
        for (int i = 0; i < len; i++)
            res += min(s[i + 1] - s[i], d);
        return res + d;
    }
};

//Fastest
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.size() == 0 || duration == 0)
            return 0;
        int total = 0;
        int precursor = timeSeries[0];
        for (auto value : timeSeries)
        {
            total += min(duration, value - precursor);
            precursor = value;
        }
        return total + duration;
    }
};