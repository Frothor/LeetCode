# Time:  O(n)
# Space: O(n)

# Given an array of integers, return indices of the two numbers
# such that they add up to a specific target.
#
# You may assume that each input would have exactly one solution.
#
# Example:
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        for i, num in enumerate(nums):
            if target - num in lookup:
                return [lookup[target - num], i]
            lookup[num] = i
        return []

# Another
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Iterate through the array and write in a dict: key = specific number, value: hof often it occurs
        dict_nums = {}
        solution = []
        for i in range(len(nums)):
            number = nums[i]
            complement = target - number
            if complement in dict_nums.keys():
                solution.append([dict_nums[complement], i])
            else:
                dict_nums.setdefault(number, i)
        return solution[0]
    
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        # Iterate through the array and write in a dict: key = specific number, value: hof often it occurs
        dict_nums = {}
        for i in range(len(nums)):
            number = nums[i]
            complement = target - number
            if complement in dict_nums.keys():
                return [dict_nums[complement], i]
            else:
                dict_nums.setdefault(number, i)