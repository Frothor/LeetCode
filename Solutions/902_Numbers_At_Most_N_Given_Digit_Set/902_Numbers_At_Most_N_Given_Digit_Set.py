#Third fastest
class Solution():
    def atMostNGivenDigitSet(self, nums: List[str], N: int) -> int:
        @lru_cache(None)
        def dp(n,f,z):
            return sum(dp(n+1,f or i<str(N)[n],1) 
                            for i in nums 
                                if f or i<=str(N)[n]) + (not z and dp(n+1,1,0)) if n<len(str(N)) else 1
        return dp(0,0,0) - 1

#Second fastest
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        
        
        k = len(str(n))
        
       
        res = 0
        
        for i in range(1, k):
            res += len(digits) ** i
            
        largest = list(str(n))
        
        def helper(i):
            
            if i == k:
                return 1
            cnts = 0
            this = largest[i]
            for d in digits:
                if d < this:
                    cnts += len(digits) ** (k-i-1)
            if this in digits:
                cnts += helper(i+1)
            return cnts
        
        res += helper(0)            
            
        return res % (10 ** 9 + 7)

#Fastest
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        ORD0 = ord('0')
        digits = sorted([ord(_) - ORD0 for _ in digits])
        s = len(digits)
        l = int(math.log(n) / math.log(10))
        t = 10 ** l
        leading = n // t
        if leading > 9:
            t *= 10
            l += 1
            leading = n // t
        def getnum():
            leading0 = leading
            n0 = n
            l0 = l
            t0 = t
            m9 = digits[-1] * (10 ** (l0 + 1) - 1) // 9
            m0 = m9 // digits[-1] * digits[0] 
            scope = locals()
            if n0 >= m9:
                for i in range(l0 + 1):
                    yield s - 1
                return
            if n0 < m0:
                for i in range(l0):
                    yield s - 1
                return
            if n0 == m0:
                for i in range(l0 + 1):
                    yield 0
                return
            while n0:
                x = bisect.bisect_left(digits, leading0)
                scope = locals()
                if x == s:
                    for i in range(l0 + 1):
                        yield s - 1
                    return
                if leading0 == digits[x]:
                    candidate = x
                else:
                    candidate = x - 1
                remain = n0 - digits[candidate] * (10 ** l0)
                l0 -= 1
                m9 //= 10
                m0 //= 10
                scope = locals()
                if remain < m0 and t0 > 1:
                    print()
                    candidate -= 1
                    remain = n0 - digits[candidate] * (10 ** l0)
                scope = locals()
                yield candidate
                
                if t0 == 1:
                    break
                t0 //= 10
                leading0 = remain // t0
                n0 = remain
                # m0 //= 10
        nums = list(getnum())
        l = len(nums)
        if s == 1:
            return l
        ans = (s ** l - s) // (s - 1)
        t = s ** l
        for i in nums:
            t //= s
            ans += i * t
        ans += 1
        return ans