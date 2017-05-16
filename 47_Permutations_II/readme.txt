47_Permutations_II


题目大意
Given a collection of numbers that might contain duplicates, return all possible unique permutations.







解决方案
46题的进阶版本，可以有重复元素，在全排列中要去重。
我的解法是用46题的递归解法，solution1.cpp的后半部分。
添加的内容：
1. 先对vector sort一遍，确保vector中重复的元素连续出现。
2. 在递归的时候，加上条件if(next == i || nums[next-1] != nums[next])。因为如果有一连串相等的，那就不需要再将相等的交换到前头。





样例
For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]


