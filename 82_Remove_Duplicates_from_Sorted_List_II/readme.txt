82_Remove_Duplicates_from_Sorted_List_II


题目大意
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

解决方案
跟第83题相比这题要稍微难一些，因为它要把duplicate全删掉，就是要把一串相等的头也删掉，因此可以在最开始添加一个Head头，然后往后删除所有相等的。有两种做法：
1.设置一个flag，如果开始删除了，就把flag置为true，就知道要删除头
2.直接定义int val，往后一串和val相等的都被删掉，这种写法相对好些一些，但是也很容易出错！！！

样例
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

