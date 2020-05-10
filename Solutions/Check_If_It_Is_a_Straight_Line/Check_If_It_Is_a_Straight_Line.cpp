class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = coordinates.size();
        int xdiff = abs(coordinates[1][0] - coordinates[0][0]);
        int ydiff = abs(coordinates[1][1] - coordinates[0][1]);
        int curr_xdiff, curr_ydiff;
        
        for(int i=2; i<n; i++){
            int curr_xdiff = abs(coordinates[i][0] - coordinates[i-1][0]);
            int curr_ydiff = abs(coordinates[i][1] - coordinates[i-1][1]);
            if(ydiff*curr_xdiff != xdiff*curr_ydiff)
                return false;
        }
        return true;
    }
};

/*
Other solution:
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //y=mx+c
        //Find m
        double m=0;
        double num=coordinates[1][1]-coordinates[0][1];
        double den=coordinates[1][0]-coordinates[0][0];
        m=(num/den);
        double c=(coordinates[0][1]-(m*coordinates[0][0]));
        
        for(int i=2;i<coordinates.size();i++)
        {
            if((coordinates[i][1]-(m*coordinates[i][0]))!=c)
                return false;
        }
        
        return true;
        
    }
};


Other:
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = abs(double(coordinates[0][1] - coordinates[1][1]) / double(coordinates[0][0] - coordinates[1][0]));
        
        for (int i = 2; i < coordinates.size(); ++i) {
            double other = abs(double(coordinates[0][1] - coordinates[i][1]) / double(coordinates[0][0] - coordinates[i][0]));
            
            if (other != slope) {
                return false;
            }
        }
        
        return true;
    }
};


Fastest:
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(coordinates.size()==2)
            return true;
        else if(coordinates[0][0]==coordinates[1][0])
        {
            int x = coordinates[1][0];
            for(int i=0;i<coordinates.size();i++)
            {
                if(coordinates[i][0]!=x)
                    return false;
            }
        }
        else if(coordinates[0][1]==coordinates[1][1])
        {
            int x = coordinates[1][1];
            for(int i=0;i<coordinates.size();i++)
            {
                if(coordinates[i][1]!=x)
                    return false;
            }
        }
        else
        {
            int x1 = coordinates[0][0];
            int y1 = coordinates[0][1];
            float m = (coordinates[1][1] - y1)/(coordinates[1][0] - x1);
            for(int i=2;i<coordinates.size();i++)
            {
                float m2 = (float)(coordinates[i][1] - y1)/(coordinates[i][0] - x1);
                //cout<<m2<<" ";
                if(m2!= m)
                    return false;
            }
        }
        return true;
    }
};

Most common:
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int,int>>ans(N+1,{0,0});
        for(int i=0;i<trust.size();i++)
        {
            ans[trust[i][0]].first++;
            ans[trust[i][1]].second++;
        }
        for(int i=1;i<N+1;i++)
        {
            if(ans[i].first==0&&ans[i].second==N-1)
                return i;
        }
        return -1;
    }
};
*/