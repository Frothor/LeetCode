public class Solution {
    public int RangeBitwiseAnd(int m, int n) {
        int x, mask = -1;
        for (x = n - m; x != 0; x >>= 1) mask <<= 1;
        return m & n & mask;
    }
}

//Fasest
public class Solution {
    public int RangeBitwiseAnd(int m, int n) {
        
        while (n > m) {
            n &= n - 1;
        }
        return n;
    }
}