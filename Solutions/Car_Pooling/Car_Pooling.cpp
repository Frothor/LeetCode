class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 0;
        for(auto trip: trips)
            n = max(n, trip[2]);
        
        vector<int> result(n+1, 0);
        
        for(auto trip : trips) {
            result[trip[1]] += trip[0];
            result[trip[2]] -= trip[0];
        }
        
        for(int i = 1; i < n; i++)
            result[i] += result[i-1];
        
        for(int i = 0; i < n; i++)
            if(result[i] > capacity)
                return false;
        
        return true;
    }
};

//Fastest
class Solution {
public:
    
    // using 1000 stops
    bool carPooling(vector<vector<int>>& trips, int capacity){
        vector<int> stops(1001); 
        for (vector<int>& trip: trips){
            stops[trip[1]] += trip[0]; 
            stops[trip[2]] -= trip[0];
        }

        int n = 0; 
        for (int i = 0; i < 1001; ++i){
            n += stops[i]; 
            if (n > capacity) return false;
        }
        return true; 
    }
    
    
    // intuition
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         set<int> stops;
//         unordered_map<int, int> pick, drop; 
//         for (vector<int>& trip: trips){
//             pick[trip[1]] += trip[0]; 
//             drop[trip[2]] += -trip[0];
//             stops.insert(trip[1]); 
//             stops.insert(trip[2]);  
//         }

//         int n = 0; 
//         for (auto stop: stops){
//             if (pick.count(stop)) n += pick[stop]; 
//             if (drop.count(stop)) n += drop[stop]; 
//             if (n > capacity) return false; 
//         }
//         return true; 
//     }
};