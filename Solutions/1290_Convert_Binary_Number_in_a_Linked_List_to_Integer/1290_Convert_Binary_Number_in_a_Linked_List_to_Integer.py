class Solution:
    def getDecimalValue(self, head):
        s = 0
        while head:
            s = 2*s + head.val
            head = head.next
        return s

#Third fastest
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num=head.val
        while head.next:
            num=num*2+head.next.val
            head=head.next
        return num

#Second fastet
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = ''
        while head:
            ans += str(head.val)
            head = head.next
        return int(ans, 2)

#Fastest
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        number = 0
        length = 0
        copy_head = head
        while head.next != None:
            length += 1
            head = head.next
        check_number = []
        while(length>0): 
            check_number.append([copy_head.val, 2**length])
            number += copy_head.val*(2**length)
            length -= 1
            copy_head = copy_head.next
        number += copy_head.val*(2**length)

        return number