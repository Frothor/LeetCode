func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
    testRound := minutesToTest / minutesToDie
    testGroup := testRound + 1
    res := int(math.Ceil(math.Log(float64(buckets)) / math.Log(float64(testGroup))))
    return res
}