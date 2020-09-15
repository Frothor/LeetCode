public class Solution {
    public int LengthOfLastWord(string s) {
        if(string.IsNullOrEmpty(s))
            return 0;
        
        var words = s.Split(' ');
        var idxOfLastWord = words.Length - 1;
        
        while(string.IsNullOrEmpty(words[idxOfLastWord]) && idxOfLastWord > 0)
        {
            Console.WriteLine(idxOfLastWord);
            idxOfLastWord -= 1;
        }
        
        return idxOfLastWord < 0 ? 0 : words[idxOfLastWord].Length;
    }
}

//Most common
public class Solution {
    public int LengthOfLastWord(string s) {
        if(s == null){
            return 0;
            
        }
        if (s.Length == 0){
            return 0;
        }
        List<string> cuvinte = s.Split(" ").ToList();
        cuvinte = cuvinte.Where(x => !string.IsNullOrEmpty(x)).ToList();
        if (cuvinte.Count ==0){
            return 0;
        }
        return cuvinte[cuvinte.Count-1].Length;
        
    }
}

//Fastest
public class Solution {
    public int LengthOfLastWord(string s) {
        if(string.IsNullOrWhiteSpace(s))
        {
            return 0;
        }
        
        var j = s.Length-1;
        
        while(j >= 0 && s[j] == ' ')
        {
            j--;
        }
        
        var len = 0;
        
        while(j >= 0 && s[j] != ' ')
        {
            j--;
            len++;
        }
        
        return len;
    }
}