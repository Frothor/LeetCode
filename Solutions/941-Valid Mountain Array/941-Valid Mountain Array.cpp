//Fourth fastest
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        auto peak = false;
        if (arr.size() < 3 || arr[0] > arr[1] ) return false;
        for (int i=1; i<arr.size(); i++){
            //always down the mountain otherwise false 
            if( (peak && arr[i] > arr[i-1]) || arr[i]==arr[i-1]) return false;
            //find the peak of the mountain
            peak = arr[i] < arr[i-1];
        }
        return peak;
    }
};

//Third fastest
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        
        int state = 0;
        
        for(int i = 1; i < arr.size(); i++) {
            if(state == 0) {
                if(arr[i - 1] >= arr[i])
                    return false;
                state = 1;
            }
            else if (state == 1) {
                if(arr[i - 1] > arr[i])
                    state = 2;
                else if (arr[i - 1] == arr[i])
                    return false;
            }
            else {
                if (arr[i - 1] <= arr[i])
                    return false;
            }
        }
        
        if(state == 1)
            return false;
        
        return true;
    }
};

//Second fastest
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        bool peak = false;
        if (arr[1] <= arr[0]) return false;
        int j = -1;
        for (auto&& curEl: arr){
            if (j < 1){
                j++;
                continue;
            }
            if (curEl < arr[j]){
                if (!peak) peak = true;
            }
            else{
                if (curEl == arr[j]) return false;
                if (peak) return false;
            }
            j++;
        }
        return peak;
    }
};

//Fastest
class Solution {
public:
	Solution() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);
	}
	bool validMountainArray(vector<int>& arr) {
		int i = 1 , j = 2 , n = arr.size();
		if (n <= 1) {
			return 0;
		}
		if (arr[1] < arr[0]) {
			return 0;
		}
		int f = 1;
		while (j < n) {
			if (arr[i] < arr[j]) {
				if (f != 1) {
					return 0;
				}
			}
			else if (arr[i] > arr[j]) {
				if (f == 1) {
					f = 2;
				}
				else if (f == 1) {
					return 0;
				}
			}
			else {
				return 0;
			}
			i++;
			j++;
		}
		return f==2;
	}
};