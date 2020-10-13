//Fourth fastest
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *fast = head->next, *slow = head;
        //step 1: find the middle point
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //step 2: split one list to two
        fast = slow->next;
        slow->next = nullptr;
        //step 3: divide and conquer, recursively call function itself
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        return mergeTwoLists(l1, l2);
    }
    
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy = ListNode(-1);
        ListNode *curr = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

//With comments
ListNode* sortList(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	if (head->next == nullptr) {
		return head;
	}
	// Divide the list into two halves.
	pair<ListNode*, ListNode*> p = cutList(head);
	
	// First half of the list
	ListNode* left = p.first;
	// Second half of the list
	ListNode* right = p.second;
	
	// Sort the first and second half of the list
	ListNode* left_sorted = sortList(left);
	ListNode* right_sorted = sortList(right);
	
	// Merge the two sorted lists and return the resulting list
	return merge(left_sorted, right_sorted);
}

ListNode* merge(ListNode* &node1, ListNode* &node2) {
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	while (node1 || node2) {
		// All nodes in first list are exhausted
		if (!node1) {
			// Delete head from second list and append it to res list
			ListNode* next = node2->next;
			push_back(head, tail, node2);
			node2 = next;
		// All nodes in second list are exhausted 
		} else if (!node2) {
			// Delete head  from first list and append it to res list
			ListNode* next = node1->next;
			push_back(head, tail, node1);
			node1 = next;
		} else {
			// Delete the smaller node and append it to the res list
			if (node1->val < node2->val) {
				ListNode* next = node1->next;
				push_back(head, tail, node1);
				node1 = next;
			} else {
				ListNode* next = node2->next;
				push_back(head, tail, node2);
				node2 = next;
			}
		}
	}
	return head;
}

void push_back(ListNode* &head, ListNode* &tail, ListNode* &node) {
	if (head == nullptr) {
		head = node;
		tail = node;
	} else {
		tail->next = node;
		tail = tail->next;
		tail->next = nullptr;
	}
}

pair<ListNode*, ListNode*> cutList(ListNode* &head) {
	ListNode* prev_slow = head;
	ListNode* slow = head;
	ListNode* fast = head;
	
	/* Slow runner takes 1 step at a time. Fast runner takes 2 step at a time. 
	By the time fast runner reaches end of the list, slow runner will be at the middle of the list */
	while (fast && fast->next) {
		prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev_slow->next = nullptr;
	return {head, slow};
}

//Third fastest
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* rightNode = getMidNodeAndCut(head);
        head = sortList(head); 
        rightNode = sortList(rightNode);
        head = mergeTwoLists(head, rightNode);
        return head;
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (a == nullptr && b == nullptr) return a;
        ListNode pseudoHead;
        ListNode* current = &pseudoHead;
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                current->next = a;
                a = a->next;
                current = current->next;
            } else {
                current->next = b;
                b = b->next;
                current = current->next;
            }
        }
        if (a != nullptr) current->next = a;
        else if (b != nullptr) current->next = b;
        return pseudoHead.next;
    }

    ListNode* getMidNodeAndCut(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rightBegin = slow->next;
        slow->next = nullptr;
        return rightBegin;
    }
};

//Second fastest
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        if (!head->next->next) {
            if (head->val <= head->next->val) {
                return head;
            } else {
                ListNode * next_node = head->next;
                head->next = nullptr;
                next_node->next = head;
                return next_node;
            }
        }
        
        ListNode *step1 = head, *step2 = head->next;
        
        while (true) {
            if (step2->next && step2->next->next) {
                step2 = step2->next->next;
                step1 = step1->next;
            } else {
                break;
            }
        }
        
        ListNode *half1_tail = step1, *half2_head = step1->next;
        step1->next = nullptr;
        
        ListNode *half1_head = sortList(head);
        half2_head = sortList(half2_head);
        
        // Merge half1 and half2
        ListNode *half1_iter = half1_head, *half2_iter = half2_head;
        ListNode *merge_head = nullptr, *merge_tail = nullptr;
        if (half1_iter->val <= half2_iter->val) {
            merge_head = half1_iter;
            half1_iter = half1_iter->next;
        } else {
            merge_head = half2_iter;
            half2_iter = half2_iter->next;
        }
        merge_tail = merge_head;
        
        while (half1_iter && half2_iter) {
            if (half1_iter->val <= half2_iter->val) {
                merge_tail->next = half1_iter;
                half1_iter = half1_iter->next;
            } else {
                merge_tail->next = half2_iter;
                half2_iter = half2_iter->next;
            }
            merge_tail = merge_tail->next;
        }
        
        if (!half1_iter)
            merge_tail->next = half2_iter;
        else
            merge_tail->next = half1_iter;
        
        return merge_head;
    }
};

//Fastest
class Solution {
public:
 ListNode* getMid(ListNode* head){
        if(head==NULL or head->next==NULL)return head;
        if(head->next->next==NULL){
            ListNode* temp=head->next;
            head->next=NULL;
            return temp;
        }
        ListNode *slow=head,*fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* h2=slow->next;
        slow->next=NULL;
        return h2;
    }
    
    ListNode* merge(ListNode* h1,ListNode*h2){
        if(!h1)return h2;
        if(!h2)return h1;
        ListNode* res=NULL;
        if(h1->val<=h2->val){
            res=h1;
            res->next=merge(h1->next,h2);
        }
        else{
            res=h2;
            res->next=merge(h1,h2->next);
        }
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* h2=getMid(head);
        if(h2==head)return head;
        ListNode* head1=sortList(head);
        ListNode* head2=sortList(h2);
        ListNode* res=merge(head1,head2);
        return res;
    }
};