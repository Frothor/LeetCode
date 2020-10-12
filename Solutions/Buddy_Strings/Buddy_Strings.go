func buddyStrings(A string, B string) bool {
    if len(A) != len(B) {
        return false
    }
    
    duplicate := false
    count := [26]bool{}
    bad1, bad2 := -1, -1
    for i := 0; i < len(B); i++ {
        if A[i] != B[i] {
            if bad1 == -1 {
                bad1 = i
            } else if bad2 == -1 {
                bad2 = i
            } else {
                return false
            }
        }
        duplicate = duplicate || count[A[i]-'a']
        count[A[i]-'a'] = true
    }
    if bad1 == -1 && bad2 == -1 {
		// if we did not find any unmatching chars, we must swap duplicate chars
        return duplicate
    }
    if bad2 == -1 {
		// if we found only one non-matching char, impossible.
        return false
    }
	// validate that the 2 bad chars are equal to their opposite chars in the
    return A[bad1] == B[bad2] && B[bad1] == A[bad2]
}

//Another
func buddyStrings(A string, B string) bool {
    if len(A) != len(B) {
        return false
    }
    var d int
    a, b := -1, -1
    m := make([]bool, 26)
    var f bool
    for i := len(B) - 1; i >= 0; i-- {
        if m[A[i] - 'a'] {
            f = true
        } else {
            m[A[i] - 'a'] = true
        }
        if A[i] == B[i] {
            continue
        }
        d++
        if d > 2 {
            return false
        }
        if a == - 1 {
            a = i
        } else {
            b = i
        }
    } 
    return d == 0 && f || d == 2 && A[a] == B[b] && A[b] == B[a]
}