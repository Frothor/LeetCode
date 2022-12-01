public class Solution 
{
    public int LengthOfLongestSubstring(string s) 
    {
        var maxlen = 0;
        var lastIndexByChar = Enumerable.Repeat(-1, 128).ToArray();
        
        for (int i = 0, start = -1; i < s.Length; i++)
        {
            var c = (int)s[i];
            start = Math.Max(start, lastIndexByChar[c]);
            maxlen = Math.Max(maxlen, i - start);            
            lastIndexByChar[c] = i;
        }
        
        return maxlen;
    }
}

// Third fastest
public class Solution {
    public int LengthOfLongestSubstring(string s) 
    {
        if(string.IsNullOrEmpty(s)) return 0;
        
        Dictionary<char, int> map = new Dictionary<char, int>();
        
        int i = 0;
        int j = 0;
        int max = 0;
        
        while(j < s.Length)
        {
            if(!map.ContainsKey(s[j]))
            {
                map.Add(s[j], j);
            }
            else
            {
                int index = map[s[j]];
                
                if(index >= i)
                {
                    i = index + 1;
                }
                map[s[j]] = j;
            }
            
            max = Math.Max(max, j - i + 1);    
            
            j++;
        }
        
        return max;
    }
}

// Second fastest
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        if(s == null || s.Length <= 0) return 0;
        HashSet<int> result = new HashSet<int>();
        int l = 0; 
        int maxLength = 0;
        
       
      for(int i = 0;  i < s.Length; i++){
          while(result.Contains(s[i])){
              result.Remove(s[l]);
              l++;
          }
          maxLength = Math.Max(maxLength, i - l + 1);
          result.Add(s[i]);
      }
        
        return maxLength;
       
    }
}

// Fastest
public class Solution {
    public int LengthOfLongestSubstring(string s) {
       HashSet<char> vs = new HashSet<char>();
            int left = 0;
            int length = 0;
            int ll = 0;
            for (int right=0;right < s.Length; right++)
            {
                if (!vs.Contains(s[right])){

                    vs.Add(s[right]);
                    ll += 1;
                }
                else
                {

                    length = Math.Max(length, ll);
                    while (left < right)
                    {
                        if (s[left] != s[right])
                        {
                            vs.Remove(s[left]);
                            ll--;

                        }
                        else
                        {
                           
                            left++;
                            
                            break;
                        }
                        
                        left++;
                    }
                 
                }
            }
            length = Math.Max(length, ll);
        return length;
    }
}