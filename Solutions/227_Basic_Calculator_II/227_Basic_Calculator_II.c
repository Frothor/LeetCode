//https://leetcode.com/problems/basic-calculator-ii/discuss/418670/Simple-C-solution.
//Second fastest
int calculate(char * s){
    int len=strlen(s)+3;
    int *num=malloc(sizeof(int)*len/2);
    int total=0,idx=0,i=0,j=0;
    char *stack=malloc(len);
    while(s[i])
    {
        switch(s[i])
        {
            case '+': case '-':
                stack[++j]=s[i];
                break;
            case '*': 
                i++;
                while(s[i]==' ')
                    i++;
                while(s[i]>='0'&&s[i]<='9')
                {
                    int n=s[i++]-'0';
                    total=total*10+n;
                }
                num[++idx]=total;
                total=0;
                i--;
                num[idx-1]=num[idx-1]*num[idx];
                idx--;
                break;
            case '/':
                i++;
                while(s[i]==' ')
                    i++;
                while(s[i]>='0'&&s[i]<='9')
                {
                    int n=s[i++]-'0';
                    total=total*10+n;
                }
                num[++idx]=total;
                total=0;
                i--;
                num[idx-1]=num[idx-1]/num[idx];
                idx--;
                break;
            case '0' ... '9':
                while(s[i]>='0'&&s[i]<='9')
                {
                    int n=s[i++]-'0';
                    total=total*10+n;
                }
                num[++idx]=total;
                total=0;
                i--;
                break;
        }
         i++;
                
    }

    int tmp=j;
    j=1;
    idx=1;
    while(j <= tmp) { 
        if(stack[j]=='+')
            num[idx+1]=num[idx]+num[idx+1];
        else
            num[idx+1]=num[idx]-num[idx+1];
        idx++;j++;
    }
    return num[idx];

}

//Another
int calculate(char * s){
    char sign = '+';
    int i, lastNum = 0, result = 0;
    long curNum = 0;
    int size = strlen(s);
    
    if (size ==  0)
        return 0;
    
    for (i = 0; i < size; i++) {
        char curChar = s[i];
        
        if (isdigit(curChar))
            curNum = curNum * 10 + curChar - '0';
        
        if (!isdigit(curChar) && !iswspace(curChar) || i == size - 1) {
            if (sign == '+' || sign == '-') {
                result += lastNum;
                lastNum = (sign == '+') ? curNum : -curNum;
            } else if (sign == '*') {
                lastNum *= curNum;
            } else if (sign == '/') {
                lastNum /= curNum;
            }
            
            sign = curChar;
            curNum = 0;
        }
    }
    result += lastNum;
    
    return result;
}

//Fastest
struct DataNode {
    int val;
    char op;
};

int calculate(char * s){
    struct DataNode stack[2];
    int top = 0;
    int val = 0;
    
    while (*s != '\0') {
        //printf("%d %c top %d tv %d\n", val, *s, top, top > 0 ? stack[top-1].val: 0);
        if (*s == '+' || *s == '-') {
            while (top) {
                if (stack[top-1].op == '*') {
                    val = stack[top-1].val * val;
                } else if (stack[top-1].op == '/') {
                    val = stack[top-1].val / val;
                } else if (stack[top-1].op == '+') {
                    val = stack[top-1].val + val;
                } else if (stack[top-1].op == '-') {
                    val = stack[top-1].val - val;
                }
                top--;
            }
            stack[top].val = val;
            stack[top++].op = *s;
            val = 0;
        } else if (*s == '*' || *s == '/') {
            if (top) {
                if (stack[top-1].op == '*') {
                    stack[top-1].val *= val;
                    stack[top-1].op = *s;
                } else if (stack[top-1].op == '/') {
                    stack[top-1].val /= val;
                    stack[top-1].op = *s;
                } else {
                    stack[top].val = val;
                    stack[top++].op = *s;
                }
            } else {
                stack[top].val = val;
                stack[top++].op = *s;
            }
            val = 0;
        } else if (*s == ' ') {
        } else {
            val = val*10+((*s)-'0');
        }
        s++;
    }
    
    while (top) {
        if (stack[top-1].op == '*') {
            val = stack[top-1].val * val;
        } else if (stack[top-1].op == '/') {
            val = stack[top-1].val / val;
        } else if (stack[top-1].op == '+') {
            val = stack[top-1].val + val;
        } else if (stack[top-1].op == '-') {
            val = stack[top-1].val - val;
        }
        top--;
    }
    
    return val;
}