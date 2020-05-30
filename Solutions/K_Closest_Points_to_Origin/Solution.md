# Solution
## Approach 1: Sort
### Intuition

Sort the points by distance, then take the closest K points.

### Algorithm

There are two variants.

In Java, we find the K-th distance by creating an array of distances and then sorting them. After, we select all the points with distance less than or equal to this K-th distance.

In Python, we sort by a custom key function - namely, the distance to the origin. Afterwards, we return the first K elements of the list.

**Java**
```java
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int N = points.length;
        int[] dists = new int[N];
        for (int i = 0; i < N; ++i)
            dists[i] = dist(points[i]);

        Arrays.sort(dists);
        int distK = dists[K-1];

        int[][] ans = new int[K][2];
        int t = 0;
        for (int i = 0; i < N; ++i)
            if (dist(points[i]) <= distK)
                ans[t++] = points[i];
        return ans;
    }

    public int dist(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
}
```

**Python**
```python
class Solution(object):
    def kClosest(self, points, K):
        points.sort(key = lambda P: P[0]**2 + P[1]**2)
        return points[:K]
```

### Complexity Analysis

* Time Complexity: *O(NlogN)*, where *N* is the length of **points**.

* Space Complexity: *O(N)*.

## Approach 2: Divide and Conquer
### Intuition

We want an algorithm faster than *NlogN*. Clearly, the only way to do this is to use the fact that the K elements returned can be in any order -- otherwise we would be sorting which is at least *NlogN*.

Say we choose some random element **x = A[i]** and split the array into two buckets: one bucket of all the elements less than **x**, and another bucket of all the elements greater than or equal to **x**. This is known as "quickselecting by a pivot **x**".

The idea is that if we quickselect by some pivot, on average in linear time we'll reduce the problem to a problem of half the size.

### Algorithm

Let's do the **work(i, j, K)** of partially sorting the subarray **(points[i], points[i+1], ..., points[j])** so that the smallest **K** elements of this subarray occur in the first **K** positions **(i, i+1, ..., i+K-1)**.

First, we quickselect by a random pivot element from the subarray. To do this in place, we have two pointers **i** and **j**, and move these pointers to the elements that are in the wrong bucket -- then, we swap these elements.

After, we have two buckets **[oi, i]** and **[i+1, oj]**, where **(oi, oj)** are the original **(i, j)** values when calling **work(i, j, K)**. Say the first bucket has **10** items and the second bucket has **15** items. If we were trying to partially sort say, **K = 5** items, then we only need to partially sort the first bucket: **work(oi, i, 5)**. Otherwise, if we were trying to partially sort say, **K = 17** items, then the first **10** items are already partially sorted, and we only need to partially sort the next 7 items: **work(i+1, oj, 7)**.

**Java**
```java
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    int[][] points;
    public int[][] kClosest(int[][] points, int K) {
        this.points = points;
        sort(0, points.length - 1, K);
        return Arrays.copyOfRange(points, 0, K);
    }

    public void sort(int i, int j, int K) {
        if (i >= j) return;
        int k = ThreadLocalRandom.current().nextInt(i, j);
        swap(i, k);

        int mid = partition(i, j);
        int leftLength = mid - i + 1;
        if (K < leftLength)
            sort(i, mid - 1, K);
        else if (K > leftLength)
            sort(mid + 1, j, K - leftLength);
    }

    public int partition(int i, int j) {
        int oi = i;
        int pivot = dist(i);
        i++;

        while (true) {
            while (i < j && dist(i) < pivot)
                i++;
            while (i <= j && dist(j) > pivot)
                j--;
            if (i >= j) break;
            swap(i, j);
        }
        swap(oi, j);
        return j;
    }

    public int dist(int i) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }

    public void swap(int i, int j) {
        int t0 = points[i][0], t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }
}
```

**Python**
```python
class Solution(object):
    def kClosest(self, points, K):
        dist = lambda i: points[i][0]**2 + points[i][1]**2

        def sort(i, j, K):
            # Partially sorts A[i:j+1] so the first K elements are
            # the smallest K elements.
            if i >= j: return

            # Put random element as A[i] - this is the pivot
            k = random.randint(i, j)
            points[i], points[k] = points[k], points[i]

            mid = partition(i, j)
            if K < mid - i + 1:
                sort(i, mid - 1, K)
            elif K > mid - i + 1:
                sort(mid + 1, j, K - (mid - i + 1))

        def partition(i, j):
            # Partition by pivot A[i], returning an index mid
            # such that A[i] <= A[mid] <= A[j] for i < mid < j.
            oi = i
            pivot = dist(i)
            i += 1

            while True:
                while i < j and dist(i) < pivot:
                    i += 1
                while i <= j and dist(j) >= pivot:
                    j -= 1
                if i >= j: break
                points[i], points[j] = points[j], points[i]

            points[oi], points[j] = points[j], points[oi]
            return j

        sort(0, len(points) - 1, K)
        return points[:K]
```


### Complexity Analysis

* Time Complexity: *O(N)* in average case and *O(N^2)* in the worst case, where *N* is the length of **points**.

* Space Complexity: *O(N)*.