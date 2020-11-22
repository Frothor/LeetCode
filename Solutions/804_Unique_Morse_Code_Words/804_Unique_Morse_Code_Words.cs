public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
        var map = new string[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        var res = new HashSet<string>();
        foreach(var word in words){
            var sb = new StringBuilder();
            foreach(var c in word.ToCharArray()){
                sb.Append(map[c-'a']);
            }
            res.Add(sb.ToString());
        }
        
        return res.Count;
    }
}

//Third fastest
public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
        string[] sa = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        var ss = new HashSet<string>();
        
        foreach (var s in words) {
            string ns = "";
            
            foreach (char c in s) {
                ns += sa[c - 'a'];
            }
            ss.Add(ns);
        }
        return ss.Count;
    }
}

//Second fastest
public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
                    var morsesCode = new List<string>() { ".-", "-...", "-.-.", "-..", ".", "..-.",
                "--.", "....", "..", ".---", "-.-",
                ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                "...", "-", "..-", "...-", ".--",
                "-..-", "-.--", "--.." };
            var dictionary = new Dictionary<char, string>();
            char letter = 'a';
            foreach (var item in morsesCode)
            {
                dictionary.Add(letter, item);
                letter++;
            }

            var wordsInMoses = new List<string>();
            foreach (var item in words)
            {
                string wordInMoses = "";
                foreach (var c in item)
                {
                    wordInMoses += dictionary[c];
                }
                wordsInMoses.Add(wordInMoses);
            }
            return wordsInMoses.Distinct().Count();
    }
}

//Fastest
public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
        var morseCode = new string[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        var set = new HashSet<string>();
        for(int i=0; i<words.Length; i++) {
            var builder = new StringBuilder();
            for(int k=0; k<words[i].Length; k++) {
                builder.Append(morseCode[words[i][k]-'a']);
            }
            set.Add(builder.ToString());
        }
        return set.Count;
    }
}