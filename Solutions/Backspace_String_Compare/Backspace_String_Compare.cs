//C#, simple solution without stack, O(n) time and O(1) space, beats 99% runtime
public class Solution {
    public bool BackspaceCompare(string S, string T) {
        int si = S.Length-1;
        int ti = T.Length-1;
        
        while (si >=0 || ti >= 0) {
            si = GetNextCharIndex(S, si);
            ti = GetNextCharIndex(T, ti);
            
            if (si < 0 && ti < 0)
                return true;
            
            if ((si >=0 && ti < 0) || (ti >=0 && si < 0))
                return false;
            
            if (S[si] != T[ti])
                return false;
            
            si--;
            ti--;
        }
        return true;
    }

    private int GetNextCharIndex(string s, int index) {
        int b = 0;
        while (index >= 0 && (s[index] == '#' || b > 0)) {
            b = (s[index] == '#') ? b + 1 : b - 1;
            index--;
        }
        return index;
    }
}

//Another
public bool BackspaceCompare(string S, string T)
{
	var newS = RemoveBackspaces(S);
	var newT = RemoveBackspaces(T);

	static string RemoveBackspaces(string s)
	{
		var result = string.Empty;
		foreach (var ch in s)
		{
			if (ch == '#' && result.Length > 0)
				result = result.Remove(result.Length - 1, 1);
			else if (ch != '#') result += ch;
		}

		return result;
	}

	return newS == newT;
}

//////////////////////////////
//The approach used was the same used by all solutions that had O(N) time and O(1) space in mind. The only thing to point out is that the costructor of the enumerable class uses a ref parameter for not duplicating the string in memory since C# passes string arguments by value and not by reference, this way the solution strictly complies with the O(1) space constraint.

public class Solution {
    public bool BackspaceCompare(string s, string t) {
        var enumerable1 = new CharBackspaceEnumerator(ref s);
        var enumerable2 = new CharBackspaceEnumerator(ref t);
        
        return enumerable1.SequenceEqual(enumerable2);
    }
    
    class CharBackspaceEnumerator : IEnumerable<char> {
        string s;
        int currentPosition;
        int amountToSkip;
        
        public CharBackspaceEnumerator(ref string s) {
            this.s = s;
            this.currentPosition = s.Length - 1;
            this.amountToSkip = 0;
        }
        
        public IEnumerator<char> GetEnumerator() {
            while (this.currentPosition >= 0) {
                while (this.currentPosition >= 0){
                    if (this.s[this.currentPosition] == '#') {
                        this.amountToSkip++;
                    }
                    else {
                        if (amountToSkip == 0) {
                            break;
                        }
                        amountToSkip--;
                    }
                    
                    this.currentPosition--;
                }
                
                if (this.currentPosition >= 0) {
                    yield return this.s[this.currentPosition];
                    this.currentPosition--;
                }
            }
        }
        
        IEnumerator IEnumerable.GetEnumerator() {
            // just boilerplate
            return this.GetEnumerator();
        }
    }
}