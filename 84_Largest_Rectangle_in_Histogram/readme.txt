84_Largest_Rectangle_in_Histogram


题目大意
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

解决方案


有两种解法：

1.
参考http://ihuafan.com/%E7%AE%97%E6%B3%95/largest-rectangle-in-histogram#o-nlogn-%E7%9A%84%E5%88%86%E6%B2%BB%E6%B3%95
利用最矮的那个直方图，将其作为二分的分界线。
1. 找到数组中最小的元素，计算矩形覆盖candidate = 最小元素 * 直方图数量
2. 计算最小元素左边的最大矩形覆盖leftMax（不包括最小元素）
3. 计算最小元素右边的最大矩形覆盖rightMax（不包括最小元素）
4. 最大矩形覆盖是 max( candidate, leftMax, rightMax )
关键是如何高效地求得数组中的最小元素，答案是线段树。
这种解法对应solution1.cpp

2.
参考http://blog.csdn.net/revivedsun/article/details/52420679
用一个升序栈，顺序遍历，如果当前的值小于栈顶，那就一直弹栈，直到栈为空或者栈顶小于当前的值，那么，以当前的值为右边界，栈顶为左边界的矩形就是以当前的值为右边界所能获得的最大矩形面积
这种解法对应solution2.cpp


第11、42、84、85题结合看
样例
Given heights = [2,1,5,6,2,3],
return 10.

