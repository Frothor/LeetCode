public class Solution {
    public IList<int> PancakeSort(int[] A) {
        var currVal = A.Length;
        var answer = new List<int>();
        while(currVal > 0) {
            var idx = Array.IndexOf(A, currVal);
            
            if (idx == currVal - 1) { // current value is in right place, go to next one
                currVal--;
                continue;
            }
            
            if (idx != 0) {  // if current value is not at index 0, flip it to first
                answer.Add(idx + 1);
                Flip(A, idx);
                //Console.WriteLine($"a: {string.Join(",", A)}");
            }
            answer.Add(currVal);  // flip current value to right index
            Flip(A, currVal - 1);
            //Console.WriteLine($"b: {string.Join(",", A)}");
            currVal--;
        }
        
        return answer;
    }
    
    private void Flip(int[] A, int kIndex) {
        var l = 0;
        var r = kIndex;
        while(l < r) {
            var tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
            l++;
            r--;
        }
    }
}

//Fastest
public class Solution {
    public IList<int> PancakeSort(int[] A) {
        // find max element
        var solution = new List<int>();
        solve(A, A.Length, solution);
        
        return solution;
        
    }
    
    public void solve(int[] A, int length, IList<int> solution) {
        /*foreach(var e in A){
            Console.WriteLine(e);
        }
        Console.WriteLine("foo");*/
        if(length == 1){
            return;
        }
        long max = Int32.MinValue;
        int i = 0;
        
        for(int j = 0; j<length; j++){
            if(A[j] > max){
                i = j;
                max = A[j];
            }
        }
        
        if(i != length-1){
        Array.Reverse(A, 0, i+1);
        Array.Reverse(A, 0, length);
        solution.Add(i+1);
        solution.Add(length);
        }
        
        solve(A, length-1, solution);
    }
}