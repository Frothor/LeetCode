public class Solution {
    public int LongestMountain(int[] A) {
        int l = 0, h = 0, i = 1, res = 0, n = A.Length;
        if(n == 0 || n == 1)
            return res;
            
        while(i < n-1){
            if(A[i-1] < A[i] && A[i] > A[i+1]){
                l = i-1;
                h = i+1;
                while(l > 0 && A[l]>A[l-1]) l--;
                while(h < n-1 && A[h]>A[h+1]) h++;
                res = Math.Max(res, h-l+1);
                i = h+1;
            }
            else
                i++;
            
        }
        
        return res;
    }
}

//Most common
public class Solution {
    public int LongestMountain(int[] A) {
        int res = 0;
            int k = 0;
            while (k < A.Length - 1)
            {
                if (A[k] >= A[k + 1])
                    k++;
                else
                    break;
            }
            if (k == A.Length - 1)
                return res;
            bool bUp = true;
            int count = 1;
            while (k < A.Length - 1)
            {
                if (A[k] > A[k + 1])
                {
                    if (count <= 1)
                    {
                        k++;
                        continue;
                    }
                    else
                    {
                        if (bUp)
                        {
                            bUp = false;
                            count++;
                        }
                        else
                            count++;
                        k++;
                    }
                }
                else if (A[k] == A[k + 1])
                {
                    if (bUp)
                    {
                        count = 1;
                    }
                    else
                    {
                        res = Math.Max(res, count);
                        bUp = true;
                        count = 1;
                    }
                    k++;
                }
                else
                {
                    if (bUp)
                    {
                        count++;
                        k++;
                    }
                    else
                    {
                        res = Math.Max(res, count);
                        count = 2;
                        bUp = true;
                        k++;
                    }
                }
            }
            if (!bUp && count >= 3)
            {
                res = Math.Max(res, count);
            }
            return res;
    }
}

//Third fastest
public class Solution {
    public int LongestMountain(int[] A) {
        if (A == null || A.Length == 0)
        {
            return 0;
        }
        
        int maxLength = 0;
        int start = 0;
        while (start < A.Length)
        {
            int end = start;
            
            // starting the mountain
            if (end + 1 < A.Length && A[end] < A[end + 1])
            {
                while (end + 1 < A.Length && A[end] < A[end + 1])
                {
                    end++;
                }
                
                // go down the mountain
                if (end + 1 < A.Length && A[end] > A[end + 1])
                {
                    while (end + 1 < A.Length && A[end] > A[end + 1])
                    {
                        end++;
                    }
                    
                    maxLength = Math.Max(maxLength, end - start + 1);
                }
            }
            
            
            // either increment by 1 or start at end position
            start = Math.Max(start + 1, end);
        }
        
        return maxLength;
    }
}

//Second fastest
public class Solution {
    public int LongestMountain(int[] A) {
        int len = A.Length;
        if (len < 3) return 0;
        int maxSeen = 0;
        int valley = A[0] < A[1] ? 0 : len;
        Console.WriteLine(valley);
        int currentMountain;
        for(int i = 1; i < len - 1; i++)
        {
            if (A[i] == A[i-1]) 
            {
                if (A[i] < A[i+1])
                {
                    valley = i;
                }
                else
                {
                    valley = len;
                }
            }
            else if (A[i] < A[i-1] && A[i] <= A[i+1])
            {
                currentMountain = i - valley + 1;
                if(currentMountain > maxSeen) maxSeen = currentMountain;
                valley = i;
            }
        }
        
        if (A[len-1] < A[len-2]) {
            currentMountain = len - valley;
            if (currentMountain > maxSeen) return currentMountain;
        }
        return maxSeen;
    }
}

//Fastest
public class Solution {
    
    /*
    Time : O(N)
    Space: O(1)
    
    iterate through array, and basically check all cases
    case we start descending 5,4,3,2,1,2,3,4
            cant increment from 1...
            but have to  set isDescend to false and set currCnt = 2
    case 1,2,3,4,5,4,3,2,1
         basic mountain, we keep track if we go up and if we go down
    case 1,2,3,4,5,4,3,2,2,2,2,2
        mountain ranges are not equal to each other
        
    
    */
    public int LongestMountain(int[] A) {
        int n = A.Length;
        if(n == 0 || n == 1)return 0;
       
        
        int currCount = 0;
        int maxCount = 0;
        bool isAscended = false;
        bool isDescended = false;
        
        for(int i  = 0, j = 1; j < n;){
            
            if(A[j] > A[i]){
        
                //if we have descended 
                if(isDescended){
                    //check if we have ascended due to case 5,4,3,2,1,2,3,4,5 ...
                    
                    if(isAscended){
                        maxCount = Math.Max(currCount, maxCount);
                    }
                    
                    currCount = 2;
                    isDescended = false;
                }
                else if(currCount == 0){
                    currCount = 2;
                }
                else{
                    currCount++;
                }
                 isAscended = true;
            }
            //if we ascended we can increment our currentCounter
            else if(A[j] < A[i]){
                isDescended = true;
                if(isAscended){
                    currCount++;
                }    
                
            }
            //both equal
            else{
                if(isDescended && isAscended){
                    maxCount = Math.Max(currCount, maxCount);
                }
                currCount = 0;
                isDescended = false;
                isAscended = false;
            }
            
            i++;
            j++;
        }
        
        
        return (isAscended && isDescended) ? Math.Max(currCount, maxCount) :   maxCount;
        
    }
}