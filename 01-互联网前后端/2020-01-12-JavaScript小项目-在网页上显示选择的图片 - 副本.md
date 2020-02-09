---
title: JavaScript小项目-在网页上显示选择的图片
date: 2020-01-12
tags: 
categories: 互联网前后端
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200112082453756](2020-01-12-JavaScript小项目-在网页上显示选择的图片/image-20200112082453756.png)

<!--more-->

## 思路分析

1. 选用`<input type="file">`原生组件，实现该组件美化。
2. 选用`<img src="file">`实现图片预览。

## 代码实现

```html
<!DOCTYPE html>
<html>

	<head>
		<meta charset="UTF-8">
		<title>图片预览</title>
		<script src="js/test.js">
            function upload(file) {
                console.log(file)
                let img = document.getElementById('img')
                let formData = new FormData()
                let temp = file.files[0]
                console.log(temp)
                if (temp){
                    formData.append('file',temp)
                    img.src = window.URL.createObjectURL(temp)
                }
            }
        </script>
		<style type="text/css">
			.myBtn{
				padding: 5px 10px;
	            background: rgb(92,184,92);
	            color: white;
	            outline: none;
	            border: none;
	            border-radius: 5px;
	            cursor: pointer;
			}
		</style>
	</head>

	<body>
		<input type="file" style="display: none;" id="file" onchange="upload(this)" />
		<button class="myBtn" onclick="fileBtn()">上传文件</button>
		<br />
		<img src="" id="img" style="width: 50%">
	</body>

</html>
```

## 效果展示

![image-20200112083136137](2020-01-12-JavaScript小项目-在网页上显示选择的图片/image-20200112083136137.png)

> 一番雾语：JavaScript上传图片并预览。

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