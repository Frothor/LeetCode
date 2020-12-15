//Third fastest
func sortedSquares(nums []int) []int {
    res := make([]int, len(nums))
    pos := len(nums)-1
    l,r := 0, len(nums)-1
    
    // for i := len(nums)-1; i >= 0; i-- {
    for l <= r {
        ls, rs := nums[l]*nums[l], nums[r]*nums[r]
        if ls < rs {
            res[pos] = rs
            r--
        } else {
            res[pos] = ls
            l++
        }
        pos--
    }
    
    return res

}

// find the first positive number

//Second fastest
import "math"

func sortedSquares(A []int) []int {
    res := make([]int, len(A))
    left, right := 0, len(A)-1
    for end := len(A)-1; end >= 0; end--{
        
        if math.Abs(float64(A[left])) < math.Abs(float64(A[right])) {
            res[end] = A[right]*A[right]
            right -= 1
        } else {
           
            res[end] = A[left]*A[left]
            left += 1
        }
    }
    return res
}

//Fastest
func sortedSquares(A []int) []int {
    i:=0
    j:=0
    t:=0
    tempi:=0
    tempj:=0
    res :=make([]int,len(A))
    
    for i=0;i<len(A) && A[i] < 0 ; {
        i++
    }
    i-=1
    j=i+1
    for i>=0 && j <len(A) {
        tempi=A[i] * A[i]
        tempj=A[j] * A[j]
        if tempi < tempj {
            res[t]=tempi
            i--
        } else {
            res[t]=tempj
            j++
        }
        t++
    }
    
    for i>=0 && t < len(A) {
        res[t] = A[i] * A[i]
        i--
        t++
    }
    
    for j<len(A) {
        res[t]  = A[j] * A[j]
        j++
        t++
    }
    return res
}