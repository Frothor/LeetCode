//Time Complexity is O(N * sqrt(max(arr[i])).
//The idea is that for every number we find and link all of its factors to a unique parent number. Then simply count the numbers which has the given parent and output the maximum such frequency.

int parent[100001];
int find (int x)
{
    if(parent[x]==-1)
        return x;
    else return parent[x]=find(parent[x]);
}
bool uni(int x,int y)
{
    int xp=find(x);
    int yp=find(y);
    if(xp!=yp)
        parent[yp]=xp;
    else return false;
    return true;
}
int largestComponentSize(vector<int>& arr) 
{
    unordered_map<int,int> memo;
    memset(parent,-1,sizeof(parent));
    int ret=0;
    for(int x:arr)
    {
       int flag=0;
        for(int i=2;i*i<=x;++i)
            if(x%i==0)
            {
                uni(i,x);
                uni(x,x/i);
                flag=1;
            }
    }
    for(int x:arr)
        ret=max(ret,++memo[find(x)]);
    return ret;
}


//Most common
class DSU
{
	public:
	DSU(int n) : parents(n)
	{
		iota(parents.begin(), parents.end(), 0);
	}
	void Union(int x, int y)
	{
		parents[Find(x)] = parents[Find(y)];
	}
	int Find(int x)
	{
		return parents[x] == x ? x : parents[x] = Find(parents[x]);
	}
	private:
	vector<int>parents;
};
class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		int n = *max_element(A.begin(), A.end());
		DSU s(n + 1);
		for(int a : A)
		{
			int t = sqrt(a);
			for(int k = 2; k <= t; k++)
			{
				if(a % k == 0)
				{
					s.Union(a, k);
					s.Union(a, a / k);
				}
			}
		}
		unordered_map<int, int>c;
		int ans = 1;
		for(auto a : A)
			ans = max(ans, ++c[s.Find(a)]);
		return ans;
	}
};

//Fastest
static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);
    return 0; 
}();

class Solution {
    const static int N = 100001;
    int parent[N];
    int m[N];
    int size[N];
    
    // find smallest prime factor other than 1 of all numbers
    void findPrime(vector<int> &prime){
        prime.resize(N, 0);
        for (int i = 2; i*i < N; i++)
            if (prime[i] == 0)
                for (int j= i*i; j < N; j += i) 
                    prime[j] = i; 
        
        for(int i = 2 ; i < N; ++i)
            if(prime[i] == 0)
                prime[i] = i;
    }
    
    void init(int n){
        for(int i = 0 ; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
            m[i] = -1;
        }
    }
    
public:
    int largestComponentSize(vector<int>& A) {
        init (*max_element(A.begin(), A.end()));
        int res = 0;
        
        static vector<int> prime;
        if(prime.empty())
            findPrime(prime);
        
        for (int a : A) {
            int cur = a;
            while(a > 1){
                if(m[prime[a]] == -1)
                    m[prime[a]] = cur;
                res = max(res , unionize(m[prime[a]],cur));
                
                //remove all prime factors p from a
                int p = prime[a];
                while(prime[a] == p)
                    a /= p;      
            }        
        }

        return res;
    }
    
    int root(int val){
        while(val != parent[val]) {
            parent[val] = parent[parent[val]];
            val = parent[val];
        }
        return val;
    }
    
    int unionize(int x, int y){
        int r1 = root(x), r2 = root(y);
        if(r1 == r2)
            return size[r1];
        
        parent[r1] = r2;
        size[r2] += size[r1];
        return size[r2];
    }
};