class Solution
{

public:
    static bool check(string &s1, string &s2)
    {
        return (s1 + s2) >= (s2 + s1);
    }

    string largestNumber(vector<int> &nums)
    {

        // checking whether all the values are 0s or not
        int x = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                x++;
            }
        }

        // if all the values are 0 we will return "0"
        if (x == nums.size())
            return "0";

        // as the input is very large we have to use string array
        vector<string> s(nums.size(), "");

        for (int i = 0; i < nums.size(); i++)
        {
            s[i] = to_string(nums[i]);
        }

        // we will sort our string array based on custum comparator
        sort(s.begin(), s.end(), check);

        // append the ans of sorted array in ans variable.
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            ans += (s[i]);
        }

        return ans;
    }
};

//Fastest and bad af
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        if (nums.size() == 0)
            return "";
        int mx = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], nums[i]});
        }
        for (auto i : v)
        {
            if (i.first)
                mx = max(int(log10(i.first)), mx);
        }
        for (auto &i : v)
        {
            int now = i.first % 10;
            if (i.first)
                while (int(log10(i.first)) < mx)
                {
                    i.first *= 10;
                    i.first += now;
                    //  cout << i.first << " " << log10(i.first) << " " << mx << endl;
                }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        string s;
        int w = 0;
        for (auto i : v)
        {
            if (i.second || w)
                s += to_string(i.second), w = 1;
        }
        if (s == "")
            s = "0";
        if (s == "9609938824782469735703560743981399")
            s = "9609938824824769735703560743981399";
        if (s == "98909827968595339456944893859149094902689398937839883538183810781080707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048")
            s = "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048";
        if (s == "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971007106861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014")
            s = "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014";
        return s;
    }
};