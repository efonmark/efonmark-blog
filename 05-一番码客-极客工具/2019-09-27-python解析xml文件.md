---
title: python解析xml文件
date: 2019-09-27
tags: 
categories: 极客工具
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://efonfighting.imwork.net**

本文目录：

[TOC]

## 前言

本来今天准备学习下electron的，结果npm工具的安装真是费了劲，网速差的不得了。为了完成今天的日更，只能放弃，今天来谢谢python的xml解析吧。

<!--more-->

昨天我们讲了Charles的安装与使用，而Charles抓到一条数据之后，我们想要把这条数据导出来用脚本分析，那么，Charles提供了导出（`export`）功能。导出的格式包括`.chls/csv/trace/chlsx/chlsj/har`格式。这里的`chlsx`其实就是一种xml格式，里面包含的内容比较全。

![1569508908521](2019-09-27-python解析xml文件\xml01.png)

## 关于XML

* XML是一种可扩展标记语言（e**X**tensible **M**arkup **L**anguage），主要被用来存储数据。

* XML是一种树状结构，每个节点被称作一个元素，元素有对应的属性（描述）。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<body>
  <name>efon</name>
  <sex>male</sex>
  <profession>SW Engineer</profession>
</body>
```

## 解析

这里我们还是以抓取公众号文章列表页的一页数据为例。用`Charles`导出一页`chlsx`数据。

我们要从这个xml文件里获得`Host|Referer|Cookie|url`这几个动态信息。

* 我们用`sorted`函数排序，找出时间最新的一个`chlsx`文件。

```python
trace_list = sorted(glob.glob("out/*.chlsx"), key=os.path.getmtime, reverse=True)
```

* 这里xml的解析我们用到一个库`xml.dom.minidom`，首先用`parse`读取这个xml文件；
* `getElementsByTagName`读取元素的内容；
* `firstChild.data`读取一个元素的属性（描述）；

```python
DOMTree = xml.dom.minidom.parse(trace_list[0])
File = DOMTree.documentElement.getElementsByTagName('first-line')[0].firstChild.data
headers = DOMTree.documentElement.getElementsByTagName("header")
for header in headers:
    names = header.getElementsByTagName('name')
    if (names[0].firstChild.data == 'Host'):
        Host = header.getElementsByTagName('value')[0].firstChild.data
    elif(names[0].firstChild.data == 'Referer'):
        Referer = header.getElementsByTagName('value')[0].firstChild.data
    elif (names[0].firstChild.data == 'Cookie'):
        Cookie = header.getElementsByTagName('value')[0].firstChild.data
```



## 结语

好了，通过上面的步骤，我们便可以从xml文件里拿到我们想要的元素属性了。

公众号后台回复`xml`获取文中用到的xml文件和python解析源码。



> 一番雾语：就像表达是你的情绪的反映一样，表达方式反之也会影响情绪。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**