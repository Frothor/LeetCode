/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = NULL, *p1 = l1, *p2 = l2, *p3 = l3, *p3_prev = NULL; int carry = 0; int turn = 0;
  while(p1 || p2 || carry) {
    int val1 = 0, val2 = 0, val3 = 0;
    if (p1) {
      val1 = p1->val;
      p1 = p1->next;
    }
    if (p2) {
      val2 = p2->val;
      p2 = p2->next;
    }
    val3 = val1 + val2 + carry;
    carry = val3 / 10;
    p3 = (struct ListNode *) malloc(sizeof(struct ListNode)); p3->val = val3 % 10; p3->next = NULL;
    if (!turn)
      l3 = p3;
    else
      p3_prev->next = p3;
    p3_prev = p3;
    turn++;
  }
  return l3;
}

// Almost the fastest
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *current_result = result;

    int overflow = 0;
    
    int val1 = l1->val;
    int val2 = l2->val;

    do
    {
        int sum = val1 + val2 + overflow;
        overflow = 0;
        overflow = (int) sum / 10;
        current_result->val = sum % 10;
        
        l1 = (l1 && l1->next) ? l1->next : NULL;
        l2 = (l2 && l2->next) ? l2->next : NULL;

        if (l1 == NULL && l2 == NULL)
        {
            if (overflow == 1)
            {
                current_result->next = (struct ListNode *) malloc(sizeof(struct ListNode));
                current_result = current_result->next;
                current_result->val = 1;
            }

            current_result->next = NULL;
            break;
        }
        else
        {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            
            current_result->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            current_result = current_result->next;
        }
    }
    while(true);

    return result;
}

// Fastest
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *first = NULL,*last = NULL;
    int carry = 0;
    while(l1&&l2){
        int sum = carry+l1->val+l2->val;
        struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
       
        t->val = sum%10;
        carry = sum/10;
        if(first==NULL){
            first = t;
            last = first;
            last->next = NULL;
        }
        else{
            last->next = t;
            last = t;
            last->next = NULL;
        }
        l1 = l1->next;
        l2 = l2->next;
     }
       while(l1){
            int sum = carry+l1->val;
            struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
            t->val = sum%10;
            carry = (sum/10);
            if(first==NULL){
                first = t;
                last = first;
                last->next = NULL;

            }
            else{
                last->next = t;
                last = t;
                last->next = NULL;
            }
            l1 = l1->next;
        }
     
     while(l2){
        int sum = carry+l2->val;
         struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        t->val = sum%10;
        carry = (sum/10);
         if(first==NULL){
            first = t;
            last = first;
            last->next = NULL;
        }
        else{
            last->next = t;
            last = t;
            last->next = NULL;
        }
        l2 = l2->next;
    }
    if(carry!=0){
        struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = carry;
        last->next = t;
        last = t;
        last->next = NULL;
    }
    return first;
    return 0;
}