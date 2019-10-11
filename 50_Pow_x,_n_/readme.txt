50_Pow_x,_n_


题目大意
Implement pow(x, n).

解决方案
用二分法计算sqrt然后相乘。否则超时！！！
注意INT_MIN转为INT_MAX时会出错，用long变量是最直接有效的方法。
样例


