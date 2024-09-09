#!/usr/bin/env python3
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            first = nums[i]
            slicedArray = nums[i + 1:]

            for j in range(len(slicedArray)):
                if first + slicedArray[j] == target:
                    return [i, j + i + 1]


inst = Solution()
print(inst.twoSum([2, 7, 2, 11], 4))

'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
'''