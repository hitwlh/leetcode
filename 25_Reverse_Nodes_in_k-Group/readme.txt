25_Reverse_Nodes_in_k-Group


题目大意
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

实现一个子函数ListNode* reverseK(ListNode* head, int k)，
它能从给定head开始，反转长度为k的链，并返回反转后的链的头，

解决方案
由于head是调用前的头，调用完之后它就成了当前段的尾
设置一个标记变量，如果反转的串的长度小于k，则置这个标记变量(这样就知道反转结束)。
实现这个函数之后，就可以在主函数里循环反转k，反转完成后，要把最末尾的next置为下一次反转的head

容易错的地方：
1.由于head是调用前的头，调用完之后它就成了当前段的尾
2.不知道高效地怎么反转链表


样例
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

