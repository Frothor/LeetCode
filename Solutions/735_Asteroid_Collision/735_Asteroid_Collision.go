//Second fastest
import "math"

func asteroidCollision(asteroids []int) []int {
    var stack []int 
    for _, rock := range asteroids {
        collide := false
        for len(stack) != 0 && rock<0 && stack[len(stack)-1]>0 {
            if rock + stack[len(stack)-1] == 0 {
                collide = true
                stack = stack[:len(stack)-1]
                break
            } else if math.Abs(float64(rock)) > math.Abs(float64(stack[len(stack)-1])) {
                stack = stack[:len(stack)-1]
            } else {
                collide = true
                break
            }
        }
        if !collide {
            stack = append(stack,rock)
        }
    }
    return stack
}

//Another second fastest
func asteroidCollision(asteroids []int) []int {
    stack := make([]int, 0)
    result := make([]int, 0)
    for _, num := range asteroids {
        if num > 0 {
            stack = append(stack, num)
            continue
        }
        for len(stack) > 0 && stack[len(stack)-1] <= -num {
            topElement := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            if topElement == -num {
                num = 0
                break
            }
        }
        if len(stack) == 0 && num != 0 {
            result = append(result, num)
        }
    }
    result = append(result, stack...)
    return result
}

//Fastest
import "math"

func asteroidCollision(asteroids []int) []int {
    var stack []int 
    for _, rock := range asteroids {
        collide := false
        for len(stack) != 0 && rock<0 && stack[len(stack)-1]>0 {
            if rock + stack[len(stack)-1] == 0 {
                collide = true
                stack = stack[:len(stack)-1]
                break
            } else if math.Abs(float64(rock)) > math.Abs(float64(stack[len(stack)-1])) {
                stack = stack[:len(stack)-1]
            } else {
                collide = true
                break
            }
        }
        if !collide {
            stack = append(stack,rock)
        }
    }
    return stack
}