class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v('z'+1, {0, 0});
        
        for(char c: s)
            v[c] = {v[c].first+1, c};
        
        sort(v.begin(), v.end());
        
        string result = "";
        
        for(auto p: v)
            result = string(p.first, p.second) + result;
        
        return result;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();



/*
Faster:
class Solution {
public:
    vector <int> dat;
    vector <pair <int, int> > freq;

    string frequencySort(string s) {
        dat.assign(256, 0);
        for(auto x: s)
            dat[x]++;
        for(int i = 0; i < dat.size(); i++)
            if(dat[i])
                freq.push_back({-dat[i], i});
        sort(freq.begin(), freq.end());
        string result = "";
        for(auto kv: freq)
            result += string(-kv.first, kv.second);
        return result;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
*/