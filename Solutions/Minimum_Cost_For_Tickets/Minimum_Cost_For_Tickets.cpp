class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int minCost[366];
        minCost[0] = 0;
        
        unordered_map<int,bool> daysIncluded;
        for(auto day : days)
            daysIncluded[day]=true;
        
        for(int i=1;i<=365;i++)
        {
            if(!daysIncluded[i])
                minCost[i]=minCost[i-1];
            else
            {
                int _1DayPass = minCost[i-1] + costs[0];
                int _7DayPass = minCost[max(0,i-7)] + costs[1];
                int _30DayPass = minCost[max(0,i-30)] + costs[2];

                minCost[i] = min(_1DayPass,min(_7DayPass,_30DayPass));
            }
        }
        return minCost[365];
    }  
};

//Most common
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), numeric_limits<int>::max());
        vector<int> C(30);
        
        int cur_cost = costs[2];
        for(int i = 29; i >= 0; i--){
            if( i == 6 )
                cur_cost = min( cur_cost, costs[1] );
            if( i == 0 )
                cur_cost = min( cur_cost, costs[0] );
            C[i] = cur_cost;
        }
        
        for(int i = 0; i < days.size(); i++){
            if( days[0] + 30 <= days[i] )
                break;
            dp[i] = min( dp[i], C[days[i] - days[0]] );
        }
        
        for(int i = 1; i < days.size(); i++){
            for(int j = i; j < days.size(); j++){
                if( days[i] + 30 <= days[j] )
                    break;
                dp[j] = min( dp[j], C[days[j] - days[i]] + dp[i-1] );
            }
        }
        
        return dp.back();
    }
};

//Fastest
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366),vis(366,0);
        for(auto i:days) {
            vis[i] = 1;
        }
        if(days.size()==0) return 0;
        dp[0]=0;
        for(int i=1; i<=365; i++) {
            if(vis[i]==0){dp[i]=dp[i-1]; continue;}
            int m = dp[i-1]+costs[0];
            if(i-7>=0) {
                m = min(dp[i-7]+costs[1],m);
            } else {
                m = min(dp[0]+costs[1],m);
            }
            if(i-30>=0) {
                m = min(dp[i-30]+costs[2],m);
            } else {
                m = min(dp[0]+costs[2],m);
            }
            dp[i]=m;
        }
        return dp[days[days.size()-1]];
    }
};