import "strconv"

func fizzBuzz(n int) []string {
    
    result := make([]string, n)
    i := 1
    
    for i<= n{
        
        if i%15 == 0 {
            result[i-1] = "FizzBuzz"
        } else if i%3 == 0{
             result[i-1] = "Fizz"
        } else if i%5 == 0{
             result[i-1] = "Buzz"
        } else{
            result[i-1] = strconv.Itoa(i)
        }
        
        i += 1
    }
    
    return result
    
}
