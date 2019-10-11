46_Permutations


题目大意
Given a collection of distinct numbers, return all possible permutations.

解决方案
有很多种思路

1.递归。solution1.cpp 参考https://blog.csdn.net/a358463121/article/details/45543879
设R={r1,r2,…,rn}是要进行排列的n个元素，Ri=R-{ri}. 
集合X中元素的全排列为Perm(X)。
（1）当n=1时，Perm(R)=(r),其中r是集合R中唯一的元素； 
（2）当n>1时，Perm(R)可由(r1)+Perm(R1),(r2)+Perm(R2),…,(rn)+Perm(Rn)构成。
具体写的时候找开头元素有swap和insert两种方式。
insert能保证字典序排列，而swap不行
如{1,2,3}，在用3开头时，如果是swap，第一个是1和3交换得来的321，而用insert就是把3insert到前面去，再删除后面的3，就是312，这才能保证正确的顺序。

2. 用next_permutation将按字母表顺序生成给定序列的下一个较大的序列，直到整个序列为减序为止。solution2.cpp

3. solution3.cpp
考虑3个数的全排列
[a1]
[a1 a2] [a2 a1]
[a3 a1 a2] [a1 a3 a2] [a1 a2 a3] [a3 a2 a1] [a2 a3 a1] [a2 a1 a3] 
因此每次就是把需要插入的数字插入到上一层每个vector的每个位置
这种方法没法保证顺序

样例
For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

