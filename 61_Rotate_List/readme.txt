61_Rotate_List


题目大意
Given a list, rotate the list to the right by k places, where k is non-negative.
给定一个链表，向右旋转k个位置，其中k是非负的。
先遍历一遍，得出链表长度 len，注意 k 可能大于 len，因此令 k% = len。

解决方案
这题挺简单的，就是要理解下题目，然后问清楚k可能大于len

样例
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

