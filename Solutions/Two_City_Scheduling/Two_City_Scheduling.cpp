class Solution {
    static bool compareCosts(vector<int>& a, vector<int>& b){
        return a[1]-a[0] > b[1]-b[0];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), compareCosts);
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += i >= n/2 ? costs[i][1] : costs[i][0];
        
        return ans;
    }
};

/*
Fastest:

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size(), ans=0, i;
        
        vector<pair<int, int>>vec;
        for(i=0; i<n ;i++){
            vec.push_back(make_pair(costs[i][0]-costs[i][1], i));
        }
        sort(vec.begin(), vec.end());
        
        for(i=0; i<n/2; i++){
            ans+=costs[vec[i].second][0];
        }
        
        for(i=n/2; i<n; i++){
            ans+= costs[vec[i].second][1];
        }
        
        return ans;
        
    }
};
*/