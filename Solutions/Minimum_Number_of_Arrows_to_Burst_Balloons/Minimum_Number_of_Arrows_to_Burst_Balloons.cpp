    bool comp(const vector<int> &t1,const vector<int> &t2)
{
	return (t1[1]<t2[1]) ;
}
class Solution {

public:
    int findMinArrowShots(vector<vector<int>>& points) {
    
    
    if(points.size()==0) return 0;
    
    if(points.size()==1) return 1;
    
    
    sort(points.begin(),points.end(),comp);
    
    int count=1;
    int prev=points[0][1];
    
    for(int i=1;i<points.size();i++)
    {
        if(points[i][0]<=prev) continue; // overlapping part
        
        count++;
        prev=points[i][1];
    }
    
    //++arrow_cnt;//for last arrow
    return count;
    
}
};

//Second fastest
class Solution {
public:
    static bool comp (pair<int, int>& i, pair<int, int>& j) { 
        return i.second < j.second; 
    }
    
    int findMinArrowShots(vector<vector<int>>& p) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        size_t n = p.size();
        if (n == 0)
            return 0;
        vector<pair<int, int>> interval;
        for(int i = 0; i < n; ++i){
            interval.push_back({p[i][0], p[i][1]});
        }
        sort(interval.begin(), interval.end(), comp);
        
        int res = 1;
        int ce = interval[0].second;
        for (int i = 1; i < n; ++i) {
            if (interval[i].first <= ce)
            {
                continue;
            } else {
                ce = interval[i].second;
                ++res;    
            }
                
            
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    static bool comp (pair<int, int>& i, pair<int, int>& j) { 
        return i.second < j.second; 
    }
    
    int findMinArrowShots(vector<vector<int>>& p) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        auto n = p.size();
        if (n == 0)
            return 0;
        int i;
        vector<pair<int, int>> interval;
        for(i = 0; i < n; ++i){
            interval.push_back({p[i][0], p[i][1]});
        }
        sort(interval.begin(), interval.end(), comp);
        
        auto res = 1;
        auto ce = interval[0].second;
        for (i = 1; i < n; ++i) {
            if (interval[i].first <= ce)
            {
                continue;
            } else {
                ce = interval[i].second;
                ++res;    
            }
                
            
        }
        return res;
    }
};