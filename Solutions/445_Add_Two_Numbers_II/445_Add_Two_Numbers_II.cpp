class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a, b;
        ListNode *result = nullptr;
        while(l1) { a.push_back(l1->val+'0'); l1 = l1->next;}
        while(l2) { b.push_back(l2->val+'0'); l2 = l2->next;}
        int l = a.size()-1, r = b.size()-1, carry = 0;
        while(l >= 0 || r >= 0 || carry == 1) {
            int c = (l >= 0 ? a[l--]-'0' : 0) + ( r >= 0 ? b[r--]-'0' : 0) + carry;
            ListNode *temp = new ListNode(c%10);
            temp->next = result;
            result = temp;
            carry = c/10;
        }        
        return result;
    }
};

//Third fastest
class Solution {
    ListNode* reverse(ListNode *head) {
        ListNode *pre = nullptr, *cur = head;
        while(cur) {
            auto nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode dummy;
        ListNode *cur = &dummy;
        while(l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return reverse(dummy.next);
    }
};

//Second fastest
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head1 = l1;
        struct ListNode *head2 = l2;
        string str1 = "", str2 = "";
        while( head1 != nullptr ) {
            str1 += to_string(head1 -> val);
            head1 = head1 -> next;
        }
        while( head2 != nullptr ) {
            str2 += to_string(head2 -> val);
            head2 = head2 -> next;
        }
        
        
        
        
        if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
        string result = ""; 

        int n1 = str1.length(), n2 = str2.length(); 

        reverse(str1.begin(), str1.end()); 
        reverse(str2.begin(), str2.end()); 

        int carry = 0; 
        for (int i=0; i<n1; i++) 
        { 
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
            result.push_back(sum%10 + '0'); 

            carry = sum/10; 
        } 

        for (int i=n1; i<n2; i++) 
        { 
            int sum = ((str2[i]-'0')+carry); 
            result.push_back(sum%10 + '0'); 
            carry = sum/10; 
        } 

        if (carry) 
            result.push_back(carry+'0'); 

        reverse(result.begin(), result.end());
        
        
        
        
        
        struct ListNode *dummy1 = new ListNode(-1);
        struct ListNode *temp = dummy1;
        for ( int i = 0; i < result.size(); i++ ) {
            struct ListNode *dummy = new ListNode(-1);
            temp -> next = dummy;
            temp -> next -> val = int(result.at(i)) - 48;
            temp = dummy;
        }
        return (dummy1 -> next);
    }
};

//Fastest
#include <memory>
class Solution {
public:
   // ListNode* reverseList(ListNode* root);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = nullptr;
        auto l1Rev=reverseList(l1);
        auto l2Rev = reverseList(l2);
        
        int c = 0;
        int sum,x,y, value;
        while(l1Rev || l2Rev){
              x = l1Rev ? l1Rev->val:0;
                y = l2Rev ? l2Rev->val:0;
            sum= x+y+c;
            value = sum % 10;
            c = sum/10;
            
            //update list
            auto node = new ListNode(value);
            node->next = result;
            result = node;
            
            l1Rev =  l1Rev ? l1Rev->next: l1Rev;
            l2Rev = l2Rev ? l2Rev->next : l2Rev;
        }
        if(c){
            auto carryOnNode = new ListNode(c);
            carryOnNode->next = result;
            result = carryOnNode;
        }
        return result;
    }
//         ListNode* reverseList(ListNode* root){
//         ListNode* prev = new ListNode{0, root};
//         auto start = root;
//         auto curr = prev->next;

//         auto it =root;
//         auto finish = prev;
            

//           // finish = finish->next;
            
            
            
//         while(finish->next){
//             finish = finish->next;
//            //  cout<<finish->val<<endl;
//         }

//             int i =10;
//         while(start != finish){
//             start = start->next;
//             auto next = curr->next;
//             curr->next = next->next;
//             next->next = prev->next;
//             prev->next = next;
            
//         }


//         return prev->next;    


//     }
    
     ListNode* reverseList(ListNode* root){
     
         ListNode* head;
         ListNode* current = root;
         ListNode* prev = nullptr; ListNode* next = nullptr;
         

         while(current){
             next = current->next;
             current->next = prev;
             prev = current;
             current = next;
             
             
         }
       head = prev;
         return head;
    }
};



/*

find beginning of the reversed list (begin)
use 3 pointers begin, current(traversing from beginning of list), next

 prev  7 - 2 - 4 - 3


next =  


start = 
finish= 

prev curr, next
dummyHead = finish

while(it++)

while(start++<finish){

}



*/