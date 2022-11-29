# LeetCode Medium 2. Add Two Numbers Solution

## Approach 1: Elementary Math

### Intuition
Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of list, which contains the least-significant digit.
![addtwonumber1](images/2_add_two_numbers.svg)
*Figure 1. Visualization of the addition of two numbers: `342+465=807`. Each node contains a single digit and the digits are stored in reverse order*.
### Algorithm

Just like how you would sum two numbers on a piece of paper, we begin by summing the least-significant digits, which is the head of `l1` and `l2`. Since each digit is in the range of `0…9`, summing two digits may "overflow". For example `5+7=12`. In this case, we set the current digit to `2` and bring over the `carry=1` to the next iteration. `carry` must be either `0` or `1` because the largest possible sum of two digits (including the carry) is `9+9+1=19`.

The pseudocode is as following:

* Initialize current node to dummy head of the returning list.
* Initialize carry to `0`.
* Loop through lists `l1` and `l2` until you reach both ends and crarry is `0`.
    * Set `x` to node `l1`'s value. If `l1` has reached the end of `l1`, set to `0`.
    * Set `y` to node `l2`'s value. If `l2` has reached the end of `l2`, set to `0`.
    * Set `sum=x+y+carry`.
    * Update `carry=sum/10`.
    * Create a new node with the digit value of `(sum mod 10)` and set it to current node's next, then advance current node to next.
    * Advance both `l1` and `l2`.
* Return dummy head's next node.

Note that we use a dummy head to simplify the code. Without a dummy head, you would have to write extra conditional statements to initialize the head's value.

Take extra caution of the following cases:

| Test case      | Explanation |
| -----------    | ----------- |
| `l1=[0,1], l2=[0,1,2]`     | When one list is longer than the other.       |
| `l1=[], l2=[0,1]`   | When one list is null, which means an empty list.        |
| `l1=[9,9], l2=[1]` | The sum could have an extra carry of one at the end, which is easy to forget. |

### Implementation

#### C++:
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};
```
#### Java:
```java
class Solution {
    // Add Two Numbers (Java improved)
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        return dummyHead.next;
    }
}
```
#### Python:
```python
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        curr = dummyHead
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0
            columnSum = l1Val + l2Val + carry
            carry = columnSum // 10
            newNode = ListNode(columnSum % 10)
            curr.next = newNode
            curr = newNode
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummyHead.next
```

### Complexity Analysis

* Time complexity : `O(max⁡(m,n))`. Assume that mmm and nnn represents the length of `l1` and `l2` respectively, the algorithm above iterates at most `max⁡(m,n)` times.

* Space complexity : `O(max⁡(m,n))`. The length of the new list is at most `max⁡(m,n)+1`.

### Follow up

What if the the digits in the linked list are stored in non-reversed order? For example:

`(3→4→2)+(4→6→5)=8→0→7`