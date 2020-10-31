func inorderTraversal(root *TreeNode) []int {
    var stack []*TreeNode
    var result []int
    curr := root
    for curr != nil || len(stack) != 0 {
        // go left as far as possible
        for curr != nil {
            stack = append(stack, curr)
            curr = curr.Left
        }        
        // add to result and go right
        curr = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        result = append(result, curr.Val)
        curr = curr.Right
    }
    return result
}