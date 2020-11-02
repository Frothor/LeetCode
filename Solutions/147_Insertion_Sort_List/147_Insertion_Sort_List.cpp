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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr ){
            return nullptr ;
        }
       vector<ListNode*>nodes;
        nodes.push_back(head);
        ListNode*temp = head->next ;
        while(temp != nullptr ){
            nodes.push_back(temp);
            for(int i = nodes.size()-1 ; i > 0 ; i -- ){
                if( nodes[i]->val < nodes[i-1]->val ){
                     swap(nodes[i-1]->val , nodes[i]->val);    
                }
                else{
                    break;
                }
            }
            temp = temp->next;
        }
       return head ;
    }
};

//Fourth fastest
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode dummy(0, head);
        ListNode* p = head->next;
        while(p) {
            if(p->val >= head->val) {
                p = p->next;
                head = head->next;
            } else {
                head->next = p->next;
                insertToSortedList(&dummy, p);
                p = head->next;
            }
        }
        
        return dummy.next;
    }
    
    ListNode* insertToSortedList(ListNode* dummyHead, ListNode* node) {
        ListNode* cur = dummyHead->next;
        ListNode* prev = dummyHead;
        while(cur) {
            if(node->val < cur->val) {
                // insert node before cur
                prev->next = node;
                node->next = cur;
                return dummyHead;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        prev->next = node;
        node->next = nullptr;
        return dummyHead;
    }
};

//Third fastest
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode dummy(0, head);
        ListNode* p = head->next;
        while(p) {
            if(p->val >= head->val) {
                p = p->next;
                head = head->next;
            } else {
                head->next = p->next;
                
                // move p to the correct position
                ListNode* prev = &dummy;
                ListNode* cur = dummy.next;
                while(cur && p->val >= cur->val ) {
                    cur = cur->next;
                    prev = prev->next;
                }
                prev->next = p;
                p->next = cur;
                
                p = head->next;
            }
        }
        
        return dummy.next;
    }
    
//     ListNode* insertToSortedList(ListNode* dummyHead, ListNode* node) {
//         ListNode* cur = dummyHead->next;
//         ListNode* prev = dummyHead;
//         while(cur) {
//             if(node->val < cur->val) {
//                 // insert node before cur
//                 prev->next = node;
//                 node->next = cur;
//                 return dummyHead;
//             } else {
//                 prev = cur;
//                 cur = cur->next;
//             }
//         }
//         prev->next = node;
//         node->next = nullptr;
//         return dummyHead;
//     }
};

//Second fastest
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                pre = dummy;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};


//Fastest
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        if(head==NULL)  return NULL;
        
        ListNode* prev = new ListNode(0);
        prev->next=head;
        ListNode* sorted=head;
        ListNode* unsorted = head->next;
        ListNode* cur = head;
        ListNode* behind=prev;
        ListNode* t1=prev->next;
        
        while(unsorted){
   //         cout<<"\nsorted="<<sorted->val<<"\tunsorted="<<unsorted->val;
            if(unsorted->val>=sorted->val){
                unsorted = unsorted->next;
                sorted = sorted->next;
            }
            else{
                behind=prev;
                cur = prev->next;
                while(unsorted->val>cur->val){
                    behind=cur;
                    cur=cur->next;
                }
      //                      t1 = prev->next;
    /*            cout<<"\nPt1 list:";
                while(t1){
                    cout<<"\t"<<t1->val;
                    t1=t1->next;
                } */
                ListNode* next = unsorted->next;
                unsorted->next = cur;
                sorted->next=next;
                behind->next = unsorted;
                unsorted = next;
                
            }
    /*        t1 = prev->next;
            cout<<"\nlist:";
            while(t1){
                cout<<"\t"<<t1->val;
                t1=t1->next;
            }*/
        }
        return prev->next;
        
    }
};