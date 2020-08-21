/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};

//Most common
class Solution {
public:
    ListNode *middle(ListNode *head){
        if(head==NULL or head->next==NULL)return head;
        
        ListNode *fst=head->next, *slw=head;
        
        while(fst and fst->next){
            fst=fst->next->next;
            slw=slw->next;
        }
        return slw;
    }
    
    void reverse(ListNode *&head){
        ListNode *curr=head, *next=NULL, *prev=NULL;
        
        while(curr){
            next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
        head= prev;
    }
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head==NULL or head->next==NULL)return;
        
        ListNode *mid = middle(head);
        
        ListNode *h1=head, *h2=mid->next;
        mid->next=NULL;
        
        reverse(h2);
        ListNode *x, *y;
        
        while(h1 && h2){
            x = h1->next;
            y = h2->next;
            
            h1->next=h2;
            h1 = x;
            
            h2->next=x;
            h2 = y;
        }
    }
};

//Fastest
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        
        ListNode* temp = head;
        ListNode* prev;
        ListNode* runner = head;
        
        while (runner && runner->next) {
            prev = temp;
            temp = temp->next;
            runner = runner->next->next;
        }
        
        if (runner == NULL)
            temp = prev;
        
        ListNode* l2 = temp->next;
        temp->next = NULL;
        ListNode* l1 = head;
        l2 = reverse(l2);
        
        l1 = mergeLists(l1, l2);
        return;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
       
        ListNode* head = l1;
        
        while (l1 && l2) {
            ListNode* temp = l1->next;
            ListNode* temp2 = l2->next;
 
               
            l1->next = l2;
            l2->next = temp;
            l1 = temp;
            l2 = temp2;
        }
        
        return head;
    }
    
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

//Another
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head){
            return; 
        }
        // Step 1. Break the list from the middle
        ListNode* current1 = head;
        ListNode* current2 = head->next;
        while(current2 && current2->next){
            current1 = current1->next;
            current2 = current2->next->next;
        }
        current2 = current1->next;
        current1->next = nullptr;
        
        // Step 2. Adjust pointers to head and tail
        current1 = head;
        current2 = reverse(current2);
        
        // Step 3. Merge two lists
        while(current2){
            ListNode* temp1 = current1->next;
            ListNode* temp2 = current2->next;
            current1->next = current2;
            current2->next = temp1;
            current1 = temp1;
            current2 = temp2;
        }
    }
};