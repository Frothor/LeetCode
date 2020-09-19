class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        out = []
        queue = deque(range(1, 10))
        while queue:
            elem = queue.popleft()
            if low <= elem <= high:
                out.append(elem)
            last = elem % 10
            if last < 9:
                queue.append(elem*10 + last +1)
        return out

#Fastest
from math import log10

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        low_digits = int(log10(low))+1
        high_digits = int(log10(high)) + 1
        all_digits = [str(i) for i in range(10)]
        res = []

        for digits in range(low_digits, high_digits+1):
            if digits > low_digits:
                tmp = [int(''.join(all_digits[i:i+digits])) for i in range(1, 11-digits)]
                res.extend([*filter(lambda x: low <= x <= high, tmp)])
            else: # digits == low_digits
                tmp = [int(''.join(all_digits[i:i+digits])) for i in range(11-digits)]
                res.extend([*filter(lambda x: low <= x <= high, tmp)])
        
        return res

#second fastest
from functools import lru_cache as memoize

class Solution:
#     def sequentialDigits(self, low: int, high: int) -> List[int]:
        
#         @memoize(None)
#         def is_sequential(last_number, number):
#             if last_number is None:
#                 return is_sequential(number % 10, number // 10)
            
#             if number < 10:
#                 return last_number - 1 == number
            
#             new_last_number = number % 10
            
#             if last_number - 1 == new_last_number:
#                 return is_sequential(new_last_number, number // 10)
            
#             return False
        
#         return [num for num in range(low, high+1) if is_sequential(None, num)]

    def sequentialDigits(self, low: int, high: int) -> List[int]:
        possible = '123456789'
        result = []
        
        start_idx = 0
        
        while start_idx < len(possible):
            end_idx = start_idx
            
            while end_idx < len(possible):
                
                num = int(possible[start_idx:end_idx+1])
                
                if low <= num <= high:
                    result.append(num)
                elif num > high:
                    break
                    
                end_idx += 1
            
            start_idx += 1
        
        return sorted(result)