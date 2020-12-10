//Third fastest
// 模拟就行了。
// 二分不太合适，因为不一定是合法的。
func validMountainArray(arr []int) bool {
    n := len(arr)
    if n < 3 {
        return false
    }
    last := -1
    down := false
    pivot := 0
    for i := 0; i < n; i++ {
        if arr[i] == last {
            return false
        }
        if !down {
            if arr[i] < last {
                down = true
                pivot = i - 1
            }
        } else {
            if arr[i] > last {
                return false
            }
        }
        last = arr[i]
    }
    if !down || pivot==0 {
        return false
    }
    return true
}

//Second fastest
func validMountainArray(arr []int) bool {
    if len(arr) < 3     {return false}
    if arr[1] <= arr[0] {return false}
    if arr[len(arr)-1] >= arr[len(arr)-2] {return false}
    f := true
    for i := 2; i < len(arr)-1; i++ {
        d := arr[i] - arr[i-1]
        if d == 0 { return false }
        if d > 0 {
            if f {continue}
            return false
        } else {
            if !f {continue}
            f = false
        }
    }
    return true
}

//Fastest
func validMountainArray(arr []int) bool {
    // walk up then walk down
    distance := len(arr) -1
    step := 0
    
    for step < distance && canStepUp(arr,step) {
        step++
    }
    
    if step == distance || step == 0 {
        return false
    }
    
    for step < distance && canStepDown(arr,step){
        step++
    }
    
    if step == distance {
        return true
    }
    
    return false
    
}

func canStepUp(arr []int,step int) bool {
    return arr[step] < arr[step+1]
}

func canStepDown(arr []int,step int) bool {
    return arr[step] > arr[step+1]
}