public class Solution {
    public int MaxDistToClosest(int[] seats) {
        int i = 0;
        
        while(i < seats.Length && seats[i] != 0)
            i++;
        
        int maxd = 0;
        int s = -1;
        
        while(i < seats.Length){
            s = i;
            int count = 0;
            while(i < seats.Length && seats[i] == 0){
                count++;
                i++;
            }
            
            int empty = i - s;
            
            if(s == 0 || i == seats.Length)
                maxd = Math.Max(maxd, empty);
                
            maxd = Math.Max(maxd, (empty+1)/2);
            
            while(i < seats.Length && seats[i] != 0)
                i++;
        }
        return maxd;
    }
}

//Second fastest
ublic class Solution {
    public int MaxDistToClosest(int[] seats)
        {
            var start = NumberOfPrefixZeros(seats);
            var stop = NumberOfPostfixZeros(seats);
            var maxBorder = start > stop ? start : stop;

            var middleSequenceLength = MiddleSequenceLength(seats);
            var middleSequenceDist = middleSequenceLength / 2 + (middleSequenceLength % 2);

            return maxBorder > middleSequenceDist ? maxBorder : middleSequenceDist;
        }

        private int MiddleSequenceLength(int[] seats)
        {
            var sequence = 0;
            var maxSequence = 0;

            for (var i = 0; i < seats.Length; i++)
            {
                if (seats[i] == 1)
                {
                    if (maxSequence < sequence)
                    {
                        maxSequence = sequence;
                    }

                    sequence = 0;
                }
                else
                {
                    sequence++;
                }
            }

            return maxSequence;
        }

        private int NumberOfPrefixZeros(int[] seats)
        {
            var i = 0;
            while (seats[i] == 0)
            {
                i++;
            }

            return i;
        }
        
        private int NumberOfPostfixZeros(int[] seats)
        {
            var i = 0;
            while (seats[seats.Length - 1 - i] == 0)
            {
                i++;
            }

            return i;
        }
}

//Fastest
public class Solution {
    public int MaxDistToClosest(int[] seats) {
        int maxRange = 0, currentSeats = 0;
        for (int i = 0; i < seats.Length; i++){
            switch (seats[i]){
                case 0:
                    currentSeats++;
                    break;
                case 1: 
                    if (i == currentSeats)
                        maxRange = i;
                    else if ((currentSeats + 1) / 2 > maxRange)
                        maxRange = (currentSeats + 1) / 2;
                    currentSeats = 0;
                    break;
            }
        }
        if (currentSeats > maxRange)
            maxRange = currentSeats;
        return maxRange;
    }
}