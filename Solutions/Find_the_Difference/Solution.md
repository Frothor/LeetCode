# LeetCode Find the Difference Solution
## First Approach:

**Hashmap approach : **

in this approach we will store the frequency of each character of our S string in hashmap and then iterate over our T string and then check whether the ith character has frequency greater than 0 in the hashmap or not.

```c++
  class Solution {
  public:
  char findTheDifference(string s, string t) {

    unordered_map<char,int> mp;
    
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    
    for(int i=0;i<t.length();i++)
    {
        if(!mp.count(t[i])) return t[i];
        
        if(mp.count(t[i]) and mp[t[i]]==0)
        {
            return t[i];
        }
        
        mp[t[i]]--;
        
    }
    
    return ' ';'''
```

## Second Approach -> Sorting Approach

In this approach we will sort both of the strings and then iterate over our smaller string i.e S and at every index comapre the value of ith index of S with ith index of T . when we found that the two values are not same then will return the T[i].
And if while iterating we didnt find different values at same index that means that the character is inserted at end.

```c++
	class Solution {
    public:
    char findTheDifference(string s, string t) {
	
		sort(s.begin(),s.end());
    
		sort(t.begin(),t.end());
    
    
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!=t[i])
			{
				return t[i];
			}
		}
    
		return t[t.length()-1];
```

## Third Approach -> Xor operation

This approach is similar to question in which we have to find the unique number from an array in which every other number is given twice.

we know that xor of 2 same numbers is 0.

in this question we are given that t is a string that is has same characters as s string except 1 character.

so what we do , we simply xor the the characters of two strings.
After this xor the repeating characters will become zero and our answer will be eqaul to the unique character.

```c++
   class Solution {
   public:
   char findTheDifference(string s, string t) {
    
    char x = 0;
    
    for(auto ch : s)
    {
        x^=ch;
    }
    
    for(auto ch: t)
    {
        x^=ch;
    }
    
    return x;
    
}
```

## [Python] Linear oneliner, explained

We need to find letter which we added to s so we get t. Let us just count of letters both in t and s and then evaluate difference! What we have in the end is counter with only one letter with frequency 1 and it will be exaclty the letter we need. So, let us just do it and we are happy.

Complexity: time complexity is O(n), because we just iterate our strings once. Space complexity is O(26), because we keep frequencies of our letters in counter.

```python
class Solution:
    def findTheDifference(self, s, t):
        return list((Counter(t) - Counter(s)).keys())[0]
```