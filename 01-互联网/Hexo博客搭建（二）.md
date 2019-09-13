---
title: Hexo博客搭建（二）
date: 2019-09-11
tags: 
categories: 互联网
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://efonfighting.imwork.net**

[TOC]

## 日更前语

昨天写了缘起、调研，今天直接进入正题。

<!-- more -->

## 3. 环境搭建

一番是个linux控，因此一番的博客搭建也用的是ubuntu服务器。当然，因为Hexo是基于js的，天生具有跨平台的特点，Hexo的搭建也支持Mac和Windows，具体可以参考第7节引用里的《hexo中文文档》。

Hexo安装依赖于Node.js和Git，因此如果没有安装这两个工具，需要提前安装一下：

* 安装git：

```shell
sudo apt-get install git-core
```

* 安装Node.js（nvm的方式）:

```shell
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.34.0/install.sh | sh
```

重启终端

```shell
nvm install stable
```

* 安装Hexo：

```shell
npm install -g hexo-cli
```

这样，我们的Hexo环境就搭建好了。可以说非常简单，比我们一个标签一个布局的自己去码代码方便太多了。更重要的是还不专业，写的肯定没有这个好，bug肯定比这个多，哈哈。

## 4. 初始化Hexo：

接下来我们要初始化Hexo，进到你希望保存Hexo博客文件的目录（例如：/home/efonfighting/efonfighting-hexo-blog）：

```shell
hexo init /home/efonfighting/efonfighting-hexo-blog
cd /home/efonfighting/efonfighting-hexo-blog
npm install
```

完成后文件目录如下：

```shell
root@instance-zxwd3h3s:/home/efonfighting/efonfighting-hexo-blog# tree -L 1
.
├── _config.yml # 基本配置文件，包括一些个性化的配置
├── db.json
├── node_modules
├── package.json
├── scaffolds # 新建文章的模板文件
├── source # 存放我们实际文章的地方，我们将Markdown或者HTML的文件放到该目录下的_posts目录，即可自动解析
└── themes # 主题文件夹，我们可以在_config.yml里配置用哪个主题
```

## 5. 本地访问

到这个时候，虽然我们还没写一篇博客，但已经完成了hexo的初始化，我们只需要启动服务，就可以用ip:port的方式访问了。

启动服务的命令：

```shell
hexo server
```

这时我们就可以打开浏览器，输入 `http://localhost:4000/`，可以访问到我们的博客了。

当然，我们后面搭建网址访问的时候需要指定ip和端口，可以通过加参数的方式实现：

| 选项           | 描述                           |
| -------------- | ------------------------------ |
| `-i`           | 指定ip                         |
| `-p`, `--port` | 指定端口                       |
| `-l`, `--log`  | 启动日记记录，使用覆盖记录格式 |
| `--debug`      | 生成debug信息                  |

例如：

```shell
hexo server -i 192.168.0.4 -p 8011 --debug
```



## 6. 个性化配置

主要修改_config.yml：

```shell
title: 一番码客 #网站标题
subtitle: 挖掘你关注的亮点！ #网站副标题
description:
keywords:
author: Efon-fighting
language: zh-CN #网站语言
timezone:
.
.
.
theme: material-x #这里选择主题，即theme目录下的主题
```

## 7. 引用

当然，关于Hexo，还有很多其他的配置，大家可以参看这里的一些资料，查找自己对应的需求。特别是解决用markdown语法引用本地图片的问题，当时困扰了一番好久，几乎一度想放弃。

* hexo中文文档：https://hexo.io/zh-cn/docs/setup
* material-x主题：https://xaoxuu.com/wiki/material-x/#特别示例
* hexo引用本地图片无法显示：https://blog.csdn.net/xjm850552586/article/details/84101345
* 解决Hexo博客文章置顶问题：https://zhwhong.cn/2017/03/23/deal-with-hexo-article-top-problem/

## 日更结语

好了，写到这里，我们已经完成了Hexo的搭建，就可以通过markdown的方式写博客了——美观、个性、方便。

云服务器搭建、域名访问我们明天写在Hexo的最后一篇里。

一番的日更打卡群已经建立了，今天刚好满10人，送了第一波红包，公众号后台回复“**打卡群**”即可进入，监督一番坚持日更原创文章，建群目的和规则参看上一篇文章。



> 一番雾语：积极向上的我们，为了当下的生活各种忙碌，程序员忙于业务代码而没时间学习框架，忙但如果不挤出时间改变，这些将都不会改变。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://efonfighting.imwork.net**