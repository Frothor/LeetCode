class Solution {
    static bool comparator(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]<b[1];
        
        return a[0]<b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), comparator);
        
        vector<vector<int>> ans(n, vector<int>(2, -1));
        
        for(int i=0; i<n; i++){
            int count = people[i][1];
            for(int j=0; j<n; j++){
                if(ans[j][0] == -1 && count == 0){
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                    count-=1;
            }
        }
        
        return ans;
    }
};

/*
Fastest:

typedef unsigned int uint;
inline bool cmp(vector<int> *a, vector<int> *b){return (*a)[0]<(*b)[0]||(*a)[0]==(*b)[0]&&(*a)[1]>(*b)[1];}
class Solution {
public:
	vector<int> *A[1005];
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
    	uint c[36],n=a.size(),m=n?(n-1)/32+1:0;
    	for (int i=0;i<n;++i)A[i]=&a[i];
        sort(A,A+n,cmp);
        vector<vector<int> > res(n);
        for (int i=0;i<m;++i)c[i]=~0u;
        int m1=m/2+1,sum1=m1*32;
        for (int I=0;I<n;++I){
        	vector<int> *it=A[I];
        	int s=(*it)[1]+1,i0=0;
        	if (s>sum1)i0=m1,s-=sum1;
        	for (int i=i0;i<m;++i){
        		int s1=__builtin_popcount(c[i]);
        		if (s<=s1){
        			int j=0; uint &c1=c[i];
        			if (__builtin_popcount(c1<<(j+16))>=s)j+=16;
        			if (__builtin_popcount(c1<<(j+8))>=s)j+=8;
        			if (__builtin_popcount(c1<<(j+4))>=s)j+=4;
        			if (__builtin_popcount(c1<<(j+2))>=s)j+=2;
        			if (__builtin_popcount(c1<<(j+1))>=s)j+=1;
        			j=31-j; c1-=1u<<j;
        			res[i*32+j]=*it;
        			if (i0==0)--sum1;
        			break;
        		}
        		s-=s1;
        	}
        }
        return res;
    }
};

Another:
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &l, const vector<int> &r) {
    return l[0] < r[0] or (l[0] == r[0] and l[1] > r[1]);
}

class Solution {
public:
    short left[4096], right[4096];
    vector<vector<int> > *ret;
    int n, m;
    inline int lson(int pos) {return pos << 1;}
    inline int rson(int pos) {return lson(pos) + 1;}
    inline void init() {
        m = 1;
        do {
            m <<=1;
        } while(m < (n+1));
        --m;
        memset(left + m + n, 0, sizeof(left[0]) * (m - n + 2));
        memset(right + m + 1, 0, sizeof(left[0]) * (m + 1));
        for(int i = m + n; i > m; --i) {
            left[i] = 1;
        }
        for(int i = m; i >= 1; --i) {
            left[i] = left[lson(i)] + right[lson(i)];
            right[i] = left[rson(i)] + right[rson(i)];
        }
    }
    int query(int pos, int k) {
        if(pos > m) return pos - m - 1;
        short &t=left[pos];
        if(t >= k) {
            --t;
            return query(pos << 1, k);
        } else {
            return query((pos << 1)+1, k - t);
        }
    }
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        n = people.size();
        ret = new vector<vector<int> >(n);
        sort(people.begin(), people.end(), cmp);
        init();
        for(auto &it : people) (*ret)[query(1, it[1] + 1)] = it;
        return *ret;
    }
};

Another:
class Solution {
public:
    vector<int> BIT;
    int n;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int>(n+1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
        for(int i = 2; i <= n; i++) update(i, 1);  // BIT[1] is the 0th empty position, so we didn't add 1
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n, vector<int>());
        for(int i = 0; i < n; i++){
            int l=0, r=n;
            int ans = 0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(getsum(mid+1)<people[i][1]){
                    l=mid+1;
                }  // we need get the index mid empty information, but actually it's stored in BIT[mid+1]
                else{
                    ans = mid;
                    r=mid - 1;
                }
            }
            res[ans]=people[i];
            update(ans+1, -1);
        }
        return res;
    }
    void update(int x, int v){
        for(int i = x; i <= n; i+=(i&-i)){
            BIT[i]+=v;
        }
    }
    int getsum(int x){
        int sum=0;
        for(int i = x; i > 0; i-=(i&-i)){
            sum += BIT[i];
        }
        return sum;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};

*/