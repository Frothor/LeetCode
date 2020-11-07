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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        var s1 = new Stack<int>();
        var s2 = new Stack<int>();
        var currl1 = l1;
        var currl2 = l2;
        while(currl1 != null){
            s1.Push(currl1.val);
            currl1 = currl1.next;
        }
        
        while(currl2 != null){
            s2.Push(currl2.val);
            currl2 = currl2.next;
        }
        
        var carry = 0;
        ListNode head = null;
        while(s1.Count > 0 || s2.Count > 0 || carry > 0){
            int d1 = 0;
            int d2 = 0;
            if(s1.Count > 0)
                d1 = s1.Pop();
            if(s2.Count > 0)
                d2 = s2.Pop();
            
            int digit = d1 + d2 + carry;
            
            if(digit >= 10){
                carry = 1;
                digit %= 10;
            }
            else
                carry = 0;
            
            var node = new ListNode(digit);
            node.next = head;
            head = node;
        }
        return head;
    }
}

//Third fastest
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {        
        return AddTwoNumbersNoReverse(l1, l2);
    }   
    
    private ListNode AddTwoNumbersNoReverse(ListNode l1, ListNode l2)
    {
        int len1 = GetLen(l1);
        int len2 = GetLen(l2);
        
        if(len2 > len1)
        {
            var temp = l1;
            l1 = l2;
            l2 = temp;
            
            var tempLen = len1;
            len1 = len2;
            len2 = tempLen;
        }
        
        var curr1 = l1;
        var curr2 = l2;
        
        var diff = len1 - len2;
        
        var dummyHead = new ListNode(0);
        
        while(curr1 != null)
        {
            int l1Val = curr1.val;
            int l2Val = diff > 0 ? 0 : curr2.val;
            
            var node = new ListNode(l1Val + l2Val, dummyHead.next);
            dummyHead.next = node;
            
            curr1 = curr1.next;
            curr2 = diff > 0 ? curr2 : curr2.next;            
            --diff;
        }
        
        ListNode curr = dummyHead.next;
        ListNode prev = null;
        
        int carry = 0;
        while(curr != null)
        {
            int digit = (curr.val + carry) % 10;
            carry = (curr.val + carry) / 10;
            
            curr.val = digit;
            var next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        if(carry > 0) {
            var node = new ListNode(1);
            node.next = prev;
            return node;
        }
        
        return prev;
    }
    
    private int GetLen(ListNode l)
    {
        int len = 0;
        
        while(l != null)
        {
            l = l.next;
            ++len;
        }
        
        return len;
    }
    
    private ListNode AddTwoNumbersReverse(ListNode l1, ListNode l2)
    {
        l1 = Reverse(l1);        
        l2 = Reverse(l2);
        
        return Reverse(AddTwoNumbersInternal(l1, l2));
    }
    
    private ListNode AddTwoNumbersInternal(ListNode l1, ListNode l2) {
        ListNode result = null, current = null;
        int carry = 0;
        while(l1 != null || l2 != null)
        {
            int l1Val = l1 == null ? 0 : l1.val;
            int l2Val = l2 == null ? 0 : l2.val;
            
            int digit = (carry + l1Val + l2Val) % 10;
            carry = (carry + l1Val + l2Val) / 10;
            var node = new ListNode(digit);
            if(result == null) {
                result = node;                
            } else {
                current.next = node;                
            }                
            current = node;
            l1 = l1?.next;
            l2 = l2?.next;
        }
        
        if(carry > 0)
            current.next = new ListNode(1);
        
        return result;
    }
    
    private ListNode Reverse(ListNode l)
    {
        ListNode prev = null;
        ListNode curr = l;
        
        while(curr != null)
        {
            var next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
}

//Second fastest
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        l1 = ReverseList(l1);
        l2 = ReverseList(l2);
        
        ListNode result = new ListNode();
        ListNode resultDummie = result;
        
        int carry = 0;
        while(l1 != null && l2 != null)
        {
            int num = l1.val + l2.val + carry;
            carry = num / 10;
            int resultNumber = num % 10;
            resultDummie.val = resultNumber;         
            if(l1.next == null || l2.next == null){
                l1 = l1.next;
                l2 = l2.next;
                break;
            }
            resultDummie.next = new ListNode();
            resultDummie = resultDummie.next;      
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while(l1 != null)
        {
            int num = l1.val + carry;
            carry = num / 10;
            int resultNumber = num % 10;
            resultDummie.next = new ListNode(resultNumber);
            l1 = l1.next;
            resultDummie = resultDummie.next;
        }
        
        while(l2 != null)
        {
            int num = l2.val + carry;
            carry = num / 10;
            int resultNumber = num % 10;
            resultDummie.next = new ListNode(resultNumber);
            l2 = l2.next;
            resultDummie = resultDummie.next;
        }
        if(carry > 0)
            resultDummie.next = new ListNode(carry);
    
        return ReverseList(result);
    }
    
    public ListNode ReverseList(ListNode list)
    {
        ListNode prev = null;      
        ListNode temp = list;
        
        while(temp != null)
        {
            ListNode next = temp.next;
            temp.next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;
    }
}

//Fastest
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        Stack<int> s1 = new Stack<int>();
        Stack<int> s2 = new Stack<int>();
        
        int carry = 0, sum = 0;
        
        while(l1 != null)
        {
            s1.Push(l1.val);          
            l1 = l1.next;    
        }
        
        while(l2 != null)
        {        
            s2.Push(l2.val);      
            l2 = l2.next;
        }
        
        ListNode prev = null;
        while(s1.Count() != 0 || s2.Count() != 0)
        {
            int x = s1.Count() != 0 ? s1.Pop() : 0;
            int y = s2.Count() != 0 ? s2.Pop() : 0;
            sum = x + y + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode dummy = new ListNode(sum,null);
            dummy.next = prev;
            prev = dummy;
        }
        
        if(carry > 0)
        {
            ListNode dummy = new ListNode(carry,null);
            dummy.next = prev;
            prev = dummy;
        }
        return prev;
    }
}