#Most common
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False

        diffCount = 0
        charDiffs = []
        uniqueChars = {}
        isRepeat = False
        for i in range(len(A)):
            if not isRepeat:
                if A[i] in uniqueChars:
                    isRepeat = True
                else:
                    uniqueChars[A[i]] = True
            if A[i] != B[i]:
                diffCount = diffCount+1
                charDiffs.append([A[i], B[i]])
            
            if diffCount == 3:
                return False
            
        if diffCount == 0:
            if isRepeat:
                return True
            else:
                return False
        elif diffCount == 2:
            if charDiffs[0][0] == charDiffs[1][1] and charDiffs[0][1] == charDiffs[1][0]:
                return True
            else:
                return False
        else:
            return False

#Third fastest
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A == B:
            seen = set()
            for a in A:
                if a in seen:
                    return True
                seen.add(a)
            return False
        else:
            pairs = []
            for a, b in zip(A, B):
                if a != b:
                    pairs.append((a, b))
                if len(pairs) > 2:
                    return False
            return len(pairs) == 2 and pairs[0] == pairs[1][::-1]

#Second fastest
class Solution:
    def buddyStrings(self, A, B):
        if len(A) != len(B) or set(A) != set(B): return False       
        if A == B:
            return len(A) - len(set(A)) >= 1
        else:     
            indices = []
            counter = 0
            for i in range(len(A)):
                if A[i] != B[i]:
                    counter += 1
                    indices.append(i)       
                if counter > 2:
                    return False       
            return A[indices[0]] == B[indices[1]] and A[indices[1]] == B[indices[0]]

#Fastest
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A)!=len(B):
            return False
        if len(A)<2:
            return False
        if A==B:
            cnt = Counter(A)
            return bool([v for v in cnt.values() if v>1])
        diffs = []
        for i, a in enumerate(A):
            if a!=B[i]:
                diffs.append(i)
        if len(diffs) == 2:
            i,j = diffs
            return A[i]==B[j] and A[j]==B[i]
        
        return False