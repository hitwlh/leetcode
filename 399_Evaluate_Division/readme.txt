399_Evaluate_Division


题目大意
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

解决方案
这题容易漏的点：
(a,b) (c,d) (b,c)
也就是说如果简单地线性处理，可能后面的等式将同类的字符串归到不同类去了
正确的思路是：
每次处理整个vector来找同类，遇到同类则直接归并，遇到不同类不能直接新增，如果要新增类，需要上次处理时什么也没做（这样处理这个例子时，遇到cd因为当前轮有动作，所以不新增类，下一轮会发现cd不是新类）


样例
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.



