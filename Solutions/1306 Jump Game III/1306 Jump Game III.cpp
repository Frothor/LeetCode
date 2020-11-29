//Fourth fastest
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            
            if (arr[index] == 0)
                return true;
            
            if (index + arr[index] < arr.size() && !visited[index + arr[index]]) {
                q.push(index + arr[index]);
                visited[index + arr[index]] = true;
            }
            
            if (index - arr[index] >= 0 && !visited[index - arr[index]]) {
                q.push(index - arr[index]);
                visited[index - arr[index]] = true;
            }    
        }
        return false;
    }
};

//Third fastest
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        queue<int> q; q.push(start);
        while (!q.empty()) {
            int curr = q.front();
            if (arr[curr] == 0) {
                return true;
            }
            q.pop();
            if(!visited[curr]) {
                visited[curr] = 1;
                if (curr - arr[curr] >= 0) q.push(curr - arr[curr]);
                if (curr + arr[curr] < arr.size()) q.push(curr + arr[curr]);
            }
        }
        return false;
    }
};

//Second fastest
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n,false);
        return bfs(start,visited,arr);
    }
    bool bfs(int node,vector<bool>& visited,vector<int>& arr){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        queue<int> q;
        int n=arr.size();
        q.push(node);
        visited[node]=true;
        if(arr[node]==0) return true;
        while(q.empty()==false){
            int temp=q.front();
            q.pop();
            int forward=temp+arr[temp];
            int backward=temp-arr[temp];
            if(forward<n){
                if(!visited[forward]){
                    q.push(forward);
                    visited[forward]=true;
                }
                if(arr[forward]==0) return true;
            }
            if(backward>=0){
                if(!visited[backward]){
                    q.push(backward);
                    visited[backward]=true;
                }
                if(arr[backward]==0) return true;
            }
        
        }
        return false;
    }
};

//Fastest
class Solution {
public:
    void dfs(int s, vector<int> &arr, int n,vector<bool>&vis, int &t)
    {
        vis[s] = true;
        if(arr[s]==0)
        {
            t=1;
            return;
        }
        //bool a=false,b=false;
        if(s+arr[s]<n && s+arr[s]!=s && vis[s+arr[s]]==false)
             dfs(s+arr[s],arr,n,vis,t);
        if(s-arr[s]>=0 && s-arr[s]!=s && vis[s-arr[s]]==false)
            dfs(s-arr[s],arr,n,vis,t);
        return;  
            
    }
    bool canReach(vector<int>& arr, int start) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = arr.size();
        if(arr[start]==0)
            return true;
        vector<bool>vis(n,false);
        int t=0;
        
        dfs(start,arr,n,vis,t);
        if(t)
            return true;
        return false;
    }
};