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
@max = 0
def diameter_of_binary_tree(root)
  @max = 0
  return @max if root.nil?
  
  depth(root)
  @max
end

def depth(node)
  return 0 if node.nil?
  
  left = depth(node.left)
  right = depth(node.right)  
  curr = left + right
  @max = curr if curr > @max
  
  [left, right].max+1
end

#Second fastest
def diameter_of_binary_tree(root)
    @ans = 0
    puts dfs(root)
    @ans
  end
  
  def dfs(node)
    return 0 if node.nil?
    l = dfs(node.left)
    r = dfs(node.right)
    @ans = [@ans, l + r].max
    [r, l].max + 1
  end
  
  =begin
            1
           / \
      (2) 2   3
         / \   \    
        4   5   9
                 \
                  10
  
  =end

#Fastest
def diameter_of_binary_tree(root)
    @ans = 1
    depth(root)
    @ans - 1
end

def depth(node)
    return 0 if !node
    left = depth(node.left)
    right = depth(node.right)
    @ans = [left + right + 1, @ans].max
    return [left, right].max + 1
end