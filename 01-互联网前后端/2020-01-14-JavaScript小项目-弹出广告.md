---
title: JavaScript小项目-弹出广告
date: 2020-01-14
tags: 
categories: 互联网前后端
---

> **一番码客 : 挖掘你关心的亮点。**
> **http://www.efonmark.com**

本文目录：

[TOC]

![image-20200114080255462](2020-01-14-JavaScript小项目-弹出广告/image-20200114080255462.png)

<!--more-->

## 思路分析

1. 4秒钟之后显示广告,广告显示2秒钟，之后隐藏。
2. 循环往复3次，广告永远消失。
3. setInterval(function, timeout ms):每隔多长时间执行一次函数，该定时器会重复执行。
4. clearInterval()：取消定时器，需要传入定时器对象。
5. setTimeout(function, timeout ms):在指定延时时间后调用函数，该定时器只执行一次。
6. clearTimeout(): 取消定时器，需要传入定时器对象。

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
				padding-top: 1px
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
				width: 100%;
				margin-top: 10px;
				margin-bottom: 10px;
			}
			
			.lunbo img {
				width: 100%;
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

		<!--
			4秒钟之后显示广告,广告显示2秒钟,之后隐藏
			循环往复3次,广告永远消失
		-->

		<script type="text/javascript">
			var index = 0;
			var timer = null;

			function showAd() {

				index++;

				var adTag = document.getElementById("ad");
				adTag.style.display = "block";

				setTimeout("hideAd()", 2000);

				if(index == 3) {
					clearInterval(timer);
				}
			}

			function hideAd() {
				var adTag = document.getElementById("ad");
				adTag.style.display = "none";
			}

			window.onload = function() {

				timer = setInterval("showAd()", 4000);

			}
		</script>
	</head>

	<body>
		<div id="ad" style="width:100%;display: none;">
			<img src="../img/ad_.jpg" width="100%" />
		</div>
		<!--
			一个大div中放置8个div
		-->
		<div>
			<!--logo
				嵌套三个div
			-->
			<div class="header">
				<div>
					<img src="../img/logo.png" height="40px" />
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
				<img src="../img/1.jpg" />
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

			<!--最新-->
			<div></div>

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

![](2020-01-14-JavaScript小项目-弹出广告/Video_20200114080959.gif)

> 一番雾语：这就是我们平时讨厌的网页广告。

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