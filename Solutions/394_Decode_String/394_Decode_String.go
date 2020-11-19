//Stack -> https://leetcode.com/problems/decode-string/discuss/346216/Golang-solution-using-2-stacks-with-my-thoughts-and-notes
import (
	"strconv"
	"strings"
)

func decodeString(s string) string {
	intStack := Stack{}
	strStack := Stack{}
	cur := ""
	k := 0
	for i := 0; i < len(s); i++ {
		if n, err := strconv.Atoi(string(s[i])); err == nil {
			// handle cases like 100[leetcode]
			k = k*10 + n
		} else if s[i] == '[' {
			intStack.Push(k)
			strStack.Push(cur)
			cur = ""
			k = 0
		} else if s[i] == ']' {
			tmp := cur
			cur = strStack.Pop().(string)
			cur += strings.Repeat(tmp, intStack.Pop().(int))
		} else {
			cur += string(s[i])
		}
	}
	return cur
}

type Stack []interface{}

func (s *Stack) Push(x interface{}) {
	*s = append(*s, x)
}

func (s *Stack) Pop() interface{} {
	if len(*s) == 0 {
		return nil
	}
	tail := (*s)[len(*s)-1]
	*s = (*s)[:len(*s)-1]
	return tail
}

//Recursion -> https://leetcode.com/problems/decode-string/discuss/346959/Golang-solution-using-recursion-with-my-analysis
func decodeString(s string) string {
	r, _ := helper(s, 0)
	return r
}

func helper(s string, start int) (cur string, end int) {
	if len(s) == 0 {
		return "", 0
	}
	k := 0
	i := start
	for i < len(s) {
		ch := string(s[i])
		if n, err := strconv.Atoi(ch); err == nil {
			k = k*10 + n
		} else if ch == "[" {
			decoded, end := helper(s, i+1)
			cur += strings.Repeat(decoded, k)
			i = end
			k = 0
		} else if ch == "]" {
			// this is the base case
			return cur, i
		} else {
			cur += ch
		}
		i++
	}
	return cur, i
}

//Most memory efficient
type frame struct {
    r int
    buf []byte
}

type stack struct {
    frames []frame
}

func (s *stack) push(f frame) {
    s.frames = append(s.frames, f)
}

func (s *stack) pop() frame {
    f := s.frames[len(s.frames)-1]
    s.frames = s.frames[:len(s.frames)-1]
    return f
}

func decodeString(s string) string {
    s = "1["+s
    
    st := &stack{}
    cnt := 0
    for i := 0; i < len(s); i++ {
        b := s[i]
        
        if b >= '0' && b <= '9' {
            cnt *= 10
            cnt += int(b - '0')
        } else if b == '[' {
            st.push(frame{
                r: cnt,
            })
            cnt = 0
        } else if b == ']' {
            f := st.pop()
            var buf []byte
            for j := 0; j < f.r; j ++ {
                buf = append(buf, f.buf...)
            }
            st.frames[len(st.frames)-1].buf = append(st.frames[len(st.frames)-1].buf, buf...)
        } else {
            st.frames[len(st.frames)-1].buf = append(st.frames[len(st.frames)-1].buf, b)
        }
    }
    
    
    return string(st.frames[0].buf)
}