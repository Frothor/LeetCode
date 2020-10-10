//Most common
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 type Codec struct {
    
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    s := preOrder(root)
    fmt.Printf("Serialized: %v\n", s)
    return s
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
    
    root,_ := helper(data)
    return root
}

func helper(data string) (*TreeNode, string) {
    var node *TreeNode
    //fmt.Printf(":%v:\n", data)
    if data == "" {
        return nil, ""
    }
    node, data = getNode(data)
    if node == nil {
        return nil, data
    }
    node.Left, data = helper(data)
    node.Right, data = helper(data)
    return node, data
}

func getNode(data string) (*TreeNode, string) {
    var node *TreeNode
    var tok string
    idx := strings.IndexRune(data, rune(','))
    if idx == -1 {
        tok = data
        data = ""
    } else {
        tok = data[:idx]
        data = data[idx+1:]
    }
    if tok == "null" {
            node = nil
    } else {
        var val int
        var err error
        if val, err = strconv.Atoi(tok); err != nil {
            panic(err)    
        }
        node = &TreeNode{val, nil, nil}
    }
    
    return node, data
}

func postOrder(root *TreeNode) string {
    if root == nil {
        return "null"
    }
    s := postOrder(root.Left) + "," + postOrder(root.Right) + "," + strconv.Itoa(root.Val)
    return s
}


func preOrder(root *TreeNode) string {
    if root == nil {
        return "null"
    }
    
    s := strconv.Itoa(root.Val) + "," + preOrder(root.Left) + "," + preOrder(root.Right)
    return s
}
/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * data := obj.serialize(root);
 * ans := obj.deserialize(data);
 */

 //Third fastest
 type Codec struct {
}

func Constructor() Codec {
    
    return Codec{}
    
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    
    var preOrder func(*TreeNode) []rune
    
    preOrder = func(root *TreeNode) []rune{
        
        if root==nil{
            return nil
        }
        
        curr:= append([]rune{rune(root.Val)}, preOrder(root.Left)...)
        curr = append(curr, preOrder(root.Right)...)
        
        return curr
    }
        
    return string(preOrder(root))
    
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {    
        
    nodes:= []rune{}

    for _, n:= range data{
        nodes=append(nodes, n)
    }
    
    startIndex := 0
    
    var buildTree func([]rune, int, int) *TreeNode
    
    buildTree = func(arr []rune, min, max int) *TreeNode{
        
        if startIndex >= len(arr){
            return nil
        }
        
        if int(arr[startIndex]) < min || int(arr[startIndex]) > max{
            return nil
        }
        
        root:= &TreeNode{int(arr[startIndex]), nil, nil}
        startIndex++
        root.Left= buildTree(arr, min, root.Val)
        root.Right= buildTree(arr, root.Val, max)
        
        return root
    }

    return buildTree(nodes, math.MinInt32, math.MaxInt32)

}

//Second fastest
import (
    "strings"
    "strconv"
)

type Codec struct {
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    var b strings.Builder
    encode(root, &b)
    return b.String()
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
    dataArr, i := strings.Split(data, "/"), 0
    return decode(dataArr[1:], &i, -1<<63, (1<<63)-1)
}

func decode(dataArr []string, i *int, low int, high int) *TreeNode {
    if *i == len(dataArr) {
        return nil
    }
    
    n, _ := strconv.Atoi(dataArr[*i])
    if n < low || n > high {
        return nil
    }
    
    (*i)++
    
    root := &TreeNode{Val: n}
    root.Left = decode(dataArr, i, low, n)
    root.Right = decode(dataArr, i, n, high)
    return root
}

func encode(n *TreeNode, b *strings.Builder) {
    if n == nil {
        return
    }
    
    b.WriteByte('/')
    b.WriteString(strconv.Itoa(n.Val))
    encode(n.Left, b)
    encode(n.Right, b)
}


//Fastest
type Codec struct {
    sb string
    
}

func Constructor() Codec {
    return Codec {
        "",
    }
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    sb := make([]byte, 0)
    ser(root, &sb)
    //fmt.Println(string(sb))
    return string(sb)
}

func ser(root *TreeNode, sb *[]byte) {
    //fmt.Println(string(*sb))
    if root == nil {
        *sb = append(*sb, '#')
        *sb = append(*sb, ',')
    } else {
        v := strconv.Itoa(root.Val)
        for i := 0; i < len(v); i++ {
            *sb = append(*sb, v[i])
        }
        *sb = append(*sb, ',')
        ser(root.Left, sb)
        ser(root.Right, sb)
    }
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {    
    que := strings.Split(data, ",")
    
    return des(&que, math.MinInt32, math.MaxInt32)
}

func des(que *[]string, left, right int) *TreeNode {
    //fmt.Println(que)
    s := (*que)[0]
    *que = (*que)[1:]
    if s == "#" {
        return nil
    }
    v, err := strconv.Atoi(s)
    if err != nil {
        return nil
    }
    node := &TreeNode {
        v,
        nil,
        nil,
    }

    node.Left = des(que, left, v)

    node.Right = des(que, v, right)

    return node
    
}
