143_Reorder_List


题目大意
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

解决方案
1.将链表平均分两部分

2.将后半部分reverse

3.将第一部分和reverse之后的后半部分合并。

样例
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

