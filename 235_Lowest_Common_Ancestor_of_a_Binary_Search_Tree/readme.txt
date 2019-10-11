235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree


题目大意
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

解决方案
这题的难度是easy，但是要想到O(N)的解法其实并不简单吧
1.比较简单的做法是从root开始递归看左右，这样的时间复杂度是O(NlogN)，代码在solution1.cpp
2.O(N)时间，O(N)空间的解法：
用后根遍历，后根序列能保证一个节点的父亲一定在它后面，将后根遍历的结果保存在一个(queue/vector/stack)里，然后线性扫描它，找p和q的父亲，一旦父亲相等，那就是需要的Lowest Common Ancestor
举一反三：凡是需要二叉树的pre指针，可以用后根遍历
代码在solution2.cpp
3.O(logN)时间，O(1)空间的解法：
根据二叉比较树的性质，直接判断root是否是最低根
样例

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
