#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    *returnSize = 2;
    int* returnArray = (int*)malloc(2 * sizeof(returnSize));

    for (i = 0; i < numsSize; i ++)
    {
        for (j = 0; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }

    return NULL;
}

/**
 * findMedianSortedArrays - merge two arrays then find their median.
 * 
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
 */
double findMedianSortedArrays(int* nums1, int size1, int* nums2, int size2, int* merge) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (nums1[i] < nums2[j])
        {
            merge[k++] = nums1[i++];
        } else {
            merge[k++] = nums2[j++];
        }
    }

    while (i < size1)
    {
        merge[k++] = nums1[i++];
    }
    while (j < size2)
    {
        merge[k++] = nums2[j++];
    }

    int sizeOfMerge = size1 + size2;;
    printf("Size of new array -> %d\n", sizeOfMerge);
    if ((sizeOfMerge % 2) == 0)
    {
        int halfArrayIdx = sizeOfMerge / 2;
        float median = (merge[halfArrayIdx] + merge[halfArrayIdx - 1]);

        return median / 2;
    }
    else
    {
        int medIdx = floor(sizeOfMerge / 2);
        return merge[medIdx];
    }
}

int main()
{
    int nums[] = {2, 7, 9, 11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 13;
    int returnSize;

    int* result =  twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL)
    {
        printf("Values are at indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution is found!\n");
    }

    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int mergeArray[size1 + size2];
    printf("%.1f\n", findMedianSortedArrays(arr1, size1, arr2, size2, mergeArray));
}
