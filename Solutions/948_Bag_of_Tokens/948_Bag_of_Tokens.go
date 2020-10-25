func bagOfTokensScore(tokens []int, P int) int {
    score := 0
    sort.Slice(tokens, func(i, j int) bool { return tokens[i] < tokens[j] })
    for len(tokens) > 0 && P >= tokens[0] {
        P = P - tokens[0]
        score++
        tokens = tokens[1:]
        
        if len(tokens) > 1 && P < tokens[0] {
            P = P + tokens[len(tokens)-1]
            score--
            tokens = tokens[:len(tokens)-1]
        }
    }
    
    return score
}

//Another
import "math/rand"

func bagOfTokensScore(tokens []int, P int) int {

	points := 0;

	// Sort the tokens by ascending values
	quicksort(tokens);
    
    first, last := 0, len(tokens) -1
    for first<=last {
        if P-tokens[first] >= 0 {
            points++
            P -= tokens[first]
            first++
        } else if points>0 && first<last {
            points--
            P += tokens[last]
            last--
        } else {
            break
        }
    }
    
    //// Buy the lowest cost in power
    //for {
    //    if !(len(tokens) != 0 && power > tokens[0]) {
    //        break;
    //    }
	//	power -= buyFirstToken(&tokens);
	//	points++;
	//	//fmt.Printf("--BUY-- Tokens :  %v | Power : %d | Points : %d \n", tokens, power, points);
    //}
//
	//// Repeat as much as possible
	//for {
    //    
    //    if !(len(tokens)>1) || points == 0{
    //        break;
    //    }
	//	// Sell the highest cost for power
	//	power += sellLastToken(&tokens);
	//	points--;
	//	//fmt.Printf("--SELL-- Tokens :  %v | Power : %d | Points : %d \n", tokens, power, points);
//
	//	// Buy as much as possible
	//	for ok := true; ok; ok = (len(tokens) != 0 && tokens[0] <= power) {
	//		power -= buyFirstToken(&tokens);
	//		points++;
	//		//fmt.Printf("--LOOP-- Tokens :  %v | Power : %d | Points : %d \n", tokens, power, points);
	//	}
	//}

	return points;
}

//func buyFirstToken(tokens *[]int) int{
//	power := (*tokens)[0];
//	*tokens = (*tokens)[1:];
//
//	return power
//}
//
//func sellLastToken(tokens *[]int) int{
//	lastIndex := len(*tokens)-1;
//	power := (*tokens)[lastIndex];
//	*tokens = (*tokens)[:lastIndex];
//
//	return power
//}


func quicksort(array []int) []int {
	if len(array) < 2 {
		return array
	}

	left, right := 0, len(array)-1

	pivot := rand.Int() % len(array)

	array[pivot], array[right] = array[right], array[pivot]

	for i, _ := range array {
		if array[i] < array[right] {
			array[left], array[i] = array[i], array[left]
			left++
		}
	}

	array[left], array[right] = array[right], array[left]

	quicksort(array[:left])
	quicksort(array[left+1:])

	return array
}