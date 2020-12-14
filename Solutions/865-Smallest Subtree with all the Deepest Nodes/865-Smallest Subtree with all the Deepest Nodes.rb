#Third fastest
def subtree_with_all_deepest(root)
    return nil if root.nil?
    
    left_depth = max_depth(root.left)
    right_depth = max_depth(root.right)
    
    return root if left_depth==right_depth
    
    if left_depth > right_depth
      subtree_with_all_deepest(root.left)
    else
      subtree_with_all_deepest(root.right)
    end
  end
  
  def max_depth(root)
    return 0 if root.nil?
    
    left = max_depth(root.left)
    right = max_depth(root.right)
    
    if left > right
      return left+1
    else
      return right+1
    end 

#Second fastest
def subtree_with_all_deepest(root)
    queue, deepest, parents = [root], nil, {}
    while !queue.empty?
        deepest = queue.dup
        queue.size.times do
            node = queue.shift
            if node.left
                parents[node.left] = node
                queue << node.left
            end
            if node.right
                parents[node.right] = node
                queue << node.right
            end
        end
    end
    
    while !deepest.empty?
        return deepest.first if deepest.size == 1
        deepest = deepest.map{ |i| parents[i] }.compact.uniq
    end
end

#Fastest
def subtree_with_all_deepest(root)
  return nil if root.nil?
  left = max_depth(root.left)
  right = max_depth(root.right)
  if left > right
    subtree_with_all_deepest(root.left)
  elsif right > left
    subtree_with_all_deepest(root.right)
  else
    root
  end
end

def max_depth(root)
  return 0 if root.nil?
  
  left = max_depth(root.left)
  right = max_depth(root.right)
  [
    left,
    right
  ].max + 1    
end