public class Solution {
    public  IList<int> SequentialDigits(int low, int high)
        {
            var res = new List<int>();
            int len = low.ToString().Length, maxLen = high.ToString().Length;
            for (; len <= maxLen; len++)
            for (int j = 1; j <= 9; j++)
            {
                var builder = new StringBuilder();
                for (int i = j; i < j + len && i <= 9; i++)
                    builder.Append(i);
                if (builder.Length == len && int.TryParse(builder.ToString(), out int num) && num >= low && num <= high)
                    res.Add(num);
            }

            return res;
        }

}

//Most common
public class Solution {
    public IList<int> SequentialDigits(int low, int high) {
        var result = new List<int>();
        for (int i = 1; i <=9 ;i++)
        {
            var last = i+1; //10
            var sum = i; 
            while (sum <= high) // 12 < 300
            {
                if (last >= 10)
                {
                    break;
                }

                sum = sum * 10 + last; // 120 + 3 == 123
                last++; //4
                if (sum >= low && sum <= high)
                {
                    result.Add(sum);
                }
            }
        }
        result.Sort();
        return result;
    }

}

//Fastest
public class Solution {
    public IList<int> SequentialDigits(int low, int high) 
    {
        var result = new List<int>();
        var queue = new Queue<Tuple<int, int>>();
        
        for(var i = 1; i < 9; i++)
        {
            queue.Enqueue(Tuple.Create(i, i + 1));
        }
        
        while(queue.Count != 0)
        {
            var current = queue.Dequeue();
            var prevNum = current.Item1;
            var currentDigit = current.Item2;
            var currentNum = prevNum * 10 + currentDigit;
            if (currentNum > high) continue;
            if (currentNum >= low) result.Add(currentNum);
            if (currentDigit < 9) queue.Enqueue(Tuple.Create(currentNum, currentDigit + 1));
        }
        
        return result;
    }
}