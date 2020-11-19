//https://leetcode.com/problems/decode-string/discuss/716906/C-0ms-runtime-with-stack-implementation
struct stack{
    int val;
    unsigned int cap;
    struct stack *link;
    struct stack *prev_link;
};
int head(struct stack** top){
    if((*top)==NULL)
        return 0;
    return (*top)->val;
}

void push(struct stack** top,struct stack **end,int x){
    struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
    temp->val = x;
    temp->link = NULL;
    temp->prev_link = NULL;
    if((*top)!=NULL){
        temp->cap = ((*top)->cap)+1;
        (*top)->prev_link = temp;
        temp->link = *top;
        *top = temp;
    }
    else{
        temp->cap = 0;
        *top = *end = temp;
    }

}
void pop(struct stack** top){
    if((*top)==NULL)return ;
    struct stack *t = NULL;
    t=(*top);
    (*top) = t->link;
    free(t);
}
void pop_end(struct stack** end){
    if((*end)==NULL)return;
    struct stack *t = *end;
    (*end) = t->prev_link;
    free(t);
}
void print(struct stack* top){
    if(top==NULL)return;
    struct stack* t = top;
    printf("Stack - {");
    while(t!=NULL){
        printf("%c ",t->val);
        t = t->link;
    }
    printf("}");
    printf("\n");
}
/*
	* encoding rules k[encoded_string]
	* using stack to push the brackets and values and follow accordingly
	* store the data in as an integer value , ascii table codes are in range of 0 to 255 int is capbale of storing this data and reversing it 
*/


char * decodeString(char * s){
    if(s==NULL)return NULL;
    if(strlen(s)==0)return "";
    struct stack *encoded_string = NULL;
    struct stack *end = NULL;

    int n = 0;
    int i = 0;
    int j = 0;

    while(*s){

        /// check if the value presented is a number or a char

        if((*s) >= '0' && (*s) <= '9'){

            //build sequence for number bigger than 9

            n = n*10 + (*s)-'0';

        }else if(*s=='['){
            //push the number and the bracket because the bracket comes immediately after the number
            push(&encoded_string,&end,n);
            push(&encoded_string,&end,(int)(*s));//push the bracket
            n=0;

        }else{
            //push the rest of the elements
            push(&encoded_string,&end,(int)(*s));
        }
        if(*s == ']'){
            i=0;
            pop(&encoded_string);           //pop ] bracket
            int len = strlen(s);
            int alloc = len;
            char *string= (char *)calloc(len,sizeof(char));

            int instruction = 0;
            while(head(&encoded_string)!=(int)('[')){
                if(i==len){
                    string = (char *)realloc(string,(len+=alloc));
                }
                string[i] = (char )head(&encoded_string);
                pop(&encoded_string);
                i++;
            }
            pop(&encoded_string);           //pop [ bracket
            instruction = head(&encoded_string);
            pop(&encoded_string);           //pop instruction
            j=i;
            while(instruction){
                while(i){
                    push(&encoded_string,&end,string[i-1]);
                    i--;
                }
                i=j;
                instruction--;
            }
        }
        s++;
    }
    char *res = (char *)calloc(encoded_string->cap+2,sizeof(char));
    while(head(&end)){
        char ch = (char )head(&end);
        res[end->cap] = ch;
        pop_end(&end);
    }
    return res;

}

//Fastest
void *vmRealloc(void *ptr, int inSize, int outSize)
{
    char *out = (char *)calloc(outSize, sizeof(char));
    char *in = (char *)ptr;
    memcpy(out, ptr, inSize * sizeof(char));
    free(in);
    return (void *)out;
}

typedef struct
{
    char *arrChar;
    int size;
    int capacity;
} charStack;

charStack *createCharStack()
{
    charStack *obj = (charStack *)malloc(sizeof(charStack));
    obj->size = 0;
    obj->capacity = 100;
    obj->arrChar = (char *)calloc(obj->capacity + 1, sizeof(char));
    return obj;
}

void pushChar(charStack *obj, char ch)
{
    obj->arrChar[(obj->size)++] = ch;
    if (obj->size >= obj->capacity)
    {
        obj->capacity += 100;
        obj->arrChar = (char *)vmRealloc(obj->arrChar, obj->size * sizeof(char), 
                                         (obj->capacity + 1) * sizeof(char));
    }
}

char *popStr(charStack *obj)
{
    char *ptr = strrchr(obj->arrChar, '[');
    if (ptr)
    {
        char *ret = (char *)calloc(strlen(ptr), sizeof(char));
        memcpy(ret, ptr + 1, (strlen(ptr) - 1) * sizeof(char));
        
        obj->size -= strlen(ptr);
        memset(ptr, 0, strlen(ptr) * sizeof(char));
        
        return ret;
    }
    return NULL;
}

typedef struct
{
    int *arrVal;
    int size;
    int capacity;
} vmStack;

vmStack *createStack()
{
    vmStack *obj = (vmStack *)malloc(sizeof(vmStack));
    obj->size = 0;
    obj->capacity = 10;
    obj->arrVal = (int *)calloc(obj->capacity, sizeof(int));
    return obj;
}

void pushVal(vmStack *obj, int val)
{
    obj->arrVal[(obj->size)++] = val;
    if (obj->size >= obj->capacity)
    {
        obj->capacity += 10;
        obj->arrVal = (int *)vmRealloc(obj->arrVal, obj->size * sizeof(int), obj->capacity * sizeof(int));
    }
}

int popVal(vmStack *obj)
{
    if (!obj || obj->size < 1)
        return 0;
    return obj->arrVal[--obj->size];
}

bool isEmpty(vmStack *obj)
{
    return obj->size == 0;
}

int str2int(char *s, int *idx)
{
    int num = 0, len = strlen(s);
    
    if (*idx >= len)
        return num;
    
    for (; *idx < len; (*idx)++)
    {
        if (s[*idx] >= '0' && s[*idx] <= '9')
        {
            num *= 10;
            num += (s[*idx] - '0');
        }
        else
            return num;
    }
    return num;
}

char * decodeString(char * s){
    
    int i, len = strlen(s), val, times;
    
    if (len < 1)
        return "";
    
    int retSize = 0, retCapacity = 100;
    char *result = (char *)calloc(retCapacity, sizeof(char)), ch, *ptr;
    vmStack *valObj = createStack();
    charStack *charObj = createCharStack();
    
    
    for (i = 0; i < len; i++)
    {
        ch = s[i];
        
        if (ch >= '0' && ch <= '9')
        {
            val = str2int(s, &i);
            i--;
            
            pushVal(valObj, val);
        }
        else if (ch == '[')
            pushChar(charObj, ch);
        else if (ch == ']')
        {
            times = popVal(valObj);
            ptr = popStr(charObj);
            
            //printf("%s, times=%d\n", ptr, times);
            
            if (ptr)
            {
                if (isEmpty(valObj))
                {
                    while (times)
                    {
                        if (retSize + strlen(ptr) >= retCapacity)
                        {
                            retCapacity += strlen(ptr) + 100;
                            result = (char *)vmRealloc(result, retSize, retCapacity * sizeof(char));
                        }

                        memcpy(result + retSize, ptr, strlen(ptr) * sizeof(char));
                        retSize += strlen(ptr);

                        times--;
                    }
                }
                else
                {
                    while (times)
                    {
                        if (charObj->size + strlen(ptr) >= charObj->capacity)
                        {
                            charObj->capacity += strlen(ptr) + 100;
                            charObj->arrChar = (char *)vmRealloc(charObj->arrChar,
                                                                 charObj->size,
                                                                 charObj->capacity * sizeof(char));
                        }
                        
                        for (val = 0; val < strlen(ptr); val++)
                                pushChar(charObj, ptr[val]);
                        
                        times--;
                    }
                }
                
                free(ptr);
            }
            
        }
        else
        {
            if (isEmpty(valObj))
                result[retSize++] = ch;
            else
                pushChar(charObj, ch);
        }
    }

    return result;
}