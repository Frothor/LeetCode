class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for(int e : arr) {
            if(m.find(e) != m.end()) {
                m[e]++;
            }
            else {
                m[e] = 1;
            }
        }
            
            int r = 0;
            
            for(auto n : m) {
                if(m.find(n.first + 1) != m.end()) {
                    r += n.second;
                }
            }
            
            return r;
        
    }
};