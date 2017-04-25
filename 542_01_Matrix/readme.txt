542_01_Matrix


题目大意
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.



解决方案
挺简单的一道题，竟然写了好多遍才ac，记得要对queue做pop
这道题的思路就是先把非0改为-1，表示没到过
然后将所有0入队，然后再入队(-1， -1)表示这是一层。
然后对队列第一层的所有点的邻点判断是否到过，没到过就入队，并置为到这里的步数

one-time-attention
记得要置为步数、以及最后压入-1的前提是非空。否则读到最后一个-1，然后反复压入-1就糟糕了，死循环




样例
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1

