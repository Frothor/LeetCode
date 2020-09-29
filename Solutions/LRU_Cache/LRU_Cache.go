type LRUCache struct {
	Cache    map[int]*Element
	Head     *Element
	Tail     *Element
	Capacity int
}

type Element struct {
	Value int
	Key   int
	Prev  *Element
	Next  *Element
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Cache:    make(map[int]*Element, capacity),
		Capacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	e, ok := this.Cache[key]
	if !ok {
		return -1
	}
	if e == this.Head {
		return e.Value
	}
	this.removeElement(e)
	this.MoveToFront(e)
	return e.Value
}

func (this *LRUCache) MoveToFront(e *Element) {
	if e == this.Head {
		return
	}
	// if element is tail
	if e == this.Tail && e.Prev != nil {
		e.Prev.Next = nil
		this.Tail = e.Prev
	}
	e.Prev = nil
	e.Next = this.Head
	if this.Head != nil {
		this.Head.Prev = e
	}
	this.Head = e
}

func (this *LRUCache) Put(key int, value int) {
	e, ok := this.Cache[key]
	if ok {
		e.Value = value
		if e != this.Head {
			this.removeElement(e)
			this.MoveToFront(e)
		}
		return
	}
	if len(this.Cache) >= this.Capacity {
		this.evictElement()
	}
	e = &Element{
		Value: value,
		Key:   key,
	}
	if this.Tail == nil {
		this.Tail = e
	}
	this.Cache[key] = e
	this.MoveToFront(e)
}
func (this *LRUCache) evictElement() {
	if this.Tail == nil {
		return
	}
	key := this.Tail.Key
	// point tail to prev element
	if this.Tail.Prev != nil {
		this.Tail = this.Tail.Prev
		this.Tail.Next = nil
	}
	delete(this.Cache, key)
}
func (this *LRUCache) removeElement(e *Element) {
	// remove element
	if e.Next != nil {
		e.Next.Prev = e.Prev
	}
	if e.Prev != nil {
		e.Prev.Next = e.Next
	}
}

//Another
type LRUCache struct {
	Cache map[int]*Data
	Head *Node
	Tail *Node
	Size int
}
type Data struct{
	Val int
	Ref *Node
}
type Node struct {
	Key int
	Next *Node
	Prev *Node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Cache: make(map[int]*Data,capacity),
		Size: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	if val,exists := this.Cache[key];exists{

		if val.Ref==this.Tail{
			return val.Val
		}
		if val.Ref == this.Head && val.Ref != this.Tail{
			this.Head = val.Ref.Next
			val.Ref.Next.Prev = nil
		}else{
			val.Ref.Prev.Next = val.Ref.Next
			val.Ref.Next.Prev = val.Ref.Prev
		}

		//update ref
		val.Ref = this.AppendInLinkedList(key)
		return val.Val
	}

	return -1
}

func (this *LRUCache) Put(key int, value int)  {
	if _,exists:=this.Cache[key];exists{
		//using Get to update ref
		this.Get(key)
		this.Cache[key].Val = value
		return
	}
	if len(this.Cache)==this.Size{
		//overflow
		//del
		delete(this.Cache,this.Head.Key)
		//point to next node
		this.Head = this.Head.Next
		if this.Head==nil{
			this.Tail=nil
		}
	}

		//add in cache
		this.Cache[key]=&Data{
			Val: value,
			Ref: this.AppendInLinkedList(key),
		}

	return
}

func (this *LRUCache) AppendInLinkedList(key int)(ref *Node){
	if this.Head==nil{
		//append with update head
		this.Head = &Node{
			Key:  key,
		}
		this.Tail = this.Head
		ref = this.Head
	}else{
		//append
		n := &Node{
			Key:  key,
			Prev:this.Tail,
		}
		ref = n
		this.Tail.Next = n
		this.Tail = n
	}
	return
}