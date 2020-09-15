class Solution {
public:
    int lengthOfLastWord(string s) {
        int A = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] != ' ') ++A;
            else if (A) return A;
        }
        return A;
    }
};

//Fastest
class Solution {
public:
	int lengthOfLastWord(string s) {
		vector<string> temp;
		auto i = s.begin(), j = s.end();
		j--;
		int res = 0;
		while ((*i) == ' ') i++;
		while ((*j) == ' ') j--;
		while (i <= j) {
			if ((*i) == ' ') {
				res = 0;
			}else
			{
				res++;
			}
			i++;
		}
		return res;
	}
};