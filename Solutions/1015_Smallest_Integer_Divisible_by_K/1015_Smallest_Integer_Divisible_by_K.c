//https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/261115/simple-C-solution
int smallestRepunitDivByK(int K) {
    int *hash = malloc(K*sizeof(int));
    for(int i=0;i<K;i++)
        hash[i] = 0;
    int ret = 1;
    int retvalue = 1;
    while(retvalue<K)
    {
        ret++;
        retvalue = retvalue*10+1;
    }
    int mod = retvalue%K;
    while(mod!=0)
    {
        if(hash[mod]!=0)
            break;
        hash[mod] = ret;
        ret++;
        mod = 10*mod +1;
        mod %=K;
    }
    if(mod==0)
        return ret;
    else 
        return -1;
}

//Another
int smallestRepunitDivByK(int K)
{
	int remainder = 0;
	for (int i = 1; i <= K; ++i)
	{
		remainder = (remainder * 10 + 1) % K;
		if (remainder == 0)
			return i;
	}
	return -1;
}