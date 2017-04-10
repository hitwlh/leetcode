6_ZigZag_Conversion


题目大意
把一个 zigzag pattern的string给read line by line

解决方案
nRows==1时，中间没有；nRows==2时，中间有一行；其它情况中间有nRows-1行

样例
convert("PAYPALISHIRING", 3)
P   A   H   N
A P L S I I G
Y   I   R
return "PAHNAPLSIIGYIR"