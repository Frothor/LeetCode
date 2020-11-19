#Third fastest
class Solution:
    def decodeString(self, s: str) -> str:
        cur_str, cur_num, stack = '', 0, []
        for c in s:
            if c == '[':
                stack.append(cur_str)
                stack.append(cur_num)
                cur_str = ''
                cur_num = 0
            elif c == ']':
                num = stack.pop()
                pre_str = stack.pop()
                cur_str = pre_str + num * cur_str
            elif c.isdigit():
                cur_num = cur_num * 10 + int(c)
            else:
                cur_str += c
        return cur_str

#Second fastest
class Solution:
    def decodeString(self, s: str) -> str:
        
        stack = []
        for i, _s in enumerate(s):
            if len(stack) == 0:
                stack.append(_s)
            else:
                if _s.isnumeric() and stack[-1].isnumeric():
                    stack[-1] = str(int(stack[-1])*10 + int(_s))
                elif _s.isnumeric() and not stack[-1].isnumeric():
                    stack.append(_s)
                elif _s == '[':
                    stack.append(_s)
                elif _s.isalpha():
                    if stack[-1].isalpha():
                        stack[-1] = stack[-1] + _s
                    else:
                        stack.append(_s)
                elif _s == ']':
                    
                    word = stack[-1]
                    del stack[-1]    # del word
                    del stack[-1]    # del [
                    number = int(stack[-1])
                    del stack [-1]   # del number
                    
                    new_word = []
                    while number:
                        new_word.append(word)
                        number -= 1
                    word_to_append = "".join(new_word)
                    
                    if len(stack) == 0:
                        stack.append(word_to_append)
                    elif stack[-1].isalpha():
                        stack[-1] = stack[-1] + word_to_append
                    else:
                        stack.append(word_to_append)
        
        return stack[0]
        
# "3[a]2[bc]"
# "3[a2[c]]"
# "2[abc]3[cd]ef"
# "abc3[cd]xyz"
# "100[leetcode]"

#Fastest
class Solution:
    def decodeString(self, s: str) -> str:
        
        stack = []
        res = []
        
        for char in s:
            if char == ']':
                tmpStr = []
                k = 0
                base = 0
                while stack[-1] != '[':
                    tmpStr.append(stack.pop())
                stack.pop()
                while stack and stack[-1].isnumeric():
                    num = stack.pop()
                    k += (ord(num) - ord('0')) * (10 ** base)
                    base += 1
                for _ in range(k):
                    for i in range(len(tmpStr) - 1, -1, -1):
                        stack.append(tmpStr[i])
            else:
                stack.append(char)
        
        return  ''.join(stack)