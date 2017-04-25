149_Max_Points_on_a_Line


题目大意
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

解决方案
给一堆点，找一条线能穿过最多点，返回最多是多少个点
思路：选择一个点作为必须经过的点，然后遍历所有点，计算通过这个点的线最多能通过多少个点
unordered_map<double, int> mymap;//double是斜率，int是这个斜率出现过多少次
one-time-attention
第一类点直接用map处理
1. 斜率可能无穷大，这就不能映射进map，这是第二类点
2. 重叠的点，既可以属于map，也可以属于斜率无穷大，因此是第三类
3. 注意map之前int 转double


样例


