class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        
        map<char,int> freq;
        int max_freq = 0,inc=0;
        for(int x : tasks) {
            freq[x]++;
            max_freq = max(max_freq, freq[x]);
        }
        int idle_time = (max_freq-1)*(n+1)+1;
        for(auto it: freq){
            if(it.second==max_freq) inc++;
        }
        int ans = idle_time+(inc-1); 
        return max(ans, (int)tasks.size());
    }
};

/*
Most common:
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto t : tasks) {
            freq[t - 'A']++;
        }
        sort(begin(freq), end(freq), std::greater<int>());
        int fmax = freq[0];
        int max_idle_time = (freq[0] -1) * n;
        cout << max_idle_time << endl;
        for(int i = 1; i < freq.size() && max_idle_time > 0; i++) {
            max_idle_time = max_idle_time - min(fmax-1, freq[i]);
        }
        max_idle_time = max(max_idle_time, 0);
        return max_idle_time + tasks.size();
    }
};

Fastest:
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq;
        freq.resize(26); //A-Z
        for(auto task:tasks) {
            freq[task-'A']++;
        }
        
        sort(freq.begin(),freq.end());
        //Now the most frequent element placed at the right most element (i.e., freq[25])
        
        int idle_time =(freq[25]-1)*n; //freq[25] is freq_max, -1 is due to there is no need to wait at the end of cycle, just finish scheduling.
        
        //looping back, more frequent -> less frequent
        for(int i=24;i>0;i--) {
            idle_time -=min(freq[25]-1,freq[i]);
        }
        idle_time = max(0,idle_time);
        return idle_time+tasks.size();
    }
};
*/