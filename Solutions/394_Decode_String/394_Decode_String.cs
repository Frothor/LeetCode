
//Fourth fastest -> https://leetcode.com/problems/decode-string/discuss/662294/c
public class Solution {
    public string DecodeString(string s) {
            if (s == null || s == string.Empty)
                return string.Empty;

            Stack<char> stack = new Stack<char>();;

            for (int i = 0; i < s.Length; i++)
                if (s[i] != ']')
                    stack.Push(s[i]);
                else
                {
                    List<char> temp = new List<char>();
                    int j = 0,
                        k = 0;

                    while (stack.Count > 0 && stack.Peek() != '[')
                        temp.Add(stack.Pop());

                    if (stack.Count > 0 && stack.Peek() == '[')
                        stack.Pop();

                    while (stack.Count > 0 && (stack.Peek() >= '0' && stack.Peek() <= '9'))
                        j += (stack.Pop() - '0') * (int)Math.Pow(10, k++);

                    for (int l = 0; l < j; l++)
                        for (int m = temp.Count - 1; m > -1; m--)
                            stack.Push(temp[m]);
                }
            
            return new string(stack.ToArray().Reverse().ToArray());
    }
}

//Third fastest
public class Solution {
    public string DecodeString(string s) {
        var sb = new StringBuilder($"1[{s}]");
        DecodeString(sb, 0);
        return sb.ToString();
    }
    
    private void DecodeString(StringBuilder sb, int startIndex){
        var k = GetAndRemoveKFromStringBuilder(sb, startIndex);
        
        var index = startIndex;
        var sbToMultiply = new StringBuilder();
        while (index < sb.Length){
            if (sb[index] == ']'){
                // reached the end of the part to multiply
                sb.Remove(index, 1);
                break;
            }            
            
            if (sb[index] < '0' || sb[index] > '9'){
                // not a digit
                sbToMultiply.Append(sb[index]);
                index++;
                continue;
            }
            
            // must be digit
            DecodeString(sb, index);
            sbToMultiply.Append(sb[index]);
            index++;            
        }
        
        if (k > 1 && sbToMultiply.Length > 0){
            for (var i = 0 ; i < k - 1; i++){
                sb.Insert(index, sbToMultiply.ToString());
            }
        }        
    }
    
    private int GetAndRemoveKFromStringBuilder(StringBuilder sb, int startIndex){
        var kIndex = startIndex;
        var kAsString = new StringBuilder();
        while (sb[startIndex] >= '0' && sb[startIndex] <= '9'){
            kAsString.Append(sb[startIndex]);
            sb.Remove(startIndex, 1);
        }
        
        // remove '['
        sb.Remove(startIndex, 1);
        
        return int.Parse(kAsString.ToString());
    }
}

//Second fastest
public class Solution {
    public string DecodeString(string s)
        {
            if (string.IsNullOrEmpty(s))
                return "";
            StringBuilder sb = new StringBuilder();
            StringBuilder sbc = new StringBuilder();
            int i = 0;
            while( i < s.Length)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    sbc.Append(s[i]);
                    i++;
                }
                else if (s[i] != '[' && s[i] != ']')
                {
                    sb.Append(s[i]);
                    i++;
                } 
                else if (s[i] == '[')
                {
                    int c = Int32.Parse(sbc.ToString());
                    sbc.Clear();
                    int l = 1, r = 0, j = i + 1;
                    while (j < s.Length)
                    {
                        if (s[j] == '[')
                            l++;
                        else if (s[j] == ']')
                        {
                            r++;
                            if (l == r)
                            {
                                string inner = DecodeString(s.Substring(i + 1, j - i - 1));
                                for (int k = 0; k < c; k++)
                                {
                                    sb.Append(inner);
                                }
                                i = r + 1;
                                break;
                            }
                        }
                        j++;
                    }
                    i = j + 1;
                }
            }
            return sb.ToString();
        }
}

//Fastest
public class Solution {
    public string DecodeString(string s) {
        int N = s.Length;
        int cur = 0;
        Stack<char> st = new Stack<char>();
        
        while (cur < N) {
            char c = s[cur++];
            
            if (']' == c) {
                string repeat = "";
                int repeat_num = 0;
                string dec = "";
                
                while ('[' != st.Peek())
                    repeat = st.Pop() + repeat;
                
                st.Pop();
                
                int i = 1;
                while (st.Count > 0 && is_digit(st.Peek())) {
                    repeat_num = repeat_num + (int)(st.Pop() - '0') * i;
                    i = i * 10;
                }
                
                while (repeat_num-- > 0) dec += repeat;
                
                foreach (char r in dec) st.Push(r);
            }
            else {
                st.Push(c);
            }
        }
        
        char[] ans = st.ToArray();
        Array.Reverse(ans);
        
        return new string(ans);
    }
    
    private bool is_digit(char c) {
        return '0' <= c && c <= '9';
    }
}