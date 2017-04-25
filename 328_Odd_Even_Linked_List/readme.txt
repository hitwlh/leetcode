328_Odd_Even_Linked_List


题目大意
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

解决方案
这题本身挺容易的，但是有个易错的点
one-time-attention:
把原队列打断为两段之后，前半段的末尾要和后半段连接上，这是很容易的，但是千万记住后半段的末尾要置为NULL!否则可能后半段的末尾指向前半段造成环

样例
Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

