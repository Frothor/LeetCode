//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/519260/golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	parents := make(map[*TreeNode]*TreeNode)
	levels := [][]*TreeNode{}
	dfs(nil, root, parents, 0, &levels)
	last := levels[len(levels)-1]
	for len(last) != 1 {
		next := []*TreeNode{}
		m := make(map[*TreeNode]bool)
		for _, node := range last {
			n := parents[node]
			if !m[n] {
				m[n] = true
				next = append(next, n)
			}
		}
		last = next
	}

	return last[0]
}

func dfs(prev, cur *TreeNode, parents map[*TreeNode]*TreeNode, level int, levels *[][]*TreeNode) {
	if cur == nil {
		return
	}
	parents[cur] = prev
	if level == len(*levels) {
		*levels = append(*levels, []*TreeNode{})
	}

	(*levels)[level] = append((*levels)[level], cur)
	dfs(cur, cur.Left, parents, level+1, levels)
	dfs(cur, cur.Right, parents, level+1, levels)
}

//Another
func getLevel(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + int(math.Max(float64(getLevel(root.Left)),float64(getLevel(root.Right))))
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	leftLevel := getLevel(root.Left)
	rightLevel := getLevel(root.Right)
	if leftLevel == rightLevel {
		return root
	} else if leftLevel > rightLevel {
		return subtreeWithAllDeepest(root.Left)
	} else {
		return subtreeWithAllDeepest(root.Right)
	}
}