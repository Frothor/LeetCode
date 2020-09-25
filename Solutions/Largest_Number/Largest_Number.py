class Solution:
    def largestNumber(self, nums):
        compare = lambda a, b: -1 if a+b > b+a else 1 if a+b < b+a else 0
        return str(int("".join(sorted(map(str, nums), key = cmp_to_key(compare)))))

#Fastest
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cmp(x, y):
            u = x + y
            v = y + x
            if u == v:
                return 0
            elif u < v:
                return -1
            else:
                return 1

        v = map(str, nums)
        result = ''.join(reversed(sorted(v, key=cmp_to_key(cmp))))
        if result and result[0] == '0':
            return '0'
        else:
            return result