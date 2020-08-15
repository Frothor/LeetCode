class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0, r = INT_MIN;
        sort(intervals.begin(), intervals.end(), [](auto x, auto y){return x[1] < y[1];}); 
        for(auto x: intervals) x[0] >= r ? r = x[1] : ans++;                               
        return ans;
    }
};

//Most common
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(),i,currindx,count=0;
        
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            //sort acc to end time
            //if there is a clash order doesn't matter
            return a[1]<b[1];
        });
        
        i=0;
        int j;
        while(i<n)
        {
            currindx=i;
            j=currindx+1;
            while(j<n)
            {
                if(intervals[j][0]<intervals[i][1])
                    count++;
                else
                    break;
                j++;
            }
            i=j;
        }
        return count;
    }
};

//Fastest
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        if(n == 0) return 0;
        vector<pair<int,int>> interval;
        for(int i = 0; i < n; i++)
            interval.push_back({intervals[i][0],intervals[i][1]});
        
        sort(interval.begin(),interval.end());
        
        int end = interval[0].second;
        for(int i = 1; i < n; i++){
            if(interval[i].first < end){
                ans++;
                if(interval[i].second < end)
                    end = interval[i].second;
            }
            else end = interval[i].second;
        }
        return ans;
    }
};