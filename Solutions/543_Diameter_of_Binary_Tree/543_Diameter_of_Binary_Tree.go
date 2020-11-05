func diameterOfBinaryTree(root *TreeNode) int {
    var max int
    deepestPath(root, &max)
    return max
}

func deepestPath(t *TreeNode, max *int) int {
    if t == nil {
		return 0
	}
	left := deepestPath(t.Left, max)
	right := deepestPath(t.Right, max)
    sum := maxValue(left, right) + 1
	*max = maxValue(*max, left + right)
	return sum
}

func maxValue(a, b int) int {
    if a > b {
        return a
    }
    return b
}

//Another
func diameterOfBinaryTree(root *TreeNode) int {
    res := 0
    visit(root, &res)
    return res
}

func visit(root *TreeNode, res *int) int {
    if root == nil {
        return 0
    }
    
    left := visit(root.Left, res)
    right := visit(root.Right, res)
    
    *res = max(*res, left + right)
    return 1 + max(left, right)
    
}

func max(a, b int) int {
    if a > b {
        return a
    }
    
    return b
}

//Fastest
func diameterOfBinaryTree(root *TreeNode) int {
	_, ret := maxDepth(root, 1)

	return ret - 1
}

func maxDepth(root *TreeNode, ret int) (int, int) {
	if root == nil {
		return 0, ret
	}

	left, lmax := maxDepth(root.Left, ret)
	right, rmax := maxDepth(root.Right, ret)

	ret = max(lmax, rmax)
	ret = max(ret, left+right+1)

	return max(left, right) + 1, ret
}

func max(a, b int) int {
	if a >= b {
		return a
	}

	return b
}