class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		short oddNumbers = 0, evenNumbers = 0;
		for (std::vector<int>::iterator it = position.begin(); it != position.end(); ++it)
		{
			if (*it % 2 == 0)
			{
				++evenNumbers;
			}
			else
			{
			   ++oddNumbers; 
			}
		}
		if (oddNumbers >= evenNumbers)
		{
			return evenNumbers;
		}
		return oddNumbers;
	}
};

//Another
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount=0;
        int oddCount=0;
        for(int i=0;i<position.size();i++){
            if(position[i]%2==0){
                evenCount++;
            }else{
                oddCount++;
            }
        }
        return min(evenCount,oddCount);
    }
};