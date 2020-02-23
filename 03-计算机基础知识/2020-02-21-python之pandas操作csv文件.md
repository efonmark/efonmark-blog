---
title: python之pandas操作csv文件
date: 2020-02-21
tags: 
categories: 计算机基础知识
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200221223448593](2020-02-21-python之pandas操作csv文件/image-20200221223448593.png)

<!-- more -->

## 前言

我们在存储、处理数据的时候很多时候会保存为csv格式，以便于用excel来处理。那么，今天一番总结一下python中pandas库对csv文件的一些常用操作。

## pandas 

pandas 是基于 NumPy 的一个 Python 数据分析包，主要目的是为了数据分析。它提供了大量高级的数据结构和对数据处理的方法。

pandas 有两个主要的数据结构：**Series** 和 **DataFrame**。

### Series

Series 是一个一维数组对象 ，类似于 NumPy 的一维 array。它除了包含一组数据还包含一组索引，所以可以把它理解为一组带索引的数组。

### DataFrame

数据帧(DataFrame)是二维数据结构，即数据以行和列的表格方式排列。

数据帧(DataFrame)的功能特点：

* 潜在的列是不同的类型
* 大小可变
* 标记轴(行和列)
* 可以对行和列执行算术运算

## csv常用操作

比如我们现在有一个`data.csv`文件，内容如下。

```txt
Time[s], 数据0, 数据1, 数据2, 数据3
2.512600000, 0, 0, 0, 0
2.512950000, 1, 1, 1, 1
2.513000000, 0, 0, 0, 0
2.513100000, 1, 1, 1, 1
2.513350000, 0, 0, 0, 0
2.513500000, 1, 1, 1, 1
2.513550000, 0, 0, 0, 0
```

### 读取文件

```python
import pandas as pd
import operator

srcFile = 'data.csv'
data = pd.read_csv(srcFile, encoding='utf-8', header=0)
```

### 获取数据行数

```python
print(len(data.index))
```

输出：

```
7
```



### 获取数据列数

```python
    print(len(data.loc[0]))
```

输出：

```
5
```



### 遍历每行

```python
for index, row in data.iterrows():
  print(row[0]) # 输出每行的第一列
```

输出：

```
2.5126
2.51295
2.513
2.5131
2.51335
2.5135
2.51355
```



### 获取某行某列数据

```python
print(data.loc[4][0])
```

输出：

```
2.51335
```



### 获取某列数据

```python
print(data['Time[s]'])
```

输出：

```
0    2.51260
1    2.51295
2    2.51300
3    2.51310
4    2.51335
5    2.51350
6    2.51355
```



### 获取多列数据

```python
print(data[['Time[s]', ' 数据1']])
```

输出：

```
Name: Time[s], dtype: float64
   Time[s]   数据1
0  2.51260     0
1  2.51295     1
2  2.51300     0
3  2.51310     1
4  2.51335     0
5  2.51350     1
6  2.51355     0
```



### 获取列名

```python
print(data.columns)
```

输出：

```
Index(['Time[s]', ' 数据0', ' 数据1', ' 数据2', ' 数据3'], dtype='object')   
```



### 获取索引

```python
print(data.index)
```

输出：

```
RangeIndex(start=0, stop=7, step=1)
```



### 按照某一列筛选

```python
print(data[data[' 数据0']> 0])
```

输出：

```
   Time[s]   数据0   数据1   数据2   数据3
1  2.51295     1     1     1     1
3  2.51310     1     1     1     1
5  2.51350     1     1     1     1
```



### 简单的个数统计

```python
print(data[' 数据0'].value_counts())
```

输出：

```
0    4
1    3
Name:  数据0, dtype: int64
```



### 将某列作为索引

```python
print(data.pivot_table(index=['Time[s]'])）
```

输出：

```
          数据0   数据1   数据2   数据3
Time[s]
2.51260     0     0     0     0
2.51295     1     1     1     1
2.51300     0     0     0     0
2.51310     1     1     1     1
2.51335     0     0     0     0
2.51350     1     1     1     1
2.51355     0     0     0     0
```



> 一番雾语：你确定想用python来代替excel？

<table>
<tr>
<td ><center><img src="http://www.efonmark.com/efonmark-blog/readme/guanzhu_1.jpg" width=50%></center></td>
<td width="50%" align=left><b>
    免费知识星球：<a href="http://www.efonmark.com/efonmark-blog/readme/zhishixingqiu1.png">一番码客-积累交流</a><br>
    微信公众号：<a href="http://www.efonmark.com/efonmark-blog/readme/guanzhu_1.jpg">一番码客</a><br>
    微信：<a href="http://www.efonmark.com/efonmark-blog/readme/weixin.jpg">Efon-fighting</a><br>
    网站：<a href="http://www.efonmark.com">http://www.efonmark.com</a><br></b></td>
</tr>
</table>