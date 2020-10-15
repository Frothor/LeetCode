class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()  # will make spoting of duplicates easy

        triplets = []
        length = len(nums)

        for i in range(length-2):  # ignore last two

            # check if element is a duplicate. the first cannot be a duplicate
            if i > 0 and nums[i] == nums[i-1]:
                # skip handling an element if it's similar to the one before it
                # because it is sorted, we effectively skip duplicates
                continue

            # TWO SUM for a sorted array
            # 1. find elements that will add up to 0
            # 2. check inner elements
            left = i + 1
            right = length - 1
            while left < right:

                # will be used to check if the sum is equal to 0
                total = nums[i] + nums[left] + nums[right]

                # if total is less than 0 we try to increase it's value
                if total < 0:
                    left += 1  # moving left to a lerger value

                # if total is more than 0 we try to decrease it's value
                elif total > 0:
                    right -= 1  # moving right to a smaller value

                # 1. add list of elements to triplets
                # 2. check inner elements
                else:
                    # add elements to triplets
                    triplets.append([nums[i], nums[left], nums[right]])

                    # check inner elements
                    # 1. skip similar elements
                    # 2. move to inner elements

                    # skip:
                    # no need to continue with an element with the same value as l/r
                    # Skip all similar to the current left and right so that,
                    # when we are moving to the next element, we dont move to an element with the same value
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1

                    # move to inner elements
                    left += 1
                    right -= 1

        return triplets

#Somewhat fast
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        ans = []
        
        if nums.count(0) >= 3:
            ans.append([0, 0, 0])
        
        negm = {}
        posm = {}
        zero = False
        for num in nums:
            if num < 0:
                if -num in negm:
                    negm[-num] = True
                else:
                    negm[-num] = False
                # if negs.count(num) < 2:
                #     negs.append(num)
            elif num > 0:
                if num in posm:
                    posm[num] = True
                else:
                    posm[num] = False
                # if poss.count(num) < 2:
                #     poss.append(num)
            else:
                zero = True
        # negs = sorted(negs)
        # poss = sorted(poss)
        negs = list(negm)
        poss = list(posm)
        negset = set(negs)
        posset = set(poss)

        for i in range(len(negs)):
            n1 = negs[i]
            if negm[n1] == True:
                p = n1 * 2
                if p in posset:
                    ans.append([-n1, -n1, p])
            
            for j in range(i + 1, len(negs)):
                n2 = negs[j]
                p = n1 + n2
                if p in posset:
                    ans.append([-n1, -n2, p])
                    
        for i in range(len(poss)):
            p1 = poss[i]
            if posm[p1] == True:
                n = p1 * 2
                if n in negset:
                    ans.append([-n, p1, p1])
                
            for j in range(i + 1, len(poss)):
                p2 = poss[j]
                n = p1 + p2
                if n in negset:
                    ans.append([-n, p1, p2])
        
        if zero:
            common = posset & negset
            for c in common:
                ans.append([-c, 0, c])
        
        return ans

#Fastest
import bisect

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3 or min(nums) > 0 or max(nums) < 0:
            return []
        res = []
        count = defaultdict(int)
        for num in nums:
            count[num] += 1
        nums = sorted(count)
        for idx, num in enumerate(nums):
            if num > 0:
                break
            two_sum = 0 - num
            num2_min, num2_max = two_sum - nums[-1], two_sum / 2
            # if num2_max <= num2_min: continue
            # left, right = idx + 1, len(nums) - 1
            # while left < right:
            #     mid = (left + right) // 2
            #     if nums[mid] < num2_min:
            #         left = mid + 1
            #     else:
            #         right = mid
            # i = right
            # left, right = left, len(nums) - 1
            # while left < right:
            #     mid = (left + right) // 2
            #     if nums[mid] < num2_max:
            #         left = mid + 1
            #     else:
            #         right = mid
            # j = right


            i = bisect_left(nums, num2_min, idx + 1)
            j = bisect_left(nums, num2_max, i)
            for num2 in nums[i:j]:
                num3 = two_sum - num2
                if num3 in count:
                    res.append((num, num2, num3))
        for num in nums:
            if count[num] > 1:
                if num == 0 and count[num] >= 3:
                    res.append((num, num, num))
                elif num != 0 and 0 - 2 * num in count:
                    res.append((num, num, 0 - 2 * num))
        return res
    
        def three_target_sum(target=0):
            count_hash = {}
            for num in nums:
                try:
                    count_hash[num] += 1
                except:
                    count_hash[num] = 1
            res_list = []
            sorted_nums = sorted(count_hash)
            for idx, num in enumerate(sorted_nums):
                if count_hash[num] >= 2:
                    if count_hash[num] >= 3 and num == target / 3:
                        res_list.append([num, num, num])
                    if num != target / 3 and target - 2 * num in count_hash:
                        res_list.append([num, num, target - 2 * num])
                two_sum = target - num
                left = bisect.bisect_left(sorted_nums, two_sum - sorted_nums[-1], idx + 1)
                right = bisect.bisect_left(sorted_nums, two_sum / 2, left)
                for num2 in sorted_nums[left:right]:
                    num3 = two_sum - num2
                    if num3 in count_hash:
                        res_list.append([num, num2, num3])
            return res_list
        return three_target_sum()
                
                        
            
        # res_list = []
        # nums.sort()
        # for i in range(len(nums) - 2):
        #     if nums[i] > 0: break
        #     if i > 0 and nums[i] == nums[i - 1]: continue
        #     left = i + 1
        #     right = len(nums) - 1
        #     while right > left:
        #         summ = nums[i] + nums[left] + nums[right]
        #         if summ == 0:
        #             res_list.append([nums[i], nums[left], nums[right]])
        #             left += 1
        #             right -= 1
        #             while left < right and nums[left] == nums[left - 1]:
        #                 left += 1
        #             while right > left and nums[right] == nums[right + 1]:
        #                 right -= 1
        #         elif summ > 0:
        #             right -= 1
        #         else:
        #             left += 1
        # return res_list
            
#         def three_target_sum(nums, target):
#             res_list = []
#             count_dict = collections.defaultdict(int)
#             for num in nums:
#                 count_dict[num] += 1
#             nums = sorted(count_dict)
#             for idx, num in enumerate(nums):
#                 two_sum = target - num
#                 left = bisect.bisect_left(nums, two_sum - nums[-1], idx + 1)
#                 right = bisect.bisect_right(nums, two_sum / 2, left)
#                 for num2 in nums[left:right]:
#                     num3 = two_sum - num2
#                     if num3 in count_dict and num3 != num2:
#                         res_list.append([num, num2, num3])

#                 if count_dict[num] >= 2:
#                     if num == target / 3:
#                         if count_dict[num] >= 3:
#                             res_list.append([num] * 3)
#                     else:
#                         if target - 2 * num in count_dict:
#                             res_list.append([num, num, target - 2 * num])
#             return res_list
#         return three_target_sum(nums, 0)
     
        # nums.sort()
        # res_list = []
        # if len(nums) < 3 or nums[0] > 0 or nums[-1] < 0: return []
        # for i in range(len(nums) - 2):
        #     if nums[i] > 0: break
        #     if i > 0 and nums[i] == nums[i - 1]: continue
        #     left = i + 1
        #     right = len(nums) - 1
        #     while left < right:
        #         summ = nums[i] + nums[left] + nums[right]
        #         if summ == 0:
        #             res_list.append([nums[i], nums[left], nums[right]])
        #             left += 1
        #             right -= 1
        #             while left < right and nums[left] == nums[left - 1]:
        #                 left += 1
        #             while right > left and nums[right] == nums[right + 1]:
        #                 right -= 1
        #         elif summ > 0:
        #             right -= 1
        #         else:
        #             left += 1
        # return res_list