package main

func lengthOfLastWord(s string) int {
	var res int
	i := len(s) - 1
	for ; i >= 0 && s[i] == ' '; i-- {

	}
	for ; i >= 0; i-- {
		if s[i] != ' ' {
			res++
		} else {
			break
		}
	}
	return res
}