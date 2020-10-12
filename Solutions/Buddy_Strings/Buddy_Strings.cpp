class Solution {
public:
    bool buddyStrings(string &a, string &b) {
        // support variables
        int lenA = a.size(), diff = -1;
        // edge cases, out: different sizes or too short
        if (lenA != b.size() || lenA < 2) return false; 
        for (int i = 0; i < lenA; i++) {
            // acting only when a difference is found
            if (a[i] != b[i]) {
                // checking if it is the first difference we found and in case storing i
                if (diff == -1) {
                    diff = i;
                }
                // exiting if it was the third mismatch
                else if (diff == -2) return false;
                // checking if it is a valid or invalid second match
                else {
                    // valid match
                    if (a[diff] == b[i] && a[i] == b[diff]) diff = -2;
                    // invalid match
                    else return false;
                }
            }
        }
        // checking if we found only 2 mismatches or if we found 1 and the string was
        // long enough or not made of all different characters
        return diff == -2 || diff == -1 && (lenA > 26 || unordered_set(begin(a), end(a)).size() != lenA);
    }
};

//Another
class Solution {
public:
    bool buddyStrings(string_view A, string_view B) {
		// If the sizes are different, there is not way to make them
		// the same by swapping, so return false
        if (A.size() != B.size()) return false;
        
		// Find the first index `i` where A[i] != B[i]
		// The standard library function `mismatch` does exactly that.
        auto [ai, bi] = mismatch(A.begin(), A.end(), B.begin());
		
		// If A already equals B, we shoud try to void the swap by
		// swapping two charaters that are the same. This can only
		// be done if the string contains duplicates
        if (ai == A.end()) return contains_duplicates(A);
        
		// Try to find the next index `j` where A[j] != B[j]
        auto [aj, bj] = mismatch(next(ai), A.end(), next(bi));
		
		// If the rest of the characters (after the i'th index) are the same,
		// there is only one different character in the two strings, and we
		// can't fix that by swapping, so return false
        if (aj == A.end()) return false;
        
		// By reaching this part of the code, we have already found two
		// distinct indices `i` and `j` such that A[i] != B[i] and A[j] != B[j].
		// All that is left is to make sure that the rest of the strings (after
		// the j'th index) are the same.
        auto [ak, bk] = mismatch(next(aj), A.end(), next(bj));
		
		// Of course, if they are not the same then there is more that
		// two positions where the characters are different, and we can't fix
		// that by swapping just two characters, so return false
        if (ak != A.end()) return false;
        
		// Lastly, make sure that swapping the two characters A[i] and A[j]
		// actually makes A == B
        return *ai == *bj && *aj == *bi;
    }
	
    bool contains_duplicates(string_view s) {
        bool seen[26]{};
        for (char c : s) {
            if (seen[c - 'a']) return true;
            seen[c - 'a'] = true;
        }
        return false;
    }
};

//Fastest
class Solution {
public:
    int count[26] = {0};
    bool check() {
        for(int i = 0; i < 26 ; i++) 
            if(count[i] > 1)
                return true;
        return false;
    }
    
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) return false;
        int diff = 0;
        int index1 = -1, index2 = -1;
        
        for(int i = 0; i < A.length() && diff < 3; i++) {
            if(A[i] != B[i]) {
                diff++;
                if(index1 != -1) index2 = i;
                else index1 = i;
            }
            else count[A[i] - 'a']++;
        }
        if(diff == 0) return check();
        else if(diff != 2) return false;
        else if(A[index1] == B[index2] && A[index2] == B[index1]) return true;
        else return false;
    }
};