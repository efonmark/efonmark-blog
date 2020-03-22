---
title: tkinter在canvas上放图片
date: 2020-03-15
tags: 
categories: 计算机基础知识
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200315234446399](2020-03-15-tkinter在canvas上放图片/image-20200315234446399.png)

<!-- more -->

## 前言

不得不说图形界面编程还是比较麻烦的一件事情，tkinter确实参考资料比较少，很多东西只能自己摸索。

今天这里说一下在tkinter的canvas组件上放图片怎么实现。

## 代码

直接上代码：

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
#import tkinter
# 创建一个矩形，指定画布的颜色为白色
from tkinter import *
from PIL import Image, ImageTk

root = Tk()
im = Image.open('1.jpg')
tk_im = ImageTk.PhotoImage(im) 

# 创建一个Canvas，设置其背景色为白色
cv = Canvas(root)
cv.pack()
Label(cv, image=tk_im).pack(side=LEFT)
root.mainloop()
```

效果图：

![image-20200315234751785](2020-03-15-tkinter在canvas上放图片/image-20200315234751785.png)

原理就是在canvas组件上放一个label，用lable来放图片。

这里涉及到用Image和ImageTk模块来读取为tkinter可以用的图片内容。

当然，还有遗留问题，就是怎么让图片自适应窗口的大小，以及用滚动条实现大图的浏览。这些问题一番还在尝试，确实比较麻烦，因为网上几乎没有相关的资料。



> 一番雾语：图形界面编程还是需要专业积累。

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