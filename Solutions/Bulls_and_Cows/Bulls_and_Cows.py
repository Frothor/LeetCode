class Solution:
    def getHint(self, secret, guess):
        B = sum([x==y for x,y in zip(secret, guess)])
        Count_sec = Counter(secret)
        Count_gue = Counter(guess)
        B_C = sum([min(Count_sec[elem], Count_gue[elem]) for elem in Count_sec])
        return str(B) + "A" + str(B_C-B) + "B"

#Fastest
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        
        bull=0
        for i in range(len(secret)):
            bull += int(secret[i] == guess[i])
        
		# This loop will take care of "cow" cases
        cows=0
        for c in set(secret):
            cows += min(secret.count(c), guess.count(c))
        
        return f"{bull}A{cows-bull}B"