# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
    a1 = Array.new
    a2 = Array.new
    
    while l1!=nil
        a1<<l1.val
        l1=l1.next
    end
    
    while l2!=nil
        a2<<l2.val
        l2=l2.next
    end
    
    if a1.length>a2.length
        (a1.length-a2.length).times { a2.unshift(0) }
    else
        (a2.length-a1.length).times { a1.unshift(0) }
    end
    
    carry = 0
    
    for i in (a2.length-1).downto(0)
        sum = a2[i]+a1[i]+carry
        a2[i] = sum % 10
        carry = sum / 10
    end
    
    a2.unshift(1) if carry==1
    
    next_ptr = nil
    
    for i in (a2.length-1).downto(0)
        l1 = ListNode.new
        l1.val = a2[i]
        l1.next = next_ptr
        next_ptr = l1
    end
    return next_ptr
end

#Second fastest
def add_two_numbers(head1, head2)
    num = add_two_nums_helper(head1)
    num += add_two_nums_helper(head2)
  
    num = num.to_s
    res = ListNode.new
    curr = res
    i = 0
    while i < num.length
      curr.next = ListNode.new(num[i].to_i)
      i += 1
      curr = curr.next
    end
  
    res.next
  end
  
  def add_two_nums_helper(head)
    count = 0
    num = 0
  
    fast = head
    while fast && fast.next
      count += 1
      fast = fast.next.next
    end
  
    if count == 0
      count = 1
    else
      count *= 2
      count += 1 if fast
    end
  
    i = count-1
    curr = head
    while curr
      num += curr.val * (10**i)
  
      i -= 1
      curr = curr.next
    end
  
    num
  end

#Fastest
def add_two_numbers(l1, l2)
    s1 = []
    s2 = []
    c1 = l1
    c2 = l2
    while c1
        s1 << c1.val
        c1 = c1.next
    end
    while c2
        s2 << c2.val
        c2 = c2.next
    end
    curr = nil
    carry = 0
    while !s1.empty? && !s2.empty?
        sum = s1.pop + s2.pop + carry
        carry = sum / 10
        curr = ListNode.new(sum % 10, curr)
    end
    
    while !s1.empty?
        sum = s1.pop + carry
        carry = sum / 10
        curr = ListNode.new(sum % 10, curr)
    end
    
    while !s2.empty?
        sum = s2.pop + carry
        carry = sum / 10
        curr = ListNode.new(sum % 10, curr)
    end
    
    if carry > 0
        curr = ListNode.new(carry, curr)
    end
    curr
end