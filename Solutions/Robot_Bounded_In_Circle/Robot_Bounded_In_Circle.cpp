//Fastest and most common
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int pos[2] = {0,0};
        
        // N, E, S, W
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int cur = 0;
        
        for (int i = 0; i < 4; ++i) {
            for (auto m : instructions) {
                if (m == 'G') {
                    pos[0] += dir[cur][0];
                    pos[1] += dir[cur][1];
                }
                else if (m == 'L') {
                    cur = (cur + 3) % 4;
                }
                else cur = (cur + 1) % 4;
            }
            if (pos[0] == 0 && pos[1] == 0) return true;
        } 
        
        return false;
    }
};