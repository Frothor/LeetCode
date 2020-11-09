# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end

def build_tree(root)
    return [] if root==nil
    return [[root.val]] if root.left==nil and root.right==nil
    left = build_tree(root.left)
    right = build_tree(root.right)
    (left+right).map {|arr| arr.unshift(root.val)}
end

# @param {TreeNode} root
# @return {Integer}
def max_ancestor_diff(root)
    build_tree(root).map {|arr| arr.max-arr.min}.max
end

#Second fastest
def build_tree(root)
    return [] if root==nil
    return [[root.val]] if root.left==nil and root.right==nil
    left = build_tree(root.left)
    right = build_tree(root.right)
    (left+right).map {|arr| arr.unshift(root.val)}
end

# @param {TreeNode} root
# @return {Integer}
def max_ancestor_diff(root)
    build_tree(root).map {|arr| arr.max-arr.min}.max
end

#Fastest
def max_ancestor_diff(root)
  dfs(root, root.val, root.val)
end

def dfs(root, max, min)
  return max - min if root.nil?
  
  max = [max, root.val].max
  min = [min, root.val].min
  cur_diff = max - min
  
  left_diff  = dfs(root.left, max, min)
  right_diff = dfs(root.right, max, min)
  
  [left_diff, right_diff, cur_diff].max
end