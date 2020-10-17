//Second fastest
var numMap = map[byte]uint32 {
    'A': 0,
    'C': 1,
    'G': 2,
    'T': 3,
}

var upperMask uint32 = 0xFFF00000 

func findRepeatedDnaSequences(s string) []string {
    sMap := map[uint32]bool{}
    res := []string{}
    
    var v uint32
    for i := 0; i < len(s); i++ {
        num := numMap[s[i]]
        v <<= 2
        v |= num
        v = v &^upperMask
        if i < 9 {
            continue
        }
        
        counted, ok := sMap[v]
        
        if !ok {
            sMap[v] = false
        } else if !counted {
            sMap[v] = true
            res = append(res, s[i-9:i+1])
        }
    }

    return res
}

//Fastest
func findRepeatedDnaSequences(s string) []string {
	if len(s) < 10 {
		return []string{}
	}

	result := []string{}
	repeat := map[uint64]int{}

	hash := uint64(0)
	pow := uint64(1)
	for i := 0; i < 10; i++ {
		hash += uint64(s[i]) * pow
		pow *= 10
	}
	pow /= 10
	repeat[hash] = 1
	for i := 10; i < len(s); i++ {
		hash = (hash-uint64(s[i-10]))/10 + uint64(s[i])*pow
		repeat[hash] += 1
		if repeat[hash] == 2 {
			result = append(result, s[i-9:i+1])
		}
	}

	return result
}