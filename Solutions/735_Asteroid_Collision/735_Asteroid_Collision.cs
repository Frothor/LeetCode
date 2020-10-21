//Third fastest
public class Solution {
    public int[] AsteroidCollision(int[] asteroids) {
        var stack = new Stack<int>();
        
        foreach(var asteroid in asteroids) {
            if(stack.Count == 0 || Colliding(stack.Peek(), asteroid) == false) 
                stack.Push(asteroid);
            else {
                var next = asteroid;
                while(stack.Count > 0 && Colliding(stack.Peek(), next) == true) {
                    var curr = stack.Pop();
                    
                    var A = Math.Abs(curr);
                    var B = Math.Abs(next);
                    
                    if(A == B) {
                        next = 0;
                        break;
                    }
                    
                    next = A > B ? curr : next;
                }
                if(next != 0) stack.Push(next);
            }
        }
        
        var result = stack.ToArray();
        Array.Reverse(result);
        
        return result;
    }
    
    bool SameDir(int a, int b) => (a<0 && b<0) || (a>0 && b>0);
    
    bool Colliding(int a, int b) => a > 0 && b < 0;
}

//Second fastest
public class Solution {
    public int[] AsteroidCollision(int[] asteroids) 
    {
        var stack = new Stack<int>();
        foreach(var curr in asteroids)
        {
            if (!stack.Any() || curr >= 0)
            {
                stack.Push(curr);
                continue;
            }
            
            // curr < 0,
            while(stack.Any() && stack.Peek() > 0 && stack.Peek() < -curr)
            {
                stack.Pop();
            }
            
            if (stack.Any() && stack.Peek() == -curr)
            {
                stack.Pop();
                continue;
            }
            
            if (stack.Any() && stack.Peek() > -curr)
            {
                continue;
            }
                                        
            stack.Push(curr);
        }
        
        var n = stack.Count();
        var ret = new int[n];
        for(var i = n-1; i>=0; i--)
        {
            ret[i] = stack.Pop();
        }
        
        return ret;
    }
}

//Fastest
public class Solution {
    public int[] AsteroidCollision(int[] asteroids) {
        int len = asteroids.Length;
        Stack<int> stack = new Stack<int>();
        stack.Push(asteroids[0]);
        
        for (int i = 1; i < len; i++) {
            if (stack.Count == 0 || stack.Peek() < 0 || asteroids[i] > 0) {
                stack.Push(asteroids[i]);
                continue;
            }
            
            while (stack.Count > 0) {
                int diff = stack.Peek() + asteroids[i];
                if (diff == 0) {
                    stack.Pop();
                    break;                    
                }
                if (diff < 0) {
                    stack.Pop();
                    if (stack.Count == 0 || stack.Peek() < 0) {
                        stack.Push(asteroids[i]);
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        
        int[] result = new int[stack.Count];
        int index = stack.Count-1;
        while (stack.Count > 0)
            result[index--] = stack.Pop();
        return result;
    }
}

//Another fastest
public class Solution {
    public int[] AsteroidCollision(int[] asteroids) {
        //9:47
        
        var output = new Stack<int>();
        for(int index = 0 ; index<asteroids.Length;index++)
        {
            var currentAsteroid = asteroids[index];
            
           
            while(output.Any() && 
                  output.Peek() > 0 && currentAsteroid<0 &&  //check direction
                   output.Peek() < Math.Abs(currentAsteroid)) // check size
                 
            {
                output.Pop(); //Last in the row explode
            }
            
            if(output.Any() && output.Peek() > 0 && currentAsteroid<0 && output.Peek()==Math.Abs(currentAsteroid)) //Both explodes
            {
                output.Pop();
            }
            
            else if(output.Any() && 
                  output.Peek() > 0 && currentAsteroid<0 &&  //check direction
                   output.Peek() > Math.Abs(currentAsteroid)) // check size
            {
                continue;
            }
            else
            {
                output.Push(currentAsteroid);
            }
           
        }
        
        return output.Reverse().ToArray();
    }
}