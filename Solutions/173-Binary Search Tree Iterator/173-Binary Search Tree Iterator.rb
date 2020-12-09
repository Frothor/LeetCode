#Third fastest
class BSTIterator

    =begin
        :type root: TreeNode
    =end
        def initialize(root)
            @root = root
            @index = 0
            @res = []
    
            stack = []
            curr = root
            while stack.any? || curr
                if curr
                    stack.push(curr)
                    curr = curr.left
                    next
                end
    
                curr = stack.pop
                @res << curr.val
                curr = curr.right
            end
        end
    
    
    =begin
        @return the next smallest number
        :rtype: Integer
    =end
        def next()
            res = @res[@index]
            @index += 1
            res
        end
    
    
    =begin
        @return whether we have a next smallest number
        :rtype: Boolean
    =end
        def has_next()
            @index != @res.size
        end
    
    end

#Second fastest
class BSTIterator
    attr_accessor :stack
=begin
    :type root: TreeNode
=end
    def initialize(root)
        @stack = []
        left(root)
        
        # Use a stack.
        # Method to populate stack from left
        # If right exists, go right and then populate stack with left
    end


=begin
    @return the next smallest number
    :rtype: Integer
=end
    def next()
        node = @stack.pop
        
        if !node.right.nil?
            left(node.right)
        end
        
        node.val
    end


=begin
    @return whether we have a next smallest number
    :rtype: Boolean
=end
    def has_next()
        !@stack.empty?
    end
    
    private
    
    def left(root)
       until root.nil?
           @stack << root
           root = root.left
       end
    end

end

#Fastest
class BSTIterator

=begin
    :type root: TreeNode
=end
  def initialize(root)
    @stack = []
    
    go_to_most_left(root)

    # go to the most left node
    # push each visited node to the stack along the way
    # "next" triggered
      # pop node from stack
      # return itself (use flag)
      # go to right node and then again to the most left
  end

=begin
    @return the next smallest number
    :rtype: Integer
=end
  def next
    return if @stack.empty?

    res = @stack.pop
    go_to_most_left(res.right)
    res.val
  end

=begin
    @return whether we have a next smallest number
    :rtype: Boolean
=end
  def has_next
    !@stack.empty?
  end
  
  private
  
  def go_to_most_left(node)
    n = node
    while n
      @stack << n
      n = n.left
    end
  end
end
