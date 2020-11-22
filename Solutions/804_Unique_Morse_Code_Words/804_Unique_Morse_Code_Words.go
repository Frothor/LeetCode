//https://leetcode.com/problems/unique-morse-code-words/discuss/138396/0ms-golang-solution
func uniqueMorseRepresentations(words []string) int {
    table := []string{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}
    
    result := make(map[string]bool)
    for _, w := range words {
        var res string
        for _, r  := range w {
            res += table[unicode.ToLower(r)-'a']
        }
        result[res] = true
    }
    
    return len(result)
}

//More space efficient
import "strings"

func uniqueMorseRepresentations(words []string) int {
    uniq := make(map[string]int)
    
    for _, word := range words {
        uniq[Morsify(word)]++
    }
    
    return len(uniq)
}

var morseTable = [...]string{
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
}

func Morsify(word string) string {
    sb := strings.Builder{}
    for _, c := range word {    
        sb.WriteString(morseTable[c - 97])
    }
    return sb.String()
}