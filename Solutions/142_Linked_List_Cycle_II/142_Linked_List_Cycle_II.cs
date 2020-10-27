/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        var s = new HashSet<ListNode>();
        while(head != null){
            if(s.Contains(head))
                return head;
            else 
                s.Add(head);
            head = head.next;
        }
        
        return null;
    }
}

//Third fastest
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        var hs = new HashSet<ListNode>();
        
        var node = head;
        
        while(node != null)
        {
            if(!hs.Add(node)) 
                return node;
            node = node.next;
        }
        
        return null;
    }
}

//Second fastest
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        int length = 0;
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow) {
                length = cycleLength(slow);
                break;
            } 
        }
        if(length  == 0) return null;
        ListNode pt1 = head;
        ListNode pt2 = head;
        while(length > 0)
        {
            pt2 = pt2.next;
            length--;
        }
        while(pt1 != pt2)
        {
            pt2 = pt2.next;
            pt1 = pt1.next;
        }
        return pt1;
    }
    public int cycleLength(ListNode slow)
    {
        ListNode current = slow;
        int length = 0;
        do{
            length++;
            current = current.next;
        }while(slow != current);
        return length;
    }
}

//Fastest
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        if (head == null)
            {
                return null;
            }

            ListNode slow = head, fast = head;

            while (fast != null)
            {
                slow = slow.next;
                fast = fast.next;
                if (fast != null)
                {
                    fast = fast.next;
                }
                if (slow == fast)
                {
                    break;
                }
            }

            if (fast == null)
            {
                return null;
            }

            slow = head;
            while(slow != fast)
            {
                slow = slow.next;
                fast = fast.next;
            }

            return slow;
    }
}