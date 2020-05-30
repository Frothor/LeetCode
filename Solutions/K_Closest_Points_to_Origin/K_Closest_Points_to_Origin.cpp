class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        auto cmp = [](const vector<int>& p1, const vector<int> &p2)
        { return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]); };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for(auto p: points){
            q.push(p);
            if(q.size() > K)
                q.pop();
        }
        
        while(K--){
            result.push_back(q.top());
            q.pop();            
        }
  
        return result;
    }
};


/*
Most common:
class Solution {
public:
    struct comp{
       bool operator()(pair<int,int> &p1,pair<int,int> &p2){
           return (p1.first*p1.first+p1.second*p1.second)>(p2.first*p2.first+p2.second*p2.second);
       }  
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
          
        vector<vector<int>> ans(K);
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        for(auto it : points){
            pq.push({it[0],it[1]});
        }
        int i  =0 ;
        while(K--){
            ans[i]={pq.top().first,pq.top().second}; pq.pop();
            i++;
        }
        return ans;
    }
};

Second most common:
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), CompareDistanceLess());
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }
    
private:

    static  int getDistanceFromOrigin(int x, int y) {
        return x*x + y*y;
    }
    struct CompareDistance {
        bool operator() (const vector<int> &lhs, const vector<int> &rhs) {
            return getDistanceFromOrigin(lhs[0], lhs[1]) > getDistanceFromOrigin(rhs[0], rhs[1]); 
        }
    };
    
    struct CompareDistanceLess {
      bool operator() (const vector<int> &lhs, const vector<int> &rhs) {
            return getDistanceFromOrigin(lhs[0], lhs[1]) < getDistanceFromOrigin(rhs[0], rhs[1]); 
        }  
    };
};

Fastest:
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

//解法与寻找前k大元素相同
inline int partition(std::vector<std::vector<int>> &p,int first,int last){
    int dis = p[last][0]*p[last][0] + p[last][1]*p[last][1];
    int i = first;
    for(int j=first;j<last;j++){
        int x = p[j][0]*p[j][0] + p[j][1]*p[j][1];
        if(x<dis){
            std::swap(p[i][0],p[j][0]);
            std::swap(p[i][1],p[j][1]);
            i++;
        }
    }
    std::swap(p[i][0],p[last][0]);
    std::swap(p[i][1],p[last][1]);    
    return i;
}

void get_res(std::vector<std::vector<int>> &p,int first,int last,int k){
    int mid = partition(p,first,last);
    if(mid-first<k-1){
        get_res(p,mid+1,last,k-mid+first-1);
    }else if(mid-first>k){
        get_res(p,first,mid-1,k);    
    }
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(K<points.size()){
            get_res(points,0,points.size()-1,K);
            points.resize(K);
        }
        return std::move(points);
    }
};
*/