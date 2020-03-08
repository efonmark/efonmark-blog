---
title: mongoose-面向对象操作mongodb的Nodejs框架
date: 2020-03-07
tags: 
categories: 互联网前后端
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200307223313117](2020-03-07-mongoose-面向对象操作mongodb的Nodejs框架/image-20200307223313117.png)

<!--more-->

## 介绍

无论是mysql还是mongodb，传统的与数据库交互的方式都是按照他们提供的API来写代码。它们提供的API往往不是很容易理解，而且难以记忆，如果传错了参数，写错一个符号都要查文档。

ORM（对象关系映射，Object Relational Mapping）框架，允许我们面向对象操作，不需要记忆任何的数据库API，只需要操作对象即可，由框架底层去调用数据库API，这样就大大提高了程序员的开发效率。

不过既然多了一层封装，肯定要损失一点点的性能，可以忽略不计。

在NodeJS中，操作mongodb最好的ORM框架就是**mongoose**。

## 安装mongoose

```bash
npm install mongoose --save
```

如果你本机没有安装nodejs驱动，会自动安装nodejs驱动，因为mongoose依赖nodejs驱动。

文档参考：[mongoose官方文档](http://mongoosejs.com/docs/index.html)：`http://mongoosejs.com/docs/index.html`

## 连接数据库

```javascript
'use strict'
let User = require('./model/user');
let mongoose = require('mongoose');
mongoose.connect("mongodb://127.0.0.1/test");

let db = mongoose.connection;
// 监听错误的事件
db.on('error', err => {
    console.log(err);
});

db.once('open', () => {
    console.log('mongodb connect successfully!');
    highOrderQuery()
});
```

## 模型定义

`mongoose`使用`schema`来描述数据的格式、字段、规则，有了`schema`之后可以生成`model`来操作数据。

一般我们新建一个model目录来存放这些模型文件，比如这里我们新建一个`model/user.js`

```js
'use strict'
let mongoose = require('mongoose');
let schema = mongoose.Schema({
    name: String,
    age: Number,
    address: String,
    fav: [String]
}, {
    versionKey: false
}
);

module.exports = mongoose.model("users", schema);
```

## 增删改查

直接查看文档中Model相关API。

```js
async function testCRUD() {
    //增
    let arr = [
        {
            name: "李连杰", age: 50, address: "北京", fav: ["功夫", "演电影", "旅游"]
        },
        {
            name: "吴京", age: 48, address: "北京", fav: ["功夫", "演电视剧", "运动"]
        },
    ];
    let res = await User.create(arr);
    console.log(res);
    
    //查
    let res = await User.findOne({address: "北京"}); //查询出符合条件的第一个文档
    console.log(res);
    let res = await User.find({address: "北京"}); // 查询出符合条件的所有文档
    console.log(res);

    //改
    let res = await User.updateOne({_id: "5b4065e548651d0b7035843d"}, {age: 11, address: "深圳"});
    console.log(res);

    //删
    let res = await User.deleteOne({_id: "5b4065e548651d0b7035843d"});
    console.log(res);
}

```

## 高级查询

所有条件操作符：`https://docs.mongodb.com/manual/reference/operator/query/`。

```js
async function highOrderQuery() {
    //条件查询
    let res = await User.find({age: {$gt: 15}});
    
    //数组查询
    let res = await User.find({
    	fav: "玩游戏"
    });
    
    //分页查询
    // sort({age:1}) : 1（默认）是从小到大，-1是从大到小
    // sort("-age") ：可以直接写`-`，表示从大到小
    // select("")只选择某个或某几个字段；select("-fav")不选某个字段
    let res = await User.find().skip(0).limit(2).sort("-age").select("-fav"); 

    console.log(res);
}
```

## 参考

* 黑马程序员 120天全栈区块链开发 开源教程

    > https://github.com/itheima1/BlockChain

> 一番雾语：操作mongodb最好的NodeJS框架。

-------
<table>
<tr>
<td ><center><img src="http://www.efonmark.com/efonmark-blog/readme/guanzhu_1.jpg" width=40%></center></td>
<td width="50%" align=left><b>
    免费知识星球：<a href="http://www.efonmark.com/efonmark-blog/readme/zhishixingqiu1.png">一番码客-积累交流</a><br>
    微信公众号：<a href="http://www.efonmark.com/efonmark-blog/readme/guanzhu_1.jpg">一番码客</a><br>
    微信：<a href="http://www.efonmark.com/efonmark-blog/readme/weixin.jpg">Efon-fighting</a><br>
    网站：<a href="http://www.efonmark.com">http://www.efonmark.com</a><br></b></td>
</tr>
</table>

