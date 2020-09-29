class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {

        int counter = 0;

        while (n != m)
        {
            n >>= 1;
            m >>= 1;
            counter++;
        }

        return n << counter;
    }
};

/*
Curious Solution:
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
//         int x = 0;
//         if(m == n)
//             return m;
//         x = m & (m + 1);
        
//         m = m + 2;
//         for(int i = m; i <= n; i++)
//         {
//             x = x & i;
//         }
//         return x;
        
        while(m < n)
        {
            n -= (n & -n);
        }
        return n;
    }
};
*/