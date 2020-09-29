#Python | Recursive Bottom-Up Traversal | ~95% O(n) and Commented
class Solution:
    def maxPathSum(self, root: 'TreeNode') -> int:
        best_sum = -float('inf')                   # tracker for best sum
        def maxPath(v: 'vertex'):                  # define helper function
            nonlocal best_sum                      # reference our tracker
            if v is None:                          # base case
                return 0
            L = maxPath(v.left)                    # recurse on left child
            R = maxPath(v.right)                   # recurse on right child
            best_sum = max(best_sum, v.val+L+R)    # update tracker with subtree sum
            return max(0, v.val+L, v.val+R)        # return the best possible branch for the parent subtree
        maxPath(root)                              # run recursive traversal
        return best_sum

#ANOTHER
#We use DFS to solve this question from children to parents. For each node two values are stored:

#one_child, the max when the current node has at most one adjacent child
#curr_max, the max until the current node for global comparison
#one_child is important since it can be later added to its parent and make a path.

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
		return self.dfs(root)[1]                    # return the global max
    def dfs(self, root):
        if not root:                                # base case when root == None
            return (-inf, -inf)                     # -inf is for comparison
        left = self.dfs(root.left)                  # left child
        right = self.dfs(root.right)                # right child
        one_child = max(0, left[0], right[0]) + root.val              # include no/left/right child
        two_children = left[0] + right[0] + root.val                  # a complete path is made with two children 
        curr_max = max(one_child, two_children, left[1], right[1])    # update the max until the current node
        return (one_child, curr_max)