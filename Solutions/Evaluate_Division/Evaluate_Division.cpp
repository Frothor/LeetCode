class Solution
{
private:
    unordered_map<string, vector<pair<string, double>>> graph; // adjacency list

    pair<bool, double> search(string &a, string &b, unordered_set<string> &vis, double val)
    {
        if (vis.count(a) == 0)
        {
            vis.insert(a); // mark a as visited
            for (auto p : graph[a])
            {
                double temp = val * p.second;
                if (p.first == b)
                {
                    return make_pair(true, temp);
                } // found result
                auto result = search(p.first, b, vis, temp);
                if (result.first)
                {
                    return result;
                } // found result
            }
        }
        return make_pair(false, -1.0);
    }

public:
    vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &val, vector<vector<string>> q)
    {
        vector<double> ans;
        for (int i = 0; i < eq.size(); ++i)
        {
            graph[eq[i][0]].push_back(make_pair(eq[i][1], val[i]));       // build graph list a->b
            graph[eq[i][1]].push_back(make_pair(eq[i][0], 1.0 / val[i])); // build graph list b->a
        }
        for (auto p : q)
        {
            unordered_set<string> vis; // to record visited nodes
            if (p[0] == p[1] && graph.count(p[0]))
                ans.push_back(1.0);
            else
                ans.push_back(search(p[0], p[1], vis, 1.0).second);
        }
        return ans;
    }
};

//Fastest
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        if (equations.empty() || queries.empty())
            return {};
        const int n = values.size();
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < n; i++)
        {
            m[equations[i][0]].emplace(equations[i][1], values[i]);
            m[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
            m[equations[i][0]].emplace(equations[i][0], 1.0);
            m[equations[i][0]].emplace(equations[i][1], 1.0);
        }
        for (auto query : queries)
        {
            if (!m.count(query[0]) || !m.count(query[1]))
            {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visited{query[0]};
            q.push({query[0], 1.0});
            bool found = false;
            while (!q.empty() && !found)
            {
                auto pair = q.front();
                q.pop();
                //std::cout<<pair.first<<" "<<endl;
                if (query[1] == pair.first)
                {
                    found = true;
                    res.push_back(pair.second);
                    break;
                }
                for (auto t : m[pair.first])
                {
                    if (visited.count(t.first))
                        continue;
                    visited.insert(t.first);
                    t.second *= pair.second;
                    q.push(t);
                }
            }
            if (!found)
                res.push_back(-1.0);
        }
        return res;
    }
};