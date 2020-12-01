def max_depth(root)
    return 0 if root==nil
    [1+max_depth(root.left),1+max_depth(root.right)].max
end

#Third fastest
def max_depth(root)
    return 0 if root.nil?
  
    1 + [max_depth(root.left), max_depth(root.right)].max
  end

#Second fastest
def max_depth(root)
    unless root
        return 0
    else
        [1+max_depth(root.left),1+max_depth(root.right)].max
    end
end

#Fastest
Result = Struct.new(:data)

def max_depth(root)
    return 0 if root.nil?
    [max_depth(root.left), max_depth(root.right)].max + 1
end