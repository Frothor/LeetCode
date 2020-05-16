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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* result = head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* connectNode = head->next;
        
        while(p1->next != NULL && p2->next != NULL){
            ListNode* tmp = p2->next;
            if(!tmp)
                break;
            p1->next = p2->next;
            p1 = p1->next;
            
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next = connectNode;
        return result;
    }
};

/*
Fastest:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even=new ListNode(0);
        ListNode *odd= new ListNode(0);
        
        ListNode *curr= head;
        
        ListNode *oddcurr=odd;
        ListNode *evencurr=even;
        int i=1;
        
        while(curr!=NULL)
        {
            if(i%2!=0)
            {
                oddcurr->next=curr;
                oddcurr=oddcurr->next;
            }
            else
            {
                evencurr->next=curr;
                evencurr=evencurr->next;
            }
            i++;
            curr=curr->next;
        }
        evencurr->next=NULL;
        oddcurr->next=even->next;
        odd=odd->next;
        return odd;
    }
};

Another:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode *odd = head , *even = head->next;
        ListNode  *s_o = odd , *s_e = even; 
        while(even!=NULL and even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = s_e;
        // even->next = NULL;
        
        return s_o;
    }
};

Another:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2 ? p2->next : nullptr;
        ListNode* h2 = p2;
        while (p3) {
            p1->next = p3;
            p2->next = p3->next;
            p3->next = h2;
            p1 = p1->next;
            p2 = p2->next;
            p3 = p2 ? p2->next : nullptr;
        }
        return head;
    }
};
*/