//Second fastest
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int* x, int* y) 
{ 
	int temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void permute1(int* a, int l, int r, int *count,int **ret,int numsSize,int **returnColumnSizes) 
{ 
	int i; 
	if (l == r) 
    {
        *(ret+*count)=malloc(sizeof(int)*numsSize);
        memcpy(*(ret+*count), a, numsSize * sizeof(int));
        *returnColumnSizes=realloc(*returnColumnSizes, sizeof(int)*(*(count)+1));
        *(*returnColumnSizes+(*count))=numsSize;
        (*count)++; 
       
    }
    else { 
		for (i = l; i <= r; i++) { 
			swap((a + l), (a + i)); 
			permute1(a, l + 1, r, count,ret,numsSize,returnColumnSizes); 
			swap((a + l), (a + i)); // backtrack 
		} 
	} 
} 
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int cnt=0;
    *returnColumnSizes=malloc(sizeof(int)*1);
    int **ret=malloc(sizeof(int *)*1000);
    permute1(nums,0,numsSize-1,&cnt,ret,numsSize,returnColumnSizes);
    *returnSize=cnt;
    return ret;
    
}

//Another
static void swap(int *a, int *b)
{
    int tmp = *a;
    
    *a = *b;
    *b = tmp;
}

static void perm(int *nums, int numsSize, int **res, int *cnt, int *cols, int pos)
{
    int idx_s;
        
    if (pos >= (numsSize - 1)) {
        res[*cnt] = (int *)malloc(sizeof(int) * numsSize);
        if (res[*cnt] == NULL) {
            cols[*cnt] = 0;
            return;
        }
        
        cols[*cnt] = numsSize;
        memcpy(res[*cnt], nums, (sizeof(int) * numsSize));
        *cnt += 1;
        return;
    }
    
    for (idx_s = pos; idx_s < numsSize; idx_s++) {
        swap(&nums[pos], &nums[idx_s]);
        perm(nums, numsSize, res, cnt, cols, (pos + 1));
        swap(&nums[pos], &nums[idx_s]);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int total_perm;
    int cnt;
    int **res;
    
    cnt = 2;
    total_perm = 1;
    while (cnt <= numsSize) {
        total_perm *= cnt;
        ++cnt;
    }
    
    *returnSize = total_perm;
    res = (int **) malloc(sizeof(int *) * total_perm);
    if (!res) {
        return NULL;
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * total_perm);
    cnt = 0;
    perm(nums, numsSize, res, &cnt, *returnColumnSizes, 0);
 
    return res;
}

//Fastest
void swap(int *nums, int i, int j){
    if (i == j)
        return;
    int x = nums[i];
    nums[i] = nums[j];
    nums[j] = x;
}

void fill_permutations(int *nums, int num_size, int *arr, int index, int *size, int ***ans, int **col_size){
    int i = index;
    if (num_size == index) {
        (*size)++;
        *ans = realloc(*ans, sizeof(int **) * (*size));
        *col_size = realloc(*col_size, sizeof(int *) * (*size));
        (*ans)[(*size) - 1] = malloc(sizeof(int) * num_size);
        (*col_size)[(*size) - 1] = num_size;
        for (i = 0; i < num_size; i++)
            (*ans)[(*size) - 1][i] = arr[i];
        return;
    }
    for (i = index; i < num_size; i++) {
        arr[index] = nums[i];
        swap(nums, i, index);
        fill_permutations(nums, num_size, arr, index + 1, size, ans, col_size);
        swap(nums, i, index);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ans = NULL;
    int *arr, size;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (numsSize == 0)
        return NULL;
    arr = malloc(sizeof(int) * numsSize);
    fill_permutations(nums, numsSize, arr, 0, returnSize, &ans, returnColumnSizes);
    return ans;
}