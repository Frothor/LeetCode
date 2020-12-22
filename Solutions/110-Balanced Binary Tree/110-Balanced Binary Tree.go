//Third fastest
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	
	return abs(depth(root.Left)-depth(root.Right)) <= 1 && isBalanced(root.Left) && isBalanced(root.Right)
}

func depth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	
	return 1 + max(depth(root.Left), depth(root.Right))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}


//Second fasstest
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	_, ret := helper110(root)
	return ret
}

func helper110(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}
	left, ret := helper110(root.Left)
	if !ret {
		return 0, false
	}
	right, ret := helper110(root.Right)
	if !ret {
		return 0, false
	}
	if left-right < -1 || left-right > 1 {
		return 0, false
	}
	if left > right {
		return left + 1, true
	}
	return right + 1, true
}

//Fastest
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(node *TreeNode) bool {
	if node == nil {
		return true
	}

    balanced := math.Abs(float64(getHeight(node.Left)-getHeight(node.Right))) <= 1
	return balanced && isBalanced(node.Left) && isBalanced(node.Right)
}

func getHeight(node *TreeNode) int {
	if node == nil {
		return 0
	}

	leftHeight := 1 + getHeight(node.Left)
	rightHeight := 1 + getHeight(node.Right)

	return int(math.Max(float64(leftHeight), float64(rightHeight)))
}