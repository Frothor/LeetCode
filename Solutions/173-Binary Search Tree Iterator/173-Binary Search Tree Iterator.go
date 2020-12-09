//Third fastest
type BSTIterator struct {
    p []*TreeNode
    c *TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    b:= BSTIterator{}
    
    b.c = root
    for b.c.Left != nil {
        b.p = append(b.p, b.c)
        b.c = b.c.Left
    }
    
    return b
}


func (this *BSTIterator) Next() int {
    r := this.c.Val
    if this.c.Right != nil {
        this.c = this.c.Right
        for this.c.Left != nil {
            this.p = append(this.p, this.c)
            this.c = this.c.Left
        }
    } else {
        if len(this.p) == 0 {
            this.c = nil
        } else {
            this.c = this.p[len(this.p)-1]
            this.p = this.p[:len(this.p)-1]
        }
    }
    
    return r
}


func (this *BSTIterator) HasNext() bool {
    if this.c == nil {
        return false
    }
    return true
}


//Second fastest
type BSTIterator struct {
    stack []*TreeNode
}


func Constructor(root *TreeNode) BSTIterator {
    var stack []*TreeNode
    for root != nil {
        stack = append(stack, root)
        root = root.Left
    }
    return BSTIterator{
        stack: stack,
    }
}


/** @return the next smallest number */
func (this *BSTIterator) Next() int {
    n := len(this.stack)
    node := this.stack[n-1]
    value := node.Val
    this.stack = this.stack[0:n-1]
    if node.Right != nil {
        node = node.Right
        for node != nil {
            this.stack = append(this.stack, node)
            node = node.Left
        }
    }
    return value
}


/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
    return len(this.stack) > 0
}


//Fastest
//https://leetcode.com/problems/binary-search-tree-iterator/discuss/270901/golang
type BSTIterator struct {
	stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	st := []*TreeNode{}
	cur := root
	for cur != nil {
		st = append(st, cur)
		cur = cur.Left
	}
	return BSTIterator{
		stack: st,
	}
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	cur := this.stack[len(this.stack)-1]
	this.stack = this.stack[:len(this.stack)-1]
	ret := cur.Val
	cur = cur.Right
	for cur != nil {
		this.stack = append(this.stack, cur)
		cur = cur.Left
	}

	return ret
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return len(this.stack) > 0
}

//Another
type BSTIterator struct {
    inorder []int
    index int
}


func Constructor(root *TreeNode) BSTIterator {
    bst := BSTIterator{index: -1} 
    bst._inorder(root)
    
    return bst
}

func (this *BSTIterator) _inorder(root *TreeNode) {
    if root == nil {
        return
    }
    
    this._inorder(root.Left)
    this.inorder = append(this.inorder, root.Val)
    this._inorder(root.Right)
}

func (this *BSTIterator) Next() int {
    this.index += 1
    return this.inorder[this.index]
}


func (this *BSTIterator) HasNext() bool {
    return this.index + 1 < len(this.inorder)
}