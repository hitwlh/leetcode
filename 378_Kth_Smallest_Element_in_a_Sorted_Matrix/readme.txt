378_Kth_Smallest_Element_in_a_Sorted_Matrix


题目大意
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.





解决方案
这题一个关键要把握的点就是有序的关系。我一开始想的是
a[0][0]
a[0][1] a[1][0]
a[0][2] a[1][1] a[2][0]
这样依次有序。但是不对，a[0][1] < a[1][1] a[0][1] < a[0][2] 但是a[0][1]和a[2][0]的大小关系是不确定的



参考
https://www.hrwhisper.me/leetcode-kth-smallest-element-sorted-matrix/



solution1
因此如果想一直能找到最小的，应该加上一个小根堆进去。
先将a[0][0]放进堆里，然后只要没找到第k大，就把相邻的元素压入堆里。这样就能保证一直找到正确的当前最小，一直找到前k小为止。时间复杂度为O(klogk)
要注意入堆的策略，避免重复入堆。
solution1.cpp里的策略是第一行的入堆右边和下边，非第一行的只入堆下边。
代码里头自定义结构的优先队列代码值得参考



solution2
二分法。初始L = matrix[0][0] R = matrix[n-1][n-1]
这里的二分法非常值得看。

每次获得整个矩阵里小于等于mid的元素的个数temp
如果temp < k , 则L = mid + 1， 否则R = mid
要注意必须这样写。如果temp >= k ， R = mid。 因为如果要找第100小的，假如是50，假如严格比50小的数字只有90个，而第91到第110全是50，而mid = 50，这个时候temp是110 > k 但下一步的right也只能是50，而不是50-1



时间复杂度
查找一行需要log(n) ，有n行所以nlog(n)，最坏下需要查找log(X)次（X= int最大值的时候logX仅仅才为32），X为最大最小数差值。  所以总复杂度为O(nlogn *  logX)

后来我自己写了lower_bound的方法。lower_bound不简洁，最后会有2个备选答案L/R，且L+1==R，需要跳出循环后判断哪一个成立。



样例
Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

