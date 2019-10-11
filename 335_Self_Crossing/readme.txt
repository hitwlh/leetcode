335_Self_Crossing


题目大意
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

解决方案
参考
http://www.cnblogs.com/grandyang/p/5216856.html
http://blog.csdn.net/ciaoliang/article/details/50791254

这题的解法是假如把当前画的这笔作为最后一笔，那这一笔是否可能造成Self_Crossing？
这题的关键在于自己去画，画过之后发现，只有3种Self_Crossing模式，其余所有相交，都可以被转换成这3种模式。这里不方便画图，看链接。
然后就很容易了，从第3笔开始，看它是否是某种模式，如果是，就找到了，可以返回了。

样例
Example 1:
Given x = 
[2, 1, 1, 2]
,
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)
Example 2:
Given x = 
[1, 2, 3, 4]
,
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
Example 3:
Given x = 
[1, 1, 1, 1]
,
┌───┐
│   │
└───┼>

Return true (self crossing)

