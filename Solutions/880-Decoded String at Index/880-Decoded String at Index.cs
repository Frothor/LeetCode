//Idea -> https://leetcode.com/problems/decoded-string-at-index/discuss/979623/C%2B%2B-TimeSpace%3A-O(N)-O(1)-greedy-simulation
public class Solution {
    public string DecodeAtIndex(string S, int K) {
        long N = 0;
        int i = 0;
        
        for(; N<K; i++)
            N = Char.IsDigit(S[i]) ? N * (S[i] - '0') : N+1;
        
        while(i-- > 0){
            if(Char.IsDigit(S[i])){
                N /= S[i] - '0';
                K = (int)(((long)K)%N);
            }
            else if(K % N-- == 0){
                return S[i].ToString();
            }
        }
        
        return string.Empty;
    }
}

//Third fastest
public class Solution {
    public string DecodeAtIndex(string S, int K) {
        long len = 0;
        Stack<char> stack = new Stack<char>();
        int index = 0;
        long longK = K;
        while (len < longK)
        {
            char c = S[index++];
            if ('a' <= c && c <= 'z')
            {
                stack.Push(c);
                len++;
            }
            else
            {
                stack.Push(c);
                len = len * (c - '0');
            }
        }
        
        while (!(stack.Peek() >= 'a' && stack.Peek() <= 'z' && len == longK))
        {
            char c = stack.Pop();
            if (c >= 'a' && c<='z')
            {
                len--;
            }
            else
            {
                int times = c - '0';
                len /= times;
                longK = (longK % len == 0) ? len : longK % len;
            }
        }
        
        return stack.Peek().ToString();
    }
}

//Second fastest
public class Solution {
    public string DecodeAtIndex(string S, int K) {
        long size = 0, k =(long) K;
        for (int i = 0; i < S.Length; i++) 
        {
            if (char.IsDigit(S[i])) 
            {
                size *= S[i] - '0';
            }
            else 
            {
                size++;
            }
        }

        for (var i = S.Length - 1; i >= 0; i--) 
        {
            k %= size;
            var c = S[i];
            if (k == 0 && !char.IsDigit(c)) return c.ToString();
            if (char.IsDigit(c)) 
            {
                size /= c - '0';
            }
            else 
            {
                size --;
            }
        }
        throw new Exception();
    }
}

//Fastest
public class Solution {
    public string DecodeAtIndex(string S, int K) 
    {
            long size = 0;
            //calculate the length of the decoded string
            for(int i = 0; i < S.Length; i++)
            {
                if (Char.IsLetter(S[i]))
                    size++;
                else
                    size = size * (S[i] - 48);
            }

            for(int i = S.Length - 1; i >= 0; i--)
            {
                K = Convert.ToInt32(K % size);
                if (K == 0 && Char.IsLetter(S[i]))
                    return S[i].ToString();

                else if (Char.IsDigit(S[i]))
                    size = size / (S[i] - '0');

                else
                    size--;
            }

            return "";  
    }
}