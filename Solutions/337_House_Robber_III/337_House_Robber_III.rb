#Second fastest
def rob(root)
    result = dfs(root)
    return [result[0], result[1]].max
  end
  
  def dfs(root)
    return [0, 0] if root.nil?
    
    left = dfs(root.left)
    right = dfs(root.right)
    
    result = []
    
    result[0] = [left[0], left[1]].max + [right[0], right[1]].max
    result[1] = root.val + left[0] + right[0]
    
    return result
    
  end

#Fastest
#https://leetcode.com/problems/house-robber-iii/discuss/388336/Easy-Ruby-DP
def rob(root)
    def dfs(a)
        return [0, 0] if a.nil?
        return [a.val, 0] if a.left.nil? and a.right.nil?

        l = dfs(a.left)
        r = dfs(a.right)

        p1 = a.val + l[1] + r[1]
        p2 = [(l[0] + r[0]), (l[0] + r[1]), (l[1] + r[0]), (l[1] + r[1])].max
        [p1, p2]
    end

    dfs(root).max
end