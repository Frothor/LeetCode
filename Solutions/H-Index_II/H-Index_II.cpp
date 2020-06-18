class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n-1, mid;
        int res;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(citations[mid] == (n-mid)){
                return citations[mid];
            }
            else if(citations[mid]>(n-mid))
                high = mid-1;
            else
               low = mid+1;
        }
        
        return n-low;
    }
};

/*
Fastest:
class Solution {
public:
    int hIndex(vector<int>& arr) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if(arr.size()==0)return 0;
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(arr[m]==arr.size()-m)return arr[m];
            if(arr[m]>arr.size()-m)r=m-1;
            else l=m+1;
        }
        return arr.size()-l;
    }
};
*/