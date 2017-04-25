160_Intersection_of_Two_Linked_Lists


题目大意
Write a program to find the node at which the intersection of two singly linked lists begins.

解决方案
把headB队列的尾指向headA，然后将headB作为队列起点，调用找环起点的函数，最后再改回原来的样子，就ok

样例
For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

