//Third fastest
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size(), res = A[n - 1] - A[0];
        int left = A[0] + K, right = A[n - 1] - K;
        // divide A into [0, i] and [i + 1, n - 1]
        for (int i = 0; i < n - 1; i++) {
            int high = max(right, A[i] + K), low = min(left, A[i + 1] - K);
            res = min(res, high - low);
        }
        return res;
    }
};

//Second fastest
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        const int n = A.size();
        if (n <= 1) return 0;
        
        vector<int> points(30001, 0);
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int max_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            const int val = A[i] - K;
            points[val + 10000] = 1;
            min_val = std::min(min_val, val);
            max_val = std::max(max_val, val);
            max_min = std::min(max_min, A[i] + K);
        }

        int res = INT_MAX;
        const int s_limit = std::min(max_val, max_min);
        for (int s = min_val; s <= s_limit; s++) {
            if (points[s + 10000] == 0) continue;
            res = std::min(res, max_val - s);
            const int next_val = s + 2 * K;
            points[next_val + 10000] = 1;
            if (next_val > max_val) {
                max_val = next_val;
            }
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K)
    {
        // Key: if we shift a value down by K, it will only hurt to shift things above it up.  Similarly
        //      if we shift a number up, will only hurt to shift things below it down.  So just need to
        //      find the best point to flip: everything below shifted up; everything at or above shifted down.
        //      Note that shifting everything up or everything down is equivalent as far as interval width goes.
        //      Once we pick a flip point, we can determine the width in constant time (assuming the values
        //      are sorted!): the minimum as either val[0] + K or val[shift] - K.  Similarly for the largest
        //      point.  We can discard duplicates (ltr)
        int pnWorkspace[10001];
        int nMin, nMax;
        int nNumVals = 0;
        memset(pnWorkspace,0,10001*sizeof(int));
        // sort the values
        for(int i=0;i<A.size();i++)
        {
            pnWorkspace[A[i]] = 1;
        }
        for(int i=0;i<10001;i++)
        {
            if(pnWorkspace[i])
            {
              //  printf("* %i %i\n",nNumVals,i);
                pnWorkspace[nNumVals++] = i;
            }
        }
        int nMaxMinusK = pnWorkspace[nNumVals-1] - K;
        if(nMaxMinusK <= pnWorkspace[0])
        {
            // shift EVERYTHING down.  Short-circuit
            return pnWorkspace[nNumVals-1] - pnWorkspace[0];
        }
        int nMinPlusK = pnWorkspace[0] + K;
        if(2*K <= nMaxMinusK - nMinPlusK)
        {
            // short circuit: if below midpoint of 0, max shift up; if above, down.  Won't cross minplusK/maxminusK
            return nMaxMinusK - nMinPlusK;
        }
        int nMinWidth = pnWorkspace[nNumVals-1] - pnWorkspace[0]; // can always get this by shifting everything the same direction
        for(int i=1; i<nNumVals; i++)
        {
            // assume shift everything below i up; everything at or above i, down
            nMin = pnWorkspace[i] - K;
            if(nMinPlusK < nMin) nMin  = nMinPlusK;
            nMax = pnWorkspace[i-1] + K;
            if(nMax < nMaxMinusK) nMax = nMaxMinusK;
            nMin = nMax - nMin;
            if(nMin < nMinWidth) nMinWidth = nMin;
        }
        return nMinWidth;
    }
};