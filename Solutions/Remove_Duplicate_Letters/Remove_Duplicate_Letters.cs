public class Solution {
    public string RemoveDuplicateLetters(string s) {
        var mp = new Dictionary<char, int>();
        var res = new List<char>();
        
        for(int i = 0; i < s.Length; i++) {
            if(mp.Keys.Contains(s[i]))
                mp[s[i]]++;
            else
                mp.Add(s[i], 1);
        }
        
        for(int i = 0; i < s.Length; i++) {
            if(!res.Contains(s[i])) {
                while(res.Count > 0 && res[res.Count - 1] >= s[i] && mp[res[res.Count - 1]] > 0){
                    res.RemoveAt(res.Count - 1);
                }
                res.Add(s[i]);
            }
            mp[s[i]]--;
        }
        var ans = new string(res.ToArray());
        return ans;
    }
}

//Third fastest
public class Solution {
  public string RemoveDuplicateLetters (string s) {
    string unique = ""; 
    for (int i = 0; i < s.Length; i ++) {
      if (unique.Contains(s[i])) continue;

      while (unique.Length > 0 && unique[unique.Length - 1] > s[i] && s.Substring(i, s.Length - i).Contains(unique[unique.Length - 1])) { 
        unique = unique.Remove(unique.Length - 1, 1); 
        };
      unique += s[i].ToString();
    }
    // Console.Write(unique);
    return unique;
  }
}

//Second fastest
public class Solution {
    public string RemoveDuplicateLetters(string s) {
        var lastIndex = new int[26];
        for (var i = 0; i < s.Length; i++)
            lastIndex[s[i] - 'a'] = i;
        var used = new bool[26];
        for (var i = 0; i < 26; i++)
            used[i] = false;
        var res = new Stack<char>();
        for (var i = 0; i < s.Length; i++)
        {
            if(used[s[i]-'a']) continue;
            while (res.Count > 0 && res.Peek() > s[i] && lastIndex[res.Peek() - 'a'] > i)
            {
                used[res.Peek() - 'a'] = false;
                res.Pop();
            }
            used[s[i] - 'a'] = true;
            res.Push(s[i]);
        }
        var result = "";
        while (res.Count > 0)
            result = res.Pop() + result;
        return result;
    }
}

//Fastest
public class Solution {
    public string RemoveDuplicateLetters(string s) {
        var charAndCount = new int[256];

        foreach (var c in s) {
            charAndCount[c]++;
        }

        var isVisited = new HashSet<char>();
        var charStack = new Stack<char>();

        foreach (var c in s) {
            if (!isVisited.Contains(c)) {
                while (charStack.Any()) {
                    var preChar = charStack.Peek();

                    if (charAndCount[preChar] > 0 && preChar > c) {
                        var popped = charStack.Pop();
                        isVisited.Remove(popped);
                    } else {
                        break;
                    }
                }

                isVisited.Add(c);
                charStack.Push(c);
            }

            charAndCount[c]--;
        }

        var result = new List<char>();

        while (charStack.Any()) {
            result.Add(charStack.Pop());
        }

        result.Reverse();

        return string.Join("", result);
    }
}