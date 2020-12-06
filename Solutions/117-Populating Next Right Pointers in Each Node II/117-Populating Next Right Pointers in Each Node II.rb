#Third fastest
def connect(root)
    if root.nil?
        return nil
    end
    node = root
    node.next = nil
    while node
        current = node
        if current.left && current.right
            current.left.next = current.right
            current.right.next = nil
        end
        last = nil
        while current.next
            
            if current.left && current.right
                puts current.left.val
                puts current.right.val
                current.left.next = current.right
                current.right.next = nil
                last = current.right
            elsif current.left
                last = current.left
            elsif current.right
                last = current.right
            end
            if last
                if current.next.left
                    last.next = current.next.left

                elsif current.next.right
                    last.next = current.next.right
                end
            end
            if current.next.left && current.next.right
                current.next.left.next = current.next.right
            end
            current = current.next
        end
        if node.left
            node = node.left
        elsif node.right
            node = node.right
        else
            node = node.next
        end
    end
    return root
end


#Second fastest
def connect(root)
   stack = [root]
   while stack.any? do
       righter = nil
       copy = [] + stack
       stack = []
       while copy.any? do
            current = copy.shift
            right = current.right
            left = current.left
            if right
                right.next =righter
                righter = right
                stack << right
            end
            if left
                left.next =righter
                righter = left
                stack << left
            end
            stack
       end
   end
    root
end

#Fastest
def connect(root)
  return if root.nil?

  head = root
  while head
    node = head
    dummy = Node.new(0)
    prev_child = dummy
    while node
      if node.left
        prev_child.next = node.left
        prev_child = node.left
      end

      if node.right
        prev_child.next = node.right
        prev_child = node.right
      end

      node = node.next
    end
    
    head = dummy.next
  end
  return root
end