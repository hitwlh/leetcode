435_Non-overlapping_Intervals


题目大意
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

解决方案
给出一系列区间，要求删除掉有交叉的区间。
由于题目给出了end>start这个条件，那就说明所有start相同的区间都肯定交叉了，必须删除冗余、只留下一个
sort一下，然后unique来删冗

然后就是从头到尾去删除交叉了。贪心策略：如果要删除，就删掉占用空间尽量少的那个
从左往右看，先看第一个和第二个，如果不用删除，那就看第三个，如果要删除，删掉占用空间更小的那个。

一开始写错了，改了两次才改对。就是如果选的话用min函数，如果不选用max函数
one-time-attention
if(intervals[i].start < next_end){
    ret++;
    next_end = min(intervals[i].end, next_end);
}else
    next_end = max(intervals[i].end, next_end);

样例
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

