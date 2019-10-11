365_Water_and_Jug_Problem


题目大意
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

解决方案
参考http://www.cnblogs.com/grandyang/p/5628836.html
该问题等价为1&&2
1. 给定的量小于等于水罐容积之和
2. 用两个水罐，往一个大水箱里加水。能否加到给定的量？
第二个问题的解，ax+by=c，等价为c是否为a、b的最大公约数的倍数。



样例
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False


