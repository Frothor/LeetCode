/*
https://leetcode.com/problems/can-place-flowers/discuss/202780/C
Count sequences of 0' and depends on sequence length to calculate available slots.

If sequence of 0 is in middle of string, we have following fomular: available slots = length / 2 + length % 2 - 1
Ex: 10000001 -> available slots = 6 / 2 + 6 % 2 - 1 = 2
If sequence of 0 is beginning or end of string, add 10 or 01 at the end and use formula as case 1
Ex: 00001 -> 1000001 -> available slots = 5 / 2 + 5 % 2 - 1 = 2

*/
public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
            if (flowerbed.Length <= 2) return n <= (flowerbed.Any(f => f == 1) ? 0 : 1);

            var c = 0;
            var x = -1;
            var y = -1;

            for (var i = 0; i < flowerbed.Length; i++)
            {
                if (flowerbed[i] == 0)
                {
                    if (x == -1) x = i;
                    else y = i;
                }
                else
                {
                    if (x != -1 && y != -1)
                    {
                        var z = (x == 0 ? 1 : 0) + (y == flowerbed.Length - 1 ? 1 : 0) + y - x + 1;

                        c += z / 2 + z % 2 - 1;
                    }

                    x = -1;

                    y = -1;
                }
            }

            if (x != -1 && y != -1)
            {
                var z = (x == 0 ? 1 : 0) + (y == flowerbed.Length - 1 ? 1 : 0) + y - x + 1;

                c += z / 2 + z % 2 - 1;
            }

            return c >= n;
    }
}

//Third fastest
public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
      int index = 0;
      int count = 0;
      while (index < flowerbed.Length) {
        //Console.WriteLine($"{index}:{count}");
        if (index == 0 && flowerbed[0] == 0) {
          if (flowerbed.Length == 1) {
            count++;
            index++;
          } else if (flowerbed[1] == 0) {
            count++;
            index += 2;
          }else{
            index += 3;
          }
        } else if (index == flowerbed.Length - 1) {
          if (flowerbed[flowerbed.Length - 1] == 0 && flowerbed[flowerbed.Length - 2] == 0) {
            count++;
            index += 2;
          }
          else{
            index++;
          }
        } else {
          if(flowerbed[index] == 1) {
            index += 2;
          } else {
            // Console.WriteLine($"{index}:{count}");
            if (flowerbed[index - 1] == 0 && flowerbed[index + 1] == 0) {
              count++;
              index += 2;
            }else{
              index++;
            }
          }
        }
      }
      return (count >= n);
    }
}

//Second fastest
public class Solution {
    public bool CanPlaceFlowers( int[] flowerbed, int n ) {
        if( n == 0 ) {
            return true;
        }
        
        if ( flowerbed.Length < 3 ) {
            if ( Array.Exists( flowerbed, x => x == 1 ) ) {
                return false;
            } else {
                return n <= 1;
            }
        }
        
        int numAvailable = 0;
        bool didPlantLast = false;
        for ( int i = 0; i < flowerbed.Length; i++ ) {
            if ( didPlantLast ) {
                didPlantLast = false;
                continue;
            }
            
            bool isThisPlanted = ( flowerbed[ i ] == 1 );
            if ( !isThisPlanted ) {
                bool isLeftPlanted = false;
                bool isRightPlanted = false;
                
                if ( i - 1 >= 0 ) {
                    isLeftPlanted = ( flowerbed[ i - 1 ] == 1 );
                }
                if ( i + 1 < flowerbed.Length ) {
                    isRightPlanted = ( flowerbed[ i + 1 ] == 1 );
                }
                
                if ( !isLeftPlanted && !isRightPlanted ) {
                    numAvailable++;
                    didPlantLast = true;
                }
            }
        }
        
        return numAvailable >= n;
    }
}

//Fastest
public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
        var cnt = 0;
        for(int i = 0; i < flowerbed.Length; ++i)
        {
            if ((i - 1 < 0 || flowerbed[i-1] == 0) &&
                (i + 1 >= flowerbed.Length || flowerbed[i+1] == 0) &&
               flowerbed[i] == 0)
            {
                ++cnt;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
}