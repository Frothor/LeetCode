//Third fastest
public class Solution {
    public int LongestSubstring(string s, int k)
        {
            if (string.IsNullOrEmpty(s) || s.Length < k)
                return 0;
            int[] cs = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                cs[s[i] - 'a']++;
            }
            bool correct = true;
            for (int i = 0; i < 26; i++)
            {
                if (cs[i] > 0 && cs[i] < k)
                    correct = false;
            }
            if (correct)
                return s.Length;
            int res = 0, l = 0, r = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (cs[s[i] - 'a'] < k)
                {
                    if (l == r)
                    {
                        l++;
                        r++;
                    }
                    else
                    {
                        int sub = LongestSubstring(s.Substring(l, i - l), k);
                        res = Math.Max(res,sub);
                        r = i + 1;
                        l = r;
                    }
                }
                else
                {
                    r++;
                }
            }
            if (r > l)
                res = Math.Max(res, LongestSubstring(s.Substring(l, r - l), k));
            return res;
        }
}

//Second fastest
public class Solution {
    public int LongestSubstring(string s, int k) {
        int[] charAndCount = new int[256];
        foreach (char c in s) {
            charAndCount[c]++;
        }

        for (int i = 0; i < s.Length; i++) {
            if (charAndCount[s[i]] > 0 && charAndCount[s[i]] < k) {
                // this char is wrong, either left or right has longestSubstring
                int left = LongestSubstring(s.Substring(0, i), k);
				
				i++;
				// improvement: find the first available char as the left of the rightStr part
                while (i < s.Length && charAndCount[s[i]] > 0 && charAndCount[s[i]] < k) {
                    i++;
                }

                int right = LongestSubstring(s.Substring(i), k);
                return Math.Max(left, right);
            }
        }

        return s.Length;
    }
}

//Fastest
public class Solution {
    public int LongestSubstring(string s, int k) {
        if (s == null || s.Length < k)
        {
            return 0;
        }
        
        var charToCountMap = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++)
        {
            if (charToCountMap.ContainsKey(s[i]))
            {
                charToCountMap[s[i]]++;
            }
            else
            {
                charToCountMap[s[i]] = 1;
            }
        }
        
        HashSet<char> charsToRemove = new HashSet<char>();
        
        foreach (var keyValue in charToCountMap)
        {
            if (keyValue.Value < k)
            {
                charsToRemove.Add(keyValue.Key);
            }
        }
        
        if (charsToRemove.Count == 0)
        {
            return s.Length;
        }
        
        int max = 0;        
        int start = 0;
        int end = 0;        
        while (end < s.Length)
        {
            while (end < s.Length && !charsToRemove.Contains(s[end]))
            {
                end++;
            }
            
            max = Math.Max(max, LongestSubstring(s.Substring(start, end - start), k));
                        
            end++;
            start = end;
        }
        
        return max;
    }
}