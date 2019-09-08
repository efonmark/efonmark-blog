---
title: python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别
---

> **一番码客 : 挖掘你关心的亮点。  **
> **http://efonfighting.imwork.net**

<img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/fighting1.jpg">

> 前面我们讲到了adb的封装，里面具体讲到到了在一副图片中寻找目标的坐标并点击。这篇文章我们讲讲对一副图片的特定区域做截取，并利用开源库做图纹识别。  
要实现这个步骤的原因是，最初想实现爬取微信公众号历史文章这个功能时，一番没有抓包爬虫经验，于是为了获取历史文章的标题用于pdf打印时的命名，一番想到截图后对图片做图文识别，然后点击文章标题，进入到文章阅读界面然后结合目标图片识别“复制链接”来获取到文章的链接。  

<!-- more -->

## 安装 tesseract-ocr

tesserat是一个开源的文字识别引擎，目前已经开发到4.0版本，训练支持了100+种的语言了。这里安装以ubunut18.04为例。  

安装分为两部分:
1. 安装引擎
对于ubuntu18.04来说安装很简单，两条命令搞定：
> sudo apt install tesseract-ocr
> sudo apt install libtesseract-dev

* 安装需要识别语言的现有训练库:
安装简体中文的识别库：
> sudo apt install tesseract-ocr-chi-sim

如果是英文识别库：
> sudo apt install tesseract-ocr-eng

如果是windows，下载对应的32位或64位安装包，然后将下载的语言识别库“xxx.traineddata”放到安装目录（比如C:\Program Files\Tesseract-OCR\tessdata）下。  
对于mac或者其他版本linux系统的安装方式，当然包括windows详细安装教程，请参考tesseract-ocr官方github的wiki（当然是英文的啦）。

> 后台回复关键字 **“ tesseract-ocr ”** 获取官方工程github地址和windows安装包、语言包。  

安装完成之后你发现就可以用tesseract命令啦。
<img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/tesseract_1.jpg">

## python结合pytesseract做图文识别
首先确保安装了python pytesseract包，
> * pycharm 请在setting里安装。
> * 终端安装直接 "pip3 install pytesseract"。

接下来就可以直接通过python调用pytesseract的接口做图文识别啦。下面以一幅手机屏幕截图为例。  
> <img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/一番码客.jpg" width=50%\>

1. 这里标定每篇文章题目的范围，如图红框。
* test代码
```
def test():
    from PIL import Image
    import pytesseract
    import matplotlib.pyplot as plt

    #读取图片，并截取其中的一部分
    img = Image.open("/home/soy/Desktop/一番码客.jpg")
    grey = img.convert('L') # 只留取亮度信息，转换为黑白色，有利于文字识别
    cutPic = grey.crop((25, 270, 690, 540)) # 上图红框里的范围(x1,y1,x2,y2)

    #这里为了将所有非白色的像素点转换为纯黑色，有利于增高文字的锐度、清晰度。
    xSize = cutPic.size[0]
    ySize = cutPic.size[1]
    for y in range(ySize):
        for x in range(xSize):
            if(cutPic.getpixel((x,y)) != 255):
                cutPic.putpixel((x,y),0)

    #展示处理后的图像
    plt.imshow(cutPic)
    plt.show()

    #图文识别
    itemStr = pytesseract.image_to_string((cutPic), lang='chi_sim').replace(' ', '')
    print(itemStr)

    #文字拼接处理
    itemStrList = itemStr.split('\n',8)
    dateStr = itemStrList[len(itemStrList)-1]
    topicStr = ''
    for idx in range (len(itemStrList)-1):
        topicStr += itemStrList[idx]

    #处理后的文字
    print(dateStr+'_'+topicStr)
```
* 处理后图片：
> <img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/tesseract_2.jpg">

* 识别结果：
> <img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/tesseract_3.jpg">

## 结语
怎么样，用python做图文识别是不是超简单？这就是python的魅力所在啊。  
那么获取每篇文章的思路就是：
1. 通过OCR获取最上面一篇的文章标题；
2. 点击进去，通过图像目标查找，点击“复制文章链接”按钮，并将链接传回PC保存；
3. 返回，向下滑动页面刚好一栏标题，重复1。
4. 通关！

> **人生的蜕变不知是否一定需要伴随着痛苦，但从很多经验来看，这条路是行得通的。
你承受了人生的痛苦，也经历着世间的繁华。无所谓不可承受之重。**

<img src="2019-04-13-python爬虫实战-微信公众号文章下载-(03)python开源库做图文识别/fighting.jpg" >

> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**