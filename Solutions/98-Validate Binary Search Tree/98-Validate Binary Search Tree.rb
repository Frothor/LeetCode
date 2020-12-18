#Fourth fastest
def is_valid_bst(root, min: nil, max: nil)
    return false unless root
    val = root.val
    # p "#{val}, min: #{min}, max: #{max}"
    return false if (min && val <= min) || (max && val >= max)
    result = true
    

    if root.left
        result = root.left.val < val && is_valid_bst(root.left, max: val , min: min)
    end
    
    return false unless result
    
    if root.right
        result = root.right.val > val && is_valid_bst(root.right, min: val, max: max)
    end

    return result
end

#Third fastest
def is_valid_bst(root)
    helper(root, nil, nil)
  end
  
  def helper(root, lower, upper)
    return true unless root
    
    if lower && root.val <= lower
      return false
    end
    
    if upper && root.val >= upper
      return false
    end
    
    helper(root.left, lower, root.val) && helper(root.right, root.val, upper)
  end

#Second fastest
def is_valid_bst(root)
    return true if root.nil? 
    return false if !helper(root.left, -1.0/0.0 , root.val) or !helper(root.right, root.val, 1.0/0.0)
    return true
end

def helper(root, min, max)
    return true if root.nil?
    return false if root.val >= max or root.val <= min
    return true if helper(root.left, min, root.val) and helper(root.right, root.val, max)
    return false
end

#Fastest
$inorder_traverse = Array.new

def is_valid_bst(root)
    return true if root == nil
    $inorder_traverse.clear
	traverse_helper(root)
	sorted = true
	$inorder_traverse.each_index { |i|
		next if i == 0
		sorted = (sorted and ($inorder_traverse[i - 1] < $inorder_traverse[i]))
	}
	return sorted
end

def traverse_helper(root)
	traverse_helper(root.left) if root.left
	$inorder_traverse.push(root.val)
	traverse_helper(root.right) if root.right
end