def range_sum_bst(root, low, high)
  stack = [root]
  result = 0
  
  until stack.empty?
    node = stack.pop
    
    result += node.val if (low..high).cover?(node.val)
   
    stack << node.left if node.left && node.val >= low
    stack << node.right if node.right && node.val <= high
  end
  
  result
end

#Third fastest
def range_sum_bst(root, l, r)
    searcher = Searcher.new
    searcher.dfs(root, l, r)
    searcher.sum
end

class Searcher
    def initialize
        @sum = 0
    end
    attr_reader :sum
    
    def dfs(root, l, r)
        return if root.nil?

        @sum += root.val if root.val.between?(l, r)

        if root.val >= l
            dfs(root.left, l, r)
        end

        if root.val <= r
            dfs(root.right, l, r)
        end
    end
end


#Second fastest
def range_sum_bst(node, l, r, sum = 0)
    return 0 unless node 
    
    sum += node.val if node.val >= l && node.val <= r
    sum = range_sum_bst(node.left, l, r, sum) if node.left
    sum = range_sum_bst(node.right, l, r, sum) if node.right
    
    return sum
end


#Fastest
def range_sum_bst(node, l, r, sum = 0)
    return 0 unless node 
    
    if node.val < l
        sum = range_sum_bst(node.right, l, r, sum)
    elsif node.val > r
        sum = range_sum_bst(node.left, l, r, sum)
    else
        sum += node.val + range_sum_bst(node.right, l, r, sum) + range_sum_bst(node.left, l, r, sum)
    end
    
    return sum
end
