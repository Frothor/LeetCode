class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = 0, e = citations.size() - 1, avg;
        sort(begin(citations), end(citations));
        while (s <= e) {
            if (citations[avg = (e + s) / 2] < citations.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return citations.size() - s;
    }
};

//Most common
class Solution {
public:
    int hIndex(vector<int>& citations) {
                int maxCitation = 0;
         for(int i : citations){
            maxCitation = max(maxCitation, i);
         }
        int hIdx = min((int)citations.size(), maxCitation);
        vector<int> citeNum(hIdx+1, 0);
        for(int i : citations){
            if(i > hIdx){
                citeNum[hIdx]++;
            } else{
                citeNum[i]++;
            }
        }
        int sum = 0;
        for(int i = hIdx ; i >=1 ; i--){
            sum+=citeNum[i];
            if(sum>= i)
                return i;
        }
        return 0;
    }
};

//Fastest
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,j,n=citations.size();
        sort(citations.begin(),citations.end());
        if(n==0)
            return 0;
        int ans=1;
        for(i=0;i<n;i++){
            if(n-i<=citations[i])
                return n-i;
        }
        return 0;
    }
};