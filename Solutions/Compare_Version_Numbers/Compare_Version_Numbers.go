func compareVersion(version1 string, version2 string) int {
	v1 := strings.Split(version1, ".")
	v2 := strings.Split(version2, ".")

	var d1, d2 int
	for i, digit := range v1 {
		d1, _ = strconv.Atoi(digit)
		if i > len(v2)-1 {
			d2 = 0
		} else {
			d2, _ = strconv.Atoi(v2[i])
		}

		if d1 < d2 {
			return -1
		}

		if d1 > d2 {
			return 1
		}
	}

	if len(v2) > len(v1) {
		for i := len(v1); i < len(v2); i++ {
			d2, _ = strconv.Atoi(v2[i])
			if d2 > 0 {
				return -1
			}
		}
	}

	return 0
}

//Fastest
func compareVersion(version1 string, version2 string) int {
	ind1 := 0
	ind2 := 0
	num1, num2 := 0, 0
	for ind1 < len(version1) || ind2 < len(version2) {
		num1, ind1 = findNext(version1, ind1)
		num2, ind2 = findNext(version2, ind2)
		if num1 > num2 {
			return 1
		}
		if num1 < num2 {
			return -1
		}
	}
	return 0
}

func findNext(version string, start int) (int, int) {
	if start > len(version)-1 {
		return 0, start
	}
	i := start
	for i < len(version) {
		if version[i] != '.' {
			i++
		} else {
			break
		}
	}
	versionNum, _ := strconv.Atoi(version[start:i])
	return versionNum, i + 1
}