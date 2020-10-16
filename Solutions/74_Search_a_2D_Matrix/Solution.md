# LeetCode 74 Search a 2D Matrix
## [C++] Stair search | O(n + m) time
### Approach 1
The brute force approach is to search the entire matrix which will get us to a `O(nm)` solution.

### Approach 2
We are told that in the matrix, each row and each column is sorted. Maybe we should use this constraint to optimize our solution. For each row we could perform a binary search which will get us to a `O(n log m)` solution. We could further improve this approach to get us to a `O(min(n, m) log(max(n, m))` solution.

### Approach 3
In approach 2, we are ignoring the fact that each column is also sorted. This should force us to even more optimize the solution. The algtorithm is as follows:

* We start searching from the top right corner of the matrix.
* If target is found we return true;;
* If target is less than the current value, we move 1 step to the left. (Because, we know the matrix is column-wise sorted, so target cannot be in the current column)
* If target is greater than the current value, we move 1 step below. (Because, we know that matrix is row-wise sorted, so target cannot be anywhere in the current row)

```c++
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) {
		return false;
	}
	int i = 0;
	int j = matrix[0].size() - 1;

	while (i < matrix.size() && j >= 0) {
		if (matrix[i][j] == target) {
			return true;
		} else if (target < matrix[i][j]) {
			j--;
		} else {
			i++;
		}
	}
	return false;
}
```

Time complexity - `O(n + m)`
Space complexity - `O(1)`
*(Note: n = number of rows; m = number of columns)*

[Linkt to original post](https://leetcode.com/problems/search-a-2d-matrix/discuss/896744/C%2B%2B-Stair-search-or-O(n-%2B-m)-time)

## [Python] Simple binary search, explained
What we have in this problem is matrix, which is sorted and what we use to find element in sorted structure? Correct, this is binary search. Imagine, that we have matrix

```
10 11 12 13
14 15 16 17
18 19 20 21
```

Let us flatten this matrix, so now we have `10 11 12 13 14 15 16 17 18 19 20 21` and do binary search in this list. However if you do it, we will have `O(mn)` complexity, so we will use **virtual** flatten: we do not do it for all matrix, but only for elements we need: if we need element number `i` from our flattened list, it coresponds to element `matrix[i//m][i%m]` in our matrix.

**Complexity:** time complexity is O(log mn), space complexity is O(1).

```python
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]: return False
        m, n = len(matrix[0]), len(matrix)
        beg, end = 0, m*n - 1
        while beg < end:
            mid = (beg + end)//2
            if matrix[mid//m][mid%m] < target:
                beg = mid + 1
            else:
                end = mid
        return matrix[beg//m][beg%m] == target
```

[Link to original post](https://leetcode.com/problems/search-a-2d-matrix/discuss/896821/Python-Simple-binary-search-explained)