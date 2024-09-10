#!/usr/bin/env python3
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        '''
        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
        You may assume that each input would have exactly one solution, and you may not use the same element twice.
        You can return the answer in any order.
        '''
        for i in range(0, len(nums)):
            first = nums[i]
            slicedArray = nums[i + 1:]

            for j in range(len(slicedArray)):
                if first + slicedArray[j] == target:
                    return [i, j + i + 1]


inst = Solution()
# print(inst.twoSum([2, 7, 2, 11], 4))


import math

class Solution2:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        '''
        Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
        The overall run time complexity should be O(log (m+n)).
        '''
        merged = nums1 + nums2
        merged.sort()

        len_ = len(merged)

        for i in range(0, len_):
            if len_ % 2 == 0:
                halfArrayIdx = int(len_ / 2)
                median = (merged[halfArrayIdx] + merged[halfArrayIdx - 1]) / 2
                return median
            else:
                medianIdx = math.floor(len_ / 2)
                return merged[medianIdx]

median = Solution2()
print(median.findMedianSortedArrays([-1, -2], [3]))
