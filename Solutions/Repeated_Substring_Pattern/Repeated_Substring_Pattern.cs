public class Solution {
    public bool RepeatedSubstringPattern(string s) {
        
        bool sections = false;
        int size = 0;
        int start =0;
        
        for(int i=2; i<= s.Length; i++)
        {
            if (s.Length % i != 0) { continue; }
            
            sections = true;
            start=0;
            size = s.Length / i;
            
            for(int j=1; j< i && sections; j++)
            {
                sections = sections && CheckSection(s, start, j * size, (j+1) * size); 
                start = j * size;
            }
            
            if (sections) { return true; }
        }
        
        return false;
    }
    
    private bool CheckSection(string s, int start, int mid, int limit)
    {
        for(int i=start, j=mid; j < limit; i++, j++)
        {
            if (s[i] != s[j]) { return false; }
        }
        return true;
    }
}

//Fastest
public class Solution {
    public bool RepeatedSubstringPattern(string s) {
        int n = s.Length;
        
        int[] dp = new int[s.Length];
        
        int j=0;
        
        for(int i=1;i<n;i++)
        {
            j=dp[i-1];
            
            while(j>0&&s[i]!=s[j])
                j=dp[j-1];
            if(s[i]==s[j])
                 j++;
            dp[i]=j;
                
        }
        int len=dp[n-1];
        return len>0&& n%(n-len)==0;
    }
}