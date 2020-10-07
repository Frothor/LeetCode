#Third fastest
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        def _getLength(n):
            l = 0
            while n:
                l += 1
                n = n.next
            return l
        if not head or k == 0:
            return head
        l = _getLength(head)
        print(l)
        l = k % l
        p1 = head
        i = 0
        while i < l:
            p1 = p1.next
            i += 1
        p2 = head
        while p1.next:
            p1 = p1.next
            p2 = p2.next
        
        p1.next = head
        head = p2.next
        p2.next = None
         
        return head
    
'''

1     2  3    4   5  N
         p2       p1

l = 5
k = 2
l = 2 /5



'''

#Second fastest
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode: 
        
        if not head: 
            return head 
        
        # find length of the list 
        n = 0 
        node = head
        while node: 
            n += 1 
            if not node.next: 
                tail = node 
            node = node.next 
        
        k = k % n 
        
        if k == 0: 
            return head 
        
        tail.next = head 
        
        node = head 
        for _ in range(n-1-k): 
            node = node.next 
            
        new_head = node.next 
        node.next = None 
        
        return new_head 

#Fastest
class Solution:
    def size(self, head):
        length = 0
        tail = None
        while head:
            tail = head
            head = head.next
            length += 1
        return length, tail
        
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        
        length, oldTail = self.size(head)            
        k = k%length
        if k == 0:
            return head        
        #print('k:',k)
        prev = None
        curr = head
        i = k
        first = head
        while i and first:
            first = first.next
            i -= 1
        #print('first:',first)
        second = head
        newTail = None
        while first:
            newTail = second
            second = second.next
            first = first.next
        #print('newTail:',newTail)            
        #print('second:',second)            
        newTail.next = None
        #print('head:',head)
        #print('prev:',prev)
        #print('curr:',curr)
        #print('tail:',tail)
        if oldTail:
            oldTail.next = head
        #print(second)
        return second
        