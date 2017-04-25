90_Subsets_II


题目大意
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.

解决方案
和78. Subsets相似，就是加了重复元素的内容
先sort一下
观察规律：
222A
[[A]]
[[A] [A2]]
[[A] [A2] [A22]]
[[A] [A2] [A22] [A222]]
可见如果发现重复元素，并且气候有quantile个重复元素，那就往后面quantile/(quantile+1)的列表里头添加2并加入ret



样例
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

