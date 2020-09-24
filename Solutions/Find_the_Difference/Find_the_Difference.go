func findTheDifference(s string, t string) byte {
	var missing byte
	for i := 0; i < len(s); i++ {
		missing ^= s[i] ^ t[i]
	}

	return missing ^ t[len(t)-1]
}

//Another
func findTheDifference(s string, t string) byte {
    set := make([]rune, len(s)+len(t)) 
    for index, val := range s { set[index] = val }
    for index, val := range t { set[index+len(s)] = val }
    return byte(uniq(set))
}

func uniq(s []rune) rune {
    if len(s) == 1 { return s[0] }
    return s[0] ^ uniq(s[1:])
}