class Solution {
    int catalan_Number(int n){
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i=2; i<=n; i++){
            catalan[i]=0;
            for(int j=0; j<i; j++){
                catalan[i] += catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_Number(n);
    }
};

/*
Others:
class Solution {
public:
int numTrees(int n) {
int result = 0;
if (!n) return n;
vector Sum(n+1, 0);
Sum[0] = 1;
Sum[1] = 1;
for (int i = 2; i <= n; i++)
for (int j = 0; j < i; j++)
Sum[i] += Sum[j] * Sum[i - 1 - j];
return Sum[n];
}
};
*/