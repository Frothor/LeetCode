class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_map<char,int>mp;
        for(int index = 0;index<secret.size();index++)
            if(secret[index]==guess[index])A++;
            else mp[secret[index]]++;
        
       for(int index = 0;index<guess.size();index++)
           if(secret[index]!=guess[index]&&mp[guess[index]]>0)B++,mp[guess[index]]--;  
       return to_string(A)+'A'+to_string(B)+'B';
    }
};

//Fastest
class Solution {
    short _data[10][4] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };
    int _bullCount = 0;
    int _cowCount = 0;
public:
    void computeBulls(const std::string& secret, const std::string& guess) {
        // Map bull to table
        for (size_t i = 0; i < secret.size(); i++) {
            int sidx = secret[i] - '0';
            if (secret[i] == guess[i]) {
                _data[sidx][2]++; // symbol B
            }
        }
    }
    void computeCows(const std::string& secret, const std::string& guess) {
        for (size_t i = 0; i < secret.size(); i++) {
            // Incoming number digit frequencies
            int sidx = secret[i] - '0';
            int gidx = guess[i] - '0';

            _data[sidx][0]++; // symbol N
            _data[gidx][1]++; // symbol T
        }
        
        // Compute cows
        // symbol C = min(N, T) - B
        for (size_t i = 0; i < 10; i++) {
            _data[i][3] = std::min(_data[i][0], _data[i][1]) - _data[i][2];
        }
    }
    void computeResults() {
        for (size_t i = 0; i < 10; i++) {
            _bullCount += _data[i][2];
            _cowCount += _data[i][3];
        }
    }
    std::string getAnswer() {
        return std::to_string(_bullCount) + "A" + std::to_string(_cowCount) + "B";
    }
    string getHint(string secret, string guess) {
        computeBulls(secret, guess);
        computeCows(secret, guess);
        computeResults();
#if 0
        for (size_t i = 0; i < 10; i++) {
            for (size_t j = 0; j < 4; j++) {
                std::cout << _data[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
#endif

        return getAnswer();
    }
};