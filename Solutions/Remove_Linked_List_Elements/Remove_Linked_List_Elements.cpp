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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        ListNode *prev = nullptr, *curr = head;
        
        while(curr){
            if(curr->val == val){
                if(!prev)
                    head = curr->next;
                else
                    prev->next = curr->next;
            } 
            else
                prev = curr;
            
            curr = curr->next; 
        }
        
        return head;
    }
};


/*
Most common:
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        
        ListNode* sen = new ListNode(0, head);
        ListNode* curr = sen;
        
        while(curr->next != nullptr){
            if(curr->next->val == val){
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return sen->next;
    }
};

Second most common:
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        while(head!=NULL && head->val==val){
            head=head->next;
        }
       ListNode* current = head;
       while(current!=NULL && current->next!=NULL){
           if(current->next->val==val){
               current->next= current->next->next;
           }
           else{
               current=current->next;
           }
       }
        return head;
        
    }
};

Fastest:
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** cur = &head;
        while(*cur) {
            if((*cur)->val == val) {
                (*cur) = (*cur)->next;
            } else {
                cur = &((*cur)->next);
            }
        }
        return head;
        
    }
};

*/