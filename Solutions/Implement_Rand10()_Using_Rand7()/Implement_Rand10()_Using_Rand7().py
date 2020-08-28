# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7
class Solution:
    def rand10(self):
        c = (rand7() - 1)*7 + rand7() - 1
        return self.rand10() if c >= 40 else (c % 10) + 1

#Most common
class Solution:
    def rand10(self):
        """
        :rtype: int
        """
#         # my implement
#         i = 0
#         while i < 1 or i > 5:
#             i = rand7()  # sample a i between [1, 2, 3, 4, 5]
        
#         j = 7
#         while j > 6: # sample a j in [6, 7]
#             j = rand7()
        
#         if j % 2 == 0:
#             return i
#         else:
#             return i + 5
        
        # rejection sampling
        num = 50
        while num > 40:
            num = 7 * (rand7() - 1) + rand7()
        
        return 10 - (num % 10)


#Fastest
class Solution:
    s = 0

    def rand10(self):
        self.s += 7
        return 1 + ((rand7() + self.s) % 10)