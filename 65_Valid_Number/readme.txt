65_Valid_Number


题目大意
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.



解决方案
参考网上的


'+' '-'等价
搞清楚逻辑：
'.'前面不能有'.'、'e'
'e'前面不能有'e'，并且'e'前面必须有数字
'+'要么在开头，要么在e后面

不能以'+' '-' 'e'结尾
有'.'必须有数字
不能全为' '


满足以上条件就返回true



样例

e9
6.e+10
6e+9
