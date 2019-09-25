---
title: win10下electron开发环境搭建
date: 2019-09-24
tags: 
categories: 极客工具
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://efonfighting.imwork.net**

本文目录：

[TOC]

这几年虽然随着移动互联网的崛起，移动端应用已经成了一片红得发紫的红海，仿佛还没有真正红过的PC桌面应用直接进入了夕阳行业。但目前为止，PC仍然是这个社会的主要生产工具。所以虽然一番在玩泥巴的年纪错过了PC桌面应用当红的时代，现在一番还是对开发一些提升生产力的PC桌面工具感兴趣。（咳，关注一番的同学应该知道了，一番就是个初级软件开发爱好者，一会儿python整一下，一会儿android app弄一下，一会儿博客搭建戳一下，这会儿又想玩PC桌面应用了，浅尝辄止，还是在玩泥巴的阶段。）

<!-- more -->

electron最大的特点就是**界面潮、跨平台**。就这两个特点，就能把其他桌面应用开发工具拍在沙滩上了。

近几年微软大力发展推广的IDE VsCode就是用electron开发的，可见electron的势头还是很猛的。只是因为一些历史的拖累，老的开发者还停留在c++ mfc或者c#的开发方式上（当然，他们还是可以做的不错的）。

## Win10 开发环境配置

### 安装Node.js

打开Node.js官网下载页面：`https://nodejs.org/en/download/`，点击下载`Windows Installer`，一番这里下载的`node-v10.16.3-x64.msi`，下载完后点击一路默认安装即可。

![1569338919221](2019-09-24-win10下electron开发环境搭建\electron.png)

安装完后在终端输入如下命令查看安装信息：

```
# 下面这行的命令会打印出Node.js的版本信息
node -v

# 下面这行的命令会打印出npm的版本信息
npm -v
```

npm是Node.js下的包管理器，一般情况下安装node.js同时都会自带安装好npm。如果需要升级npm可以运行`npm install npm -g`。

![1569339972048](2019-09-24-win10下electron开发环境搭建\electron1.png)



### 安装开发工具：VSCode

开发工具，一番选择官方推荐的VSCode，访问官网`https://code.visualstudio.com/`下载，一路默认安装即可。

![1569340126922](2019-09-24-win10下electron开发环境搭建\electron2.png)



### 安装Electron

* 独立安装：`npm install --save-dev electron`

  官方推荐的是在app工程所在目录，执行该命令来安装。这样可以保持每个app有一个独立的electron开发环境。

* 全局安装：`npm install electron -g`

  这种方式意味着所有的项目共用一个electron版本。

* git clone 一个仓库，安装依赖库，并启动运行

  ```
  # 克隆这仓库
  $ git clone https://github.com/electron/electron-quick-start
  # 进入仓库
  $ cd electron-quick-start
  # 安装依赖库
  $ npm install
  # 运行应用
  $ npm start
  ```

这样我们便搭建了一个electron的开发环境，当然，它什么功能都还没有。后面一番会继续学习。



## 参考：

* https://electronjs.org/docs
* https://mp.weixin.qq.com/s/52yKMYXnxriqqelspTjWlA
* https://www.imooc.com/article/68465



> 一番雾语：傲气和谦卑。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**