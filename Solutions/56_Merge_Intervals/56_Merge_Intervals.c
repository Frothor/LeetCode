

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc(int** a, int** b)
{
    return (*a)[0] - (*b)[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int* temp=NULL;
    int i;
    int count = 0;
    
    if((intervals==NULL) || (intervalsSize==0))
    {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize,sizeof(int*),cmpfunc);
    
    temp = intervals[0];
    for(i=1;i<intervalsSize;i++)
    {
        if(temp[1] >= intervals[i][0])
        {
            temp[1] = (temp[1] > intervals[i][1])?temp[1]:intervals[i][1];
        }
        else
        {
            intervals[count][0] = temp[0];
            intervals[count][1] = temp[1];
            count++;
            temp = intervals[i];
        }
    }
    intervals[count][0] = temp[0];
    intervals[count][1] = temp[1];
    count++;

    *returnSize = count;
    (*returnColumnSizes) = (int*)malloc(count*sizeof(int));
    for(i=0;i<count;i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return intervals;
}

//Fastest
int qsort_intervals(int** intervals, int s_pos, int e_pos){
    int i=s_pos, j=e_pos, k_pos=s_pos;
    int key=0;
    int *key_interval=NULL;
    
    if(s_pos>=e_pos){
        return 0;
    }
    
    key=intervals[i][0];
    key_interval=intervals[i];
    
    while(i<j){
        if(k_pos == i){
            if(intervals[j][0]<key){
                intervals[i++]=intervals[j];
                k_pos=j;
            }
            else{
                j--;
            }
        }
        else{
            if(intervals[i][0]>key){
                intervals[j--]=intervals[i];
                k_pos=i;
            }
            else{
                i++;
            }
        }
    }
    
    intervals[k_pos]=key_interval;
    
    qsort_intervals(intervals, s_pos, k_pos-1);
    qsort_intervals(intervals, k_pos+1, e_pos);
    
    return 0;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **rintervals=NULL;
    int i=0, k=0;
    
    if(intervalsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    qsort_intervals(intervals, 0, intervalsSize-1);
    
    rintervals=(int **)malloc(intervalsSize * sizeof(int*));
    
    for(i=0; i<intervalsSize; i++){
        if(i==0){
            rintervals[k]=(int *)malloc(2*sizeof(int));
            rintervals[k][0]=intervals[0][0];
            rintervals[k][1]=intervals[0][1];
            k++;
        }
        else{
            if(rintervals[k-1][1]>=intervals[i][0]){
                if(rintervals[k-1][1]<intervals[i][1]){
                    rintervals[k-1][1]=intervals[i][1];
                }
            }
            else{
                rintervals[k]=(int *)malloc(2*sizeof(int));
                rintervals[k][0]=intervals[i][0];
                rintervals[k][1]=intervals[i][1];
                k++;
            }
        }
    }
    
    *returnSize = k;
    *returnColumnSizes = (int*)malloc(k*sizeof(int));
    for(i=0; i<k; i++){
        (*returnColumnSizes)[i]=2;
    }
    
    return rintervals;
}