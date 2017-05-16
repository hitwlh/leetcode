401_Binary_Watch


题目大意
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".




解决方案
参考http://blog.csdn.net/camellhf/article/details/52738031

这题有两种思路。第一种思路是bitset，遍历。
把亮0、1、2、3盏灯所可能的hour放到对应的vector里
再把亮0、1、2、3、4、5盏灯所可能的minute放到对应的vector里
然后根据num，从0盏hour到min(3, num)盏hour，同时对应得出num - i盏minute，然后把两个vector拼在一起就ok了
还有种bitset的写法。
类似的写法全在solution1.cpp里了


第二种思路就是递归，每次看一盏灯是否能点亮。
这里的dfs挺有借鉴价值的：有两排灯，某次要选择一个灯去点亮。
if(flag1 && flag2)
    dfs(n_h.to_ulong(), n_m.to_ulong(), num-2, h_start+1, m_start+1);
if(flag1)
    dfs(n_h.to_ulong(), minute, num-1, h_start+1, m_start+1);
if(flag2)
    dfs(hour, n_m.to_ulong(), num-1, h_start+1, m_start+1);
dfs(hour, minute, num, h_start+1, m_start+1);
注意第一个dfs，如果2盏灯都可以亮，那应该有同时点亮这两盏灯的


综合起来看，这题最快的思路还是solution1.cpp里的第三种写法。但是这种解法是暴力搜索整个解空间，应该算是效率比较低，只是因为这题的空间太小，所以没问题。

样例
Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

