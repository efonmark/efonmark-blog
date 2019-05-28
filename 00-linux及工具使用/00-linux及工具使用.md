# 00-linux及工具使用

> **一番码客 : efonfighting.imwork.net**  
> 挖掘你关心的亮点。  
----

## Markdown

----

* Markdown编辑器教程: <https://www.w3cschool.cn/lme/?>

----

* markdown指定代码块语言类型

\```python  
    print('欢迎关注公众号“一番码客”')  
\```  

----

* 链接中有空格：用“%20”代替空格
----

## samba

卸载samba,smbclient,samba-common

```shell
$sudo apt-get remove samba-common
$sudo apt-get remove smbclient
$sudo apt-get remove samba
```

安装Ubuntu samba服务器

```shell
sudo apt-get install samba
sudo apt-get install smbfs
```

----
