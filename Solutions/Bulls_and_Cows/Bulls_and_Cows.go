func getHint(secret string, guess string) string {
	tally := make([]int, 10)
	for _, ch := range guess {
		tally[ch-'0']++
	}

	var bulls, cows int
	for i, ch := range secret {
		if ch == rune(guess[i]) {
			bulls++
		}

		if tally[ch-'0'] > 0 {
			tally[ch-'0']--
			cows++
		}
	}

	return fmt.Sprintf("%dA%dB", bulls, cows-bulls)
}

//Another
func getHint(secret string, guess string) string {
	bull := 0
	cow := 0
	// secret a number appear times
	cowArray := make([]int, 10)
	for i := 0; i < len(secret); i++ {
		s := secret[i] - '0'
		g := guess[i] - '0'
		if s == g {
			bull++
			continue
		}
		if cowArray[s] < 0 {
			cow++
		}
		cowArray[s]++
		if cowArray[g] > 0 {
			cow++
		}
		cowArray[g]--
	}

	return fmt.Sprintf("%dA%dB", bull, cow)
}