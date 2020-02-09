---
title: electron桌面应用开发（七）
date: 2019-10-05
tags: 
categories: 极客工具


---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

## 前言

今天想继续写electron，在准备素材做实验的时候，发现基本概念太薄弱了，对工程的目录作用和基本运行逻辑都不是很熟，导致做起实验举步维艰，所以还是需要加强下基础知识。所以这里学学electron-vue的基础知识，首先认识下工程目录构成。

<!-- more -->

## 目录结构

* **开发主进程**：`src/main/index.dev.js`，开发主进程入口。该文件专门用于开发和安装开发工具。最后跳转到`src/main/index.js`。
* **开发状态和产品状态**：我们所看到的所有目录在最终产品构建的时候只有`dist、node_modules和package.json`这几个文件夹和文件，其他的目录和文件只存在于开发过程中。

* **渲染器进程（renderer目录）**：Electron 中的每个网页都在自己的进程中运行，称为渲染器进程 (renderer process)。
  * vue 组件：`renderer/components`目录，创建子组件时，一个常用的组织化实践是将它们放置在一个使用其父组件名称的新文件夹中。
  * vue路由：鼓励使用 `vue-router`创建 单页应用程序 。
  * vuex模块：electron-vue 利用 `vuex` 的模块结构创建多个数据存储，并保存在 `src/renderer/store/modules` 中。
* **主进程**：electron实际是以`package.json`这个脚本为入口的，运行的这个脚本其实就是主进程。
  * 三个变量：`__dirname`,`__filename`和`__static`。

* **Webpack 配置**：`.electron-vue`文件夹便是存放Webpack配置文件的。里面有专门针对main和rederer的配置。

## 参考

- [electron-vue文档](https://simulatedgreg.gitbooks.io/electron-vue/content/cn/)

## 一番今日

今天到家差不多快12点了，为写文章找素材。因为做实验不顺利，做了一个小时发现思路和代码状态越来越乱，快1点了。所以决定还是早点休息，5点半左右起来继续写文章，保证7点前发文。因为晚睡对精神状态和身体健康的负面影响太大了，所以尝试看早点睡早点起的方式会不会好一点。睡了四个多小时起来的状态还是比1点的时候要好很多。因为今天不上班，发了文还可以回去继续睡觉，哈哈。

> 一番雾语：早睡早起比晚睡晚起要健康吧。



> **免费知识星球： [一番码客-积累交流]([wwww](https://t.zsxq.com/NRVBURr))**
> **微信公众号：一番码客**
> **微信：Efon-fighting**
> **网站： http://www.efonmark.com**