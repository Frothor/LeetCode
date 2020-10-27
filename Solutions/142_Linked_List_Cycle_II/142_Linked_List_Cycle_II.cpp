//Third fastest
class Solution {
public:
    
    ListNode *IsCycle(ListNode *head){
         ListNode *forward=head;
         ListNode *back=head;
            while(forward!=NULL&&forward->next!=NULL){
            
            forward=forward->next->next;
            back=back->next;
            if(forward==back)
                return forward;
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
      ListNode *slow= IsCycle(head);
        if(slow==NULL)
            return NULL;
        ListNode *fast=head;
        while(head!=slow)
        {
            head=head->next;
            slow=slow->next;
        }
        return slow;
    }
    
};

//Second fastest
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // edge case - empty list
        if (!head || !head->next || !head->next->next) return NULL;
        // support animals
        ListNode *turtle = head, *hare = head;
        // checking if we loop or not
        while (hare->next && hare->next->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle) break;
        }
        // exiting if we do not find a loop
        if (hare != turtle) return NULL;
        // finding the start of the loop
        turtle = head;
        while (turtle != hare) {
            hare = hare->next;
            turtle = turtle->next;
        }
        return turtle;
    }
};

//Another second fastest
class Solution {
public:

ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      
            while(slow != entry) {           
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                       
}
};

//Fastest
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==NULL || head->next==NULL)
            return NULL; 
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};