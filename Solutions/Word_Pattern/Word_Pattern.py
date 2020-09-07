class Solution(object):
    def wordPattern(self, pattern, s):
        s, pattern = s.split(), list(pattern)
        return map(s.index, s) == map(pattern.index, pattern)