public class Solution {
    public int MaxPower(string s) {
        int max_pow = 0, pow = 1;
        char prev = ' ';
        
        foreach(var c in s){
            if (c==prev)
                pow++;
            else
                pow = 1;
            
            if (pow > max_pow)
                max_pow = pow;
            
            prev = c;
        }
        return max_pow;
    }
}

//Third fastest
public class Solution {
    public int MaxPower(string s) {
        int max = 1;
        int cur = 1;
        for(int i=1;i<s.Length;i++)
        {
            if(s[i]==s[i-1])
            {
                cur++;
            }
            else
            {
                max = Math.Max(cur,max);
                cur = 1;
            }
        }
        max = Math.Max(cur,max);
        return max;
    }
}

//Second fastest
public class Solution {
    public int MaxPower(string s) {
        int massimo =0, c=0;
        char carattere=' ';
        for(int i=0; i<s.Length; i++)
        {
            if(i==0)
                carattere=s[i];
            if(carattere==s[i])
                c++;
            else
            {
                
                c=1;
                carattere=s[i];
            }
            if(c>massimo)
                    massimo=c;
        }
        return massimo;
    }
}

//Fastest
public class Solution {
    public int MaxPower(string s) {
      int gMax = 0;
      int lMax = 1;
      
      char[] ca = s.ToCharArray();
      
      for(int i=1; i< s.Length; i++)
      {
        if(ca[i]!=ca[i-1])
        {
          if(lMax > gMax)
            gMax = lMax;
          
          lMax = 1;
        }
        else
          lMax++;
      }
      
      if(lMax > gMax)
        gMax = lMax;
      
      return gMax; 
    }
}