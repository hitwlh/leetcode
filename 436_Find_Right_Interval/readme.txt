436_Find_Right_Interval


题目大意
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.


让我们找每个区间的最近右区间，要保证右区间的start要大于等于当前区间的end



解决方案


首先对所有区间的起始点进行排序，然后对每个区间使用二分查找来找到与这个区间结束点最接近的起始点的区间，并且获得该区间的索引。
这个二分查找可以抽象为：
对于不下降序列a，求最小的i，使得a[i] >= key
注意这里要找到最左边的满足条件的index，而不是找到等于key的index就返回。看代码：
mid = left + (right - left) / 2;
if(copy[mid].start < target) left = mid+1;
else right = mid - 1;
这种查找非常有意思！！！interesting




样例
Example 1:
Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:
Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
Example 3:
Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.

