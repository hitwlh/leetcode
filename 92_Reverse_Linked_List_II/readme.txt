92_Reverse_Linked_List_II


题目大意
Reverse a linked list from position m to n. Do it in-place and in one-pass.

解决方案
这题其实挺常规的，先要会206. Reverse Linked List
但是这题有个容易错的点！！！需要通过设置Head头结点来解决。
那就是翻转完以后应该返回什么？如果返回head，那就不太对了，因为head可能被翻转到后面去。因此设置一个头结点Head，初始化它的next为head，然后翻转，最后返回Head.next就行了
翻转的时候要有FOLLOW表示翻转的起点的前一个点，然后翻转完之后要把FOLLOW的next指向翻转完的段的起点。
因此如果没有Head，就不好弄了，因为FOLLOW压根就没一个正确的“意义”（FOLLOW表示翻转起点的上一个结点，如果没有Head那加入head是翻转的起点，那他的上一个点是什么呢？就全乱套了 ）

样例
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

