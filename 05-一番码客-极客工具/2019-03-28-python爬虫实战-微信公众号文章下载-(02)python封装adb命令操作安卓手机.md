---
title: python爬虫实战-微信公众号文章下载-(02)python封装adb命令操作安卓手机
date: 2019-03-28
tags: 
categories: 极客工具
---

> **一番码客 : 挖掘你关心的亮点。** 
> **http://www.efonmark.com** 

让大家久等了，来不及解释（jiaobian）了，让我们上车吧。  
<img src="2019-03-28-python爬虫实战-微信公众号文章下载-(02)python封装adb命令操作安卓手机/shangche.jpeg" width = 50% height = 30%>  
正如一番在这个系列文章的（00）篇中所说，一番在做1.0版本的时候用到了一些取巧的方法，其中就包括python通过adb操作手机。  

<!-- more -->
之前微信第一款小程序游戏“跳一跳”突然火起来的时候，办公室午休的时候掀起了一股跳一跳的热潮，这个时候也是一番接触python不久。在网上很快就有小伙伴用python做了一个外挂，并传在了github上开源开发。这其中的原理就用到了adb操作和图像处理，鉴于python的使用群体庞大，这个项目也得到了持续的优化和更新，操作对于新手非常友善，也非常值得新手用来学习，有趣又实用（有兴趣的同学，公众号后台回复“跳一跳”获取github源码地址）。

## ADB的使用方法及常见命令
adb的基本使用方法和常见的命令，接触过安卓调试的同学应该都会。这里给出一个一番觉得比较简洁明了的文章，不了解ADB的同学可以先学习下。
* [ADB命令集锦](http://mp.weixin.qq.com/s?__biz=MzIzMDU5MDg4OA==&mid=2247484837&idx=1&sn=1d9e435bbfc06b7eb8fc527fc175c879&scene=0#wechat_redirect)  
* [你应该知道的一些 ADB 命令](http://mp.weixin.qq.com/s?__biz=MzA4NTQwNDcyMA==&mid=2650662207&idx=1&sn=ac582fe052fb8ad12d7c3f8e5a140c98&scene=0#wechat_redirect)  
* [Android adb shell input 命令详解](https://blog.csdn.net/good123_2014/article/details/79107765)  
> 这里我们重点提一下**“adb shell input”** ，这个命令是我们模拟手动操作用的最频繁的一个命令，主要是**模拟输入文本、按键事件、点击、滑动**等操作，我们在用python封装的时候会重点用到，接下来的代码中大家也会看到。

## python adb操作封装
首先来看下一番的1.0版本为了采集公众号历史文章的标题和链接，封装了哪些adb操作。
<img src="2019-03-28-python爬虫实战-微信公众号文章下载-(02)python封装adb命令操作安卓手机/01.png" width=100%>
这里一番将adb 操作封装为一个AdbOpt类，__init__() 函数就是创建类的对象时自动执行的初始化函数，类似C++里的构造函数，通常我们在这个函数里做一些类变量的初始化动作。代码如下：

```
def __init__(self,phonePara):
    '''
    @ adb   工具类初始化，检查adb路径与环境
    @
    @ return
    @
    @ param
    @   phonePara 用于指定手机相关参数
    @ exception
    @ notice
    '''
    print(phonePara)
    self.deviceId = phonePara['serial'] #创建类之后需要赋值 deviceId

    if platform.system() == 'Windows':
        adbToolPath = os.path.join("adb")
        self.option = ''
    elif platform.system() == 'Linux':
        adbToolPath = adbPara['pcPara']['linux']['adbPath']
        self.option = ' -s ' + self.deviceId
    else:
        print('Host OS is not compatible.\n')
        exit(1)

    print('adbToolPath:' + adbToolPath)
    try:
        subprocess.Popen(
            [adbToolPath], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        self.adbToolPath = adbToolPath
    except OSError:
        print('请安装 ADB 及驱动并配置环境变量')
        exit(1)
```
这里phonePara，是为了适配多部手机，让一台PC可以同时adb操作多部手机（虽然后面没有用上）。为了存储每部手机的不同参数，和windows、linux的adb路径参数，一番建了一个这个文件里的adbPara变量：
```
adbPara = {
    'phonePara': {
        'HuaweiMate9': {
            'serial': '3HX0217601006195',
            'screenSize': [1080, 1920]
        },
        'meizuPro5': {
            'serial': '860BCNA224M5',
            'screenSize': [1080, 1920]
        },
    },

    'pcPara': {
        'windows': {
            'adbPath': ''
        },
        'linux': {
            'adbPath': '/home/efonfighting/Android/Sdk/platform-tools/adb'
        },
    }
}
```
下面就不一一贴代码了，解释下每个函数的封装，如果需要封装的源码，后台回复“adb”获取。
```
testDevice(self):
  @ 查看是否有设备连接

getScreenSize(self):
  @ adb 获取屏幕分辨率
  @ return  屏幕分辨率（eg. "Physical size: 1080x1920 Override size: 720x1280"）

getScreenDensity(self):
  @ 获取屏幕DPI（每英寸点数）

getDeviceInfo(self):
  @ 获取ro.product.device

getDeviceOsInfo(self):
  @ 获取ro.build.version.release

dumpDeviceInfo(self):
  @ 检查设备连接状态，显示设备信息

getScreenCapSize(self):
  @ adb 获取截屏图片分辨率
  @ return  eg.[720,1280]

runAdbCmd(self, rawCommand):
  @ 执行任意adb命令

pullScreenShot(self, savePath):
  @ 获取屏幕截图
  @ adb shell screencap -p /sdcard/screencap.png;adb pull /sdcard/screencap.png ~/Desktop

adbTap(self, x, y):
  @ 单击任意坐标点(x,y)

adbSwipe(self, x1, y1, x2, y2, ms, delay):
  @ 从一点滑动到另一点
  @ param
  @   delay:swipe后delay多少秒返回，等待某些动作缓冲完成

drawCircle(self, img, pos):
    @ 在任意坐标点(x,y)画圆

FindFlgFromCap(self, flgPath, confidenceVTH, blockEn, findDelay):
  @ 在图片中找出特征图案
  @ return 特征图案中心坐标(x,y) or None
  @ param
  @    confidenceVTH:0.0-1.0
  @    blockEn:是否阻塞等待flg出现
  @    findDelay: 找到flg后延时findDelay秒后再返回
  @ notice    必须像素点匹配

def tapFlgFromPic(self, flgPath, confidenceVTH, blockEn, findDelay, tapDelay):
  @ 单击图片中的特征图案
  @ return True/False
  @ param
  @       blockEn(bool):是否阻塞等待flg出现
  @       findDelay:找到flg后延时findDelay秒后再点击flg
  @       delayTime:tap后延时时间返回，做某些动作的缓冲时间，单位秒
  @ notice    必须像素点匹配
```
* 可以看到，为什么有一个runAdbCmd命令可以执行任意adb命令，一番还要单独封装一些常用的比如点击、滑屏等操作呢，其实这是为了方便后续要改动一个操作时，只需要改动这个这个封装的函数就行了，而不必每个用到这个操作的地方都去改动，这也是封装的一个思想。  

* 还有里面封装了一些点击特殊图案的操作，这里涉及到aircv库的操作，这里单独将FindFlgFromCap这个函数提出来说一下。  
这个函数可以帮我们找到图片中的目标图案，但前提是需要先将这个目标图案在本地保存一个，以作对比，一番估计这个find_template函数的实现原理就是简单的像素点对比。  
最后会返回一个列表，列表里包括目标图案在搜索源图案中的中心位置以及相似度confidence。  
如果找到多个目标图案则返回多个列表。这个可以帮助我们确定一些特定图案的位置，然后模拟点击，比如公众号里的“复制连接”图标等。

```
def FindFlgFromCap(self, flgPath, confidenceVTH, blockEn, findDelay):
    '''
    @ 在图片中找出特征图案
    @
    @ return 特征图案中心坐标(x,y) or None
    @
    @ param
    @    confidenceVTH:0.0-1.0
    @    blockEn:是否阻塞等待flg出现
    @    findDelay: 找到flg后延时findDelay秒后再返回
    @ exception
    @ notice    必须像素点匹配
    '''
    #process = subprocess.getoutput('date +%m%d%H%M%S')
    #date = process.replace('\n','')
    date = '' #不保存时间戳
    while True:
        screenshotPath = self.pullScreenShot('out/screencap' + date + '.png')  # eg. out/cap1006120638.png
        print(screenshotPath)
        imsrc = ac.imread(screenshotPath)
        imdst = ac.imread(flgPath)
        pos = ac.find_template(imsrc, imdst)
        if ((pos != None) and (pos['confidence'] > confidenceVTH)):
            print('find a {para1}:{para2}'.format(para1=flgPath,para2=pos))
            flgCenterPosInt = (int(pos['result'][0]), int(pos['result'][1]))
            time.sleep(findDelay)
            # draw_circle(imsrc, circleCenterPosInt)  # draw circle
            #str(input('确定开始下一步？[y/n]:'))
            return flgCenterPosInt
        elif (blockEn == False):
            print('Do not find {para1}\n'.format(para1=flgPath))
            return None
        else:
            print('wait for {para1}\n'.format(para1=flgPath))
            time.sleep(1)

```

好了，python对adb的封装就讲到这里，期待你的留言和获取源码哦。我们下期见！

> **趋势不会因为个别的吝啬与懒惰而停止向前的车轮，所以迈开脚步，一起赶路。**  

> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://www.efonmark.com**