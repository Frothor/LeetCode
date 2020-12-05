//Third fastest
static int speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(!n)
            return true;

        auto b = begin(flowerbed), e = end(flowerbed);
        if(flowerbed.size() < 2 && n > 0)
        {
            if(flowerbed[0] == 0 && n == 1)
                return true;
            return false;
        }
            

        if(*b == 0 && *(b+1) == 0)
        {
            *b = 1;
            --n;
        }
        b++;
        if(n && *(b-1) == 0 && *(b+1) == 0 && *b == 0)
        {
            *b = 1;
            --n;
        }
        b++;
        
        while( b != e )
        {
            if(!n)
                return true;
            else if(b+1 != e)
            {
                if(*(b-2) == 0 && *b == 0 && *(b-1) == 0)
                {
                    *(b-1) = 1;
                    --n;
                }
            }
            else
            {
                if(*(b-1) == 0 && *b == 0)
                {
                    *b = 1;
                    --n;
                }
            }
            ++b;
        }
        return n == 0;
    }
};

//Seocnd fastest
class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> const &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int flowersCount = 0;
        for(size_t index = 0; index < flowerbed.size();)
        {
            bool leftGood = (index == 0) || (flowerbed[index - 1] == 0);
            bool rightGood = (index == flowerbed.size() - 1) || (flowerbed[index + 1] == 0);
            if (flowerbed[index] == 0 && leftGood && rightGood)
            {
                ++flowersCount;
                ++index;
            }
            if (flowersCount == n)
                return true;
            ++index;
        }
        return false;
    }
};

//Fastest
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 0){
                bool front = (i == 0 || flowerbed[i - 1] == 0);
                bool behind = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                if (front && behind){
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n)
                        return true;
                }
            }
        }
        return false;
    }
};