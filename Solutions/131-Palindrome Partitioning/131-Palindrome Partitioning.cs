//https://leetcode.com/problems/palindrome-partitioning/discuss/383007/C-DFS-Backtracking
public class Solution {
   public IList<IList<string>> Partition(string s)
        {
            var result = new List<IList<string>>();
            if (s == null || s.Length == 0) return result;

            Helper(s, result, new List<string>(), 0);
            return result;
        }

        private void Helper(string s, List<IList<string>> result, List<string> p, int startIndex)
        {
            var partition = new List<string>(p);
            if (startIndex == s.Length)
            {
                result.Add(partition);
                return;
            }

            for (var i = startIndex; i < s.Length; i++)
            {
                var sub = s.Substring(startIndex, i- startIndex + 1);   // java's substring(startIndex, endIndex)      C#'s Substring(startIndex, SubLength)
                if (!IsPalindrome(sub)) continue;
                partition.Add(sub);
                Helper(s, result, partition, i + 1);
                partition.RemoveAt(partition.Count() - 1);       // Better to write as RemoveAt , but not Remove(x.Last()) cuz sometime it may remove the first element
            }

        }


        private bool IsPalindrome(string str)
        {
            for (int i = 0, j = str.Length - 1; i < j;)
            {
                if (str[i++] != str[j--]) return false;
            }
            return true;
        }
}

//Third fastest
public class Solution {

        public IList<IList<string>> Partition(string s)
        {
            input = s;
            SolveRecursive(-1);

            return finalResult;
        }

        string input;
        IList<IList<string>> finalResult = new List<IList<string>>();
        List<string> backtrack = new List<string>();
        void SolveRecursive(int prevEndIndex)
        {
            if (prevEndIndex == input.Length - 1)
            {
                finalResult.Add(backtrack.ToList());
                return;
            }

            int startIndex = prevEndIndex + 1;

            backtrack.Add(input[startIndex].ToString());
            SolveRecursive(startIndex);
            backtrack.RemoveAt(backtrack.Count - 1);


            int endIndex = startIndex + 1;
            while (endIndex < input.Length)
            {
                if (CheckStringForPalindrome(startIndex, endIndex))
                {
                    backtrack.Add(input.Substring(startIndex, endIndex - startIndex + 1));
                    SolveRecursive(endIndex);
                    backtrack.RemoveAt(backtrack.Count - 1);
                }
                endIndex++;
            }
        }

        bool CheckStringForPalindrome(int startIndex, int endIndex)
        {
            while (startIndex < endIndex)
            {
                if (input[startIndex++] != input[endIndex--])
                {
                    return false;
                }
            }
            return true;
        }
}

//Second fastest
public class Solution {
    public IList<IList<string>> Partition(string s) {
        IList<IList<string>> result = new List<IList<string>>();
        if(string.IsNullOrEmpty(s))
        {
            return result;
        }
        Partition(s, 0, new List<string>(), result);
        return result;
        
    }
    
    private void Partition(string s, int start, IList<string> cur, IList<IList<string>> result)
    {
        if(start >= s.Length)
        {
            result.Add(cur);
            return;
        }
        for(int i=start; i<s.Length;i++)
        {
            if(isPalindrome(s, start, i))
            {
                IList<string> newCur = new List<string>(cur);
                newCur.Add(s.Substring(start, i-start+1));
                Partition(s, i+1, newCur, result);
            }
        }
    }
    
    
    private bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    } 
}

//Fastest
public class Solution
{
    public List<IList<string>> Partition(string value)
    {
        var output = new List<IList<string>>();
        Partition(value, 0,new List<string>(), output);
        return output;
    }

        private void Partition(string input, int startIndex, List<string> current, List<IList<string>> output)
        {
            if (startIndex >= input.Length)
                output.Add(new List<string>(current));
            else
                for (var endIndex = startIndex + 1; endIndex <= input.Length; endIndex++)
                {
                    var potentialPalindrome = input.Substring(startIndex, endIndex - startIndex);
                    if (CheckPalindrome(potentialPalindrome))
                    {
                        current.Add(potentialPalindrome);
                        Partition(input, endIndex, current, output);
                        current.RemoveAt(current.Count - 1);
                    }
                }
        }

    private bool CheckPalindrome(string input)
    {
        var startIndex = 0;
        var endIndex = input.Length - 1;
        while (startIndex < endIndex)
        {
            if (input[startIndex++] != input[endIndex--]) return false;
        }

        return true;
    }
}