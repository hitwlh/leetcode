526_Beautiful_Arrangement


题目大意
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?



解决方案
输入N，找这样的序列：
位置i的数字nums[i]，满足nums[i]%i == 0 || i % nums[i] == 0
求这样的序列的个数

solution1.cpp
这里的解法是，找每个位置所能填充的数字
先看nums[0]能填充什么(如果填充10，则标记10用过了，后面的就不能再用10)；
再看nums[1]能填充什么...
这种解法比较慢

solution2.cpp
从solution1.cpp来看，这就是需要找满足题意的全排列，因此先生成一个顺序的数组，然后直接用全排列的swap方式去看全排列，然后判断一个序列是否满足题目的要求
比soluito1.cpp快了一倍以上，因为用过的数字就不靠标记，而是实现了直接从没用过的数字里来swap

solution3.cpp
是solution2.cpp的进阶，因为solution2.cpp是从前向后生成全排列的，但是第一个位置任意元素都可以放（所有元素模1都为0，所以所有元素都可以放在第一个位置。同理，mod的数越小，mod成功的概率越大(1/1, 1/2, 1/3, 1/4...),因此应该从后往前放置），这就很不好了，因为递归应该第一层越小越好，因此可以从后向前生成全排列，这能快10倍！


样例
Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.

