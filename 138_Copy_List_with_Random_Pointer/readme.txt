138_Copy_List_with_Random_Pointer


题目大意
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

Return a deep copy of the list.

解决方案
这题的题意是每个结点除了next还有random，需要拷贝。
难点在于如果直接线性顺序拷贝，在创建一个结点的时候并不知道random。
解决方案，
1. 顺序遍历队列，在原先的队列每个点后面都插入一个和自己一模一样的结点
2. 顺序遍历队列，将插入点的random设置对
3. 顺序遍历队列，将拷贝的点拉出来形成一个新的队列

one-time-attention:
2、3步不能同时进行，因为后面的点的random可能指到前面去了，而如果前面的点已经被拉出来，就会出错，因为找不到正确的random了，在提交的代码中好多wa就是这个原因导致的

样例


