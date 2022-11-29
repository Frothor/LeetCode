# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        result = ListNode(0)
        current = result
        while l1 or l2 or carry != 0:
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0
            sum = l1val + l2val + carry
            carry = sum // 10
            next_node = ListNode(sum % 10)
            current.next = next_node
            current = current.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return result.next
    
# Faster
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        c1 = l1
        c2 = l2
        carry = 0

        res = ListNode(0)
        r = res

        while c1 or c2:

            total = 0
            if not c1:
                total = c2.val + carry
                c2 = c2.next
            elif not c2:
                total = c1.val + carry
                c1 = c1.next
            else:
                total = c1.val + c2.val + carry
                c1 = c1.next
                c2 = c2.next
            
            if total > 9:
                r.next = ListNode(total - 10)
                carry = 1
            else:
                r.next = ListNode(total)
                carry = 0
            
            r = r.next

        if carry == 1:
            r.next = ListNode(1)
            r = r.next
            

        return res.next

# One of the fastest normal code:
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = l1
        carry = 0
        while True:
            curr = l1.val + l2.val + carry        
            summ, carry = curr % 10, curr // 10
            l1.val = summ
            if l1.next and l2.next:
                l1, l2 = l1.next, l2.next
            elif l1.next:
                l1 = l1.next
                break
            elif l2.next:
                l1.next = l2.next
                l1 = l1.next
                break
            elif carry:
                l1.next = ListNode(carry)
                return head
            else:
                return head
        while l1:
            curr = l1.val + carry        
            summ, carry = curr % 10, curr // 10
            l1.val = summ
            if l1.next:
                l1 = l1.next
            elif carry:
                l1.next = ListNode(carry)
                return head
            else:
                return head
    
# One of the fastest normal code:
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        quot=0
        currentl1 = l1
        currentl2 = l2
        second = True
        while True:
        #for i in range(10):
            if second:
                newval = (currentl1.val + currentl2.val + quot) %10
                quot = (currentl1.val + currentl2.val + quot) //10
            else:
                newval = (currentl1.val + quot)%10
                quot= (currentl1.val + quot)//10
            currentl1.val = newval
            if currentl1.next == None:
                if currentl2.next == None:
                    if quot ==0:
                        break
                    else:
                        newnode = ListNode(quot)
                        currentl1.next = newnode
                        break
                else:
                    currentl1.next = currentl2.next
                    currentl2 = ListNode(0)
                    currentl1 = currentl1.next
                    second = False
            elif currentl2.next == None:
                second=False
                currentl1 = currentl1.next
            else:
                currentl1 = currentl1.next
                currentl2 = currentl2.next
        return l1

# Almost the fastest
f = open("user.out", "w")
lines = __Utils__().read_lines()
trash = {91: None, 93: None, 44: None, 10: None}
while True:
    try:
        param_1 = int(next(lines).translate(trash)[::-1])
        param_2 = int(next(lines).translate(trash)[::-1])
        f.writelines(("[", ",".join(str(param_1 + param_2))[::-1], "]\n"))
    except StopIteration: exit()

# Fastest
f = open("user.out", "w")
lines = __Utils__().read_lines()
trash = {91: None, 93: None, 44: None, 10: None}
while True:
    try:
        f.writelines(("[", ",".join(
            str(int(next(lines).translate(trash)[::-1]) + int(next(lines).translate(trash)[::-1])))[::-1], "]\n"))
    except StopIteration:
        exit()