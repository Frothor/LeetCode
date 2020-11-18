class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        
        for(int i = 0, len = a.size(); i < len; ++i) {
            int start = a[i][0];
            int end   = a[i][1];
            while(i < len-1 && end >= a[i+1][0])    end = max(end, a[++i][1]);
            ans.push_back({start, end});            
        }
        
        return ans;
    }
};

//Third fastest
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int arr[10002];
        memset(arr,0,10002);
        int maxv = INT_MIN;
        vector<vector<int>> ans;
        for(int i =0;i<intervals.size();i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(e>maxv)
                maxv = e;
            if(s==e)
            {
                if(arr[s]==0)
                    arr[s] = 4;
                continue;
            } 
            
            if(arr[s]==0 || arr[s]==1 || arr[s]==4)
                arr[s] = 1;
            else
                arr[s] = 2;
            for(int k = s+1;k<e;k++)
                arr[k] = 2;
            if(arr[e]==0 || arr[e]==3 || arr[e]==4)
                arr[e] = 3;
            else
                arr[e] = 2;
        }
        int st,en;
        int f=0;
        for(int i=0;i<=maxv;i++)
        {
            if(arr[i]==1 && f==0)
            {
                st = i;
                f=1;
            } else if(arr[i]==3 && f==1)
            {
                f = 0;
                en = i;
                vector<int> val;
                val.push_back(st);
                val.push_back(en);
                ans.push_back(val);
            } else if(arr[i]==4)
            {
                vector<int> val;
                val.push_back(i);
                val.push_back(i);
                ans.push_back(val);
            }
        }
        if(f==1)
        {
           vector<int> val;
            val.push_back(st);
            val.push_back(maxv);
            ans.push_back(val); 
        }
        return ans;
    }
};

//Secondf fastest
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        res.push_back(intervals.front());
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i, n = intervals.size();
        vector<pair<int, int>> v;
        for(i=0;i<n;i++){
            v.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        sort(v.begin(), v.end());
        if(n == 0){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        int start = v[0].first;
        int end = v[0].second;
        for(i=1;i<n;i++){
            if(end >= v[i].first){
                end = max(end, v[i].second);
            }else{
                vector<int> interval;
                interval.push_back(start);
                interval.push_back(end);
                ans.push_back(interval);
                start = v[i].first;
                end = v[i].second;
            }
        }
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        ans.push_back(interval);
        return ans;
    }
};