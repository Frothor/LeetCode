class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> intersection;
    
        int i = 0, j = 0;
    
        while (i < A.size() && j < B.size()) {
            int interval_min = max(A[i][0], B[j][0]);
            int interval_max = min(A[i][1], B[j][1]);
        
            if (interval_min <= interval_max){
                vector<int> tmp = {interval_min, interval_max};  
                intersection.push_back(tmp);  
            } 
        
            A[i][1] > B[j][1] ? j++ : i++; 
        }
    
        return intersection;
    }
};

/*
Fastest:

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size()==0 || B.size()==0)
            return {};
        
        int i = 0;
        int j = 0;
        
        vector<vector<int>> ans;
        ans.reserve(max(A.size(),B.size()));
        while (i < A.size() && j < B.size()){
            if (A[i][1]<B[j][0]) // not overlaps (A then B)
                i++;
            else if (B[j][1]<A[i][0]) // not overlaps (B then A)
                j++;
            else {
                int begin = max(A[i][0],B[j][0]);
                int end = min(A[i][1],B[j][1]);
                vector<int> interval{begin,end};
                
                ans.emplace_back(interval);

                if (A[i][1] <= ans.back()[1])
                    i++;
                if (B[j][1] <= ans.back()[1])
                    j++;                 
            } 
         }
        
        return ans;
    }
};
// Time: O(max(n,m))
// Space: O(1), without extra space


Most Common: 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        for(int i = 0, iEnd = A.size(), j = 0, jEnd = B.size(); i < iEnd && j < jEnd;){
            if(A[i][1] < B[j][0]){
                i++;
            }
            else if (B[j][1] < A[i][0]){
                j++;
            }
            else{
                result.emplace_back(2);
                result.back()[0] =  max(A[i][0], B[j][0]);
                result.back()[1] = min(A[i][1], B[j][1]);
                if(A[i][1] < B[j][1]){
                    i++;
                }
                else if (A[i][1] > B[j][1]){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return result;
    }
};
*/