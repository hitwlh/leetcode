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
可见如果发现重复元素，并且其后有quantile个重复元素，那就往后面quantile/(quantile+1)的列表里头添加2并加入ret

solution2.cpp
参照78题的添加逻辑：从左到右依次遍历，每次往ret集合里添加。
唯一需要多考虑的是重复的元素，
假设ret=集合S，后续需要处理的是AAA
假设对S中所有元素末尾添加A，组成的集合记为SA
那么先对S里的每个元素，添加一下A，在push进S，产生S'，即S = S + SA，然后下一个A怎么处理呢？
应该是S'' = S + SA + SAA
也就是对含A的元素后面再添加A
S''' = S + SA + SAA + SAAA
按照此规律，当处理AAA这样的序列时，应该是对上一步刚添加进去的元素后面添加A。

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

