func helper(s []int, root *TreeNode) []int {
	if root == nil {
		return s
	}
	s = helper(s, root.Left)
	s = append(s, root.Val)
	s = helper(s, root.Right)
	return s
}
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	var s1 []int
	var s2 []int
	s1 = helper(s1, root1)
	s2 = helper(s2, root2)
	var res []int
	var l1, l2 int = 0, 0

	for l1 < len(s1) && l2 < len(s2) {
		if s1[l1] < s2[l2] {
			res = append(res, s1[l1])
			l1++
		} else {
			res = append(res, s2[l2])
			l2++
		}
	}
	for l1 < len(s1) {
		res = append(res, s1[l1])
		l1++
	}
	for l2 < len(s2) {
		res = append(res, s2[l2])
		l2++
	}
	return res
}