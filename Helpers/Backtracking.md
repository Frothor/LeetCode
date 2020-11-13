# Backtracking
In this article, we introduce another paradigm called backtracking, which is also often implemented in the form of recursion.

>Backtracking is a general algorithm for finding all (or some) solutions to some computational problems (notably Constraint satisfaction problems or CSPs), which incrementally builds candidates to the solution and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot lead to a valid solution.**[1]** 

![backtracking](images/backtracking.png)

Conceptually, one can imagine the procedure of backtracking as the ***tree traversal***. Starting from the root node, one sets out to search for solutions that are located at the leaf nodes. Each intermediate node represents a ***partial*** candidate solution that could potentially lead us to a final valid solution. At each node, we would fan out to move one step further to the final solution, i.e. we iterate the child nodes of the current node. Once we can determine if a certain node cannot possibly lead to a valid solution, we abandon the current node and ***backtrack*** to its parent node to explore other possibilities. It is due to this backtracking behaviour, the backtracking algorithms are often much faster than the ***[brute-force search](https://en.wikipedia.org/wiki/Brute-force_search) [2]*** algorithm, since it eliminates many unnecessary exploration. 

 

## Example 1
Let's try to understand the concept of backtracking by a very basic example. We are given a set of words represented in the form of a tree. The tree is formed such that every branch ends in a word.

![Word Tree](images/backtracking1.jpeg)

Our task is to find out if a given word is present in the tree. Let's say we have to search for the word **AIM**. A very brute way would be to go down all the paths, find out the word corresponding to a branch and compare it with what you are searching for. You will keep doing this unless you have found out the word you were looking for.

![Brute](images/backtracking2.jpeg)

In the diagram above our brute approach made us go down the path for **ANT** and **AND** before it finally found the right branch for the word **AIM**.

The backtracking way of solving this problem would stop going down a path when the path doesn't seem right. When we say the path doesn't seem right we mean we come across a node which will never lead to the right result. As we come across such node we **back-track**. That is go back to the previous node and take the next step.

![Brute](images/backtracking3.jpeg)

In the above diagram backtracking didn't make us go down the path from node **N**. This is because there is a mismatch we found early on and we decided to go back to the next step instead. Backtracking reduced the number of steps taken to reach the final result. This is known as **pruning** the recursion tree because we don't take unnecessary paths.

## Example 2
One of the most classical problems that can be solved with the backtracking algorithm is the N-Queen puzzle.

>The N-queens puzzle is the problem of placing ***N*** queens on an ***[N×N]*** chessboard such that no two queens can attack each other. One is asked to count the number of solutions to place the ***N*** queens on the board. 

As a reminder, a queen can attack any piece that is situated at the same row, column or diagonal of the queue. As shown in the board below, if we place a queen at the row 1 and column 1 of the board, we then cross out all the cells that could be attached by this queen. 

![n_queue_constraint](images/n_queue_constraint.png)

In order to count the number of possible solutions to place the N queens, we can break it down into the following steps:

1. Overall, we iterate over each row in the board, *i.e.* once we reach the last row of the board, we should have explored all the possible solutions.

2. At each iteration (we are located at certain row), we then further iterate over each column of the board, along the current row. At this second iteration, we then can ***explore*** the possibility of placing a queen on a particular cell.

3. Before, we place a queen on the cell with index of (row, col), we need to check if this cell is under the attacking zone of the queens that have been placed on the board before. Let us assume there is a function called `is_not_under_attack(row, col)` that can do the check.

4. Once the check passes, we then can proceed to place a queen. Along with the placement, one should also mark out the attacking zone of this newly-placed queen. Let us assume there is another function called `place_queen(row, col)` that can help us to do so.

5. As an important behaviour of backtracking, we should be able to abandon our previous decision at the moment we decide to move on to the next candidate. Let us assume there is a function called `remove_queen(row, rol)` that can help us to revert the decision along with the changes in step (4). 

Now, with the above steps and functions, we can organize them in the form of recursion in order to implement the algorithm. In the following, we present the pseudocode of the backtracking algorithm.

### Python
```python
def backtrack_nqueen(row = 0, count = 0):
    for col in range(n):
        # iterate through columns at the curent row.
        if is_not_under_attack(row, col):
            # explore this partial candidate solution, and mark the attacking zone
            place_queen(row, col)
            if row + 1 == n:
                # we reach the bottom, i.e. we find a solution!
                count += 1
            else:
                # we move on to the next row
                count = backtrack(row + 1, count)
            # backtrack, i.e. remove the queen and remove the attacking zone.
            remove_queen(row, col)
    return count
```



By filling out those above-mentioned functions, one should be able to implement his/her own algorithm to solve the N-queen problem. ***Note:*** one can find the exercise of N-queen problem later in this chapter.

## References 
- [1]. [Backtracking](https://en.wikipedia.org/wiki/Backtracking). Wikipedia.

- [2]. [Brute-force search](https://en.wikipedia.org/wiki/Brute-force_search). Wikipedia.