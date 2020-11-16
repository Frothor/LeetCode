// dynamic programming
int longestMountain(int* A, int ASize){
    if (ASize < 3) return 0;
    
    int* inc = (int*)malloc(ASize * sizeof(int));
    int* dec = (int*)malloc(ASize * sizeof(int));
    memset(inc, 0, ASize * sizeof(int));
    memset(dec, 0, ASize * sizeof(int));
    
    inc[0] = 1;
    for (int i = 1; i < ASize; i++) {
        if (A[i] > A[i-1]) inc[i] = inc[i-1] + 1;
        else inc[i] = 1; 
    }
    
    dec[ASize-1] = 1;
    for (int i = ASize-2; i >= 0; i--) {
        if (A[i] > A[i+1]) dec[i] = dec[i+1] + 1;
        else dec[i] = 1;
    }
    
    int ans = 0;
    for (int i = 0; i < ASize; i++) {
        if (inc[i] > 1 && dec[i] > 1) {
            if (inc[i] + dec[i] > ans)
                ans = inc[i] + dec[i] - 1;
        }
    }
    free(inc);
    free(dec);
    
    return ans;
}