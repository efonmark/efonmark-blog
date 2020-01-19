---
title: JavaScript小项目-轮播图
date: 2020-01-13
tags: 
categories: 互联网前后端
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200113080526961](2020-01-13-JavaScript小项目-轮播图/image-20200113080526961.png)

<!--more-->

## 思路分析

1. css定义图片样式。
2. 定时器每三秒换一个img src。

## 代码实现

```html
<!DOCTYPE html>
<html>

	<head>
		<meta charset="UTF-8">
		<title></title>
		<style>
			a {
				text-decoration: none;
			}
			
			.cle {
				clear: both;
			}
			/*logo 部分的div*/
			
			.header {
				width: 100%;
			}
			
			.header div {
				float: left;
				width: 33.33%;
				height: 60px;
				line-height: 50px;
			}
			
			.header a {
				padding: 15px;
			}
			/*菜单部分*/
			
			.menu {
				width: 100%;
				background-color: #000;
				height: 50px;
				padding-top: 1px;
				margin-bottom: 20px;
			}
			
			.menu ul li {
				list-style-type: none;
				display: inline;
			}
			
			.menu a {
				font-size: 25px;
				color: #fff;
			}
			/*轮播图*/
			
			.lunbo {
				width: 60%;
				display: table-cell;
				text-align: center;
				
			}
			
			/*热门商品*/
			/*.left,.right{
				float:left;
			}*/
			
			.left {
				float: left;
				width: 16%;
				height: 500px;
			}
			
			.right {
				float: left;
				width: 84%;
				text-align: center;
				height: 500px;
			}
			
			.middle {
				float: left;
				width: 50%;
				height: 250px;
			}
			
			.item {
				float: left;
				width: 16.66%;
				height: 250px;
			}
			/*给广告*/
			
			.ad1 {
				width: 100%;
			}
			
			.ad1 img {
				width: 100%;
			}
			/*版权*/
			
			.foot {
				width: 100%;
			}
			
			.foot p {
				text-align: center;
			}
		</style>

		<script type="text/javascript">
			var index = 1;

			function changeSrc() {
				index++;

				// 获取img标签
				var imgTag = document.getElementById("imgId");
				imgTag.src = "../img/" + index + ".jpg"

				if(index == 3) {
					index = 0;
				}

			}

			window.onload = function() {

				setInterval("changeSrc()", 3000)
			}
		</script>
	</head>

	<body>
		<!--
			一个大div中放置8个div
		-->
		<div>
			<!--logo
				嵌套三个div
			-->
			<div class="header">
				<div>
					<img src="../img/logo.png" height="50px" />
				</div>
				<div>
					<img src="../img/header.jpg" />
				</div>
				<div>
					<a href="#">登录</a>
					<a href="#">注册</a>
					<a href="#">购物车</a>
				</div>
			</div>

			<div class="cle"></div>

			<!--菜单-->
			<div class="menu">
				<ul>
					<li>
						<a href="#">首页</a>
					</li>
				</ul>
			</div>

			<!--轮播图-->
			<div class="lunbo">
				<img id="imgId" src="../img/1.jpg" />
			</div>

			<!--热门
				将起划分成两个div
					左边放图片
					右边的放商品
			-->
			<div class="hot">
				<!--存放热门商品和一张图片-->
				<div>
					<h2 style="display: inline;">热门商品</h2>
					<img src="../img/title2.jpg" />
				</div>
				<div>
					<!--存放左边的图片-->
					<div class="left">
						<img src="../img/big01.jpg" />
					</div>
					<!--存放商品图片-->
					<div class="right">
						<div class="middle">
							<img src="../img/middle01.jpg" />
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>

						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>

						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>
						<div class="item">
							<img src="../img/small08.jpg" />
							<p align="center">
								<a href="#">电饭煲</a>
							</p>
							<p align="center">200</p>
						</div>

					</div>
				</div>
			</div>

			<div class="cle"></div>

			<!--广告-->
			<div class="ad1">
				<img src="../img/ad.jpg" />
			</div>

			<!--广告-->
			<div class="ad1">
				<img src="../img/footer.jpg" />
			</div>

			<!--版权foot-->
			<div class="foot">
				<p>
					<a href="#">关于我们</a>
				</p>
				<p>
					Copyright &copy; 2010-2020 一番码客 版权所有
				</p>
			</div>

		</div>
	</body>

</html>
```

## 效果展示

![image-20200112083136137](2020-01-13-JavaScript小项目-轮播图/Video_20200113080213.gif)

> 一番雾语：做一个推广页面好不好。

-------
<table>
<tr>
<td ><center><img src="http://efonfighting.imwork.net/efonmark-blog/readme/guanzhu_1.jpg" width=40%></center></td>
<td width="50%" align=left><b>
    免费知识星球：<a href="http://efonfighting.imwork.net/efonmark-blog/%E7%AE%80%E4%BB%8B/zhishixingqiu1.png">一番码客-积累交流</a><br>
    微信公众号：<a href="http://efonfighting.imwork.net/efonmark-blog/%E7%AE%80%E4%BB%8B/guanzhu_1.jpg">一番码客</a><br>
    微信：<a href="http://efonfighting.imwork.net/efonmark-blog/%E7%AE%80%E4%BB%8B/weixin.jpg">Efon-fighting</a><br>
    网站：<a href="http://efonfighting.imwork.net">http://efonfighting.imwork.net</a><br></b></td>
</tr>
</table>