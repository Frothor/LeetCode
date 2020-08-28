class Solution {
public:
    vector<int> np;
    vector<vector<int>> Rects;
    Solution(vector<vector<int>>& rects) {
        Rects = rects;
        for(auto rect : rects){
            int l1 = rect[2] - rect[0] + 1;
            int l2 = rect[3] - rect[1] + 1;
            int val = np.size() ? np.back() + (l1*l2) : l1*l2; 
            np.push_back(val);
        }
    }
    
    vector<int> pick() {
        int m = np.back();
        int r = rand() % m;
        auto it = upper_bound(np.begin(), np.end(), r);
        int rect = it - np.begin();  //end of step 1
		//step 2 begins
        vector<int> R = Rects[rect];
        int x = rand() % (R[2]-R[0]+1) + R[0];
        int y = rand() % (R[3]-R[1]+1) + R[1];
        return {x, y};
    }
};

//Fastest
class Solution {
    unsigned int areas[100];
    unsigned int i = 0;
    default_random_engine gen;
    uniform_int_distribution<> distrib;
    vector<vector<int>> rs;
public:
    Solution(vector<vector<int>>& rects) {
        unsigned int tot = 0;
        for (const auto &r: rects) 
            areas[i++] = tot += (unsigned int)(1+r[2]-r[0])*(unsigned int)(1+r[3]-r[1]);
        distrib.param(uniform_int_distribution<>::param_type(0,tot-1));
        rs = move(rects);
    }
    
    vector<int> pick() {
        unsigned int r = distrib(gen);
        // cout << "r: " << r << endl;
        const auto ra = upper_bound(&areas[0], &areas[0]+i, r);
        r = *ra - r - 1;
        // cout << "ra: " << *ra << " new r: " << r << endl;
        const auto &tr = rs[ra - &areas[0]];
        const unsigned int w = 1+tr[2]-tr[0];
        const unsigned int y = r/w;
        const unsigned int x = r%w;
        // cout << "w: " << w << " x: " << x << " y: " << y << endl;
        return {static_cast<int>(x+tr[0]),static_cast<int>(y+tr[1])};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

static int faster=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 13;}();


//Another good
class Solution {
    vector<int> csum; //cumulative sum of points of rectangles
    vector<vector<int>> _rects; 
public:
    Solution(vector<vector<int>>& rects) { 
        // calculuate cumulative sum: 
        for (auto r: rects)
        {
            int points = ( r[2]-r[0]+1)* (r[3]-r[1]+1); 
            if (csum.size()==0)
                csum.push_back(points);
            else
                csum.push_back(points + csum.back());
        }
        _rects=rects; 
    }
    
    // 5 mistakes!!
    vector<int> pick() {
        // randomly pick one rectangle based on weights: points        
        int p = rand() %csum.back();
        
        // convert it into the points in a rectangle
        // need to calculate the distance of iterators !!
        int rect_id = upper_bound (csum.begin(), csum.end(), p) - csum.begin(); 
        
        // offset within the rectangle 
        int inner_id ; 
        if (rect_id==0) inner_id = p;
        else
            inner_id= p - csum[rect_id - 1];
        
        // convert it into a 2-D coordinates
        int v0= _rects[rect_id][0], v1=_rects[rect_id][1];
        int v2= _rects[rect_id][2], v3=_rects[rect_id][3];
        
        int col= v3-v1+1; 
        int i = inner_id/col + v0;         
        int j = inner_id%col + v1; 
        
        return {i,j}; 
    }
};