4_Median_of_Two_Sorted_Arrays


题目大意
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).





解决方案
题目翻译：找两个sorted数组的中位数。

思路：
实现找两个sorted数组第k大(排在k位置，而不是第k个distince大)的数字，如果两个数组size是奇数，那直接返回第(n1 + n2) / 2 + 1大的数字就是了；如果是偶数，那就返回中间两个数字的平均数。


记号：
数组A，B： A[0, 1, ..., m-1] B[0, 1, ..., n-1]，假设把A和B merge到一起的有序数组是C
下面就看看如何实现找C中的第k大。

对于A中的数A[i] 以及B中的B[j]，
也就是:
A[0] A[1] ... A[i]...
B[0] B[1] ... ...B[j]...
记A[i]在C中排在i'，B[j]在C中排在j'



只要A和B都不空，就一直做下面的步骤：i取A有效部分的中位数，j取B有效部分的中位数

    (1) A[i] < B[j]
    在C里，B[j]前至少有i+j+1个数，也就是j' >= i+j+1
    在C里，A[i]前至多有i+j个数，也就是i' <= i+j
    若k > i + j , 可以把A[0, ..., i]排除
    若k <= i + j，可以把B[j, ..., n-1]排除

    (2) A[i] > B[j]
    在C里，B[j]前至多有i+j个数，也就是j' <= i+j
    在C里，A[i]前至少有i+j+1个数，也就是i' >= i+j+1
    若k > i + j, 可以把B[0, ..., j]排除
    若k <= i + j，可以把A[i, ..., m-1]排除

    (3) A[i] = B[j]
    i' = i+j
    j' == i+j+1
    若 k = i+j 或 k = i+j+1 直接返回A[i]
    若 k < i+j 排除 A[i, ..., m-1] B[j, ..., n-1]
    若 k > i+j 排除 A[0, ..., i] B[0, ..., j]

直到有一个vector为空，再返回另一个里剩下的第k大。

时间分析：
每次比较之后，至少都可以把A或B排除一半。因此最差的时间复杂度是O(lgm + lgn)
lgm + lgn = lg(mn) < lg(m^2 + n^2 + 2mn) = lg((m+n)^2) = 2 * lg(m+n)= O(lg(m+n))
因此时间复杂度是O(lg(m+n))





one-time-attention
第11、12、14、16、19、24行，要传递第几大这个参数(这里每行几乎都错了)，如果不删除数组多余的部分(也就是求第k大时，要从ln开始，而不是从 0开始)

把传参的方式改一下就不容易错了。把2个vector的begin和end分别传过去。这种函数在solution.cpp的后半部分









样例
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

