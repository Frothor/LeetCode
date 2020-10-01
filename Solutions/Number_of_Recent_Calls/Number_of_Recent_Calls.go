import "container/list"

type RecentCounter struct {
	queue *list.List
}

func Constructor() RecentCounter {
	return RecentCounter{queue: list.New()}
}

// Learning: Elements from the list need to be cast into specific type before being used.
func (this *RecentCounter) Ping(t int) int {
	this.queue.PushBack(t)
	for this.queue.Front().Value.(int) < t-3000 {
		this.queue.Remove(this.queue.Front())
	}

	return this.queue.Len()
}

//Most common
type RecentCounter struct {
	times []int
}

func Constructor() RecentCounter {
	return RecentCounter{
		times: make([]int, 0, 10000),
	}
}

func (rc *RecentCounter) Ping(t int) int {
	rc.times = append(rc.times, t)

	for len(rc.times) > 0 && rc.times[0] + 3000 < t {
		rc.times = rc.times[1:]
	}

	return len(rc.times)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */

 type RecentCounter struct {
    q []int
}


func Constructor() RecentCounter {
    return RecentCounter{}
}


func (this *RecentCounter) Ping(t int) int {
    this.q = append(this.q, t)
    for this.q[0] < t - 3000 {
        this.q = this.q[1:]
    }
    return len(this.q)
}