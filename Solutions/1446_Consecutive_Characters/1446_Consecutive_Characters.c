//Second fastest
int maxPower(char * s)
{
    int i,max=0,cnt=0;
    
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==s[i+1])
        {
            cnt++;
            if(max<cnt)
                max=cnt;
        }
        else
        {
            cnt=0;
        }
    }
    return(max+1);

}

//Fastest
int maxPower(char* s){
	int max = 1;
	for(int i = 0;  s[i] != '\0'; ){
	
		int count = 0;  
		int j = i;  

		while(s[i] == s[j]) count++,j++;	
		
		i = j;
		if(count > max) max = count;
		
	}
	return max;
}

//Another fastest
int maxPower(char * s){
int max=1,prev=1;
for(int i=0;i<strlen(s)-1;i++)
{
    if(s[i]==s[i+1])
    {
        max++;
    }
    else
    {
        if(max>prev)
        {
            prev=max;
        }
         max=1;
    }
}
if(max>prev)
    return max;
return prev;
}