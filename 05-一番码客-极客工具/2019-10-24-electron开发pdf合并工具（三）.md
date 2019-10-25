---
title: electron开发pdf合并工具（三）.md
date: 2019-10-24
tags: 
categories: 极客工具
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://efonfighting.imwork.net**

本文目录：

[TOC]

## 前言

上一篇我们实现了electron中nodejs端的逻辑功能。但nodejs调用打包后的python以及python合并功能、python日志保存还没有做，今天就补充上来这些内容。

<!-- more -->

## python打包

用pyinstall打包python程序为exe文件。首先我们需要给系统安装pyinstall工具。

```
pip install pyinstall
```

然后再package.json中加入python打包命令。

```
"build-python": "pyinstaller ./py/api.py --clean --distpath ./pydist"
```

执行该命令成功后，便可以在工程根目录下找到pydist目录，里面就有打包好的python可执行程序。

## python代码

python里我们还是用pyPDF2库来实现pdf合并，并用logging和traceback模块实现日志保存。

logging模块里主要实现代码里的打印信息保存。traceback模块通过try和loggging的方式实现程序执行中产生的错误的保存。这样便可以定位到所有python执行中的问题了。

里面涉及到一些文件路径处理和编解码问题，在代码可以看到有做特殊处理。

```python
import sys, os, logging
import traceback
from PyPDF2 import PdfFileReader, PdfFileWriter

def MergePDF():
    outfile = os.path.abspath('out.pdf')
    filepath = ''
    output = PdfFileWriter()
    outputPages = 0

    for each_file in open("filepaths.txt", 'r' ,encoding='utf-8'): # 防止gtk解码问题
        each_file=each_file.replace('\n','')
        filepath = os.path.dirname(each_file)
        logging.info(filepath)
        logging.info(each_file)
        # 读取源pdf文件
        input = PdfFileReader(open(each_file, "rb"))

        # 如果pdf文件已经加密，必须首先解密才能使用pyPdf
        if input.isEncrypted == True:
            input.decrypt("map")

        # logging.info(each_file[:-4])

        # 获得源pdf文件中页面总数
        pageCount = input.getNumPages()
        outputPages += pageCount
        #logging.info("%s has %d pages" % (each_file, pageCount))

        # 分别将page添加到输出output中
        for iPage in range(pageCount):
            output.addPage(input.getPage(iPage))

        # 添加书签
        output.addBookmark(
            title=each_file[:-4].replace(filepath+'\\',''), pagenum=outputPages - pageCount)

    logging.info("All Pages Number: " + str(outputPages))
    # 最后写pdf文件
    outputStream = open(outfile, "wb")
    output.write(outputStream)
    outputStream.close()
    logging.info("finished")


def main():
    logging.info("hello efonmark.")
    MergePDF()


if __name__ == '__main__':
    logging.basicConfig(level=logging.DEBUG,#控制台打印的日志级别
                    filename='new.log',
                    filemode='w',##模式，有w和a，w就是写模式，每次都会重新写日志，覆盖之前的日志
                    #a是追加模式，默认如果不写的话，就是追加模式
                    format=
                    '%(asctime)s - %(pathname)s[line:%(lineno)d] - %(levelname)s: %(message)s'
                    #日志格式
                    )
    try:
        main()
    except Exception:
        logging.error(traceback.format_exc()) 
```

## vue中调用python打包后程序

这里用们用以一个局部变量来控制是调用python的exe打包文件还是调用pyhton命令。因为用户电脑不一定安装了python命令运行环境，因此我们需要将python打包成exe并修改js里的调用方式。

```js
pdfmerge: function () {
    const fs = require('fs')
    fs.writeFile('filepaths.txt', this.paths)
    let pycmd = ''
    const NODE_ENV = 'production'
    // const NODE_ENV = 'development'
    if (NODE_ENV === 'development') {
        pycmd = 'python py/api.py'
        require('child_process').spawn(pycmd, {
            stdio: 'inherit',
            shell: process.platform === 'win32'
        })
    } else {
        pycmd = 'pydist/api/api.exe'
        require('child_process').execFile(pycmd)
    }
```

## 遗留问题

* 菜单栏需要添加
* python可执行文件打包到electron安装包中

## 一番今日

今天看到西瓜数据里的9月份的公众号榜单，挺不错。可以从里面找到各个维度的大号，后面一番准备从中整理一些公众号大号的文章，放到付费知识星球，应该还不错。

发现现在每天很少读书了，看来也要定一些原则才行，比如每天打卡阅读多少页的书。

昨天还开始了间隔已久的跑步锻炼，从肺活量感觉身体变差了，还要继续坚持锻炼。强健的身体可以让我们心无旁骛。

> 一番雾语：身体强健，心无旁骛。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**