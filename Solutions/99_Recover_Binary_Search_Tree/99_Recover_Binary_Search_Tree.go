//Third fastest
func recoverTree(root *TreeNode) {
	var inorder func(*TreeNode, []int) []int
	inorder = func(node *TreeNode, out []int) []int {
		if node == nil {
			return out
		}
		out = inorder(node.Left, out)
		out = append(out, node.Val)
		out = inorder(node.Right, out)
		return out
	}
	inord := inorder(root, nil)
	inordSorted := append([]int(nil), inord...)
	sort.Ints(inordSorted)
	a, b := -1, -1
	for i := 0; i < len(inordSorted); i++ {
		if inord[i] != inordSorted[i] {
			if a == -1 {
				a = inord[i]
			} else {
				b = inord[i]
			}
		}
	}
	var fixTree func(*TreeNode)
	fixTree = func(node *TreeNode) {
		if node == nil {
			return
		}
		if node.Val == a {
			node.Val = b
		} else if node.Val == b {
			node.Val = a
		}
		fixTree(node.Left)
		fixTree(node.Right)
	}
	fixTree(root)
}

//Second fastest
func recoverTree(root *TreeNode) {

	stack := make([]*TreeNode, 0)
	var prev *TreeNode
	var firstStartPointer *TreeNode
	var lastEndPointer *TreeNode
	cur := root
	for len(stack) != 0 || cur != nil {

		if cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		} else {
			temp := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if prev != nil && prev.Val > temp.Val {
				if firstStartPointer == nil {
					firstStartPointer = prev
				}
				lastEndPointer = temp
			}
			prev = temp

			if temp.Right != nil {
				cur = temp.Right
			}
		}

	}
	firstStartPointer.Val, lastEndPointer.Val = lastEndPointer.Val, firstStartPointer.Val

}

//Fastest
var prevElement *TreeNode
var firstElement *TreeNode
var secondElement *TreeNode


func traverse(root *TreeNode) {
  if root == nil {
    return
  }
  
  traverse(root.Left)
  
  if firstElement == nil && (prevElement == nil || prevElement.Val > root.Val) {
    firstElement = prevElement
  }
  
  if firstElement != nil && prevElement.Val > root.Val {
    secondElement = root
  }
  
  prevElement = root
  
  traverse(root.Right)
}

func recoverTree(root *TreeNode)  {
  if root == nil || (root.Left == nil && root.Right == nil) {
    return
  }
  
  
  prevElement = nil
  firstElement = nil
  secondElement = nil
  
  traverse(root)
  
  firstElement.Val, secondElement.Val = secondElement.Val, firstElement.Val
}