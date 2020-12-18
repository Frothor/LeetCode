class Solution { //hashmap
public: // Time/Space Complexity: O(N^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> m;
        for(int a: A)
            for(int b: B)
                ++m[a+b];
        for(int c: C)
            for(int d: D)
                ans+=m[-(c+d)];
        return ans;
    }
};

//Third fastest
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // Brute force would take O(n^4) time with nested loops for i,j,k,l.
        // Use divide and conquer approach using tallies.
        // Store tallies of A, B, C, D into a, b, c, d in O(n) time.
        // Store tallies of sums of A, B into ab in O(n^2) time.
        // Count combinations of sums of C, D with compliment sums in ab in O(n^2) time.
        // Overall algorithm runs in O(n^2) time.
        if (A.size() == 0) return 0;
        Counter a, b, c, d, ab;
        for (int num: A) ++a[num];
        for (int num: B) ++b[num];
        for (int num: C) ++c[num];
        for (int num: D) ++d[num];
        for (auto& i: a) for (auto& j: b) ab[i.first + j.first] += i.second * j.second;
        int cnt=0;
        for (auto& k: c) for (auto& l: d) {
            const auto& f = ab.find(-(k.first + l.first));
            if (f != ab.end()) cnt += k.second * l.second * f->second;
        }
        return cnt;
    }
private:
    typedef unordered_map<int,int> Counter;
};

//Second fastest
static const int N = 262139;
static pair<int, uint16_t> H[N][10];
static void I(int a) {
    int i = ((a % N) + N) % N;
    int& c = H[i][0].first;
    for (int j = 1; j <= c; j++)
        if (H[i][j].first == a) {
            H[i][j].second++;
            return;
        }
    H[i][++c] = {a, 1};
}
static int O(int a) {
    int i = ((a % N) + N) % N;
    int c = H[i][0].first;
    for (int j = 1; j <= c; j++)
        if (H[i][j].first == a)
            return H[i][j].second;
    return 0;
}

class Solution {
public:
    static int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        memset(H, 0, sizeof(H));
        for (int i : A)
            for (int j : B)
                I(i + j);
        int e = 0;
        for (int i : C)
            for (int j : D)
                e += O(-(i + j));
        return e;
    }
};
static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr); return 0;
}();

//Fastest
const int N=360007;
class Hash{
int keys[N]={0}, values[N]={0};
public:
    Hash(){
        memset(values, 0, sizeof(values));
    }
    int& operator [](int n){
        int idx = (n%N + N)%N, cnt=1;
        while(keys[idx]!=n && values[idx]!=0){
            idx = (idx+cnt*cnt)%N;
            cnt += 1;
        }
        keys[idx] = n;
        return values[idx];
    }
};

class Solution {
public:

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty()){
            return 0;
        }
        int N = A.size(), re = 0;
        // map<int, int> m;
        Hash m;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int ps = A[i]+B[j];
                m[ps] += 1;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int ps = C[i] + D[j];
                re += m[-ps];
                
            }
        }
        return re;
    }
};