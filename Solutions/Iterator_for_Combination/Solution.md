## This Question Look Like Little Complicated But It's Not actully In real
So Lets See One Simple Approch

Idea :
step 1 . We Need To determind The all Possiable lexicographical String With Having combinationLength
from That Given String
## Solution Of Step 1 :
we are Going To Create A static function OR Global Function Which take that Input string and combinationLength
as an argument and return us A set of string having length of combinationLength in lexicographical form
and we can genarete That all string by Using Bitmasking . How??Lets See.. fallowing
Imp Check string length and Then Itarate Through 1 to that string length
And consider Those Num which have set bit no == combinationLength
then Just Take those character That lay on Set bit Possiation and Using of Those Create a String
Lastly Put each Of string into a String set and return that set

Lets take an Example To understand This Step
```
Suppose Input string - "abc" and combinationLength =2
    now mask = 8 which is nothing but 2 power length of of "abc"
    now Itarate from 1 to 8 

   Num             bit_rep           no_of_set_bit       a   b   c            hold_set
    1               0 0 1                 1              0   0   1              nothing   <= because combinationLength != no_of_set_bit
    2               0 1 0                 1              0   1   0              same case like upper one
    3               0 1 1                 2              0   1   1              "bc" <= combinationLength ==no_of
    4               1 0 0                 1              1   0   0              nothing
    5               1 0 1                 2              1   0   1               "ac"
    6               1 1 0                 2              1   1   0               "ab"
    7               1 1 1                 3              1   1   1              nothing <= because combinationLength != no_of_set_bit

    return that set in lexi order ["ab","ac","bc"]

Now We Done Our Main Work
```

step 2. Take an iterator and initialize whith Set Begin
and for each **next()** return it's Possiation string from set and increase that iterator
for **hasNext()** Check iterator reach to then end of set or not and return that
```c++
set<string>GenaretallComb(string s,int len){
    int mask = 1<<s.length();
    set<string>hold;
    string comString = "";
    for(int no=1;no<mask;no++){
        int num = no,i = 0;
        while(num){
            if(num&1)comString = comString + s[i];
            i++,num>>=1;
        }
        if(comString.length()==len)hold.insert(comString);
        comString = "";
    }
    return hold;
}

class CombinationIterator {
public:
    set<string>st;
    set <string> :: iterator cur;
    CombinationIterator(string characters, int combinationLength) {
        this->st = GenaretallComb(characters,combinationLength);
        this->cur = begin(st);
    }
    
    string next() {
        return !(cur==end(st))?*cur++:"";
    }
    
    bool hasNext() {
        return !(cur==end(st));
    }
};
```

### Python Implementation:
```python
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.s = characters
        self.length = len(self.s)
        self.k = combinationLength
        self.mask = (1 << self.length) - 1

    def getMaskLength(self):
        mask = self.mask
        total = 0
        while mask:
            total += mask & 1
            mask >>= 1
        return total
        
    def next(self) -> str:
        while self.mask and self.getMaskLength() != self.k: self.mask -= 1

        comb = ""
        for i in range(self.length):
            if self.mask & (1 << (self.length - i - 1)):
                comb += self.s[i]
        
        self.mask -= 1
        return comb
            
    def hasNext(self) -> bool:
        while self.mask and self.getMaskLength() != self.k: self.mask -= 1
            
        if self.mask:
            return True
        return False
```

## Solution 2
Inspired by this logic, but calculating next dynamically.
```c++
class CombinationIterator {
public:
    int len, mask;
    string s;
    CombinationIterator(string characters, int combinationLength) {
        s=characters;
        len = combinationLength;
        mask = (1 << characters.length()) - 1;
    }
    
    string next() {
        while(mask && __builtin_popcount(mask) != len) mask--;
        string out;
        for(int i=0; i< s.length(); i++) {
            if (mask & (1 << (s.length() - i - 1)))
                out += s[i];
        }
        mask--;
        return out;
    }
    
    bool hasNext() {
        while(mask && __builtin_popcount(mask) != len) mask--;
        if (!mask)
            return false;
        return true;
    }
};
```

[Link to original post](https://leetcode.com/problems/iterator-for-combination/discuss/789164/C%2B%2B-Using-Bit-manipulation-or-Detail-Explain)