324_Wiggle_Sort_II


题目大意
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Note:
You may assume all input has valid answer.



解决方案
参考http://chenyou-fdu.github.io/2016/12/17/Wiggle-Question/

这里的难点在于要求严格大于和严格小于，如果是大于等于或小于等于，那就是easy的难度，直接遍历一次看是否swap就行了。


这题的第一种解法是先sort整个数组。然后找到中位数，中位数右侧的是大数、左侧是小数。注意：中位数右侧和左侧都可以有和中位数相等的数，因此这里可能造成不满足要求的情况。所以需要(从左到右)逆序写(小数从大到小写，大数也从大到小写)。代码在solution1.cpp
这种解法空间O(N),时间O(NlogN)

再进一步思考，可以想到，其实不需要真的完美sort一遍，只需要划分为中间(一系列和中位数相等的数字，)、左边(比中位数小)、右边(比中位数大)，左边和右边内部都没有和中位数相等的数字。
至于左边和右边内部的顺序，则毫无关系。因此可以先通过c++的nth_element找到中位数，然后用sort colors的思想将数组sort成需要的划分。 最后再粘贴solutin1.cpp sort后面的代码就是了(solution1.cpp里通过sort把和中位数相等的数字排放在了一起)，代码在solutino2.cpp
这种解法空间O(N),时间O(N)。
其中用到了stl的nth_element，stl用quickselect实现的nth_element。在215题我自己也写了quickselect实现的nth_element。

再进一步思考，solution2.cpp里的核心思想其实就是大数从左往右写，小数从右往左写，剩下的空位填充中位数。
也就是对于原数组中位数左侧的，是先写中位数，再写小数。右侧的，是先写大数，再写中位数。
因此也可以借鉴sort colors处的思想。
先顺序处理奇数位，如果奇数位大于中位数，把它放左侧(奇数位，swap过来的一定是等于中位数的)，如果小于中位数，把它放右侧(偶数位)，注意如果swap右侧的过来，需要判断右侧过来的数字是什么(小数？大数？)
再顺序处理偶数位，如果偶数位大于中位数，把它放左侧(奇数位，swap过来的一定是等于中位数的)，如果小于中位数，把它放右侧(偶数位)，同样需要判断右侧swap过来的是什么数字。
道理是这么个道理，直接按照这个道理写的代码在solution3.cpp开头。


但是还有更简洁的写法：
用映射函数auto indexMap = [size](int index) { return (1+2*index) % (size | 1);};
举例1：
n = 10
index indexMap(index)
0       1
1       3
2       5
3       7
4       9
5       0
6       2
7       4
8       6
9       8

举例2：
n = 9
index indexMap(index)
0       1
1       3
2       5
3       7
4       0
5       2
6       4
7       6
8       8
令左侧(i) = 0, 右侧(j) = nums.size()-1, now = 0
然后对now从0到nums.size()-1遍历一遍。indexMap(now)就是先遍历奇数再遍历偶数。大数写左侧indexMap(i)就是从左到右写奇数位置，小数写右侧indexMap(j)就是从右到左写偶数位置。剩下没写的就是indexMap(i)以右indexMap(j)以左，也就是中位数分布在indexMap(i)右侧indexMap(j)左侧。
这种解法在solution3.cpp的后半部分



这题实在太妙了！！！



样例

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].


