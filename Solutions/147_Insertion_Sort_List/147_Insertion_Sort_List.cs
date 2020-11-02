/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        if(head == null)
            return null;
        
        var nodes = new List<ListNode>();
        nodes.Add(head);
        var tmp = head.next;
        while(tmp != null){
            nodes.Add(tmp);
            for(int i = nodes.Count-1; i > 0; i--){
                if(nodes[i].val < nodes[i-1].val){
                    int temp = nodes[i].val;
                    nodes[i].val = nodes[i-1].val;
                    nodes[i-1].val = temp;
                }
                else
                    break;
            }
            tmp = tmp.next;
        }
        return head;
    }
}

//Most common
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        if (head == null)
            return head;
        
        var newHead = head;
        var current = head.next;
        newHead.next = null;
        
        while (current != null)
        {
            var newCurrent = newHead;
            var newPrevious = default(ListNode);
            var actualNext = current.next;
            current.next = null;
            
            while (newCurrent != null && newCurrent.val < current.val)
            {                
                newPrevious = newCurrent;
                newCurrent = newCurrent.next;
            }
            
            if (newPrevious != null)
            {
                newPrevious.next = current;
            }
            
            if (newCurrent != null)
            {
                current.next = newCurrent;
                
                if (newPrevious == null)
                    newHead = current;
            }
            
            current = actualNext;
        }
        
        return newHead;
    }
}

//Fourth fastest
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
                    if (head == null)
            {
                return null;
            }

            ListNode previous = head;
            var current = head.next;

            while (current != null)
            {
                var next = current.next;
                var currentVal = current.val;
                if (currentVal > previous.val)
                {
                    previous = current;
                    current = next;
                    continue;
                }

                if (currentVal <= head.val)
                {
                    previous.next = next;
                    current.next = head;
                    head = current;
                    current = next;
                    continue;
                }


                var tempHead = head;
                while (tempHead != null && tempHead.next != null && tempHead.next.val < currentVal)
                {
                    tempHead = tempHead.next;
                }

                var tempNext = tempHead.next;
                tempHead.next = current;
                current.next = tempNext;

                previous.next = next;
                current = next;
            }

            return head;
        
    }
}

//Third fastest
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        
        ListNode lead = head.next;
        ListNode trail = head;
        ListNode fake = new ListNode(0, head);
        
        while (lead != null)
        {
            if (lead.val < trail.val)
            {
                trail.next = trail.next.next;
                ListNode temp = fake;
                while (temp != trail && lead.val > temp.next.val)
                    temp = temp.next;
                lead.next = temp.next;
                temp.next = lead;

                lead = trail.next;
            }
            else
            {
                trail = trail.next;
                lead = trail.next;
            }
        }
        
        return fake.next;
    }
}

//Second fastest
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        if (head == null) return null;
        var sEnd = head;
        for (var node = sEnd.next; node != null; node = sEnd.next) {
            int val = node.val;
            if (val < sEnd.val) {
                sEnd.next = node.next;
                if (val < head.val) {
                    node.next = head;
                    head = node;
                }
                else {
                    var pred = head;
                    while (pred.next.val < val) pred = pred.next;
                    node.next = pred.next;
                    pred.next = node;
                }
            }
            else {
                sEnd = node;
            }
        }
        return head;
    }
}

//Fastest
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        if (head == null) return null;
         ListNode dummy = new ListNode(0, head), cur = head;
            while (cur.next != null)
            {
                if (cur.val < cur.next.val)
                    cur = cur.next;
                else
                {
                    var temp = cur.next;
                    cur.next = temp.next;
                    var pos = dummy;
                    while (pos.next.val < temp.val)
                        pos = pos.next;
                    temp.next = pos.next;
                    pos.next = temp;
                }
            }
            return dummy.next;
    }
}