/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* flatten_rec(Node* head){
        Node *curr = head, *tail = head;
        while(curr){
            Node *child = curr->child;
            Node *next = curr->next;
            if(child){
                Node *_tail = flatten_rec(child);
                
                _tail->next = next;
                if(next)
                    next->prev = _tail;
                
                curr->next = child;
                child->prev = curr;
                
                curr->child = nullptr;
                
                curr = tail;
            }
            else
                curr = next;
            
            if(curr)
                tail = curr;
        }
        return tail;
    }
public:
    Node* flatten(Node* head) {
        if(head)
            flatten_rec(head);
        return head;
        
        
    }
};

/*
Fastest:
class Solution {
public:
    Node* flatten(Node* head) {
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->child != nullptr)
        {
            auto temp = ptr->next;
            auto temp2 = ptr;
            ptr->next = flatten(ptr->child);
            if(ptr->next)
			{
				ptr->next->prev = temp2;
			}
            ptr->child = nullptr;
            while (ptr && ptr->next)ptr = ptr->next;
            ptr->next = temp;
            if(temp)
			{
				temp->prev = ptr;
			}
            
        }
        ptr = ptr->next;
    }
    return head;
}
};
*/