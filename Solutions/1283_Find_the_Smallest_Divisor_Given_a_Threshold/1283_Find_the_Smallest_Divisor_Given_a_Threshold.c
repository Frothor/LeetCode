//Fastest
int calculate(int* nums, int numsSize, int divisor) {
    int sum = 0;
    for (int i=0; i<numsSize; i++) {
        sum += ceil(nums[i]*1.0/divisor);
    }
    return sum;
}

int smallestDivisor(int* nums, int numsSize, int threshold){
    int lo = 1, hi = nums[numsSize-1];
    
    // Binary search to reduce time complexity
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        int curr = calculate(nums, numsSize, mid);
        
        if (curr > threshold) 
            lo = mid+1;
        else
            hi = mid-1;
    }
    
    return lo;
}

//Another
int smallestDivisor(int* nums, int numsSize, int threshold){
    int sum=0, i, j, l, r, t;
    
    l=1;
    r=1000000;
    while (l<r) {
        j=(l+r)/2;
        t = 0;
        for(i=0; i<numsSize; i++) {
            t += (nums[i]+j-1)/j;
        }
        if (t <= threshold) r=j;
        else l=j+1;
    }
    return l;
}