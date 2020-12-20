//https://leetcode.com/problems/decoded-string-at-index/discuss/979087/Simple-O(n)-solution-in-Go
func decodeAtIndex(S string, K int) string {
	size := 0
	n := len(S)

	for _, letter := range S {
		if unicode.IsDigit(letter) {
			num, _ := strconv.Atoi(string(letter))
			size *= num
		} else {
			size += 1
		}
	}

	for i := n - 1; i >= 0; i-- {
		letter := S[i]
		K = K % size

		if K == 0 && unicode.IsLetter(rune(letter)) {
			return string(letter)
		}

		if unicode.IsDigit(rune(letter)) {
			num, _ := strconv.Atoi(string(letter))
			size = size / num
		} else {
			size -= 1
		}
	}

	return ""
}

//Another
package main


type tape struct {
    prevTape *tape
    word string
    repeatTimes int64
    length int64
}

func (t *tape) getLength() int64 {
    if t.length > 0 {
        return t.length
    }
    var prevLen int64
    if t.prevTape != nil {
        prevLen = t.prevTape.getLength()
    }
    t.length = (prevLen + int64(len(t.word))) * t.repeatTimes
    return t.length
}

func decodeAtIndex(S string, K int) string {
    var currentWord string
    var currentTape *tape
    S = S
    for i, ch := range S {
        if ch >= 'a' && ch <= 'z' {
            currentWord = currentWord + string(ch)
            if i == len(S) - 1 {
                prevTape := currentTape
                currentTape = &tape{
                    prevTape: prevTape,
                    word: currentWord,
                    repeatTimes: 1,
                }
                currentWord = ""
            }
        } else if ch >= '2' && ch <= '9' {
            if len(currentWord) > 0 {
            prevTape := currentTape
            currentTape = &tape{
                prevTape: prevTape,
                word: currentWord,
                repeatTimes: int64(byte(ch)-'0'),
                }
                currentWord = ""
            }  else {
                currentTape.repeatTimes = int64(byte(ch)-'0') * currentTape.repeatTimes
                currentWord = ""
            }
        }
    }
    
    t := currentTape
    // convert to 0-started index
    k := int64(K-1)
    for t != nil {
        prevLen := int64(0)
        if t.prevTape != nil {
            prevLen = t.prevTape.getLength()
        }
        unitLen := prevLen + int64(len(t.word))
        if unitLen == 0 {
            return "0"
        }
        k = k % unitLen
        if k >= prevLen {
            k = k - prevLen
            return string(t.word[k])
        } else {
            t = t.prevTape
        }
    }
    return "1"
}