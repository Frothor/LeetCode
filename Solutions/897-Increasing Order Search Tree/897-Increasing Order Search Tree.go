/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
    v = make([]*TreeNode, 0)
    dfs(root)
    return v[0]
}

var v []*TreeNode //slice for node pointers

func dfs(node *TreeNode) { //Depth-first search
    if node == nil  {
        return
    }
    dfs(node.Left)
    v = append(v, &TreeNode{ //Append new node with node.Val
        node.Val,
        nil,
        nil,
    })
    if len(v) >= 2  { //When slice len >= 2 make chain link
        v[len(v) - 2].Right = v[len(v) - 1];
    }
    dfs(node.Right)
}

//Another
func increasingBST(root *TreeNode) *TreeNode {
    return recursive(root, nil)
}

func recursive(curr *TreeNode, largest *TreeNode) *TreeNode {
    if curr == nil {
        return largest
    }
    smallest := recursive(curr.Left, curr)
    curr.Left = nil
    curr.Right = recursive(curr.Right, largest)
    return smallest
}