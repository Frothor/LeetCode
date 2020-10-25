class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        if(tokens.size() == 0)   /// Base case
            return 0;
        
        sort(tokens.begin(),tokens.end());
        if(P < tokens[0])   /// if P < minimum token value, we can't collect any points.
            return 0;
        int n = tokens.size();
        vector<int> prefix_sum(n,0);
        
        prefix_sum[0] = tokens[0];
        for(int i = 1;i<n;i++)
            prefix_sum[i] = prefix_sum[i-1] + tokens[i];
        
        int ans = lower_bound(prefix_sum.begin(),prefix_sum.end(),P) - prefix_sum.begin();   /// Initialize answer with the value of points we can collect without playing any face down card.
        
        int power = P;
        for(int i = n-1 ; i >= n/2; i--){     /// Running the loop till n/2 because face-up cards should be greater than face down to collexct points
             power += tokens[i];
          
            int points = lower_bound(prefix_sum.begin(),prefix_sum.end(),power) - prefix_sum.begin() - (n-i);    /// Finding the number of points for a particular value of power.
            if(binary_search(prefix_sum.begin(),prefix_sum.end(),power)){
                points = points+1;    /// Handling the case when Power of both the subsets are equal.
            }
           
            ans = max(ans,points);
        }
        return ans;
         
    }
};

//Third fastest
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty()) return 0;
        std::sort(tokens.begin(), tokens.end());
        int p1 = 0, p2 = int(tokens.size()) - 1;
        int score = 0;
        int maxScore = 0;
        while(p1 <= p2)
        {
            if(tokens[p1] <= P)
            {
                P -= tokens[p1++];
                score++;
                maxScore = std::max(maxScore, score);
            }
            else
            {
                if(score == 0)
                {
                    break;
                }
                else
                {
                    score--;
                    P += tokens[p2--];
                }
            }
        }
        return maxScore;
    }
};

//Second fastest
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int res = 0, points = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {
                points--;
                P += tokens[j--];
            } else {
                break;
            }
        }
        return res;
    }
};

//Fastest
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        if (tokens.size() == 0 || P < tokens[0]) return 0;
        int curPoints = 0;
        int i = 0;
        int j = tokens.size()-1;
        
        while(i<=j)
        {
            if(P >= tokens[i])
            {
                curPoints++;
                P -= tokens[i];
                //maxPoints = max(maxPoints, curPoints);
                i++;
            }
            else{ if( j - i > 0)
            {
                P += tokens[j];
                curPoints--;
                j--;
            }
            else
                break;
                }
        }
        
        return curPoints;
    }
};