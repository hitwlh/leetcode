284_Peeking_Iterator


题目大意
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

解决方案
加一个cache，和cache是否有效的标识need_cache

样例

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.

