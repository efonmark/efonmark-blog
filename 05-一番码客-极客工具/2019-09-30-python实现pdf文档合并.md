---
title: 
date: 2019-09-30
tags: 
categories: 极客工具
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://efonfighting.imwork.net**

本文目录：

[TOC]

之前一番在免费知识星球给大家开发过一个在windows下使用的简单的pdf合并工具。其实用python去实现真的很简单，用了`tkinter + PyPDF2 + pyinstaller`。今天一番来解读下这个小工具怎么用python实现pdf文档合并的，而且合并完后还自带目录。

![](2019-09-30-python实现pdf文档合并/pdf01.png)

<!--more-->

## 使用PyPDF2库

python里最大的好处就是封装了各种强大的轮子。同样，操作pdf也有强大的库，就是PyPDF2库。这里我们就是用的PyPDF2来实现读取pdf，然后合并pdf的。

### 获取要合并的pdf文件的文件列表

```python
def getFileName(filepath):

    file_list = sorted(glob.glob("{}*.pdf".format(filepath) ),key=os.path.getmtime, reverse=False)
    return file_list
```

* `sorted`函数：获取一个文件夹里的所有pdf文件的列表，并且以pdf文件的修改时间为排序，通过`reverse`可以选择排序是否逆序。

这样便获取到了所有要合并的pdf文件的列表了。

### 使用PyPDF2合并pdf文档

```python
def MergePDF(filepath, fileNameList, outfile):
    mergedDir = filepath + '/merged/'
    if not (os.path.isdir(mergedDir)):
        os.system('mkdir -p {}'.format(mergedDir))

    output = PdfFileWriter()
    outputPages = 0

    for each_file in fileNameList:
        print("adding %s" % each_file)
        # 读取源pdf文件
        input = PdfFileReader(open(each_file, "rb"))

        # 如果pdf文件已经加密，必须首先解密才能使用pyPdf
        if input.isEncrypted == True:
            input.decrypt("map")

        # 获得源pdf文件中页面总数
        pageCount = input.getNumPages()
        outputPages += pageCount

        # 分别将page添加到输出output中
        for iPage in range(pageCount):
            output.addPage(input.getPage(iPage))

        # 添加书签
        output.addBookmark(
            title=each_file[:-3].replace(filepath,''), pagenum=outputPages - pageCount)

    print("All Pages Number: " + str(outputPages))
    # 最后写pdf文件
    outputStream = open(mergedDir + outfile, "wb")
    output.write(outputStream)
    outputStream.close()
    print("finished")
```

* 这里先建一个存放合并后文档的目录。
* 用PyPDF2库里的`PdfFileWriter`函数创建一个文件写入流。
* 用PyPDF2库里的`PdfFileReader`函数逐一读取pdf文件，并添加到上一步创建的文件写入流，并添加书签。
* 将文件写入流写入pdf文件。

就是这么简单。

## 一番今日

今天工作中大部分时间是在开会，现在上班应该要向纯管理方向靠近了，当然，技术问题还是要思考的，每天熬夜写文章还是有点影响工作的精气神的，以后不能熬夜写文章了，但一番还没有找到一个好的方式去平衡工作、生活和日更之间的关系。一定要保持自己做事时的精气神才行。

终于放假了，国庆诶，七天啊，什么时候能放七天假啊，上班真好，放假还有工资拿（暂且为这样平庸的自己找个借口）。明天早起看大阅兵。祝大家国庆节快乐，好好享受这假期吧。

> 一番雾语：国庆节快乐。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**