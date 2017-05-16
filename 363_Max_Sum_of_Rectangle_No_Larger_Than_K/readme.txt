363_Max_Sum_of_Rectangle_No_Larger_Than_K


题目大意
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?


解决方案
题意非常好理解，就是要在一个矩阵里找和最接近k的子矩阵。

最基础的解法就是暴力遍历，这种解法在solution1.cpp里。


进一步优化。在discuss里的c++里讲得很清楚。
有两个基础。先看53题的题解。
1. 是二维空间里怎么去动规，53题题解里说了MxN矩阵求最大子矩阵的办法，这题的思想一样，就是要压缩。行的可能性暴力遍历，C(M, 2)，处理列的时候打成1维的，去1维动规。
2. 怎么处理一维。这题一维和53题的不一样，不是找最大，而是要找最接近k的。
参考了https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
其实并不是动规。对csum数组(假设对它顺序累加得到sum)。要找满足和最接近k的子数组，如果记结果为序列i, ..., j。也就是sum[j] - sum[i] + csum[i] 最接近k。
解法：保留一个set，从左到右遍历，处理到j时，假设j为终点，则起点为myset.upper_bound(csum[j] - k - 1);myset.upper_bound(x)是找myset里>x的最小数。因此myset.upper_bound(csum[j] - k - 1)就是找最小的csum[i]，且csum[i] >= csum[j]-k，即
csum[j] - csum[i] <= k， csum[i]是最小的，csum[j] - csum[i]就是最大的，也就是i是j左侧所能找到的令子数组和最接近k的左端点。 这就是以j为右端点所能获得的最靠近k的解，然后把sum[j]入myset。再处理下一个元素。

找i的开销是O(logN)，再加上从左到右遍历，因此总开销是(N*logN)
整个算法的开销是(M*M*N*logN)

如果M>N,转置下矩阵





样例

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

