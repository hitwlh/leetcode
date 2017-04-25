114_Flatten_Binary_Tree_to_Linked_List


题目大意
Given a binary tree, flatten it to a linked list in-place.
就是要用先根遍历的结果把树变成一个队列(保留树的组织形式)

解决方案
1.很简单，用一个queue存储先根遍历的结果，然后构造整棵树，在solution1.cpp中
2.参考网上答案，正面考虑这个算法
只把root这个点解决，只需要
root->right = root->left;
root->left = NULL;
需要考虑的是原先的right应该怎么处理呢？要知道root->right是先根遍历中最后处理的部分
因此只需要把它放到root左子树的最右，这样它就在左子树的先根遍历中也仍然是最后处理的部分，就保证了顺序的正确性(也就是root处理好之后，处理root左子树，在左子树处理完之后才处理root右子树)，在solution2.cpp中


样例

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
