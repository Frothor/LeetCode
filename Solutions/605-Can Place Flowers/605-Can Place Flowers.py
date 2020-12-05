#Fourth fastest
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed.append(0)
        flowerbed.insert(0,0)
        count = 0
        for bed in flowerbed:
            if bed == 0:
                count += 1
            else: count = 0
            if count == 3:
                n -= 1
                count = 1
        if n <= 0:
            return True
        return False

#Third fastest
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        flowerbed = [0] + flowerbed + [0] #modifies input
        for i in range(1, len(flowerbed)-1):
        	if flowerbed[i-1] == flowerbed[i] == flowerbed[i+1] == 0:
        		flowerbed[i] = 1
        		count += 1
        return count >= n

#Second fastest
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == len(flowerbed) -1 or flowerbed[i+1] == 0):
                flowerbed[i] = 1
                count += 1
                
        
        if count >= n:
            return True
        else:
            return False

#Fastest
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
#         num_flower = sum(flowerbed)
#         bed_len = len(flowerbed)
        
#         if (num_flower+n) > (bed_len+1)//2:
#             return False
#         else:
#             count = 0
#             for i in range(bed_len):
#                 if flowerbed[i]==0 and i==0 and (bed_len==1 or flowerbed[i+1]==0 ):
#                     flowerbed[i]=1
#                     count+=1
#                 elif flowerbed[i]==0 and i==bed_len-1 and (bed_len==1 or flowerbed[i-1]==0 ):
#                     flowerbed[i]=1
#                     count+=1
#                 elif flowerbed[i]==0 and flowerbed[i-1]==0 and flowerbed[i+1]==0:
#                     flowerbed[i]=1
#                     count+=1
                    
#                 if count>=n:
#                     return True
#             return count>=n

        num_flower = sum(flowerbed)
        bed_len = len(flowerbed)
        
        if (num_flower+n) > (bed_len+1)//2:
            return False
        else:
            count = 0
            for i in range(bed_len):
                if flowerbed[i]==0 and (i==0 or flowerbed[i-1]==0)  and (i==bed_len-1 or flowerbed[i+1]==0):
                    flowerbed[i]=1
                    count+=1
                    
                if count>=n:
                    return True
            return count>=n