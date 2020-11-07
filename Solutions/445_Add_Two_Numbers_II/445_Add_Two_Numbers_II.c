int *count(struct ListNode* head,int* size)
{
    int *count=calloc(1000,sizeof(int));
    int idx=0;
    while(head)
    {
        count[idx++]=head->val;
        head=head->next;
    }
    *size=idx;
    return count;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int len1,len2,idx=0,c=0;
    int* num1=count(l1,&len1);
    int* num2=count(l2,&len2);
    int *tmp=calloc(1000,sizeof(int));
    len1--;
    len2--;
    while(len1>=0&&len2>=0)
    {
        int num=num1[len1--]+num2[len2--]+c;
        tmp[idx++]=num%10;
        c=num/10;
    }
    while(len1>=0)
    {
        int num=num1[len1--]+c;
        tmp[idx++]=num%10;
        c=num/10;
    }
    while(len2>=0)
    {
        int num=num2[len2--]+c;
        tmp[idx++]=num%10;
        c=num/10;
    }

    struct ListNode* head=malloc(sizeof(struct ListNode));
    head->next=NULL;
    head->val=tmp[idx-1]%10;
    struct ListNode* ret=head;
    for(int i=idx-2;i>=0;i--){
        struct ListNode* node=malloc(sizeof(struct ListNode));
        node->next=NULL;
        node->val=tmp[i];
        head->next=node;
        head=head->next;
    }
    if(c)   //if carry
    {
        struct ListNode* carry=malloc(sizeof(struct ListNode));
        carry->val=1;
        carry->next=ret;
        return carry;
    }

    return ret;
}

//Third fastest
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
   if(l1== NULL)
       return l2;
    if(l2== NULL)
       return l1;
    int stack1[100] = {0}, stack2[100] = {0}, stack3[100] = {0}, j=0, k=0; 
    
    struct ListNode* ll1 = l1;
    struct ListNode* ll2 = l2;
    
    while(l1 || l2)
    {
       if( l1)
       {
            stack1[j++] = l1->val;
             l1= l1->next;
       }
        
        if( l2)
        {
             stack2[k++] = l2->val;
             l2= l2->next;
        }
        
    }

    
   int carry =0, i=(j>k? j:k); 
   int len1 = j, len2 = k, len3 = i;
    j--; k--;
    
    while(k>=0 && j>=0)
    {
       stack3[i--] = (stack1[j]+stack2[k] + carry)%10;
       carry = (stack1[j--]+stack2[k--]+carry)/10;
    }
     while(k>=0)
    {
       stack3[i--] = (stack2[k] + carry)%10;
       carry = (stack2[k--]+carry)/10;
    }
    
     while( j>=0)
    {
       stack3[i--] = (stack1[j]+ carry)%10;
       carry = (stack1[j--]+carry)/10;
    }
    struct ListNode* head = NULL;
    if(carry)
    {
        stack3[i] = carry;
    
        head = (struct ListNode* )calloc(1, sizeof(struct ListNode));
        if(head == NULL)
            return NULL;
     
         head->next = (len1>len2)?ll1:ll2;
        
    }
    else
    {
        head = (len1>len2)?ll1:ll2;
        i++;
    }
    
    ll1 = head;
 
 while(i <=len3 && head)
 {
     head->val = stack3[i++];
     head= head->next;
 }
      
   return ll1;
    
}

//Second fastest
struct ListNode *newnode(int data)
{
    struct ListNode* new;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = data;
    new->next = NULL;
    return new;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int *stack1 = (int*)malloc(sizeof(int)*100);
    int *stack2 = (int*)malloc(sizeof(int)*100);
    struct ListNode *l3, *head = NULL;
    
    int top1 = -1, top2 = -1;
    int res = 0;
    while(l1)
    {
        top1++;
        stack1[top1] = l1->val;
        l1 = l1->next;
    }
    
    while(l2)
    {
        top2++;
        stack2[top2] = l2->val;
        l2 = l2->next;
    }
    
    while(top1 >= 0 || top2 >= 0)
    {
        res = res/10;
        if(top1 >= 0)
        {
            res += stack1[top1];
            top1--;
        }
        
        if(top2 >= 0)
        {
            res +=  stack2[top2];
            top2--;
        }
        if(head == NULL)
        {
            l3 = newnode(res%10);
            head = l3;
        }
        else
        {
            l3 = newnode(res%10);
            l3->next = head;
            head = l3;
        }
    }
    
    if(res >= 10)
    {
            l3 = newnode(res/10);
            l3->next = head;
            head = l3;
        
    }
    return head;

}

//Fastest
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int get_ll_len (struct ListNode *head)
{
    int l = 0;
    
    while (head) {
        l++;
        head = head->next;
    }
    
    return (l);
} 

struct ListNode* new_node (int val)
{
    struct ListNode *n = (struct ListNode *)calloc(1, sizeof(struct ListNode)); 
    if (n) {
        n->val = val; 
    }
    
    return (n);
}

void add_ll_recursive (struct ListNode *l1, struct ListNode *l2, int *carry)
{
    int sum = 0;
    
    if (!l1 || !l2) {
        return; 
    } 
    
    if (l1->next) {
        add_ll_recursive(l1->next, l2->next, carry);
    }
    
    //printf("l1 %d, l2 %d\n", l1?l1->val:-1, l2?l2->val:-1);
  
    sum = l1->val + l2->val + *carry; 
    *carry = sum / 10;
    l1->val = sum % 10;
    l2->val = sum % 10;
}

struct ListNode* add_head (struct ListNode *l, int cnt) 
{
    int i;
    struct ListNode *head;
    
    for (i = 0; i < cnt; i++) {
        head = new_node(0); 
        head->next = l;
        l = head;
    }
    
    return (l);
}

struct ListNode* addTwoNumbers (struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    struct ListNode *head;
    int len1 = get_ll_len(l1), len2 = get_ll_len(l2); 
   
    if (len1 > len2) {
        l2 = add_head(l2, len1 - len2); 
    } else if (len1 < len2) {
        l1 = add_head(l1, len2 - len1); 
    }
    
    add_ll_recursive(l1, l2, &carry);
   
    if (carry) {
        head = new_node(carry); 
        head->next = l1;
    } else {
        head = l1;     
    }
    
    return (head);
}