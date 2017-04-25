55_Jump_Game


题目大意
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

解决方案
就是每步该往哪里跳要向后看，看到后面最好的地方跳过去。贪心算法

样例
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

