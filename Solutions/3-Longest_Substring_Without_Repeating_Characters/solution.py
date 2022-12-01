class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == None:
            return 0

        if len(s) == 0:
            return 0

        if len(s) == 1:
            return 1
        
        result = []
        temp = s[0]
        for i in s[1:]:
            if i not in temp:
                temp += i
            elif i == temp[0]:
                temp = temp[1:] + i
            elif i == temp[-1]:
                result.append(temp)
                temp = i
            else:
                result.append(temp)
                temp = temp[temp.find(i) + 1:] + i
            result.append(temp)
        
        return len(max(result, key=len))

# Second fastest
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        sub_str = ""

        for item in s:
            if item not in sub_str:
                sub_str += item
            else:
                result = max(result, len(sub_str))
                sub_str = sub_str[sub_str.index(item) + 1:] + item

        result = max(result, len(sub_str))

        return result

# Fastest
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        j = -1
        chars = {}
        ans = 0
        for i,ch in enumerate(s):
            if ch in chars and chars[ch] > j:
                j = chars[ch]
            else:
                if ans < i-j:
                    ans = i-j
            chars[ch] = i
        return ans