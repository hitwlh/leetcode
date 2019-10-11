210_Course_Schedule_II


题目大意
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.



解决方案
207 Course Schedule的进阶版本，就是改成了返回如何选课，而非简单bool
并且如果无法选就返回{}
很简单，出队的表示那门课已经选掉了，所以就是依次把出队的课程push_back到ret里就是了。

样例


