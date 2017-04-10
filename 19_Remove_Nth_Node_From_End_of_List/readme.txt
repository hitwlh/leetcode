19_Remove_Nth_Node_From_End_of_List


题目大意
Given a linked list, remove the nth node from the end of list and return its head.

解决方案
这题有个地方容易错，那就是删除的节点可能是head，因此一开始新建一个Head结点，这样便于处理删除head。
两种解决方案：
1. 先扫描一遍看一共有多少节点N，然后N-n就是待删除节点的顺排序，再扫描第二次，找到待删除节点，见solution1.cpp
2. 用两个指针，第一个指针先走n步，第二个指针不动；然后第一个指针往后走到尾，同时第二个指针一起走。这样第二个指针比第一个指针少走n步，就找到了待删除的结点，见solution2.cpp

样例
For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.

