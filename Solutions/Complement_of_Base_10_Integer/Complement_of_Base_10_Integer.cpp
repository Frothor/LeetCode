class Solution
{

public:
    int bitwiseComplement(int n)
    {

        if (n == 0)
            return 1;

        int power = 1;

        int ans = 0;

        while (n > 0)
        {
            int bit = n & 1;

            if (bit == 0)
            {
                ans += (1 * power);
            }

            n = n >> 1;

            power = power * 2;
        }

        return ans;
    }
};

//Another
class Solution
{
public:
    int bitwiseComplement(int N)
    {
        //         if(N==0)
        //             return 1;
        //        long int sum=0,i=0;
        //      while(N!=1)
        //      {
        //          if(N%2==0)
        //             sum=sum+pow(2,i)*('1'-'0');
        //          else
        //             sum=sum+pow(2,i)*('0'-'0');
        //         N=N/2;
        //          i++;
        //      }

        //              return sum;
        int c = 1;
        while (c < N)
            c = (c << 1) + 1;
        return N ^ c;
    }
};