public class Solution {
    public bool ValidMountainArray(int[] arr) {
        if(arr.Length < 3)
            return false;
        int maxIdx = 0;
        for(int i = 1; i < arr.Length; i++)
            if(arr[i] > arr[maxIdx])
                maxIdx = i;
        
        int a = maxIdx - 1;
        int b = maxIdx + 1;
        
        if(a < 0 || b > arr.Length-1)
            return false;
        
        while(a >= 0){
            if(arr[a] >= arr[a+1])
                return false;
            a--;
        }
        
        while(b < arr.Length){
            if(arr[b-1] <= arr[b])
                return false;
            b++;
        }
        
        return true;
    }
}

//Third fastest
public class Solution {
    public bool ValidMountainArray(int[] arr) {
        if(arr.Length < 3) return false;
        bool isClimbed = false, isClimbing = true;
        for(int i = 1; i< arr.Length; ++i){
            if(arr[i - 1] < arr[i]){
                if(!isClimbed) isClimbed = true;
                if(!isClimbing) return false;
            } else if(arr[i - 1] > arr[i]){
                if(!isClimbed) return false;
                if(isClimbing) {
                    isClimbing = false;
                }
            } else{
                return false;
            }
        }
        return isClimbing == false;
    }
}

//Second fastest
public class Solution {
    public bool ValidMountainArray(int[] arr) {
        if(arr.Length<3){
            return false;
        }
        bool isMountain = true;
        int i = 0;
        bool reachedPeak = false; 
        while(isMountain && ++i<arr.Length-1){
            if(!reachedPeak){
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                    reachedPeak = true; 
                }
                else if(!(arr[i]>arr[i-1] && arr[i]<arr[i+1])) {
                    isMountain = false;
                }
            }else{
                if(!(arr[i]<arr[i-1] && arr[i]>arr[i+1])){
                    isMountain = false;
                }
            }

           
        }
        return isMountain && reachedPeak;
    }
                   
}

//Fastest
public class Solution 
{
    public bool ValidMountainArray(int[] arr)
    {
        if(arr == null || arr.Length < 3) return false;
        
        int left = 0;
        int right = arr.Length-1;
        
        while(left < right)
        {
            if(arr[left] < arr[left+1])
            {
                left++;
            }
            else if(arr[right-1] > arr[right] )
            {
                right--;
            }
            else
            {
                break;
            }
        }
        
        if(left == right && left != 0 && right != arr.Length-1)
        {
            return true;
        }
        
        return false;
    }
}