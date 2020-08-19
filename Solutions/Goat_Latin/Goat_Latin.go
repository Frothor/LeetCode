func toGoatLatin(S string) string {
    var sb strings.Builder // We don't need the Repeat function
    words := strings.Split(S, " ")
    sb.Grow(len(words))
    
    for i, word := range words {
        sb.WriteByte('a')
        
        switch word[0] {
            case 'a','e','i','o', 'u', 'A', 'E', 'I', 'O', 'U':
                // skip
            default:
                word = word[1:] + string(word[0])
        }
        
        words[i] = word + "ma" + sb.String()
    }
    
    return strings.Join(words, " ")
}

//Another
package main

import "strings"

func toGoatLatin(S string) string {
	ss := strings.Split(S, " ")
	vowel := map[uint8]bool{
		'a': true,
		'e': true,
		'i': true,
		'o': true,
		'u': true,
	}
	builder := strings.Builder{}
	for i := 0; i < len(ss); i++ {
		s := ss[i]
		builder.Reset()
		if vowel[s[0]] || vowel[s[0]+'a'-'A'] {
			builder.WriteString(s)
		} else {
			builder.WriteString(s[1:])
			builder.WriteByte(s[0])
		}
		builder.WriteByte('m')
		builder.WriteByte('a')
		for j := 0; j < i+1; j++ {
			builder.WriteByte('a')
		}
		ss[i] = builder.String()
	}
	return strings.Join(ss, " ")
}
