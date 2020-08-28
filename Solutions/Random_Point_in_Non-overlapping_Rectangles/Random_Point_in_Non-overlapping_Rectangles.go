type Solution struct {
	magic []int
	rects [][]int
}

func Constructor(rects [][]int) Solution {
	magic := make([]int, 0, len(rects))
	summary := -1
	for _, v := range rects {
		summary += (v[2]-v[0]+1)*(v[3]-v[1]+1)
		magic = append(magic, summary)
	}
	return Solution{
		magic: magic,
		rects: rects,
	}
}

func (s *Solution) Pick() []int {
	choice1 := rand.Intn(s.magic[len(s.magic)-1]+1)
	l, r := 0, len(s.magic)-1
	for l <= r {
		m := (l+r)>>1
		if s.magic[m] < choice1 {
			l = m+1
		} else {
			r = m-1
		}
	}
	index := l
	choice2 := rand.Intn(100000000)
	x := s.rects[index][0] + choice2 % 10000 % (s.rects[index][2] - s.rects[index][0] + 1)
	y := s.rects[index][1] + choice2 / 10000 % (s.rects[index][3] - s.rects[index][1] + 1)
	return []int{x,y}
}

//Weighting
type Solution struct {
	Rects   []rect
	Chances []int
}

func Constructor(rects [][]int) Solution {
	sol := Solution{}
	sol.Rects = make([]rect, len(rects))[:0]
	sol.Chances = make([]int, len(rects))[:0]

	chance := 0
	for _, r := range rects {
		rec := rect{point{r[0], r[1]}, point{r[2], r[3]}}
		sol.Rects = append(sol.Rects, rec)
		chance += rec.Area()
		sol.Chances = append(sol.Chances, chance)
	}

	return sol
}

func (sol *Solution) Pick() []int {
	areaSum := sol.Chances[len(sol.Chances)-1]
	randomPoint := 1 + rand.Intn(areaSum)

	r := sol.Rects[0]
	for ck, c := range sol.Chances {
		if randomPoint <= c {
			r = sol.Rects[ck]
			break
		}
	}

	return []int{
		r[0].X + rand.Intn(r.HorizLen()+1),
		r[0].Y + rand.Intn(r.VertLen()+1),
	}
}

type point struct{ X, Y int }

type rect [2]point

func (r rect) Area() int {
	return (r.HorizLen() + 1) * (r.VertLen() + 1)
}

func (r rect) HorizLen() int {
	return abs(abs(r[0].X) - abs(r[1].X))
}

func (r rect) VertLen() int {
	return abs(abs(r[0].Y) - abs(r[1].Y))
}

func abs(n int) int {
	if n < 0 {
		return -n
	} else {
		return n
	}
}