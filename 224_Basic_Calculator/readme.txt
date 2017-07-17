224_Basic_Calculator


题目大意
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.




解决方案
其实这里的东西全都挺简单的，只有加减号以及圆括号，那就说明优先级只有遇到圆括号的时候有变化，其余的顺序处理。
逻辑：
顺序处理，遇到"("时将当前结果和符号信息入栈，然后处理括号内的内容；遇到')'时，把栈内的信息弹出来，和括号内的结果进行运算。

one-time-attention
1. 代码里用oldnum来存储当前运算('+'/'-')之前的运算结果，num存储数字。在遇到'+'/'-'的时候，要先对oldnum = oldnum + flag * num;
也就是说，遇到加减号的时候，才算读完了一个num，这时要根据上一个加减号处理oldnum和num的运算。因此在处理括号内部时，把括号内运算结果记录在num里(19行)，然后把括号前的运算信息写到oldnum和flag里。右括号后面跟的如果是'+/-'，就可以得到计算了；如果到此结束，就在跳出while循环后再完成最后一步的运算。



one-time-attention

样例

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

