//https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/263882/C-HashSet
public class Solution {
    public int SmallestRepunitDivByK(int K) {
    int res = 1;
    int len = 1;
    HashSet<int> rests = new HashSet<int>();
    while(true) {
        res %= K;
        if(res == 0) return len;
        if(rests.Contains(res)) return -1;
        rests.Add(res);
        len++;
        res *= 10;
        res += 1;
    }
}
}

//Fastest
public class Solution {
    public int SmallestRepunitDivByK(int K) {
        int remainder = 0;
        for(int i = 1; i <= K; i++)
        {
            remainder = (remainder * 10 + 1) % K;
            if(remainder == 0)
            {
                return i;
            }
        }
        return -1;
    }
}