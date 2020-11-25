//c# - shunting-yard algorithm
//https://leetcode.com/problems/basic-calculator-ii/discuss/695314/c-shunting-yard-algorithm
/*
Use shunting-yard algorithm. It can fit problem 224, 227 and 772.

read this wiki (https://en.wikipedia.org/wiki/Shunting-yard_algorithm) to understand shunting-yard algo.
rpn is reverse polish notation (https://en.wikipedia.org/wiki/Reverse_Polish_notation)
*/
public class Solution {
    public int Calculate(string s) {
        if (s == null || s == string.Empty)
            return 0;
        
        Stack<string> rpn = new Stack<string>(),
                      opt = new Stack<string>();
        int j = 0;
        
        s = s.Trim().Replace(" ", string.Empty);
        
        for (int i = 0; i < s.Length; i++)
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else if (s[i] == '+' || s[i] == '-')
            {
                rpn.Push(s.Substring(j, i - j));
                
                while (opt.Count > 0)
                {
                    string v2 = rpn.Pop(),
                           v1 = rpn.Pop();
                    
                    rpn.Push(Cal(v1, v2, opt.Pop()).ToString());
                }
                
                opt.Push(s[i].ToString());
                j = i + 1;
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                rpn.Push(s.Substring(j, i - j));
                
                while (opt.Count > 0 && opt.Peek() != "+" && opt.Peek() != "-")
                {
                    string v2 = rpn.Pop(),
                           v1 = rpn.Pop();
                    
                    rpn.Push(Cal(v1, v2, opt.Pop()).ToString());
                }
                
                opt.Push(s[i].ToString());
                j = i + 1;
            }
        
        rpn.Push(s.Substring(j, s.Length - j));
        
        while (opt.Count > 0)
        {
            string v2 = rpn.Pop(),
                   v1 = rpn.Pop();
                    
            rpn.Push(Cal(v1, v2, opt.Pop()).ToString());
        }
        
        return Convert(rpn.Peek());
    }
    
    private int Cal(string v1, string v2, string opt)
    {
        int result = 0;
        
        if (opt == "+")
            result = Convert(v1) + Convert(v2);
        else if (opt == "-")
            result = Convert(v1) - Convert(v2);
        else if (opt == "*")
            result = Convert(v1) * Convert(v2);
        else if (opt == "/")
            result = Convert(v1) / Convert(v2);
            
        return result;
    }
    
    private int Convert(string s)
    {
        int i = 0,
            j = s[0] == '-' ? 1 : 0;
        
        for (; j < s.Length; j++)
            i = i * 10 + (s[j] - '0');
        
        return s[0] == '-' ? i * -1 : i;
    }
}

//Fourth fastest
public class Solution
{
  public int Calculate2(string s)
  {
    if(s == null || s.Length == 0)
      return 0;
    
    List<object> postfix = InfixToPostfix2(s);
    Stack<int> st = new Stack<int>();
    
    foreach(object obj in postfix)
    {
      if(obj is int)
      {
        st.Push((int)obj);
      }
      else
      {
        char op = (char)obj;
        int x = st.Pop();
        int y = st.Pop();
        
        switch(op)
        {
          case '*':
            st.Push(x*y);
            break;
          case '/':
            st.Push(y/x);
            break;
          case '+':
            st.Push(x+y);
            break;
          case '-':
            st.Push(y-x);
            break;
        }
      }
    }
    
    return st.Pop();      
  }
  
  public int Calculate(string s)
  {
    if(s == null || s.Length == 0)
      return 0;
  
    return InfixToPostfix(s);
  }
  
  private int InfixToPostfix(string s)
  {
    Stack<int> nums = new Stack<int>();
    Stack<char> st = new Stack<char>();
    
    for(int i=0; i<s.Length; i++)
    {
      if(s[i] == ' ')
        continue;
      
      if(char.IsDigit(s[i]))
      {
        int num = 0;
        
        while(i<s.Length && char.IsDigit(s[i]))
        {
          num = (num*10)+(s[i]-'0');
          i++;
        }
        i--;
        nums.Push(num);
      }
      else
      {
        while(st.Count > 0 && Prec(s[i]) <= Prec(st.Peek()))
        {
          int x = nums.Pop();
          int y = nums.Pop();
          int w = Compute(st.Pop(), y, x);
          //Console.WriteLine(x + " " + y + " " + w);
          nums.Push(w);
        }
        st.Push(s[i]);
      }
    }
    /*
    Console.WriteLine();
    foreach(int n in nums)
      Console.Write(n + " ");
    Console.WriteLine();*/
    
    while(st.Count > 0)
    {
      int x = nums.Pop();
      int y = nums.Pop();
      int w = Compute(st.Pop(), y, x);
      //Console.WriteLine("---> " + x + " " + y + " " + w);
      nums.Push(w);
    }
    
    return nums.Pop();
  }
  
  private int Compute(char op, int x, int y)
  {
    switch(op)
    {
      case '*':
        return x*y;
        break;
      case '/':
        return x/y;
        break;
      case '+':
        return x+y;
        break;
      case '-':
        return x-y;
        break;
    }
    return 0;
  }
  
  private List<object> InfixToPostfix2(string s)
  {
    List<object> res = new List<object>();
    Stack<char> st = new Stack<char>();
    
    for(int i=0; i<s.Length; i++)
    {
      if(s[i] == ' ')
        continue;
      
      if(char.IsDigit(s[i]))
      {
        int num = 0;
        
        while(i<s.Length && char.IsDigit(s[i]))
        {
          num = (num*10)+(s[i]-'0');
          i++;
        }
        i--;
        res.Add(num);
      }
      else
      {
        while(st.Count > 0 && Prec(s[i]) <= Prec(st.Peek()))
        {
          res.Add(st.Pop());
        }
        st.Push(s[i]);
      }
    }
    
    while(st.Count > 0)
    {
      res.Add(st.Pop());
    }
    
    return res;
  }
  
  private int Prec(char op)
  {
    switch(op)
    {
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
        return 2;
      default:
        return 0;
    }
  }
}

//Third fastest
public class Solution {
    public int Calculate(string s) {
        
        if(s == null || s.Length == 0) return 0;
        
        Stack<int> stack = new Stack<int>();
        int  curr =0;
        char op ='+';
        
       for (int i = 0; i < s.Length; i++) {
        
            char c = s[i];
            if(Char.IsDigit(c)) curr = (curr*10) + (c -'0');
            
            if(!Char.IsDigit(c) && !Char.IsWhiteSpace(c) || i== s.Length-1)
            {
                if(op =='-') stack.Push(-curr);
                else if(op =='+')  stack.Push(curr);
                else if(op == '*')  stack.Push(stack.Pop() * curr);
                else if(op == '/')  stack.Push(stack.Pop() / curr);
                op = c;
                curr = 0;
            }
           
          
        }
        
        int result = 0;
        while (stack.Count != 0) {
            result += stack.Pop();
        }
        return result;
        
    }
}

//Secon fastest
public class Solution {
    public int Calculate(string s) {
        if(s == null || s.Length == 0) return 0;
        
        int currentNumber = 0, lastNumber = 0, result = 0;
        char operation = '+';
        
        for(int i = 0; i < s.Length; i++) {
            char currentChar = s[i];
            if(Char.IsDigit(currentChar)) {
                // char - '0' to get int
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if(!Char.IsDigit(currentChar) && !Char.IsWhiteSpace(currentChar) || i == s.Length - 1) {
                if(operation == '+' || operation == '-') {
                    result += lastNumber;
                    lastNumber = (operation == '+') ? currentNumber : -currentNumber;
                } else if(operation == '*') {
                    lastNumber *= currentNumber;
                } else if(operation == '/') {
                    lastNumber /= currentNumber;
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
}

//Fastest
public class Solution
	{
		public int Calculate(string s)
		{
			if (s == null || s.Length == 0)
				return 0;

			Stack<int> numbers = new Stack<int>();

			int curNumber = 0;
			char operation = '+';

			for (int i = 0; i < s.Length; i++)
			{
				if (Char.IsDigit(s[i]))
				{
					curNumber = curNumber * 10 + s[i] - '0';
				}
				
				if ((!Char.IsDigit(s[i]) && s[i] != ' ') || i == s.Length - 1)
				{
					if (operation == '+')
					{
						numbers.Push(curNumber);
					}
					else if (operation == '-')
					{
						numbers.Push(0 - curNumber);
					}
					else if (operation == '*')
					{
						numbers.Push(numbers.Pop() * curNumber);
					}
					else if (operation == '/')
					{
						numbers.Push(numbers.Pop() / curNumber);
					}
					operation = s[i];
					curNumber = 0;
				}
			}

			int result = numbers.Pop();

			while (numbers.Count != 0)
			{
				result += numbers.Pop();
			}
			return result;
		}
	}