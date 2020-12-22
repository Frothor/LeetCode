#Third fastest
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
# @return {Boolean}
def is_balanced(root)
    return true if root.nil?
    check_dept(root)[:status]
end

def check_dept(node)
    return { status: true, dept: -1 } unless node
    l_d = check_dept(node.left)
    r_d = check_dept(node.right)
    if (l_d[:dept] - r_d[:dept]).abs > 1 || !(l_d[:status] && r_d[:status])
        return { status: false, dept: [l_d[:dept], r_d[:dept]].max + 1  }
    end
    { status: true, dept: [l_d[:dept], r_d[:dept]].max + 1 }
end


#Second fastest
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
# @return {Boolean}
def is_balanced(root)
  return true unless root  
  return false if height(root) == -1
  
  true
end

def height(node)
  return 0 unless node
  
  lh = height(node.left)
  rh = height(node.right)
  return -1 if lh == -1 || rh == -1
  return -1 if (lh - rh).abs > 1
  
  [lh, rh].max + 1
end


#Fastest
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
# @return {Boolean}
def is_balanced(root)
  # return true if root.nil?
  # return false if (height(root.left)-height(root.right)).abs > 1
  # is_balanced(root.left) && is_balanced(root.right)
  helper(root)[0]
end

# [is_balanced, depth]
def helper(root)
  return [true, 0] if root.nil?
  left = helper(root.left)
  return [false, -1] unless left[0]
  right = helper(root.right)
  return [false, -1] unless right[0]
  return [false, -1] if (left[1] - right[1]).abs > 1
  [true, 1+[left[1], right[1]].max]
end

def height(root)
  return 0 if root.nil?
  1+[height(root.left), height(root.right)].max
end