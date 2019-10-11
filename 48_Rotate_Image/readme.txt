48_Rotate_Image


题目大意
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?

解决方案
我的做法是把上、右、下、左标为四份，每份计起点不计终点
然后先保留一份，然后赋值三份，再用保留的赋值最后一份
也就是四个for循环，见solution.cpp
one-time-attention
先在纸上写下四份的循环遍历方式，然后按照这个来写，才比较快。从这里也发现了写这种代码的方法，如果有多个for循环，最好草稿纸上写清楚for的迭代范围！！！
注意起点是(i,i) 终点是(n,n) 注意到for里有两次n+i-j，那里很容易错

但是这题还是有更容易的写法！！！
我只是按照直观地写了，懒！！要是想一想数学上的等价代换方式代码会好些不少！！
网上有一种解法：先求转置然后每行逆一下！！这个就非常容易写...

样例


