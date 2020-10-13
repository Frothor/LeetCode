# LeetCode Sort List Solution
## Overview
The problem is to sort the linked list in ***O(nlogn)*** time and using only constant extra space. If we look at various sorting algorithms, [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort) is one of the efficient sorting algorithms that is popularly used for sorting the linked list. The merge sort algorithm runs in ***O(nlogn)*** time in all the cases. Let's discuss approaches to sort linked list using merge sort.

>[Quicksort](https://en.wikipedia.org/wiki/Quicksort) is also one of the efficient algorithms with the average time complexity of ***O(nlogn)***. But the worst-case time complexity is ***O(n^2)***. Also, variations of the quick sort like randomized quicksort are not efficient for the linked list because unlike arrays, random access in the linked list is not possible in ***O(1)*** time. If we sort the linked list using quicksort, we would end up using the head as a pivot element which may not be efficient in all scenarios.

## Approach 1: Top Down Merge Sort
### Intuition

Merge sort is a popularly known algorithm that follows the [Divide and Conquer Strategy](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm). The divide and conquer strategy can be split into 2 phases:

*Divide phase:* Divide the problem into subproblems.

*Conquer phase:* Repeatedly solve each subproblem independently and combine the result to form the original problem.

The Top Down approach for merge sort recursively splits the original list into sublists of equal sizes, sorts each sublist independently, and eventually merge the sorted lists. Let's look at the algorithm to implement merge sort in Top Down Fashion.

### Algorithm

* Recursively split the original list into two halves. The split continues until there is only one node in the linked list (Divide phase). To split the list into two halves, we find the middle of the linked list using the Fast and Slow pointer approach as mentioned in [Find Middle Of Linked List](https://leetcode.com/problems/middle-of-the-linked-list/).

* Recursively sort each sublist and combine it into a single sorted list. (Merge Phase). This is similar to the problem [Merge two sorted linked lists](https://leetcode.com/problems/merge-two-sorted-lists/)

The process continues until we get the original list in sorted order.

For the linked list = `[10,1,60,30,5]`, the following figure illustrates the merge sort process using a top down approach.

![topDown_merge_sort](images/topDown_merge_sort.png)

If we have sorted lists, list1 = `[1,10]` and list2 = `[5,30,60]`. The following animation illustrates the merge process of both lists into a single sorted list.

#### 1
![1](images/1.png)

#### 2
![2](images/2.png)

#### 3
![3](images/3.png)

#### 4
![4](images/4.png)

#### 5
![5](images/5.png)

#### 6
![6](images/6.png)

#### 7
![7](images/7.png)

#### 8
![8](images/8.png)

#### 9
![9](images/9.png)

### C++
```c++

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};
```

### Java
```java

class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode mid = getMid(head);
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        return merge(left, right);
    }

    ListNode merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode tail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
                tail = tail.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
                tail = tail.next;
            }
        }
        tail.next = (list1 != null) ? list1 : list2;
        return dummyHead.next;
    }

    ListNode getMid(ListNode head) {
        ListNode midPrev = null;
        while (head != null && head.next != null) {
            midPrev = (midPrev == null) ? head : midPrev.next;
            head = head.next.next;
        }
        ListNode mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
}
```

### Complexity Analysis

* Time Complexity: ***O(nlogn)***, where nn is the number of nodes in linked list. The algorithm can be split into 2 phases, Split and Merge.

Let's assume that *n* is power of *2*. For `n` = `16`, the split and merge operation in Top Down fashion can be visualized as follows

![top_down_complexity](images/top_down_time_complexity.png)

### Split

The recursion tree expands in form of a complete binary tree, splitting the list into two halves recursively. The number of levels in a complete binary tree is given log2n. For ***n=16***, number of splits = log_2(16) = 4

### Merge

At each level, we merge n nodes which takes O(n) time. For n = 16n=16, we perform merge operation on 1616 nodes in each of the 44 levels.

So the time complexity for split and merge operation is ***O(nlogn)***

* Space Complexity: ***O(logn)***, where nn is the number of nodes in linked list. Since the problem is recursive, we need additional space to store the recursive call stack. The maximum depth of the recursion tree is ***logn***

## Approach 2: Bottom Up Merge Sort
### Intuition

The Top Down Approach for merge sort uses ***O(logn)*** extra space due to recursive call stack. Let's understand how we can implement merge sort using constant extra space using Bottom Up Approach.

The Bottom Up approach for merge sort starts by splitting the problem into the smallest subproblem and iteratively merge the result to solve the original problem.

* First, the list is split into sublists of size 1 and merged iteratively in sorted order. The merged list is solved similarly.

* The process continues until we sort the entire list.

This approach is solved iteratively and can be implemented using constant extra space. Let's look at the algorithm to implement merge sort in Bottom Up Fashion.

### Algorithm

Assume, *n* is the number of nodes in the linked list.

* Start with splitting the list into sublists of size 1. Each adjacent pair of sublists of size `1` is merged in sorted order. After the first iteration, we get the sorted lists of size `2`. A similar process is repeated for a sublist of size `2`. In this way, we iteratively split the list into sublists of size `1,2,4,8` and so on until we reach `n`.

* To split the list into two sublists of given `size` beginning from `start`, we use two pointers, `mid` and `end` that references to the start and end of second linked list respectively. The split process finds the middle of linked lists for the given `size`.

* Merge the lists in sorted order as discussed in ***Approach*** 1

* As we iteratively split the list and merge, we have to keep track of the previous merged list using pointer `tail` and the next sublist to be sorted using pointer `nextSubList`.

For the linked list = `[10,1,30,2,5]`, the following figure illustrates the merge sort process using a Bottom Up approach.

![bottom_up_merge_sort](images/bottom_up_merge_sort.png)

### C++
```c++

class Solution {
public:
    ListNode* tail = new ListNode();
    ListNode* nextSubList = new ListNode();

    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next)
            return head;
        int n = getCount(head);
        ListNode* start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next || end->next); index++) {
            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next) {
                midPrev = midPrev->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};
```

### Java
```java

class Solution {
    ListNode tail = new ListNode();
    ListNode nextSubList = new ListNode();

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        int n = getCount(head);
        ListNode start = head;
        ListNode dummyHead = new ListNode();
        for (int size = 1; size < n; size = size * 2) {
            tail = dummyHead;
            while (start != null) {
                if (start.next == null) {
                    tail.next = start;
                    break;
                }
                ListNode mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode split(ListNode start, int size) {
        ListNode midPrev = start;
        ListNode end = start.next;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev.next != null || end.next != null); index++) {
            if (end.next != null) {
                end = (end.next.next != null) ? end.next.next : end.next;
            }
            if (midPrev.next != null) {
                midPrev = midPrev.next;
            }
        }
        ListNode mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode newTail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
                newTail = newTail.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
                newTail = newTail.next;
            }
        }
        newTail.next = (list1 != null) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next != null) {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode head) {
        int cnt = 0;
        ListNode ptr = head;
        while (ptr != null) {
            ptr = ptr.next;
            cnt++;
        }
        return cnt;
    }
}
```

### Complexity Analysis

* Time Complexity: ***O(nlogn)***, where *n* is the number of nodes in linked list. Let's analyze the time complexity of each step:

1. Count Nodes - Get the count of number nodes in the linked list requires ***O(n)*** time.

2. Split and Merge - This operation is similar to ***Approach 1*** and takes ***O(nlogn)*** time. For `n = 16`, the split and merge operation in Bottom Up fashion can be visualized as follows

![bottom_up_time_complexity](images/bottom_up_time_complexity.png)

This gives us total time complexity as ***O(n)+O(nlogn)=O(nlogn)***

Space Complexity: ***O(1)*** We use only constant space for storing the reference pointers `tail` , `nextSubList` etc.

## [Python] O(n log n/ log n) merge sort, explained

This is pretty straightforward question, if you know how to use merge sort. All we need to do is to split our list into two parts, sort the first half, then sort the second half and finally merge this two parts. Here I use two axuilary function:

1. `getMid(head)`, which will find the middle of list with given `head` and cut it into two smaller lists. We use the idea of slow and fast pointers here to find middle efficiently.
2. `merge(head1, head2)` will merge two lists with given heads. To make it more readible and to avoid corner cases, it is good idea to use dummy sentinel node in the beginning of list. We iterate over two lists, using two pointers and add them one by one. When we out of nodes, we attach the rest of on of the lists to the end, we return the start of our new list.
3. `sortList(head)`: it is our original function: if list has length `0` or `1`, we do not do anything, it is corner case of our recursion. If it is not the case, we find `mid = self.getMid(head)`, which will cut our list into two smaller lists and return the start of the second list. Finally, we apply `sortList()` to `head` and to `mid` and merge two parts.

**Complexity:** Time complexity is `O(n log n)`, because it is classical complexity of merge sort. Space complexity is `O(log n)`, because we use recursion which can be `log n` deep.

```python
class Solution:
    def sortList(self, head):
        if not head or not head.next: return head
        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self.merge(left, right)
    
    def getMid(self, head):
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        mid = slow.next
        slow.next = None
        return mid
    
    def merge(self, head1, head2):
        dummy = tail = ListNode(None)
        while head1 and head2:
            if head1.val < head2.val:
                tail.next, tail, head1 = head1, head1, head1.next
            else:
                tail.next, tail, head2 = head2, head2, head2.next
    
        tail.next = head1 or head2
        return dummy.next
```

**Follow up** question askes us to do it in `O(1)` memory, and it is possible to do it, using bottom-up merge sort, which is much more difficult to implement during interview limits. What I expect that if you just explain the idea, without implementing this will be already quite good. So, idea is the following: imagine, that we have list `a1, a2, a3, a4, a5, a6, a7, a8`. Let us first sort values in pairs:
`(a1, a2), (a3, a4), (a5, a6), (a7, a8)`.
then we sort values in groups by `4`, mergin our pairs:
`(a1, a2, a3, a4), (a5, a6, a7, a8)`.
And finally we merge them in one group of `9`. It is more difficult to implement and I will add code later.

[Link to original post](https://leetcode.com/problems/sort-list/discuss/892759/Python-O(n-log-n-log-n)-merge-sort-explained)