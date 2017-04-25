56_Merge_Intervals


题目大意
Given a collection of intervals, merge all overlapping intervals.

解决方案
根据start sort，然后如果和后面的相重合就合并。

one-time-attention
1. end并不一定用后面的那个元素的，因为后面的元素可能是前面元素的子区间
2. 不应该用一个新的vector做拷贝，因为可能需要连续合并，这样的逻辑用新的vector的话判断起来麻烦点，如果单纯合并一次就添加到ret，那极有可能不对

样例
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

