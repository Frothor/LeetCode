#In python it is more like easy than medium problem, there is not a lot of cases we need to handle.

#1. First step is to split our strings using . and change type from string to int.
#2. Now, if we have lists of different length, let us add zeros to the end of short list.
#3. Finally, we need to compare s1 and s2 as lists. There is not cmp() function in python3, but we can use (s1 > s2) - (s1 < s2) trick: if s1 > s2 then we have 1-0 = 1, if s1 = s2, then we have 0-0 = 0, if we have s1< s2, then 0-1 = -1.
#Complexity: time complexity is O(n+m), where n and m are lengths of our strings, space complexity O(n+m) as well.
class Solution:
    def compareVersion(self, version1, version2):
        s1 = [int(i) for i in version1.split(".")]
        s2 = [int(i) for i in version2.split(".")]
        
        l1, l2 = len(s1), len(s2)
        if l1 < l2: s1 += [0]*(l2-l1) 
        else: s2 += [0]*(l1 - l2)
            
        return (s1 > s2) - (s1 < s2)

#Fastest
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1, l2 = version1.split('.'), version2.split('.')
        n1, n2 = len(l1), len(l2)
        
        i = 0
        for i in range(max(n1, n2)):
            val1 = int(l1[i]) if i < n1 else 0
            val2 = int(l2[i]) if i < n2 else 0
            if val1 != val2:
                return 1 if val1 > val2 else -1
            # if val1 > val2:
            #     return 1
            # elif val1 < val2:
            #     return -1
        return 0
            
#         while i < min(n1, n2):
#             v1, v2 = int(l1[i]), int(l2[i])
#             if v1 > v2:
#                 return 1
#             elif v1 < v2:
#                 return -1
#             i += 1
        
#         if n1 == n2:
#             return 0
#         elif n1 < n2:
#             for j in range(i, n2):
#                 if int(l2[j]) > 0:
#                     return -1
#             else:
#                 return 0
#         elif n1 > n2:
#             for j in range(i, n1):
#                 if int(l1[j]) > 0:
#                     return 1
#             else:
#                 return 0
            
        