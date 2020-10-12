 public bool BuddyStrings(string A, string B) {
        if (A.Length != B.Length) { return false; }
        
        int[] letterCount = new int['z'-'a'+1];
        bool hasDups = false;
        int swapIdx = -1;
        int count = 0;
        
        for(int i=0; i< A.Length; i++)
        {
            if (A[i]!= B[i])
            {
                if (count == 0)
                {
                    swapIdx = i;
                    count++;
                }
                else if (swapIdx == -1)
                {
                    return false;
                }
                else if (A[swapIdx] == B[i] && B[swapIdx] == A[i])
                {
                    swapIdx = -1;
                }
            }
            
            letterCount[A[i]-'a']++;
            if (letterCount[A[i]-'a'] > 1) { hasDups = true; }
        }
        
        return ((count == 1 && swapIdx == -1)||(count == 0 && hasDups)); 
    }

//Another
public class Solution {
    private int[] count = new int[26];
    
    private bool Check() {
        for(int i = 0; i < 26 ; i++) 
            if(count[i] > 1)
                return true;
        return false;
    }
     public bool BuddyStrings(string A, string B) {
        if(A.Length != B.Length) return false;
        int diff = 0;
        int index1 = -1, index2 = -1;
        
        for(int i = 0; i < A.Length && diff < 3; i++) {
            if(A[i] != B[i]) {
                diff++;
                if(index1 != -1) index2 = i;
                else index1 = i;
            }
            else count[A[i] - 'a']++;
        }
        if(diff == 0) return Check();
        else if(diff != 2) return false;
        else if(A[index1] == B[index2] && A[index2] == B[index1]) return true;
        else return false;
    }
}

//Third fastest
public class Solution {
    public bool BuddyStrings(string A, string B) {
        if(A.Length != B.Length) return false;
        int a = -1, b = -1;
        var characterLookup = new HashSet<char>();
        bool duplicates = false;
        for(int i = 0; i < A.Length; i++)
        {
            char ac = A[i], bc = B[i];
            if(ac != bc)
            {
                if(a == -1){
                    a = i;
                    if(i == A.Length - 1) return false;
                }
                else if(b == -1) b = i;
                
                else return false;
            }
            else if(!duplicates){
                if(characterLookup.Contains(ac)) duplicates = true;
                else characterLookup.Add(ac);
            }
        }
        
        if(a == -1 || b == -1){
            return duplicates;
        }
        
        return A[a] == B[b] && A[b] == B[a];
    }
}

//Second fastest
public class Solution {
    
    public bool BuddyStrings(string A, string B) {
        
        if(A.Length != B.Length) {
            return false;
        }
        
        int alphabet_size = 26;
        bool[] acs = new bool[alphabet_size];
        bool found = false;
        bool pair_found = false;
        bool is_equal = true;
        bool c_repeats = false;
        char ba = '0';
        char bb = '0';
        char a = '0';
        char b = '0';
        int first = (int)'a';
        
        for(int i = 0; i < A.Length; i++) {
            
            a = A[i];
            b = B[i];
            
            if(acs[(int)a - first]) {
                c_repeats = true;
            }
            
            if(a != b) {
            
                is_equal = false;
                
                if(found) {
                
                    if(pair_found) {
                        return false;
                    } else if(ba == b && bb == a) {
                        pair_found = true;
                    }
                }
                
                ba = a;
                bb = b;
                found = true;  
            }
            
            acs[(int)a - first] = true;
        }
        
        if (is_equal) {
            return c_repeats;
        } else {
            return pair_found;
        }
    }
}

//Fastest
public class Solution {
    public bool BuddyStrings(string A, string B) {
        if(A.Length != B.Length)
        {
            return false;
        }
        
        if(A.Length < 2 || B.Length < 2)
        {
            return false;
        }
        
        int characters = 0;
        int[] differentIndices = new int[2];
        int differentIndicesCount = 0;
        
        for(int index = 0; index < A.Length; index++)
        {            
            if(A[index] != B[index])
            {
                if(differentIndicesCount >= 2)
                {
                    return false;
                }
                
                differentIndices[differentIndicesCount++] = index;
            }
            
            characters |= (1 << A[index] - 'a');
        }
        
        int differentCharacters = CountDifferentCharacters(characters);
        
        if(differentIndicesCount == 0 && differentCharacters < A.Length)
        {
            return true;
        }
        
        if(differentIndicesCount != 2)
        {
            return false;
        }
        
        return A[differentIndices[0]] == B[differentIndices[1]] && A[differentIndices[1]] == B[differentIndices[0]];
    }
    
    private int CountDifferentCharacters(int characters)
    {
        int count = 0;
        
        for(int i = 0; i < 26; i++)
        {
            if((characters & 1 << i) > 0)
            {
                count++;
            }
        }
        
        return count;
    }
}