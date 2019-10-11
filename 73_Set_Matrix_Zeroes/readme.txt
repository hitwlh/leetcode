73_Set_Matrix_Zeroes


题目大意
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
click to show follow up.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?



解决方案
如果一个位置的数字是0，把它那行、列都设为0

我的想法是如果一个数字是0，把它所处的行首、列首元素设为0，遍历整张表，然后看行、列是0的地方设置对应整行、整列为0

这题非常容易写错！！！
首先需要标识第0行、第0列需不需要置零，因为整张表的0归到第0行、0列后，破坏了原先第0行、0列是否有0的信息。！！


one-time-attention
1. 最开始的代码是直接三次for，第一次设置[i][0]、[j][0]为0，第二次设置整行为0、第三次设置整列为0。
这样做错了，因为如果设置到[1][0]为0，它会把第[0]列全部置为0，然后第[0]列会把剩余的行全置为0
2. 正确的做法是先标记一下第一行、第一列是否有0元素，然后对[1,1]为左上角的矩形，按照[i][j]是否是0去设置[i][0]、[0][j]，最后根据第0行、第0列去设置[1,1]为左上角的矩形，再根据一开始的标记设置第0行、第0列


样例


