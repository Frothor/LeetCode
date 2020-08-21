public class Solution {
    public int[] SortArrayByParity(int[] A) {
        int k=0;
        for(int i=0; i < A.Length; i++)
        {
            if(A[i] % 2 == 0)
            {
                swap(ref A, i, k);
                k++;
            }
        }
        return A;
    }
    
    private void swap(ref int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}