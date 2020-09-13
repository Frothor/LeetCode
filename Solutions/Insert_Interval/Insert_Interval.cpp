class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        for(int i=0; i<intervals.size(); i++) {

            //the new interval is after the range of other interval, so we can leave the current interval baecause the new one does not overlap with it
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }
            //the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if(intervals[i][0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = intervals[i];                
            }
            //the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        ans.push_back(newInterval);
        return ans;
    }
};

//Fastest
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int st=0;
        int i;
        for(i=0;i<intervals.size();i++) {
            if(newInterval[0]<=intervals[i][1]) {
                st=i;
                break;
            }
        }
        if(i==intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int end=st;
        bool inc = true;
        for(i=st;i<intervals.size();i++) {
            if(newInterval[1]<intervals[i][0]) {
                end=i;
                inc=false;
                break;
            }
            if(newInterval[1]<=intervals[i][1]) {
                end=i;
                inc=true;
                break;
            }
        }
        if(i==intervals.size()) end = i;
        if(end==st && !inc) {
            intervals.insert(intervals.begin()+st,newInterval);
            return intervals;
        }
        merge(intervals,st,inc ? end : end-1);
        intervals[st][0] = min(intervals[st][0], newInterval[0]);
        intervals[st][1] = max(intervals[st][1], newInterval[1]);
        return intervals;
    }
    void merge(vector<vector<int>>& intervals,int i,int j) {
        j = min(j,int(intervals.size()-1));
        intervals[i][1] = intervals[j][1];
        if((i+1)>=intervals.size() || (i+1)>j) return;
        intervals.erase(intervals.begin()+i+1,intervals.begin() + j + 1);
    }
};