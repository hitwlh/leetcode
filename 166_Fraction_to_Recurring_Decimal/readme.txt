166_Fraction_to_Recurring_Decimal


题目大意
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.


解决方案
就是要做除法，并且识别出循环的部分。
其实比较简单，模拟手动除法的步骤，每次把用过的被除数保留在map里，并且把那个被除数计算所得到的结果的位置作为map的值
如果当前被除数曾经被map过，就说明出现循环了。但是要千万注意有可能能够整除完，也就是要多添加直接return的部分。

另外注意的是，小数点左边我是直接用除法算出来的，所以循环部分是否从左边开始这份代码是识别不出来的。但是如果是从左边开始循环，本来可以直接照抄左边一遍，而这里的代码就多算了一次才知道。



有错点:
1. 要注意有负数的情况，一开始直接按照正数在做，错得一塌糊涂

2. 传入参数的类型本来是int，但是int的最小负数转为正数会溢出，这个要注意处理

3. 代码里有好几个return ret的地方，每个地方都要判断是否要添加负号

4. now的移动方式要注意，不是直接简单地往后移动1位就了事，初始的时候就未必是，所以直接每次移动到末尾就没错了


样例

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

