##各种排序算法的总结
____
具体的算法实现在各目录下

### 1.算法分类
常见排序算法可以分为两大类：

* 比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn)，因此也称为非线性时间比较类排序。
* 非比较类排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。

![sortSorts](https://github.com/FeiZhao0531/BasicAlgorithm/blob/master/raw/master/picture/sortSorts.png)


### 2.算法复杂度

![sortCompare](https://github.com/FeiZhao0531/BasicAlgorithm/blob/master/raw/master/picture/sortCompare.png)
             
### 3.算法接口形式
不唯一，但是为了方便记忆，可以如以下统一：

* 冒泡排序、插入排序、希尔排序、选择排序和堆排序的排序方法接口均是sort(int[] arr,int len)的形式，其中len是序列长度。
* 归并排序由于需要临时数组存放两有序表合并的结果，排序方法接口是sort(int[] arr,int [] tmp,int low,int high)
* 快速排序不需要临时数组，其排序方法接口是sort(int[] arr,int low,int high)。
