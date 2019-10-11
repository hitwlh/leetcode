57_Insert_Interval


题目大意
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

解决方案
这题其实并不难想。首先判断区间段是否空，
如果空，直接插入，然后返回
如果不空，从头到尾看要添加的内容是否和已有的区间有重叠
1. 如果有，那就和那个区间合并，然后从头到尾做区间合并
2. 如果没有，那就从头到尾找需要插入的位置

就是区间判断重合以及insert、erase的位置需要细心一些

样例
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].



