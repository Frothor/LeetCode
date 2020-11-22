//Fastest -> https://leetcode.com/problems/unique-morse-code-words/discuss/201895/0ms-Solution-In-C
typedef struct {
    char len;
    char val;
} morseCode;

morseCode codeTable[] = {
    {2, 2}, /* a .-   10*/
    {4, 7}, /* b -... 0111*/
    {4, 5}, /* c -.-. 0101 */
    {3, 3},
    {1, 1},
    {4,13},
    {3, 1},
    {4,15},
    {2, 3},
    {4, 8},
    {3, 2},
    {4,11},
    {2, 0},
    {2, 1},
    {3, 0},
    {4, 9},
    {4, 2},
    {3, 5},
    {3, 7},
    {1, 0},
    {3, 6},
    {4,14},
    {3, 4},
    {4, 6},
    {4, 4},
    {4, 3}
};

typedef struct{
    int len;
    int val;
}morseString;

morseString getmorseString(char* s) {
    morseString str;
    str.len = 0;
    str.val = 0;
    
    char *p = s;
    while(*p != '\0')
    {
        char c = *p;
        if (c < 'a' || c > 'z'){
            printf("Invalid input *p = %c\n", c);
            p++;
            continue;
        }
        
        morseCode code = codeTable[c - 'a']; 
        str.len += code.len;
        str.val = (str.val << (code.len)) + code.val;
        p++;
    }
    
    return str;
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
    int result = -1;
    morseString stack[100];
    
    for(int i = 0; i < wordsSize; i++)
    {
        morseString str = getmorseString(words[i]);
        bool foundone = false;
        for (int j = 0; j <= result; j++)
        {
            // check one by one if str in stack
            if (stack[j].len == str.len && stack[j].val == str.val) {
                foundone = true;
                break;
            }
        }
        
        if (!foundone)
        {
            stack[++result] = str;
        }
    }
    
    return result + 1;
}

//Second fastest
int uniqueMorseRepresentations(char ** words, int wordsSize){
    
    char *code[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    char** com=(char**)calloc(wordsSize,sizeof(char*));
    
    char *hash[100]={0};////沒有初始不可用char*
   
    for(int i=0;i<wordsSize;i++)
    {
        int len=strlen(words[i]);
        
        com[i]=(char*)calloc(60,sizeof(char));//不初使會沒結尾
        for(int j=0;j<len;j++)
        {
          strcat(com[i],code[words[i][j]-'a']);
            
            
        }
        
        
    }
    
    ///////////////比較幾個字串不一樣
    int count=0;
    int f=0;
    for(int i=0;i<wordsSize;i++)
    {
    for(int j=0;j<count;j++)
    {
        if(!strcmp(com[i],hash[j]))
        {
            f=1;
            break;
        }
        
    }
    if(f==0)////儲存新增不同的數字以便之後查詢比較用
    {
    hash[count]= com[i];  
    count++;
    }   
        f=0;
    }
    
    
    /////////////////////////////
    
for(int i=0;i<wordsSize;i++)
{
    free(com[i]);
}
    free(com);
 /* char *h[3]={0};
char* hh[3]={"aa","bb","cc"};
    h[1]=hh[1];
    if(h[0]==hh[1])
    {
    return 3;
    }*/
    return count;

}