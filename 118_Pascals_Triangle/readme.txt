118_Pascals_Triangle


题目大意
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,

解决方案
杨辉三角，每一行的首个和结尾一个数字都是1，从第三行开始，中间的每个数字都是上一行的左右两个数字之和
one-time-attention:
for(int j = 1; j < i-1; j++)
    now.push_back(tmp[j-1]+tmp[j]);
样例
For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

