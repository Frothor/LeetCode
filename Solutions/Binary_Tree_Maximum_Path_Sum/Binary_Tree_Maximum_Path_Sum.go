//Very simple Go solution, beats 100% time and space
/*
A solution that's a little more explicit and easy to understand than the official solution in my opinion.

At each node there are 4 choices we have to consider:

Just the current node
The current node + max of the left subtree
The current node + max of the right subtree
The current node + both left and right subtrees (ie: a path that connects through the current node)
The only tricky part here is the 4th option can not be returned as a max for the parent to consider, since combining a parent plus that path would result in a forked path.

// t: O(n)
// s: O(height)
*/
func maxPathSum(root *TreeNode) int {
    max := math.MinInt64
    var helper func (root *TreeNode) int
    helper = func (root *TreeNode) int {
        if root == nil {
            return math.MinInt64
        }
        
        sums := []int{root.Val} // just the current node
        if root.Left != nil { // current node + best path of left subtree
            sums = append(sums, helper(root.Left) + root.Val)
        }
        if root.Right != nil { // current node + best of right subtree
            sums = append(sums, helper(root.Right) + root.Val)
        }
        if len(sums) == 3 { // single path connecting best path of left subtree, current node, best path of right subtree
            sums = append(sums, sums[1]+sums[2]-root.Val)
        }
        
        localMax := maxIntSlice(sums)
        if localMax > max {
            max = localMax
        }
        
        returnMax := localMax
        if len(sums) == 4 && returnMax == sums[3] { // if the max was the current node + left / right subtrees we can't return it and need to consider the second best path
            sums = sums[:3]
            returnMax = maxIntSlice(sums)
        }
        return returnMax
    }
    
    helper(root)
    return max
}

func maxIntSlice(ints []int) int {
    max := ints[0]
    for i := 1; i < len(ints); i++ {
        if ints[i] > max {
            max = ints[i]
        }
    }
    return max
}