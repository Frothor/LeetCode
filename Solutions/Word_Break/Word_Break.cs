//Most common
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> hs = new HashSet<string>(wordDict);
        
        bool[] result = new bool[s.Length+1];
        result[0] = true;
        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (result[j] && hs.Contains(s.Substring(j, i-j+1)))
                {
                    result[i+1] = true;
                    break;
                }
            }
        }
        
        return result[result.Length - 1];
    }
}

//DP solution
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        int n = s.Length;
        bool[] dp = new bool[n+1];
        dp[0] = true;
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && wordDict.Contains(s.Substring(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}

//DFS backtracking with memoization
public class Solution {
    
    public bool WordBreak(string s, IList<string> wordDict) {
        HashSet<string> set = new HashSet<string>();
        foreach( var word in wordDict)
            set.Add(word);
        bool?[] memo = new bool?[s.Length];
        return dfs(s, set, 0, memo);
        
    }
    
    public bool dfs(string s, HashSet<string> set, int start, bool?[] memo )
    {
        if(start == s.Length)
        {            
            return true;
        }
        if(memo[start] != null)
            return (bool)memo[start];
        
        for(int i = start; i < s.Length; i++)
        {
            if(set.Contains(s.Substring(start, i - start + 1)) && dfs(s, set, i + 1, memo))
            {
                memo[start] = true;
                return true;
            }          
        }
        memo[start] = false;
        return false;
    }
}

//Fastest
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) 
    {        
        ISet<int> words = new HashSet<int>();
        int maxlen = 1;
        foreach (string word in wordDict)
        {
            int hash = 0;
            for (int i = 0; i < word.Length; i++)
            {
                char val = word[i];
                hash = (hash << 7) ^ val ^ (hash >> 25);
            }

            if (word.Length > maxlen) maxlen = word.Length;
            words.Add(hash);
        }

        string[] builders = new string[s.Length];
        return Recurse2(0, builders,s,maxlen,words);
    }
    const string Bad="B";

    private static bool Recurse2(int index,string[] builders,string s, int maxlen, ISet<int> words)
    {
        var builder = builders[index];
        if (builder!= null) return builder.Length == 0 ;
        int maxi = Math.Min(index+maxlen, s.Length);
        int hash = 0;
        bool hadTrue = false;
        for (int i = index; i < maxi; i++)
        {
            char c = s[i];
            hash = (hash << 7) ^ c ^ (hash >> 25);
            if (words.Contains(hash))
            {
                if (i == s.Length - 1)
                {
                    builders[index]= string.Empty;
                    return true;
                }
                else
                {
                    if (Recurse2(i + 1, builders, s, maxlen, words))
                    {
                        builders[index]= string.Empty;
                        return true;
                    }
                }
            }
        }
        builders[index]= Bad;
        return false;
    }
}