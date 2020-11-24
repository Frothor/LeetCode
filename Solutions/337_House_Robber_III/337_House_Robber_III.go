//Second fastest
func rob(root *TreeNode) int {
    ans0, ans1 := helper(root)
    return max(ans0, ans1)
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func helper(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    left0, left1 := helper(root.Left)
    right0, right1 := helper(root.Right)
    self0, self1 := max(left0, left1) + max(right0, right1), root.Val + left0 + right0
    return self0, self1
}

//Fastest
func rob(root *TreeNode) int {
    rob, not := myRob(root)
    return max(rob, not)
}

func myRob(root *TreeNode)(rob, not int) {
    if root == nil {
        return 0, 0
    }
    leftR, leftN := myRob(root.Left)
    rightR, rightN := myRob(root.Right)
    
    return root.Val + leftN + rightN, max(leftN, leftR) + max(rightR, rightN)
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}