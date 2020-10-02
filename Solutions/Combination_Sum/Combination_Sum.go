func combinationSum(candidates []int, target int) [][]int {
	var rc func(nums []int, idx int, target int, valid *[][]int)
	rc = func(nums []int, idx int, target int, valid *[][]int) {
		if target <= 0 {
			if target == 0 {
                *valid = append(*valid, append([]int{}, nums...))
			}
			return
		}

		for i := idx; i < len(candidates); i++ {
			if candidates[i] > target {
				continue
			}

			rc(append(nums, candidates[i]), i, target-candidates[i], valid)
		}
	}
    sort.Ints(candidates)
	valid := [][]int{}
	rc([]int{}, 0, target, &valid)
	return valid
}

//Another
func add(l *[][]int, n []int) {
    p := make([]int,len(n))
    for k,_:= range p {
        p[k]=n[k]
    }
    *l =append(*l,p)
}

func backtrack(l *[][]int,n []int, c []int, t int,p int) {
    if t==0 {
        add(l,n)
        return
    }
    if t<0 {
        return
    }
    for i:=p;i<len(c);i++ {
        n = append(n,c[i])
        backtrack(l,n,c,t-c[i],i)
        n= n[:len(n)-1]
    }
}
func combinationSum(candidates []int, target int) [][]int {
    l := make([][]int, 0)
    n := make([]int,0)
    backtrack(&l,n,candidates, target, 0)
    return l
}

//Fastest
import (
	"fmt"
	"sort"
)

var debug = false

func log(s string, a ...interface{}) {
	if !debug {
		return
	}
	fmt.Printf(s, a...)
}

var result [][]int
var gCandidates []int

func combinationSum(candidates []int, target int) [][]int {
	result = [][]int{}
	if len(candidates) == 0 {
		return result
	}
	sort.Slice(candidates, func(i, j int) bool {
		return candidates[i] < candidates[j]
	})
	gCandidates = candidates
	findRecursive([]int{}, 0, target)

	//log("xxx result %v\n", result)
	return result
}

func findRecursive(arr []int, curIndTarget int, left int) {
	if left == 0 {
		copyArr := make([]int, len(arr))
		copy(copyArr, arr)
		result = append(result, copyArr)
		return
	}

	for i := curIndTarget; i < len(gCandidates); i++ {
		v := gCandidates[i]
		if v > left {
			break
		}
		findRecursive(append(arr, v), i, left-v)
	}
}