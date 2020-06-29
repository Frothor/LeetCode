class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        
        for(int i = 0; i<n; i++)
            adj[tickets[i][0]].insert(tickets[i][1]);
        
        stack<string> mystack;
        mystack.push("JFK");
        while(!mystack.empty()){
            string src = mystack.top();
            if(adj[src].size() == 0){
                ans.push_back(src);
                mystack.pop();
            } else {
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Fastest:
class Solution {
public:
    using Tickets = unordered_map<string, vector<pair<string, bool>>>;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        count = tickets.size() + 1;
        stops.resize(count);
        
        for (auto t: tickets) {
            all[t[0]].push_back({t[1], false});
        }
        for (auto &t: all) {
            auto &to = t.second;
            sort(to.begin(), to.end(), 
                [](auto &t1, auto &t2) { return t1.first < t2.first; } );
        }
        go("JFK");
        
        return stops;
    }
    
    void go(const string &from) {
        auto &to = all[from];
        for (auto &stop: to) {
            if (stop.second) { continue; }
            stop.second = true;
            go(stop.first);
        }
        stops[--count] = from;
    }
    
    
private:
    Tickets all;
    vector<string> stops;
    int count;
};
*/