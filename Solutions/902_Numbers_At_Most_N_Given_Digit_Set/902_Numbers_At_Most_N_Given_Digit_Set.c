//https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/312238/c-solution-beating-100-O(1)
int atMostNGivenDigitSet(char ** D, int DSize, int N){
    if (DSize == 0 || N <= 0)
        return 0;

    int k = 0;
    char digits[10] = {'0'};
    int n = N;
    while ( n > 0)
    {
        int mod = n % 10;
        digits[k++] = mod + '0';
        n -= mod;
        n /= 10;
    }

    int lt[10] = {0};
    int eq[10] = {0};
    int l = DSize - 1;
    for (int i = 9; (i >= 0 && l >= 0); i--)
    {
        if (*D[l] < ('0' + i))
            lt[i] = l + 1;
        else if (*D[l] == ('0' + i))
        {
            lt[i] = l--;
            eq[i] = 1;
        }
        else
            l--;
    }

    int result = 0;
    int ceq = 1;

	if (k == 1)
	{
		char c = digits[0];
		result = lt[c - '0'] + eq[c - '0'];
		return result;
	}

    for (int i = k - 1; i >= 0; i--)
    {
        char c = digits[i];

		if (i < k - 1)
			result += pow(DSize, i + 1);

		if (lt[c - '0'] && ceq)
			result += lt[c - '0'] * pow(DSize, i);

        if (!eq[c - '0'])
            ceq = 0;
    }
    return result + ceq;
}