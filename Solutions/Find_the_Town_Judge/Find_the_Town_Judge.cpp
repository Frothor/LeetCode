class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> arr(N, 0);
        
        for(int i=0; i < trust.size(); i++){
            arr[trust[i][0] - 1]--;
            arr[trust[i][1] - 1]++;
        }
        
        int res = -1;
        
        for(int i=0; i<N; i++){
            if(arr[i] == N-1)
                return i+1;
        }
        
        return res;
    }
};


/*
Way quicker:

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_tb(N+1, 0);
        vector<int> trusted_tb(N+1, 0);
        
        int L = trust.size();
        
        for(int i=0; i<L; i++){
            int a, b;
            a = trust[i][0];
            b = trust[i][1];
            
            trusted_tb[b]++;
            trust_tb[a]++;
        }
        
        int p = 0, J = -1;
        
        for(int i=1; i<=N; i++){
            if (trust_tb[i]==0 && trusted_tb[i]==N-1){
                p++;
                J = i;
            }
        }
        
        if(p > 1){
            J = -1;
        }
        
        return J;
    }
};


Quickest:
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        unordered_map<int,pair<int,int>> m;
        for(int i=1;i<=N;i++){
            pair<int,int> p;
            p.first=p.second=0;
            m.insert(make_pair(i,p));
        }
        for(int i=0;i<trust.size();i++){
            auto it = m.find(trust[i][0]);
            it->second.second++;
            it=m.find(trust[i][1]);
            it->second.first++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second.first>=N-1 && i->second.second==0)
                return i->first;
        }
        return -1;
    }
};

*/