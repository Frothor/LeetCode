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
    public int GetDecimalValue(ListNode head) {
        int res = head.val;
        head = head.next;
        while(head != null){
            res <<= 1;
            res += head.val;
            head = head.next;
        }
        
        return res;
    }
}

//Third fastest
public class Solution {
    public int GetDecimalValue(ListNode head) {
        var num = -1;
        var current = head;
        while(current != null)
        {
            num = num == -1 ? current.val : num * 2 + current.val;
            current = current.next;
        }
        return num;
    }
}

//Second fastest
public class Solution {
    public int GetDecimalValue(ListNode head) {
        int result = 0;
        for(ListNode ptr = head; ptr != null; ptr = ptr.next){
            result = result*2 + ptr.val;
        }
        return result;
    }
}

//Fastest
public class Solution {
    public int GetDecimalValue(ListNode head) {
        var num = -1;
        var current = head;
        while(current != null)
        {
            num = num == -1 ? current.val : num * 2 + current.val;
            current = current.next;
        }
        return num;
    }
}