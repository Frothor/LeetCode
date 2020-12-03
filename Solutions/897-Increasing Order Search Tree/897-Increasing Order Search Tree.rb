#Second fastest
#https://leetcode.com/problems/increasing-order-search-tree/discuss/813046/Ruby-solution
def build_tree(root)
    return [] if root==nil
    build_tree(root.left)+[root]+build_tree(root.right)
end

# @param {TreeNode} root
# @return {TreeNode}
def increasing_bst(root)
    node_array = build_tree(root)
    for i in 0...node_array.length-1
        node_array[i].left=nil
        node_array[i].right=node_array[i+1]
    end
    node_array[-1].left=nil
    node_array[-1].right=nil
    node_array[0]
end

#Another
def increasing_bst(root)
   @queue = []
    increasing_bst_helper(root)
    cur = top = @queue[0]
    
    1.upto(@queue.length-1) do |e|
       cur.left = nil
       cur.right = @queue[e]
       cur = @queue[e]
   end
    cur.left = nil
    top
end

def increasing_bst_helper(root)
    return if root.nil?
    increasing_bst_helper(root.left)
    @queue << root 
    
    increasing_bst_helper(root.right)
end

#Fastest
def increasing_bst(root)
    tree_array = build_tree(root)
    (0...tree_array.length - 1).each do |i|
       tree_array[i].left = nil
        tree_array[i].right = tree_array[i + 1]
    end
    tree_array[-1].left, tree_array[-1].right = nil
    tree_array[0]
end

def build_tree(root)
    return [] if root.nil?
    build_tree(root.left) + [root] + build_tree(root.right)
end