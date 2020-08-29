//Fastest
class Solution {
public:
    vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }
};

//Second fastest
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int j;
        
        for(int i=A.size(); i>0; i--){
            for(j=0; A[j]!=i; j++);
            reverse(A.begin(), A.begin()+j+1);
            ans.push_back(j+1);
            reverse(A.begin(), A.begin()+i);
            ans.push_back(i);
        }
        return ans;
    }
};

//Most common
class Solution {
    void pancake(vector<int>& A, int k) {
        int i = 0;
        while (i < k) {
            swap(A[i++], A[k--]);
        }
    }
    
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> B(A);
        sort(B.begin(), B.end());
        
        vector<int> result;
        for (int i = B.size() - 1; i > 0; --i) {
            if (A[i] == B[i]) {
                continue;
            }
            for (int j = i - 1; j >= 0; --j) {
                if (A[j] == B[i]) {
                    if (j != 0) result.push_back(j+1);
                    result.push_back(i+1);
                    pancake(A, j);
                    pancake(A, i);
                    break;
                }
            }
        }
        return result;
    }
};

//Another, 6*N flips
void add_6(vector<int>& res, int a, int b) {
    res.push_back(b);
    res.push_back(b - a + 1);
    if (b - a > 1)
        res.push_back(b - a);
    if (b - a - 1 > 1)
        res.push_back(b - a - 1);
    if (b - a > 1)
        res.push_back(b - a);
    res.push_back(b);
}

vector<int> pancakeSort(vector<int>& A) {
    vector<int> res;
    int* sort_A = new int[A.size()];
    for (int i = 0; i < A.size(); ++i) {
        sort_A[A[i] - 1] = i;
    }

    int temp;
    for (int i = 0; i < A.size() - 1; ++i) {
        if (sort_A[i] != i) {
            add_6(res, i + 1, sort_A[i] + 1);
            temp = A[i];
            swap(A[sort_A[i]], A[i]);
            swap(sort_A[i], sort_A[temp - 1]);
        }
    }

    return res;
}