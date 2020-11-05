int minCostToMoveChips(int* position, int positionSize){
	short i = 0, oddNumbers = 0, evenNumbers = 0;
	for(; i < positionSize; ++i)
	{
		if (position[i] % 2 == 0)
		{
			++evenNumbers;
		}
		else
		{
			++oddNumbers;
		}
	}
	if (oddNumbers <= evenNumbers)
	{
		return oddNumbers;
	}
	return evenNumbers;
}

//Another
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCostToMoveChips(int* position, int positionSize)
{
	int even = 0, odd = 0;
	for (int i = 0; i < positionSize; ++i)
		position[i] % 2 == 0 ? ++even : ++odd;
	return min(even, odd);
}