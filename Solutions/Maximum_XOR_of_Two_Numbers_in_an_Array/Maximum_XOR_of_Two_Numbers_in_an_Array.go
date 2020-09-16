/*The important thing to note is, we don't need to return a pair of indices of a result but just need a result of XOR.

Because a number of bits in integer is constant (in Go, leetcode has 32-bit integer environment), we can first build a Trie which has all possible bits (0 or 1) in each digit (from 31 to 0 th) among all elements in an array.

Then we can again iterate through the array and for each element, we will traverse the Trie so that XOR of each digit should have maximum value. Obviously, the more significant bit has 1, a result of XOR becomes bigger.

I also recommend try to solve this variant as well. We need an additional trick to solve this.
http://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
*/

func findMaximumXOR(nums []int) int {
    root := NewNode()
    
    // build trie
    for _, num := range nums {
        cur := root
        for i := 31; i >= 0; i-- {
            flag := (num >> uint(i)) & 1
            if cur.Children[flag] == nil {
                cur.Children[flag] = NewNode()
            }
            cur = cur.Children[flag]
        }
    }
    
    // search maximum
    max := 0
    for _, num := range nums {
        cur, val := root, 0
        for i := 31; i >= 0; i-- {
            flag := (num >> uint(i)) & 1
            switch {
            case flag == 1 && cur.Children[0] != nil, flag == 0 && cur.Children[1] != nil:
                val += 1 << uint(i)
                cur = cur.Children[1 & ^flag] // just reversing flag
            default:
                cur = cur.Children[flag]
            }
        }
        if val > max {
            max = val
        }
    }
    return max
}

type TNode struct {
    Children [2]*TNode
}

func NewNode() *TNode {
    return &TNode{Children: [2]*TNode{nil, nil}}
}

//Most common
func findMaximumXOR(nums []int) int {
    mask:=1<<31
    preFix:=0
    candidate:=0
    for mask>0{
        preFix+=mask
        set:=map [int] bool {}
        for _,num:=range(nums){
            set[num&preFix] = true
        }
        tmp:=candidate+mask
        for _,num:=range(nums) {
            if set[(num&preFix) ^ tmp ] {
                candidate=tmp
                break
            }
        }
        mask = mask>>1
    }
    return candidate
}

//Fastest
// github.com/EndlessCheng/codeforces-go
func init() { debug.SetGCPercent(-1) }

func findMaximumXOR(nums []int) int {
    N := len(nums)
    res := 0
    mask := 0
    for j := 31; j >= 0; j-- {
        mask = mask | (1 << j)
        dp := make(map[int]bool, 0)
        temp := res | (1 << j)
        for i := 0; i < N; i++ {
            if dp[(nums[i] & mask) ^ temp] {
                res = temp
                break 
            } else {
                dp[nums[i] & mask] = true
            }
        }
    }
    return  res 
}

