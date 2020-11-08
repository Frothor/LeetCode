//Second fastest
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    _, res := tilt(root)
    return res
}

func tilt(root *TreeNode) (int,int) {
    if root == nil {
        return 0, 0
    }
    left, s1 := tilt(root.Left)
    right, s2 := tilt(root.Right)
    return (root.Val+left+right), (abs(left-right)+s1+s2)
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

//Another
import "math"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    tilt := 0
    helperFindTilt(root,&tilt)
    return tilt
}

func helperFindTilt(root *TreeNode, tilt *int) int {
    if root == nil {
        return 0
    }
    
    if root.Left == nil && root.Right == nil {
        *tilt += 0
        return root.Val
    }
    
    left := helperFindTilt(root.Left,tilt)
    right := helperFindTilt(root.Right,tilt)
    
    *tilt += int(math.Abs(float64(left - right)))
    return left+ right + root.Val
}

//Fastest
func findTilt(root *TreeNode) int {
	result := 0
	itterate(root, &result)
	return result
}

func itterate(node *TreeNode, result *int) int {
	if node == nil {
		return 0
	}

	left, right := itterate(node.Left, result), itterate(node.Right, result)
	*result += absDiff(left, right)
	return left + right + node.Val
}

func absDiff(a, b int) int {
	diff := a - b
	if diff < 0 {
		diff = -diff
	}

	return diff
}