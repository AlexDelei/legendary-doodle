#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    *returnSize = 2;
    int returnArray = (int*)malloc(2 * sizeof(returnSize));

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
