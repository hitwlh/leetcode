72_Edit_Distance


题目大意
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

解决方案
很经典的动规，空间复杂度应该应该可以优化到 M+N+O(min(M,N))
那样写有点麻烦，solution.cpp里是O(MN)

one-time-attention
一开始我用len[0][i]表示s1[0] 与s2[0...i]，然后 for(int i = 1; i < len[0].size(); i++) len[0][i] = len[0][i-1] + 1;更新
这样错了，后来改成len[0][i]表示""与s2[0..i-1]

考虑反例：
se
e
如果用第一个方法，这两个的edit距离是2，事实上是1

样例


