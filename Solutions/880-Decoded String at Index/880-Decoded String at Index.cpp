//https://leetcode.com/problems/decoded-string-at-index/discuss/979623/C%2B%2B-TimeSpace%3A-O(N)-O(1)-greedy-simulation
class Solution {
public:    
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};

//Another
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long size = 0;
        int N = S.size();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            if (isdigit(S[i]))
                size *= S[i] - '0';
            else
                size++;
        }

        for (int i = N-1; i >=0; --i) {
            K %= size;
            if (K == 0 && isalpha(S[i]))
                return (string) "" + S[i];

            if (isdigit(S[i]))
                size /= S[i] - '0';
            else
                size--;
        }
        return "";
    }
};