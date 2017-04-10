37_Sudoku_Solver


题目大意
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.

解决方案
用搜索+回溯的方法做，把一个空填了，然后判断填完是否造成失败，如果失败，就换一个字符重填该空，否则递归调用来填下一个空，如果递归结果是成功，就成功，否则换一个字符重填该空。
注意在填完之后判断是否成功时，只需要判断这个空的行、列、格是否有与它相等的就行了，这样能快很多。一开始用Valid Sudoku里的map方法，发现非常耗时。这里要利用这个特点啊，就是填之前合法，只需要判断填的这个是否造成失败，也就是说填之前那些都是不相等的，就不需要用map了


样例


