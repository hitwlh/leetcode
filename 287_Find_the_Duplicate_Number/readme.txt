287_Find_the_Duplicate_Number


题目大意
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.



解决方案
题目翻译：一个大小为n+1的数组，里头的数据从1到n，其中有且只有一个数是重复出现的，找出这个数字。
要求：
1. 这个数组只读，不能改
2. 只能常数空间，不能用额外的空间
3. 时间复杂度...

第一种解法是二分法。
区间[left, right]，
初始值left = 1, right = n，
显然答案在这个区间内。
然后求middle = (left + right) / 2
遍历原数组一遍，求出middle 、 [left, middle)、 （middle, right]分别有mt、 lt、 rt个。
如果middle有超过1个，那就返回middle。否则
if(rt > lt)
    left = middle + 1;
else
    right = middle - 1;
这里是有奇偶数的考量：
以[1, 10]和[1,11]为例
[1, 10], 左右分别是[1, 5) (5, 10]左侧有4个右侧有5个，因此如果答案在右侧，rt>lt（如果答案在左侧，lt >= rt）
[1, 11]， 左右分别是[1, 6) (6, 11], 左侧有5个，右侧有5个，因此如果答案在右侧，rt>lt（如果答案在左侧，lt > rt）
可见以奇偶来看，只有rt>lt是一致的，lt可能>=rt 也可能>rt
时间复杂度是o(nlogn)
代码在solution1.cpp

第二种解法是环法
假设a[i] = m 表示a[i]的next是a[m]。显然这样访问是合法的，因为1 <= a[i] <= n。不会发生越界
并且这相当于一个链表，如果没遇到重复的数字，这个链表就会一直去往不同的地方。而一旦遇到重复的数字了，链表就会回到之前去过的地方。这就是要找带环链表的环入口了。
这个算法之前做过，还算简单。
时间复杂度是o(n)
代码在solution2.cpp

如果

样例


