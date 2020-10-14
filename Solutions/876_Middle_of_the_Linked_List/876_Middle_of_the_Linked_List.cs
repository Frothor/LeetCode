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
    public ListNode MiddleNode(ListNode head) {
        ListNode midPrev = null;
        while(head != null && head.next != null) {
            midPrev = (midPrev == null) ? head : midPrev.next;
            head = head.next.next;
        }
        ListNode mid = midPrev == null ? head : midPrev.next;
        return mid;
    }
}

//Third fastest
public class Solution {
    public ListNode MiddleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null)
        { 
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

//Second fastest
public class Solution {
    public ListNode MiddleNode(ListNode head) {        
        var s = head;
        var f = head;
        
        while(f != null && f.next != null){
            s = s.next;
            f = f.next.next;
        }
        
        return s;
    }
}

//Fastest
public class Solution {
    public ListNode MiddleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow ;
        
        
    }
}