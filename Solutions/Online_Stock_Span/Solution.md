# Solution
## Approach 1: Stack
### Intuition

Clearly, we need to focus on how to make each query faster than a linear scan. In a typical case, we get a new element like **7**, and there are some previous elements like **11, 3, 9, 5, 6, 4**. Let's try to create some relationship between this query and the next query.

If (after getting **7**) we get an element like **2**, then the answer is **1**. So in general, whenever we get a smaller element, the answer is 1.

If we get an element like **8**, the answer is 1 plus the previous answer (for **7**), as the **8** "stops" on the same value that **7** does (namely, **9**).

If we get an element like **10**, the answer is 1 plus the previous answer, plus the answer for **9**.

Notice throughout this evaluation, we only care about elements that occur in increasing order - we "shortcut" to them. That is, from adding an element like **10**, we cut to **7** [with "weight" 4], then to **9** [with weight 2], then cut to **11** [with weight 1].

A stack is the ideal data structure to maintain what we care about efficiently.

### Algorithm

Let's maintain a weighted stack of decreasing elements. The size of the weight will be the total number of elements skipped. For example, **11, 3, 9, 5, 6, 4, 7** will be **(11, weight=1), (9, weight=2), (7, weight=4)**.

When we get a new element like **10**, this helps us count the previous values faster by popping weighted elements off the stack. The new stack at the end will look like **(11, weight=1), (10, weight=7)**.

**Java**
```java
class StockSpanner {
    Stack<Integer> prices, weights;

    public StockSpanner() {
        prices = new Stack();
        weights = new Stack();
    }

    public int next(int price) {
        int w = 1;
        while (!prices.isEmpty() && prices.peek() <= price) {
            prices.pop();
            w += weights.pop();
        }

        prices.push(price);
        weights.push(w);
        return w;
    }
}
```

**Python**
```python
class StockSpanner(object):
    def __init__(self):
        self.stack = []

    def next(self, price):
        weight = 1
        while self.stack and self.stack[-1][0] <= price:
            weight += self.stack.pop()[1]
        self.stack.append((price, weight))
        return weight
```

### Complexity Analysis

* Time Complexity: *O(Q)*, where *Q* is the number of calls to **StockSpanner.next**. In total, there are *Q* pushes to the stack, and at most *Q* pops.

* Space Complexity: *O(Q)*.