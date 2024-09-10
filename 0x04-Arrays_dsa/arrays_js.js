/** 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        let first = nums[i]
        const slicedArray = nums.slice(i + 1)


        for (let j = 0; j < slicedArray.length; j++) {
            if ((first + slicedArray[j]) === target) {
                return [i, j +  i + 1]
            }
        }
    }
};


/**
 Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const size1 = nums1.length;
    const size2 = nums2.length;

    const arr3 = new Array(nums1 + nums2);

    mergeArrays(nums1, size1, nums2, size2, arr3);

    function mergeArrays(nums1, size1, nums2, size2, arr3) {
        let i = 0, j = 0, k = 0;

        while (i < size1) {
            arr3[k++] = nums1[i++];
        }

        while (j < size2) {
            arr3[k++] = nums2[j++];
        }

        arr3.sort(function(a, b) {return a - b});
    }
    const len = arr3.length;

    console.log(arr3);

    if ((len % 2) === 0) {
        const halfOfArray = len / 2;
        return (arr3[halfOfArray - 1] + arr3[halfOfArray]) / 2;
    } else {
        const halfOfArray = Math.floor(len / 2);
        return arr3[halfOfArray];
    }
};

console.log(findMedianSortedArrays([-1, -2, -3], [0]));
