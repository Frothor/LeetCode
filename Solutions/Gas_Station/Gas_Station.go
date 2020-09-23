//Most common
func canCompleteCircuit(gas []int, cost []int) int {
	left, start, fail := 0, 0, 0
	for i := range gas {
		left += gas[i] - cost[i]
		if left < 0 {
			fail += -left
			left, start = 0, (i+1)%len(gas)
		}
	}
	if left < fail {
		return -1
	}
	return start
}

//Fastest
package main

func canCompleteCircuit(gas []int, cost []int) int {
	delta := make([]int, 0)
	for i := 0; i < len(gas); i++ {
		delta = append(delta, gas[i] - cost[i])
	}

	MaxD := -2147483640
	Maxi := 0
	for i := 0; i < len(delta); i++ {
		if delta[i] > MaxD {
			MaxD = delta[i]
			Maxi = i
		}
	}
	Appendix := make([]int, 0)
	Appendix = append(Appendix, MaxD)
	for i, step := Maxi, 0; step < len(delta) - 1; step ++ {
		pre := i - 1
		if pre < 0 {
			pre += len(delta)
		}
		Appendix = append(Appendix, Appendix[len(Appendix) - 1] + delta[pre])
        i = pre
	}
	MaxPre := 0
	for i := 0; i < len(Appendix); i++ {
		if MaxD < Appendix[i] {
			MaxD = Appendix[i]
			MaxPre = i
		}
	}
    fmt.Println(MaxPre)
	TotDelta := 0
	for i := 0; i < len(delta); i++ {
		TotDelta += delta[i]
	}
	if TotDelta < 0 {
		return - 1
	} 
	ans := Maxi - MaxPre
	if ans < 0 {
		ans += len(delta)
	}
	return ans
}