//Most Common
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }
        return A;
    }
        vector<int> sortArrayByParity_2(vector<int>& A) {
        vector<int> result(A.size(), 0);
        int even_idx = 0, odd_idx = A.size()-1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                result[even_idx++] = A[i];
            } else {
                result[odd_idx--] = A[i];
            }
        }
        return result;
    }
};

//Fastest
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
	vector<int> temp(n);
	int j = 0;
	for (int i = 0;i < n;i++) {
		if (A[i] % 2 == 0) {
			temp[j++] = A[i];
		}
	}

	for (int i = 0;i < n;i++) {
		if (A[i] % 2 != 0) {
			temp[j++] = A[i];
		}
	}

	for (int i = 0;i < n;i++) {
		A[i] = temp[i];
	}

	return A;
        
    }
};

//Another Fast
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l=0,r=A.size()-1;
        while(l<r){
            while(l<r && A[l]%2==0)l++;
            while(l<r && A[r]%2==1)r--;
            swap(A[l],A[r]);
        }
        return A;
    }
};

//My
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0, j=0; i<A.size(); i++){
            if(A[i]%2 == 0){
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                j++;
            }
        }
        return A;               
    }
};

//More ellegant
vector<int> sortArrayByParity(vector<int>& A) {
    int len = A.size()-1;
    for(int i = 0; i<len; i++){

        if(A[i]%2 == 1 )
        swap( A[i--], A[len--] );
    }
    return A;
}