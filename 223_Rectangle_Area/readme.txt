223_Rectangle_Area


题目大意
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.

解决方案
题目翻译：在一个平面内给两个矩形(左下角和右上角坐标)，求这两个矩形所占的面积。
参考http://www.jianshu.com/p/59e841a8671c
这题非常值得看。如果没看这题的题解，就去分类讨论的话，那太没意义了，而且也很容易写错。
应该将相交部分分解成2个一维去处理。这个直接看链接里的图就好了，非常好理解。

one-time-attention
第5行代码是if(min(C, G) > max(A, E) && min(D, H) > max(B, F))
不能写作相减大于0的形式，因为相减可能超出int范围。

样例


