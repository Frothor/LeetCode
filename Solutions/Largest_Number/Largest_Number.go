import (
	"sort"
	"strconv"
	"strings"
)

// ByLength custom type for string comparision
type ByLength []string

func (a ByLength) Len() int           { return len(a) }
func (a ByLength) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByLength) Less(i, j int) bool { return (a[i] + a[j]) > (a[j] + a[i]) }

func largestNumber(nums []int) string {
	strnum := make([]string, len(nums))
	for i := range nums {
		strnum[i] = strconv.Itoa(nums[i])
	}
	sort.Sort(ByLength(strnum))
	ans := strings.Join(strnum, "")
	if ans[0] == '0' {
		return "0"
	}
	return ans
}


//Another
/*
[333, 2222]
3332222 
9000,89999
900089999

23, 22, 24 

123, 12 
121, 12 

12121 

12312
12123

*/ 
import (
    "sort"
    "strconv"
)

func arrangeBucket(b []string) string {
	if len(b) == 0 {
		return ""
	}

	sort.Slice(b, func(i, j int) bool {
		opA := string(b[i]) + string(b[j])
		opb := string(b[j]) + string(b[i])
		return opA > opb
	})
	result := ""
	fmt.Println(b)
	for len(b) > 1 {
		//index := findIndexDiff(b[0], b[1])
		//fmt.Println( string(b[0][index+1]), string(b[1][index]))
		//if len(b[0]) > len(b[1]) && b[0][index] <= b[1][index]{
		//	result += b[1]
		//	b = append(b[:1], b[2:]...)
		//	continue
		//}
		result += b[0]
		b = b[1:]
	}
	result += b[0]
	return result
}

func largestNumber(nums []int) string {
	stringArray := make([]string, len(nums))
	for i, n := range nums {
		stringArray[i] = strconv.Itoa(n)
	}

	buckets := make([][]string, 10)
	for i := 0; i < 10; i++ {
		buckets[i] = []string{}
	}
	for _, s := range stringArray {
		bucket := s[0] - '0'
		buckets[bucket] = append(buckets[bucket], s)
	}


	result := ""
	for i := 9; i >= 0; i-- {
		result += arrangeBucket(buckets[i])
	}

	if result[0] == '0' {
		return "0"
	}

	return result

}