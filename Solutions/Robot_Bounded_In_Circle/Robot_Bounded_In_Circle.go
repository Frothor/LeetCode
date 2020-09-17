func isRobotBounded(instructions string) bool {
	x, y, _, yc := getPos(0, 0, 0, 1, instructions)
    // if faces north after instructions, we must stay at (0, 0)
	if yc == 1 {
		return x == 0 && y == 0
	}
	return true
}

func getPos(x, y, xc, yc int, instructions string) (int, int, int, int) {
	for _, c := range instructions {
		switch c {
		case 'G':
			x += xc
			y += yc
		case 'L':
			if xc != 0 {
				xc, yc = 0, xc
			} else {
				xc, yc = -yc, 0
			}
		case 'R':
			if xc != 0 {
				xc, yc = 0, -xc
			} else {
				xc, yc = yc, 0
			}
		}
	}
	return x, y, xc, yc
}

//Another
func isRobotBounded(instructions string) bool {
    // 0 index: north
    // 1 index: east
    // 2 index: south
    // 3 index: west
    directions := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    x := 0
    y := 0
    idx := 0
    for _, char := range instructions {
        if char == 'L' {
            idx = (idx+3)%4
        } else if char == 'R' {
            idx = (idx+1)%4
        } else {
            x += directions[idx][0]
            y += directions[idx][1]
        }
    }
    return (x == 0 && y == 0) || idx != 0
}