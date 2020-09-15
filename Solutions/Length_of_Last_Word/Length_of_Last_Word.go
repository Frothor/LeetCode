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

//Another
func lengthOfLastWord(s string) int {
    s = strings.TrimSpace(s)
    ls := len(s)
    for i:=ls-1;i>=0;i-- {
        if s[i]==' ' {
            return ls-i-1
        }
    }
    return ls
}