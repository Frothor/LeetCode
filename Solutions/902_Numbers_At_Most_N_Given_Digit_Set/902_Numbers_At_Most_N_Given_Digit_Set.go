//https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/943923/Go-time%3AO(logN)-space%3A-O(1)
import ("strconv")
func atMostNGivenDigitSet(digits []string, n int) int {
    if n == 0 {
        return 0
    }
    
    dCnt := [10]int{} // count how many digits in input set is equal or less that i (0<=i<=9)    
    for _,digit := range digits {
        dCnt[digit[0] - '0']++
    }
    for i := 1; i<10; i++ {
        dCnt[i] += dCnt[i-1]
    }
    
    ans := 1
    hasLimit := true  // if the current prefixed n can be complitely writed by digits (ans contains max avaliable value)    
    fullAns := 0
    pow := 1
    s := strconv.Itoa(n)
    // go from the left to the right
    for i, digit := range s {
        d := digit -'0'  //current digit from n
        
        if !hasLimit { // if prev sum does not contain max value thats mean that we cud place any digit from input set
            ans = ans*len(digits)
        } else {
            ans = (ans-1)*len(digits) + dCnt[d] // otherwise for (ans-1) - we could set any digit and for the top most - only tat that less or equal then current digit
        }
        
        if d == 0 {
            hasLimit = false
        } else {
            hasLimit = hasLimit && dCnt[d]-dCnt[d-1] > 0 // checking if the current digit in input set, if yes - thets mean that ans still contain max value
        }
        
        // just calc all possible combination for less lengh numbers 
        if i > 0 {
            pow *=len(digits)
            fullAns += pow
        }
        
    } 
    return ans+fullAns
}