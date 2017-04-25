109_Convert_Sorted_List_to_Binary_Search_Tree


题目大意
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

解决方案
首先做108题，实现数组类型的。
这题需要改进的就是查找中点不是直接用(left+right)/2，而是要从left往right走一半
注意一个就是递归调用有这步：
reeNode *root = new TreeNode(middle->next->val);
root->left = my_sortedListToBST(left, middle);
root->right = my_sortedListToBST(middle->next->next, right);
也就是说至少长度为3才可以递归调用。因此在递归调用头部要写好长度为1、2、0的list的情况
if(left == right)
    return left == NULL ? NULL : new TreeNode(left->val);
if(left != NULL && right != NULL && left->next == right){
    TreeNode *root = new TreeNode(left->val);
    root->left = NULL;
    root->right = new TreeNode(right->val);
    return root;
}
if(right != NULL && right->next == left) return NULL;
那我找middle部分的代码就只需要考虑长度为3及3以上的list的情况了。。
这是一个挺有用的技巧！！！
就是如果递归处理不了，那就把它手写放到首部。(按照array的，那就只需要处理长度为0和长度为1递归终止，但是list这里我把2的也手动构造并终止递归了)


样例


