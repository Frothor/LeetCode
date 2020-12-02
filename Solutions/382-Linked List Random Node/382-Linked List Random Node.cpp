//Third fastest
class Solution {
public:
ListNode* h;    
    
    Solution(ListNode* head) 
    {
        h = head;
    }

    int getRandom()
    {
        int rd = 1;
        ListNode* tmp = h;
        ListNode* res = NULL;
        
        while(tmp)
        {
            if(rand()%rd==0)
            {
                res = tmp;
            }

            tmp = tmp->next;
            rd++;
        }
        return res->val;
    }

};

//Second fastest
class Solution {
private:
    int n;
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        n=0; 
        ListNode* node = head;
        this->head = head;
        while(node){
            n++;
            node = node->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand()%n;
        int count=0;
        ListNode* node = head;
        while(count<idx){
            node = node->next;  
            count++;
        }
        return node->val;
    }
};

//Fastest
class Solution {
public:
    ListNode* n;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        n = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = n;
        int k = 0;
        int x = 0;
        while(node != NULL) {
            k++;
            int r = rand()%k;
            if (r == 0) {
                x = node->val;
            }
            node = node->next;
        }
        return x;
    }
};