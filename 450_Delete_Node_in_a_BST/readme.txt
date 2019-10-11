450_Delete_Node_in_a_BST


题目大意
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

解决方案
就是简单的删除而已
我拿左子树的最右结点去替代root
记住：
1.最右结点的父节点的right要设置为最右结点的left
2. 最右结点的right设置为root的right
3. 最右结点的left设置为root的left
4. 返回最右结点

非递归的解法，在solution1.cpp。有直接赋值和纯修改指针两种方案，其中，纯直接赋值，比较简单。

样例
Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

