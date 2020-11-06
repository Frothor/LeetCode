public class Solution
{
    public int SmallestDivisor(int[] nums, int threshold)
    {
        int min = 1, max = nums.Max();
        while(min < max)
        {
            double middle = (min+max)/2;
            int sum = 0;
            foreach(int num in nums)
                sum += (int)Math.Ceiling(num/middle);
            if(sum <= threshold)
                max = (int)middle;
            else
                min = (int)middle+1;
        }
        return max;
    }
}

//Third fastest
public class Solution {
    public int SmallestDivisor(int[] nums, int threshold) {
        // find smallest divisor, where sum of each divisionr result <= threashold
            int left = 1;
            int right = nums.Max();

            while (left < right)
            {
                var mid = left + (right - left) / 2;
                if (LessThanThreashold(mid))
                {
                    right = mid;
                } else
                {
                    left = mid + 1;
                }
            }
            return left;

            bool LessThanThreashold(int divisor)
            {
                int sum = 0;
                foreach (var num in nums)
                {
                    sum += (num + divisor - 1) / divisor;
                }
                return sum <= threshold;
            }
    }
}

//Second fastest
public class Solution {
    public int SmallestDivisor(int[] nums, int threshold) {
        int res = -1;
        
        int h = Int32.MinValue;
        for(int i=0; i<nums.Length; i++){
            h = Math.Max(h, nums[i]);
        }
        
        int l=1;
        while(l<=h){
            int mid = l + (h-l)/2;
            Console.WriteLine("mid:" + mid);
            
            int sum = utils(nums, mid);
            if(sum <= threshold){
                res = mid;
                h = mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return res;
    }
    
    public int utils(int[] a, int x){
        int sum =0;
        for(int i=0; i<a.Length; i++){
            sum = sum + a[i]/x + (a[i]%x == 0 ? 0 : 1);
        }
        
        return sum;
    }
}

//Fastest
public class Solution {
    public int SmallestDivisor(int[] nums, int threshold) {
        var min = 1;
        var max = int.MinValue;
        
        foreach (var num in nums){
            max = Math.Max(max, num);
        }
        
        while (min <= max){
            var mid = min + (max - min) / 2;
            var r = DivisorSum(nums, mid);
            
            Console.WriteLine("{0} {1}", mid, r);
            if (r > threshold){
                min = mid + 1;
            }
            else {
                max = mid - 1;
            }
        }
        
        return min;
    }
    
    private int DivisorSum(int[] nums, int d){
        var result = 0;
        foreach (var num in nums){
            result += (num - 1) / d + 1;
        }
        
        return result;
    }
}