99_Recover_Binary_Search_Tree


题目大意
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

解决方案
这题很容易想到用中根遍历，找到次序不对的两个数，用place1、place2两个指针指向需要交换的位置，中根遍历找到这两个位置就ok
有性质：a[place1]>a[place1+1]、a[place2-1]>a[place2]


但是有个one-time-attention
那就是从头到尾，满足性质的place1、place2至多有2组(下面的100到1序列)，place1应该用前面的，而place2应该用后面的

2, 1, 3
这里place1指向2， place2指向1。

100, 2, 3..., 1
这里place1指向100， place2指向1。

样例


