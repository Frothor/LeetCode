# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {Integer}
def find_tilt(root)
    @tilts = 0
    dfs(root)
    @tilts
end
def dfs x
    if x.nil?
        @tilts += 0
        return 0
    else
        left = dfs(x.left)
        right = dfs(x.right)
        tilt = (left - right).abs
        @tilts += tilt
        return x.val + left + right
    end
end

#Third fastest
def find_tilt(root)
    @tilts = []
    traverse(root)
    return @tilts.sum
end

def traverse(node)
    if node.nil?
        @tilts << 0
        return 0
    else
        left = traverse(node.left)
        right = traverse(node.right)
        @tilts << (left - right).abs
        return left + right + node.val
    end
end

#Second fastest
def find_tilt(root)
    @tilt = 0
    traverse(root)
    @tilt
end

def traverse(root)
    return 0 if root.nil?
    
    left = traverse(root.left)
    right = traverse(root.right)
    
    @tilt += (left - right).abs
    
    root.val + left + right
end

#Fastest
def find_tilt(root)
    @tilt = 0
    return @tilt if root.nil?
    sum_of_tree(root)
    @tilt
  end
  
  def sum_of_tree(root)
    return 0 if root.nil?
    
    left_sum = sum_of_tree(root.left)
    right_sum = sum_of_tree(root.right)
    @tilt += (left_sum-right_sum).abs
    root.val + left_sum + right_sum
  end