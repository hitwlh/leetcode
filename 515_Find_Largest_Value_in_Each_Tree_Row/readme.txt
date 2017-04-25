515_Find_Largest_Value_in_Each_Tree_Row


题目大意
You need to find the largest value in each row of a binary tree.

解决方案
就是简单的层序遍历。但是怎么标识一层结束？当然可以push -1，但是这题没有说数字全是正数，所以可能-1也是数字，就乱了
我做的方法是表示每层有多少个数字，这样当pop出来那么多数字时，就知道这层结束了，这个要非常细心才行，很容易错！！

样例
Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

