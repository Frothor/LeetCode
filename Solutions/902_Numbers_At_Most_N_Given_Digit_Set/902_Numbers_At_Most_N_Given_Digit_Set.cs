public class Solution {
    public int AtMostNGivenDigitSet(string[] digits, int n) {
        string numstr = n.ToString();
        int m = numstr.Length;
        int res = 0;
        for(int i = 1; i<m; i++){
            res += (int)Math.Pow(digits.Length, i);
        }
        
        for(int i=0; i < m; i++){
            bool prefix = false;
            foreach(var s in digits){
                if(s[0] < numstr[i])
                    res += (int)Math.Pow(digits.Length, m - i - 1);
                else if(s[0] == numstr[i]){
                    prefix = true;
                    break;
                }
            }
            if(!prefix)
                return res;
        }
        
        return res + 1;
    }
}