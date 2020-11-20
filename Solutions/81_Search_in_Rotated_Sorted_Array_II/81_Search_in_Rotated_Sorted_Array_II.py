class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        def dfs(beg, end):
            if end - beg <= 1: return target in nums[beg: end+1]
            
            mid = (beg + end)//2
            if nums[mid] > nums[end]:   # eg. 3,4,5,6,7,1,2
                if nums[end] < target <= nums[mid]:
                    return dfs(beg, mid)
                else:
                    return dfs(mid + 1, end)
            elif nums[mid] < nums[end]: # eg. 6,7,1,2,3,4,5
                if nums[mid] < target <= nums[end]:
                    return dfs(mid + 1, end)
                else:
                    return dfs(beg, mid)
            else:
                return dfs(mid+1, end) or dfs(beg, mid)
    
        return dfs(0, len(nums)-1)

#Fourth fastest
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        start = 0
        end = len(nums) - 1
        if nums == []:
            return False
        while start < end:
            mid = (start + end) // 2
            
            if nums[mid] == target:
                return True
            
            while nums[mid] == nums[start] and start < mid:
                start += 1
            
            if nums[mid] >= nums[start]:
                if nums[start] <= target < nums[mid]:
                    end = mid
                else:
                    start = mid + 1
            else:
                if nums[mid] < target <= nums[end]:
                    start = mid + 1
                else:
                    end = mid - 1
                    
        if nums[start] == target:
            return True
        return False

#Third fastest
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        for i in range(len(nums)):
            if target == nums[i]:
                return True
        return False

#Second fastest
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        
        if not nums: return False
        
        def pivot(arr,l,r):
            
            while l<=r:
                while l < r and nums[l] == nums[l + 1]:
                    l+=1
                while l < r and nums[r] == nums[r - 1]:
                    r-=1
                    
                m = (l+r)//2
                # print(arr[l],arr[r],arr[m])
                
                if m+1<len(nums) and arr[m]>arr[m+1]:
                    return m+1
                if arr[m]<arr[l]:
                    r = m
                else:
                    l = m+1
                    
            return 0
        
        def bs(arr,l,r):
            
            while l<=r:
                
                m = (l+r)//2
                
                if target == arr[m]:
                    return True
                elif target>arr[m]:
                    l=m+1
                else:
                    r=m-1
            return False
                
                    
            
            
        p=pivot(nums,0,len(nums)-1)
        # print(p)
        
        if nums[p]<=target<=nums[len(nums)-1]:
            return bs(nums,p,len(nums)-1)
        else:
            return bs(nums,0,p-1)

#Fastest
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        if n == 0: return False
        end = n - 1
        start = 0
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return True
            if not nums[start] != nums[mid]:
                start += 1
                continue
            pivotArray = nums[start] <= nums[mid]
            targetArray = nums[start] <= target
            if pivotArray ^ targetArray:
                if pivotArray:
                    start = mid + 1
                else:
                    end = mid - 1
            else:
                if nums[mid] < target:
                    start = mid + 1
                else:
                    end = mid - 1
        return False