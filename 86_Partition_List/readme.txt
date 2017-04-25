86_Partition_List


题目大意
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

解决方案
遍历head一遍，用两个ListNode *队列分别保存两种，然后拼接起来.
one-time-attention:
1. 返回的只能是队列头
2. 拼接不只是前半部分接上后半部分，还要把后半部分的next设置为NULL！！！

样例
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

