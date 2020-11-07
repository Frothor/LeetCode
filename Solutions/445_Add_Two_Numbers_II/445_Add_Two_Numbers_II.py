class Solution:
    def addTwoNumbers(self, l1, l2):
        st1, st2 = [], []
        while l1:
            st1.append(l1.val)
            l1 = l1.next
            
        while l2:
            st2.append(l2.val)
            l2 = l2.next
        
        carry, head = 0, None

        while st1 or st2 or carry:
            d1, d2 = 0, 0
            d1 = st1.pop() if st1 else 0
            d2 = st2.pop() if st2 else 0
            carry, digit = divmod(d1 + d2 + carry, 10)
            head_new = ListNode(digit)
            head_new.next = head
            head = head_new
              
        return head

#Fourth fastest
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        num1 = 0
        num2 = 0
        
        while l1:
            num1 = num1 * 10 + l1.val
            l1 = l1.next
            
        while l2:
            num2 = num2 * 10 + l2.val
            l2 = l2.next
        head = None
        total = num1 + num2
        while total>9:
            node = ListNode(total%10)
            node.next=head
            head = node
            total = total//10
        node = ListNode(total%10)
        node.next=head
        head = node
        return head


#Third fastest
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        ans = []
        num_one = ""
        node = l1
        while node:
            num_one += str(node.val)
            node = node.next
        
        num_two = ""
        snode = l2
        while snode:
            num_two += str(snode.val)
            snode = snode.next
        
        x = int(num_one)
        y = int(num_two)
        
        
        res = (x+y)
        for i in str(res):
            ans.append(i)
        x = ",".join(ans)
        return(ListNode(x))
        
        


#Second fastest
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None or l1.val == 0:
            return l2
        if l2 == None or l2.val == 0:
            return l1
        
        n1 = 0
        p1 = l1
        while p1 != None:
            n1 = n1*10 + p1.val
            p1 = p1.next
        
        n2 = 0
        p2 = l2
        len_n2 = 0
        while p2 != None:
            n2 = n2*10 + p2.val
            p2 = p2.next
        
        num = n1 + n2
        head = None
        while num > 0:
            dig = num % 10
            num = num//10
            if head == None:
                head = ListNode(val=dig)
            else:
                n = ListNode(val=dig)
                n.next = head
                head = n
        return head

#Fastest
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a = 0
        b = 0
        head1, head2 = l1, l2
        while head1:
            a = a*10 + head1.val
            head1 = head1.next
        while head2:
            b = b*10 + head2.val
            head2 = head2.next
        res = a+b
        new_head = None
        if res == 0:
            node = ListNode(0)
            node.next = new_head
            new_head = node
            return new_head
        while res:
            val = res%10
            res = res//10
            node = ListNode(val)
            node.next = new_head
            new_head = node
        return new_head