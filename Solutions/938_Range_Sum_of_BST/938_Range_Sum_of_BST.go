//Third fastest
func traverse(root *TreeNode, low int, high int, sum *int) {
	if root == nil {
		return
	}

	if root.Val >= low && root.Val <= high {
		*sum += root.Val
	}

	traverse(root.Right, low, high, sum)
	traverse(root.Left, low, high, sum)
}

func rangeSumBST(root *TreeNode, low int, high int) int {
	sum := 0
	traverse(root, low, high, &sum)
	return sum
}

//Another
func rangeSumBST(root *TreeNode, low int, high int) int {
    sum := 0
    if root == nil {
        return sum
    }
    if root.Val >= high {
        if root.Val == high {
            sum += root.Val
        }
        sum += rangeSumBST(root.Left, low, high)
    } else if root.Val <= low {
        if root.Val == low {
            sum += root.Val
        }
        sum += rangeSumBST(root.Right, low, high)
    } else {
        sum += root.Val
        sum += rangeSumBST(root.Left, low, high)
        sum += rangeSumBST(root.Right, low, high)
    }
    return sum
}

//Second fastest
func rangeSumBST(root *TreeNode, low int, high int) int {
    if root == nil {
        return 0
    }
    
    if root.Val < low {
        return rangeSumBST(root.Right, low, high)
    }
    
    if root.Val > high {
        return rangeSumBST(root.Left, low, high)
    }
    
    return root.Val + rangeSumBST(root.Left, low, high) + rangeSumBST(root.Right, low, high)
}

//Fastest
func rangeSumBST(root *TreeNode, L int, R int) int {
	if root == nil {
		return 0
	}
	sum := 0
	if root.Val >= L && root.Val <= R {
		sum = root.Val
	}
	if root.Val >= L {
		sum += rangeSumBST(root.Left, L, R)
	}
	if root.Val <= R {
		sum += rangeSumBST(root.Right, L, R)
	}
	return sum
}