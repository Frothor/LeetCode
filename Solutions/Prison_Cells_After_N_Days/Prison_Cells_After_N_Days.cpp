class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string, int> map;
        
        for(int i=0; i<N; i++){
            string s(cells.begin(), cells.end());
            if(map.find(s) != map.end()){
                int loop_length = i - map[s];
                int remaining_days = (N-i) % loop_length;
                return prisonAfterNDays(cells, remaining_days);
            } else {
                map.insert({s, i});
                int prev = cells[0];
                for(int j=1; j<7; j++){
                    int next = cells[j+1];
                    int curr = cells[j];
                    cells[j] = prev == next;
                    prev = curr;
                }
            }
            cells[0] = 0;
            cells[7] = 0;
        }
        return cells;
    }
};

/*
Most common:
class Solution {
public:
    int getnext(int n){
        n = ~(n<<1)^(n>>1);
        n = n & 0x7e;
        return n;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int,int> visited;
        int num = 0;
        for(int c: cells){
            num <<= 1;
            num = (num|c);
        }
        bool fast = false;
        while(N>0){
            if(!fast){
                if(visited.count(num)){
                    N %= visited[num] - N;
                    fast = true;
                }
                else{
                    visited[num] = N;
                }
            }
            
            if(N>0){
                N--;
                num = getnext(num);
            }
        }
        vector<int> res(cells.size());
        for(int i=cells.size()-1; i>=0 ; i--){
            res[i] = (num& 0x1);
            num >>= 1;
        }
        return res;
    }
};

Fastes:
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        N = N%14==0 ? 14 : N%14;
        vector<int> cells2(8,0); 
        while(N>0)
        {
            for(int i=1;i<cells.size()-1;i++)
            {
                cells2[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            cells = cells2;
            N--;
        }
        
        return cells;
    }
};
*/