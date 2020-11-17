class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        k = 1
        while k*q%p: k += 1
        return 2 if k%2==0 else (k*q//p)%2

#Third fastest
class Solution:
  def mirrorReflection(self, p: int, q: int) -> int:
    def gcf(big, small):
      if small == 0:
        return big
      return gcf(small, big%small)
    g = gcf(p, q)
    p /= g
    q /= g
    if p%2 == 1:
      if q%2 == 0:
        return 0
      return 1
    return 2

#Second fastest
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        g = math.gcd(p, q)
        m, n = q // g, p // g
        if n % 2 == 0:
            return 2
        else:
            return m % 2
        return -1

#Fastest
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        
        x = p // math.gcd(p, q)
        y = q // math.gcd(p, q)
        
        if x % 2 == 1 and y % 2 == 1:
            return 1
        elif x % 2 == 0 and y % 2 == 1:
            return 2
        else:
            return 0
