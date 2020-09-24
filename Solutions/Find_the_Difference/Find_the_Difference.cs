public class Solution {
    public char FindTheDifference(string s, string t) {
        s = String.Concat(s.OrderBy(c => c));
        t = String.Concat(t.OrderBy(c => c));
        int n = s.Length;
        int i = 0;
        while(i < n)
        {
            if(s[i] != t[i])
                return t[i];
            i++;
        }
        return t[t.Length-1];
    }
}

//MostCommon
public class Solution {
    public char FindTheDifference(string s, string t) {
        
        string combine=s+t;
        
        int xor=0;
        
        foreach(char c in combine)
        {
            xor^=c;
        }
      
        return (char)xor;
    }
}

//Fastest
public class Solution {
    public char FindTheDifference(string s, string t) {
        long sum = 0;
        for (int i = 0; i < t.Length; i++){
            sum += t[i] - '0';
        }
        for (int i = 0; i < s.Length; i++){
           sum -= s[i] - '0';
        }
        return (char)(sum + '0');
    }
}