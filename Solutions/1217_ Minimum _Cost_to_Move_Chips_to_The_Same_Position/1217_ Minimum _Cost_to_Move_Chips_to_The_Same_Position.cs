public class Solution {
    public int MinCostToMoveChips(int[] position) {
        int even = 0, odd = 0;
        
        foreach(var p in position){
            if(p%2 == 0)
                even++;
            else
                odd++;
        }
        
        return Math.Min(even, odd);
    }
}

//Second fastest
public class Solution {
    public int MinCostToMoveChips(int[] position) {
        int even =0;
        int odd = 0;
        for(int i=0;i<position.Length;i++)
        {
            if(position[i]%2 == 0)
                even++;
            else
                odd++;
        }
        return Math.Min(even, odd);
    }
}

//Fastest
public class Solution {
    public int MinCostToMoveChips(int[] position) {
        
        int odd = 0;
        int even = 0;
        
        int[] pos = new int[101];
        
        for(int i=0;i<position.Length;i++)
        {
            if(position[i] %2 == 0) even++;
            else odd++;
        }

        return Math.Min(odd,even);
        
    }
}