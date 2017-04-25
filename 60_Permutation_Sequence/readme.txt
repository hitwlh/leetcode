60_Permutation_Sequence


题目大意
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.

解决方案
性质：
第k个排列的第一个元素在1-n中的位置为（k-1）/（n-1)! + 1
然后反复处理

2个子函数：
求阶乘
求1-n中第k个可用的数(因为之前可能已经把一些数字用掉了)，不能直接索引到第k个可用的数字

样例


