11_Container_With_Most_Water


题目大意
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
大意就是在x轴上给n个隔板，取出其中两个，满足这两个隔板和x轴形成的容器(矩形)面积最大

解决方案
从两边开始搜索，左边i，右边j，i的初始值是0，j的初始值是n-1
假设ai < aj ，那么可能的解一定是aj不动，i往右，加入反过来，令ai不动，aj往左，一画图就知道这样的答案不如ai aj
想到解决方案之后这道题的代码非常好写


样例


