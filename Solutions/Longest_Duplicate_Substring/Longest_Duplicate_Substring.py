class Solution:
    def longestDupSubstring(self, S: str) -> str:
        p = 2**63-1
        def rabin_karp(mid):
            cur_hash = 0
            for i in range(mid):
                cur_hash = (cur_hash * 26 + nums[i]) % p
            hashes = {cur_hash}
            pos = -1
            max_pow = pow(26, mid, p)
            for i in range(mid, len(S)):
                cur_hash = (26*cur_hash-nums[i-mid]*max_pow + nums[i]) % p
                if cur_hash in hashes:
                    pos = i + 1 - mid
                hashes.add(cur_hash)
            return pos
        
        #bst
        nums = [ord(c) for c in S]
        l,r = 0,len(S)-1
        start,end = 0,0
        
        while(l<=r):
            mid = (l+r)//2
            pos = rabin_karp(mid)
            if pos == -1:
                r = mid-1
            else:
                start,end = pos,pos+mid
                l = mid+1
        
        return S[start:start+l-1]

#Most common:
MODULO = 100000000487  # prime

class Solution:
    def longestDupSubstring(self, S: str) -> str:
        ords = bytes(ord(c) - ord('a') for c in S)
        
        cumulatives = [0]
        for o in ords:
            cumulatives.append(
                ( cumulatives[-1] * 26 + o) % MODULO
            )

        def _duplicate(length):
            MULT = (26 ** length) % MODULO 
            hsh = cumulatives[length + 1]
            seen = {hsh}
            for start in range(1, len(S) - length):
                hsh = ((hsh - MULT * ords[start - 1]) * 26 + ords[start + length]) % MODULO
                if hsh in seen:
                    return start
                seen.add(hsh)
            return None

        best = None
        best_len = -1
                
        left = 0
        right = len(S) - 1
        
        while right - left >= 2:
            middle = (left + right) // 2
            cand = _duplicate(middle)
            cand_len = middle + 1
            if cand is not None:
                if cand_len > best_len:
                    best = cand
                    best_len = cand_len
                    
                left = middle + 1
            else:
                right = middle - 1

        if best_len < left + 1:
            new_cand = _duplicate(left)
            if new_cand is not None:
                best = new_cand
                best_len = left + 1
                new_cand = _duplicate(right)
                if new_cand is not None:
                    best = new_cand
                    best_len = right + 1
        
        if best is None:
            return ''
        
        return S[best:best + best_len]