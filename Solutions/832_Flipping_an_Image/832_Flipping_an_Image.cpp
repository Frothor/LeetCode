//Second fastest
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); i++) {
            reverse(A[i].begin(), A[i].end());
            for (int j=0; j<A[i].size(); j++) {
                A[i][j] ^= 0x1;
            }
        }
        return A;
    }
};

//Another
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

for(int j=0;j<A.size();j++){
    int n=A[j].size();
   if(n%2!=0) 
  A[j][(n/2)]=!A[j][(n/2)];
for(int i=0;i<n/2;i++){
if(A[j][i]==A[j][n-1-i])
    {int x=!A[j][i];
     A[j][i]=x;
   A[j][n-1-i]=x;}
 }
     }
        return A;
    }
};

//Fastest
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        bool isOdd = A[0].size() % 2;
        int center;
        if (isOdd) center = A[0].size() / 2;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0, k = A[i].size() - 1; j < k; j++, k--) {
                int t = A[i][j];
                A[i][j] = A[i][k];
                A[i][k] = t;
                A[i][j] ^= 1;
                A[i][k] ^= 1;
            }
            if (isOdd) A[i][center] ^= 1;
        }
        return A;
    }
};