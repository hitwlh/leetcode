237_Delete_Node_in_a_Linked_List


题目大意
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

解决方案
题目的意思是给Linked List 中的一个点，然后要删除它。 但是不知道list的起点，因此有个比较好玩的思路：就是先拷贝当前node的next的val到node，然后把node->next结点删掉

样例


