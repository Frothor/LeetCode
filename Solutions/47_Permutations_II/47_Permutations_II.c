//Third fastest
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int * nums, int x, int y) {
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
}

void buildPermute(int* nums, int numsSize,int size, int* returnSize, int** returnColumnSizes , int ** ret) {
    if (size == 1) {
        *(ret + *returnSize) = malloc(sizeof(int) * numsSize);
        memcpy(*(ret + *returnSize), nums,sizeof(int) * numsSize);
        *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*((*returnSize)+1));
        *(*returnColumnSizes+*returnSize) = numsSize;
        *returnSize = *returnSize + 1;
        return;
    }
    
    for (int i=size-1;i>=0;i--) {
        if (i < size-1) {
            int repeat = 0;
            for (int j=i+1;j<= size-1;j++) {
                if (nums[j] == nums[i]) {
                    repeat = 1;
                }
            }
            if (repeat == 1) {
                continue;
            }
        }
        
        swap(nums, size-1,i);
        buildPermute(nums, numsSize, size-1, returnSize, returnColumnSizes, ret);
        swap(nums, size-1,i);
    }
}
int compare(const void *x, const void* y) {
    return *((int *)x) - *((int *)y);
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = numsSize;
    int count = 1;
    while(size > 1) {
        count = count * size;
        size--;
    }
    
    int ** ret = malloc(sizeof(int*)*count);
    *returnColumnSizes = malloc(sizeof(int));
    if (numsSize == 0) {
        *(*returnColumnSizes) = 0;
        *returnSize = 1;
        return ret;
    }
    qsort(nums,numsSize,sizeof(int),compare);
    size = numsSize;
    *returnSize = 0;
    buildPermute(nums, numsSize, size, returnSize, returnColumnSizes, ret);
    return ret;
}

//Second fastest
static void swap(int *a, int *b) {
    int tmp = *a;
    
    *a = *b;
    *b = tmp;
}

static bool is_swap(int *nums, int idx_s, int idx_e)
{
    int i;
    
    for (i = idx_s; i < idx_e; i++) {
        if (nums[i] == nums[idx_e]) {
            return false;
        }
    }
    
    return true;
}

static void perm(int *nums, int numsSize, int **res, int *cols, int *cnt, int pos) {
    int idx = 0;
    
    if (pos >= (numsSize - 1)) {
        res[*cnt] = (int *) malloc(sizeof(int) * numsSize);
        if (!res[*cnt]) {
            return;
        }
        
        cols[*cnt] = numsSize;
        memcpy(res[*cnt], nums, sizeof(int) * numsSize);
        *cnt += 1;
        return;
    }
    
    for (idx = pos; idx < numsSize; idx++) {
        if (is_swap(nums, pos, idx)) {
            swap(&nums[pos], &nums[idx]);
            perm(nums, numsSize, res, cols, cnt, pos + 1);
            swap(&nums[pos], &nums[idx]);
        }
    }
    
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res;
    int *cols;
    int cnt;
    int perm_cnt;
    
    if (!nums || (numsSize < 1)) {
        return nums;
    }
    
    perm_cnt = 1;
    cnt = 2;
    while(cnt <= numsSize) {
        perm_cnt *= cnt;
        ++cnt;
    }
    
    res = (int **) malloc(sizeof(int *) * perm_cnt);
    if (!res) {
        return res;
    }
    
    cols = (int *) malloc(sizeof(int) * perm_cnt);
    if (!cols) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    for (cnt = 0; cnt < perm_cnt; cnt++) {
        res[cnt] = NULL;
        cols[cnt] = 0;
    }
    
    cnt = 0;
    perm(nums, numsSize, res, cols, &cnt, cnt);
    *returnSize = cnt;
    *returnColumnSizes = cols;
    
    return res;
}

//Fastest
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

//malloc result
int **mallocRes(int (*data)[30], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********end of malloc result********/

void reverse(int *arr, int first, int last)
{
	while (first < last)
	{
		swap(arr[first], arr[last]);
		++first;
		--last;
	}
}

bool nextPermutation(int *nums, int numsSize)
{
	int i = numsSize;
	while (--i > 0)
	{
		if (nums[i] > nums[i - 1])
		{
			int j = numsSize - 1;
			while (nums[j] <= nums[i - 1])
				--j;
			swap(nums[i - 1], nums[j]);
			reverse(nums, i, numsSize - 1);
			return true;
		}
	}
	return false;
}

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[*size] = dataSize;
	++*size;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	do
	{
		addOneResult(staticRes, returnSize, staticResColSize, nums, numsSize);
	} while (nextPermutation(nums, numsSize));

	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}