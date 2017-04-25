75_Sort_Colors


题目大意
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

解决方案
1. 简单的解决方案直接扫描一遍记录0、1、2的数目然后写一遍数组
2. 题目要求只做一次遍历
用指针left、right、now
i是正在处理的，0....left-1都是 0， right+1...end都是 2，left...now-1 都是1，now是正在处理的， now...right是等待处理的
处理到1个数的时候的三种情况：
if(nums[i] == 0){
    swap(nums[left], nums[i]);
    left ++;
    i ++;
}
else if(nums[i] == 1)
    i ++;
else{
    swap(nums[i], nums[right]);
    right --;
}

样例


