//Second fastest
/*
To make the difference between x and y bigger, we either:

1. make x greater, when x >= y
2. make x smaller, when x < y
So we can pass the smallest and largest nodes along with the process of DFS
*/

func maxAncestorDiff(root *TreeNode) int {
	sol := Solution{}
	return sol.Run(root)
}

type Solution struct {
	maxDiff int
}

func (s *Solution) Run(root *TreeNode) int {
	s.helper(root, root.Val, root.Val)
	return s.maxDiff
}

func (s *Solution) helper(root *TreeNode, minAnc, maxAnc int) {
	if root == nil {
		return
	}
	// get diff
	d1, d2 := math.Abs(float64(minAnc-root.Val)), math.Abs(float64(maxAnc-root.Val))
	// max diff
	d := math.Max(d1, d2)
	s.maxDiff = int(math.Max(d, float64(s.maxDiff)))

	// try to get the minimum and maximum ancestors, which could give us the best chances of getting maximum difference
	minAnc, maxAnc = int(math.Min(float64(minAnc), float64(root.Val))), int(math.Max(float64(maxAnc), float64(root.Val)))
	s.helper(root.Left, minAnc, maxAnc)
	s.helper(root.Right, minAnc, maxAnc)
}

//Another
func maxAncestorDiff(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var tracks []int
	// reMax := recursion(root, &tracks, 0)
	// itMax := iteration(root, &tracks, 0)
	itMax := iterationMaxMin(root, &tracks, 0)

	return itMax
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func max(num1, num2 int) int {
	if num1 > num2 {
		return num1
	}
	return num2
}

func iterationMaxMin(root *TreeNode, tracks *[]int, itMax int) int {
	type wrapper struct {
		node    *TreeNode
		visited int
	}
	var stack []*wrapper
	stack = append(stack, &wrapper{root, 0})
	var top *wrapper
	anceMax, anceMin := root.Val, root.Val
	for len(stack) > 0 {
		top = stack[len(stack)-1]
		if top.node == nil {
			stack = stack[:len(stack)-1]
			continue
		}

		if top.visited == 1 {
			*tracks = (*tracks)[:len(*tracks)-1]
			stack = stack[:len(stack)-1]
			if top.node.Val == anceMin {
				temp := 1000000
				for _, val := range *tracks {
					if val < temp {
						temp = val
					}
				}
				anceMin = temp
			}
			if top.node.Val == anceMax {
				temp := 0
				for _, val := range *tracks {
					if val > temp {
						temp = val
					}
				}
				anceMax = temp
			}
			continue
		}

		if top.node.Val < anceMin {
			anceMin = top.node.Val
		}
		if top.node.Val > anceMax {
			anceMax = top.node.Val
		}
		if abs(anceMax-anceMin) > itMax {
			itMax = abs(anceMax - anceMin)
		}

		top.visited = 1
		*tracks = append(*tracks, top.node.Val)
		stack = append(stack, &wrapper{top.node.Right, 0})
		stack = append(stack, &wrapper{top.node.Left, 0})
	}
	return itMax
}


//Fastest
func maxAncestorDiff(root *TreeNode) int {
    largest := 0
    helper(root, &largest)
    return largest
}

func helper(node *TreeNode, largest *int) (int, int) {
    if node.Left == nil && node.Right == nil {
        return node.Val, node.Val
    }
    
    leftMax, leftMin := node.Val, node.Val
    if node.Left != nil {
        leftMax, leftMin = helper(node.Left, largest)
    }
    
    rightMax, rightMin := node.Val, node.Val
    if node.Right != nil {
        rightMax, rightMin = helper(node.Right, largest)
    }
    
    
    localMax := 0
    if abs(leftMax - node.Val) > abs(leftMin - node.Val) {
        localMax = abs(leftMax - node.Val)
    } else {
        localMax = abs(leftMin - node.Val)
    }
    
    if localMax > *largest {
        *largest = localMax
    }
    
    if abs(rightMax - node.Val) > abs(rightMin - node.Val) {
        localMax = abs(rightMax - node.Val)
    } else {
        localMax = abs(rightMin - node.Val)
    }
    
    if localMax > *largest {
        *largest = localMax
    }
    
    return max(rightMax, leftMax, node.Val), min(rightMin, leftMin, node.Val)
    
}

func abs(x int) int {
    if x > 0 {
        return x
    }
    return -x
}

func min(a, b, c int) int {
    smallest := a
    if b < smallest {
        smallest = b
    }
    
    if c < smallest {
        smallest = c
    }
    
    return smallest
}

func max(a, b, c int) int {
    biggest := a
    if b > biggest {
        biggest = b
    }
    
    if c > biggest {
        biggest = c
    }
    
    return biggest
    
}