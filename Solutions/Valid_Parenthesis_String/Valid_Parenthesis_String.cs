public class Solution {
    // Time Complexity: O(N+N+N+N)
    // Space Complexity: O(2N)
    public bool CheckValidString(string s) {
        int n = s.Length; 
        // need to know the location of the stars
        List<int> starIndicies = new List<int>();
		
		// using Tuple here, can be converted to a small class
        Stack<(char,int)> st = new Stack<(char, int)>(); 

        // O(N)
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '*')
                starIndicies.Add(i);
            else if(c == '(')
                st.Push((c, i));
            else if(c == ')' && st.Count() > 0 && st.Peek().Item1 == '(')
                st.Pop();
            else
                st.Push((c, i));
        }

        // O(N)
        // let's deal with what's left in the Stack
        while(st.Count > 0){
            if(starIndicies.Count() < 1)
                return false;

            var tup = st.Pop(); 
            if(tup.Item1 == '('){
                // find a star after index i, remove the star
                if(!FindNextStar(tup.Item2, starIndicies)){
                    return false; 
                }
            }
            else{
                // find a star after index i, remove the star
                if(!FindPrevStar(tup.Item2, starIndicies))
                    return false; 
            }
        }

        return true; 
    }

    // O(N)
    public bool FindNextStar(int index, IList<int> stars){
        foreach(int i in stars){
            if(i > index){
                stars.Remove(i);
                return true; 
            }
        }
        return false; 
    }

    // O(N)
    public bool FindPrevStar(int index, IList<int> stars){
        foreach(int i in stars){
            if(i < index){
                stars.Remove(i);
                return true; 
            }
        }
        return false; 
    }
}



//Fastest
public class Solution {
    public bool CheckValidString(string s) {
        //=======================
        int maxSum = 0 ;
        int minSum = 0 ;
        
        for(int i = 0 ; i < s.Length ;i++){
            if(s[i] == '('){
                minSum++;
            }
            else{
                minSum--;
            }
            if(s[i] == ')'){
                maxSum--;
            }
            else{
                maxSum++;
            }

            if(maxSum < 0 ){
                return false;
            }
            if(minSum < 0 ){
                minSum = 0;
            }
        }
        return minSum == 0;
    }
}