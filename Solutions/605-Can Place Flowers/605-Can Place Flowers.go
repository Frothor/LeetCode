//Third fastest
func canPlaceFlowers(flowerbed []int, n int) bool {
    
    i, count := 0, 0
    
    for i < len(flowerbed) {
        if flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] ==0) && (i == len(flowerbed) -1 || flowerbed[i + 1] == 0) {
            flowerbed[i] =1
            count++
        }
        i++
        
    }
    return count >= n
}

//Second fastest
func canPlaceFlowers(flowerbed []int, n int) bool {
	for i:=0; i<len(flowerbed); i++ {
        
        // Edge case when i == 0 and flowerbed[i+1] == 0 || i == len(flowerbed)-1 and flowerbed[i-1] == 0
        // https://www.youtube.com/watch?v=WEtHB3Ewc8I&ab_channel=NideeshTerapalli
		
        if flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len(flowerbed)-1 || flowerbed[i+1] == 0 ) {
				flowerbed[i] = 1
				n--
			}
			if n <= 0 {
				return true
		}
	}
	return false
}

//Fastest
func canPlaceFlowers(flowerbed []int, n int) bool {
	var count int
	i := 0
	//print(i == 0 || flowerbed[i-1] == 0)
	for i < len(flowerbed) {
		if flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len(flowerbed)-1 || flowerbed[i+1] == 0) {
			//flowerbed[i] = 1
			i++
			count++
		}
		if count >= n {
			return true
		}
		i++
	}
	return false
}