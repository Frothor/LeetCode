//Most common
public class Solution 
{
  public int BitwiseComplement(int N) 
  {
    int mask = (1 << GetBinaryLength(N)) - 1;
    return N ^ mask;
  }
  
  private int GetBinaryLength(int x)
  {
    int length = 0;
    
    while (x > 0)
    {
      length++;
      x /= 2;
    }
    
    return Math.Max(length, 1);
  }
}

//Second fastest
public class Solution {
    public int BitwiseComplement(int N) 
    {
        if (N == 0)
            return 1;

        var result = N;
        var nCopy = N;
        var count = 0;
        while (nCopy > 0)
        {
            result ^= 1 << count;
            count++;
            nCopy /= 2;
        }
        
        return result;
    }
}


public class Solution {
    public int BitwiseComplement(int n) {
	int mask = n | 1;
	mask |= mask >> 1;
	mask |= mask >> 2;
	mask |= mask >> 4;
	mask |= mask >> 8;
	mask |= mask >> 16;
	return n ^ mask;
}
}

//Fastest
public class Solution {
    public int BitwiseComplement(int N) {
        
        if(N == 0) return 1;
        
        int mask = N;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        
        return (~N) & mask;
        
    }
}