//Second fastest
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

//Fastest
func maxDepth(root *TreeNode) int {
    
    if root == nil {
        return 0
    }
    
    m := 0
    if root.Left == nil && root.Right == nil {
        m = 0
    } else if root.Left != nil && root.Right != nil {
        m = max(maxDepth(root.Left), maxDepth(root.Right))
    } else if root.Left != nil {
        m = maxDepth(root.Left)
    } else {
        m = maxDepth(root.Right)
    }

    return m + 1
    
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}