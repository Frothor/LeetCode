//Third fastest
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty()) return -1;
        const int n = A.size();
        int result = numeric_limits<int>::max();
        array<const int, 2> values = {A[0], A[0] == B[0]? -1 : B[0]};
        for (const auto v : values) {
            bool found = true;
            int swapsA = 0, swapsB = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] != v && B[i] != v) {
                    found = false;
                    break;
                }
                if (A[i] != v) ++swapsA;
                if (B[i] != v) ++swapsB;
            }
            if (found)
                result = min(result, min(swapsA, swapsB));
        }
        if (result == numeric_limits<int>::max()) return -1;
        return result;
    }
};

//Second fastest
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        if(A.empty()) return -1;
        int ans=INT_MAX;
        int n=A.size();
        for(int num = 1;num<=6;num++)
        {
            bool f=true;
            int cnta=0,cntb=0;
            for(int i=0;i<n;i++)
            {
                if(A[i]!=num && B[i]!=num) 
                {
                    f=false;
                    break;
                }
                else
                {
                    if(A[i]!=num) cnta++;
                    if(B[i]!=num) cntb++;
                }
            }
            if(f)
                {
                    ans = min(ans,min(cnta,cntb));
                }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

//Fastest
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty()) return -1;
        const int n = A.size();
        int result = numeric_limits<int>::max();
        array<const int, 2> values = {A[0], A[0] == B[0]? -1 : B[0]};
        for (const auto v : values) {
            bool found = true;
            int swapsA = 0, swapsB = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] != v && B[i] != v) {
                    found = false;
                    break;
                }
                if (A[i] != v) ++swapsA;
                if (B[i] != v) ++swapsB;
            }
            if (found)
                result = min(result, min(swapsA, swapsB));
        }
        if (result == numeric_limits<int>::max()) return -1;
        return result;
    }
};