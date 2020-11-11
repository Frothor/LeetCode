//Second fastest
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dis_1_to_2 = distance2power(p1, p2);
        int dis_1_to_3 = distance2power(p1, p3);
        int dis_1_to_4 = distance2power(p1, p4);

        if (dis_1_to_2 == 0 || dis_1_to_3 == 0 || dis_1_to_4 == 0) {
            return false;
        } else if (dis_1_to_2 == dis_1_to_3 && dis_1_to_4 == (dis_1_to_2 + dis_1_to_3)) {
            // judge slope
            return is90degree(p2, p1, p3) && is90degree(p2, p4, p3);
        } else if (dis_1_to_2 == dis_1_to_4 && dis_1_to_3 == (dis_1_to_2 + dis_1_to_4)) {
            return is90degree(p2, p1, p4) && is90degree(p2, p3, p4);
        } else if (dis_1_to_3 == dis_1_to_4 && dis_1_to_2 == (dis_1_to_3 + dis_1_to_4)) {
            return is90degree(p3, p1, p4) && is90degree(p3, p2, p4);
        }
        return false;
    }

    int distance2power(vector<int> &a, vector<int> &b) {
        return abs((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }

    double is90degree(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (b[1] - a[1]) * (b[1] - c[1]) + (b[0] - a[0]) * (b[0] - c[0]) == 0;
    }
};

//Another
#include<math.h>
class Solution {
public:
    double calc(vector<int>& p1, vector<int>& p2){
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<double> s;
        if(p1==p2 || p2==p3 || p3==p4 || p4==p1)return false;
        double d1=calc(p1,p2),d2=calc(p2,p3),d3=calc(p3,p4),d4=calc(p4,p1),d5=calc(p1,p3),d6=calc(p2,p4);
        s.insert(d1);s.insert(d2);s.insert(d3);s.insert(d4);s.insert(d5);s.insert(d6);
        return s.size()==2;
    }
};

//Fastest
class Solution {
public:
    double d(vector<int>& p1, vector<int>& p2) {
        return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // support variables
        double d0, d1, d2, d3;
        vector<vector<int>> pts = {p1, p2, p3, p4};
        sort(begin(pts), end(pts));
        // computing the distances between ordered points
        d0 = d(pts[0], pts[1]), d1 = d(pts[0], pts[2]), d2 = d(pts[0], pts[3]), d3 = d(pts[1], pts[2]);
        // checking if sides are non-0 and if sides and diagonals are equal
        return d0 && d2 && d0 == d1 && d2 == d3;
    }
};

//Another
class Solution {
public:
    int getSquaredDistance(vector<int> &a, vector<int> &b) {
        int dx = a[0]-b[0];
        int dy = a[1]-b[1];
        return dx*dx + dy*dy;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // connected, perpecular
        
        vector<int> dist_sq(6);
        dist_sq[0] = getSquaredDistance(p1, p2);
        dist_sq[1] = getSquaredDistance(p1, p3);
        dist_sq[2] = getSquaredDistance(p1, p4);
        dist_sq[3] = getSquaredDistance(p2, p3);
        dist_sq[4] = getSquaredDistance(p2, p4);
        dist_sq[5] = getSquaredDistance(p3, p4);
        sort(dist_sq.begin(), dist_sq.end());
        
        //For the Six Distances in Sorted Array
        //The 1st and the 4th distance should be equal (This implies first 4 are equal)
        //The 5th and the 6th distance should be equal
        //Side should not be zero/Distance of side and diagonal shouldn't be equal
        return (dist_sq[0]>0  // >0 for all
                && dist_sq[0]==dist_sq[3] // first 4 equal
                && dist_sq[4]==dist_sq[5] // longest 2 (diagnal) equal
                && dist_sq[3]<dist_sq[4]); // side < diagnal
    }
};