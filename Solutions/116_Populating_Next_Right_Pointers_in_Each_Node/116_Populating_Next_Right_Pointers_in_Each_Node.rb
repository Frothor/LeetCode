#Third fastest
def connect(root)
    return root if root.nil?
    queue = []
    queue.push(root)
    
    while !queue.empty?
      children = []
      for i in 0..queue.length-1
        node = queue[i]
        node.next = queue[i+1]
      
        children.push(node.left) if node.left
        children.push(node.right) if node.right
      end
    
     queue = children
   end
    
   return root
  end

#Second fastest
def connect(root)
    return unless root
    
    prev = root
    curr = Node.new()
    
    while prev.left do
      curr = prev
      
      while curr do
        curr.left.next = curr.right
        
        if curr.next
          curr.right.next = curr.next.left
        end  
        
        curr = curr.next  
      end
      
      prev = prev.left
    end
    
    root
  end

#Fastest
# Definition for Node.
# class Node
#     attr_accessor :val, :left, :right, :next
#     def initialize(val)
#         @val = val
#         @left, @right, @next = nil, nil, nil
#     end
# end

# @param {Node} root
# @return {Node}
def connect(root)
    old=root
    while root and root.left
      nxt = root.left
      while root
        root.left.next = root.right
        root.right.next = root.next.left if root.next
        root = root.next
      end
      root = nxt
    end
    
    old
end