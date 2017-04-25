142_Linked_List_Cycle_II


题目大意
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.



解决方案
参考以下两个：
http://blog.csdn.net/doufei_ccst/article/details/10578315
http://blog.sina.com.cn/s/blog_725dd1010100tqwp.html
判断环的方法：快慢指针
找到入口点：快慢指针碰撞的地方，然后从head以及碰撞的地方往前走，碰撞的地方就是入口
证明见上面的网页

拓展：
求环的长度、链表的长度
判断两个无环链表是否相交
如果相交，求出第一个相交的节点；



样例


