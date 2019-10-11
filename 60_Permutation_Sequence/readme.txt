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
求阶乘fac
求1-n中第k个可用的数(因为之前可能已经把一些数字用掉了)，不能直接索引到第k个可用的数字


solution2.cpp
从左到右遍历，可以根据k来确定当前位置应该填什么数字，然后再更新k、进入下一个位置(右边相邻的)，重复处理。直到处理完所有位置。
需要注意的是：某个位置填写第m大的数字，但不一定是m，因为1,2,3...,m-1可能填过了，因此需要用geti函数去找第i大的数字到底是哪个
还有就是为什么用((k-1) / calculate(n-now) + 1)
+1 是因为满了之后“溢出”
假设输入2 3 ，输出应该是132
刚进入处理的时候，n=3，now=1
则calculate(n-now)=2，而k=2，2/2+1=2，第二大，是2，错了：进位应该是按照k-1来找
所以是(k-1) / calculate(n-now) + 1


样例


