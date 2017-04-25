210_Course_Schedule_II


题目大意


解决方案
207 Course Schedule的进阶版本，就是改成了返回如何选课，而非简单bool
并且如果无法选就返回{}
很简单，出队的表示那门课已经选掉了，所以就是依次把出队的课程push_back到ret里就是了。

样例


