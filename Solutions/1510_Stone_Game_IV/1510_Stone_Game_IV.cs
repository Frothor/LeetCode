//Most common
public class Solution
{
    private bool?[] dp = new bool?[100001];
    
    public bool WinnerSquareGame(int n)
    {
        bool? saved = dp[n];
        if(saved.HasValue) return saved.Value;
        
        var sqrt = Math.Sqrt(n);
        var floor = Math.Floor(sqrt);
        if(sqrt == floor) return true;
        
        bool result = false;
        for(int i = (int) floor; i >= 1; i--)
        {
            if(WinnerSquareGame(n - i*i)) continue;
            result = true;
            break;           
        }
        
        dp[n] = result;
        return result;
    }
}

//Second fastest
public class Solution {
    public bool WinnerSquareGame(int n) {
        var w = new bool[n+1];
        
        //w[0]=false;
        
        for(int i=1;i<=n;i++){
            //w[i]=false;
            for(int j=1;j*j<=i;j++){
                if(w[i-j*j]==false){
                    w[i]=true;
                    break;
                }
            }
        }
        
        return w[n];
    }
}

//Fastest
/*

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.

General Approach 1:
DFS with Memorization

Logic: Check if next player will lose by going through all possible moves and then checking if Bob will win with remaining stones for each possible Alice move. If for any of Alice's moves that Bob can't win on his move with remaining stones, then we know Alice must win, and we can return true.

Complexity:
tO(N sqrt N) since we spend O(sqrtN) at most for each DFS call, and there are O(N) dfs calls in total
sO(N) since we need O(N) spaces to store result of DFS

//General Approach 2:
Dynamic Programming

Very similar to DFS approach, but instead we use DP.

We can use single dp[i] array to store whether the player now removing stones wins with i stones remaining

Algorithm:
Let dp[i] reprsent the result of the game with i stones
if dp[i] == true, it means curent player must win.
if dp[i] == false, it means current player must lose

How do we calculate dp[i]?

We can iterate through all possible movements, and check if we can move to a false state. If we can, then we found a must-win strategy, otherwise, we must lsoe since the opponent has a must-win because by process of elimination, if you have no winnable moves, you must lose.

More clearl,y we can iterate k from 0, and check if there exists a dp[i-k*k] == false. Of course, i - k*k >= 0.

Finally, we only need to return dp[n]

Can we do this ina  backtrack way instead?

If we have a state i that we know the current player must lose, what can we infer
Any other states that can move to state i, must be true. As in, if Alice has any moves that can get to state i, where i is a must-lose, that must mean that the move ALice made is a must-win, which means she must-win.

Let's say in another state j the current player in j can go to i by removing stones.
In this ase, the state j is true since the current player must iwn.

How do we find state j? We can iterate over the square numbers and add them to i.

Let dp[i] represent the result of the game of i stones
dp[i] == true means Alice must win
dp[i] ==  false meansBob must win.

When we get to a false state, we mark all accessible states that can get to that false state, as true.

When we get to a true state, we just continue... why? Because it's useless.

Finally, we return dp[n]

*/

public class Solution {
    public bool WinnerSquareGame(int n)
    {
        bool[] dp = new bool[n+1];
        for(int i = 0; i <= n; i++)
        {
            if (dp[i])
            {
                continue;
            }
            for (int k = 1; i + k * k <= n; k++)
            {
                dp[i + k*k] = true;
            }
        }
        return dp[n];
    }
}