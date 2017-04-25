547_Friend_Circles


题目大意
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.




解决方案
题目翻译：就是一堆人互相认识，然后要找一下看看这里头有多少个圈子。
进一步理解：
两个圈子只需要有同一个人，这两个圈子就融合了。比如ABC、ADE会融合成ABCDE
一个人如果和谁都不认识，那他自己就是一个圈子


理解清楚这两点之后这题很好写，就dfs一下，如果遇到一个人的邻居没被标记，就去dfs他就Ok了
要注意的是，不能光往“后”看，比如
1-4-2-3 这样的输入
如果光是往后看，1连接了4，4往后看没人了，看不到他和2相连，就会返回2，表示找到2个圈子，事实上应该返回1

样例
Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

