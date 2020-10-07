//Most common
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *node = head;
        if (k == 0)
        {
            return head;
        }
        int l = 0;
        while (node != NULL)
        {
            l++;
            node = node->next;
        }
        if (l == 0)
        {
            return NULL;
        }
        else if (l == 1)
        {
            return head;
        }
        else
        {
            int c = k % l;
            if (c == 0)
            {
                return head;
            }
            int x = l - c;
            node = head;
            int s = 0;
            while (s < x - 1)
            {
                s++;
                node = node->next;
            }
            ListNode *temp = head;
            head = node->next;
            node->next = NULL;
            node = head;
            while (node->next != NULL)
            {
                node = node->next;
            }
            node->next = temp;
            return head;
        }
    }
};

//Second fastest
class Solution
{
public:
    int length(ListNode *head)
    {
        int count = 0;
        while (head != NULL)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode *reverse(ListNode *cur)
    {
        ListNode *prev = NULL;
        while (cur != NULL)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = length(head);
        if (len == 0)
            return head;
        k = k % len;

        if (k != 0)
        {
            k++;
            ListNode *fast = head;
            ListNode *slow = head;
            ListNode *prev;
            while (k > 0)
            {
                prev = fast;
                fast = fast->next;
                k--;
            }

            while (fast != NULL)
            {
                prev = fast;
                fast = fast->next;
                slow = slow->next;
            }
            //ListNode* newHead = reverse(slow->next);
            //ListNode* newHead = slow->next;
            prev->next = head;
            head = slow->next;
            slow->next = NULL;
        }
        return head;
    }
};

//Fastest
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        int i = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            i++;
        }
        k = k % i;
        return rotato(head, k);
    }

    ListNode *rotato(ListNode *head, int k)
    {
        if (k <= 0)
            return head;
        ListNode *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        ListNode *temp = curr->next;
        curr->next = NULL;
        temp->next = head;
        head = temp;

        return rotato(head, k - 1);
    }
};