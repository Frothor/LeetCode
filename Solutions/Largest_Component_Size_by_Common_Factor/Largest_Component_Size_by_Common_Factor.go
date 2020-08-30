type DSU struct {
    p []int
}
func (d *DSU) find(x int) int {
    if d.p[x] != x {
        d.p[x] = d.find(d.p[x])
    }
    return d.p[x]
}

func (d *DSU) union(x, y int) {
    xr := d.find(x)
    yr := d.find(y)
    d.p[xr] = yr
}

func init_dsu(n int) *DSU{
    p := make([]int, n)
    for i := 0; i < n; i++ {
        p[i] = i
    }
    return &DSU{p}
}

func largestComponentSize(A []int) int {
    B := make([][]int, 0)
    for i:=0; i < len(A); i++ {
        a := A[i]
        d := 2
        facs := make([]int, 0)
        // fidn the common factor
        for d*d <= a {
            if a % d == 0 {
                for a % d == 0 {
                    a /= d
                }
                facs = append(facs, d)
            }
            d += 1
        }
        
        if a > 1 || len(facs) == 0 {
            facs = append(facs, a)
        }
        B = append(B, facs)
    }
    
    // get the unique prime factors
    hmap := make(map[int]bool)
    for _, facs := range B {
        for _, f := range facs {
            hmap[f] = true
        }
    }
    idx := 0
    primes := make([]int, 0)
    prime_to_index := make(map[int]int)
    for k, _ := range hmap {
        primes = append(primes, k)
        prime_to_index[k] = idx
        idx += 1
    }
    
    // init the DSU
    dsu := init_dsu(len(primes))
    for _, facs := range B {
        for _, f := range facs {
            dsu.union(prime_to_index[facs[0]], prime_to_index[f])
        }
    }
    
    counter := make(map[int]int)
    for _, facs := range B {
        counter[dsu.find(prime_to_index[facs[0]])] += 1
    }
    
    ans := 0
    for _, v := range counter {
        if v > ans {
            ans = v
        }
    }
    return ans
}



////BEST
func largestComponentSize(A []int) int {
    n := len(A)
    parents, sizes := make([]int, n), make([]int, n)
    for i := range parents {
        parents[i], sizes[i] = i, 1
    }

    factors := make([][]int, n)
    for i, v := range A {
        if v & 1 == 0 {
            factors[i] = append(factors[i], 2)
            for v & 1 == 0 {
                v >>= 1
            }
        }
        for factor := 3; factor*factor <= v; factor++ {
            for v % factor == 0 {
                v /= factor
                if len(factors[i]) == 0 || factors[i][len(factors[i])-1] != factor {
                    factors[i] = append(factors[i], factor)
                }
            }
        }
        if v > 2 {
            factors[i] = append(factors[i], v)
        }
    }
    
    factorToIndex := make(map[int]int)
    for i := range factors {
        for _, factor := range factors[i] {
            if j, ok := factorToIndex[factor]; ok {
                union(parents, sizes, i, j)
            }
            factorToIndex[factor] = i
        }
    }
    
    ans := 0
    for i := 0; i < n; i++ {
        ans = max(ans, sizes[find(parents, i)])
    }
    return ans
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func find(parents []int, i int) int {
    if parents[i] == i { return i }
    parents[i] = find(parents, parents[i])
    return parents[i]
}

func union(parents, sizes []int, i, j int) bool {
    pi, pj := find(parents, i), find(parents, j)
    if pi != pj {
        if sizes[pi] >= sizes[pj] {
            parents[pj] = pi
            sizes[pi] += sizes[pj]
        } else {
            parents[pi] = pj
            sizes[pj] += sizes[pi]
        }
    }
    return pi != pj
}