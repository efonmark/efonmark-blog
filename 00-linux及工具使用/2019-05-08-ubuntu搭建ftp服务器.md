# ubuntu搭建ftp服务器

> **一番码客 : efonfighting.imwork.net**  
> 专注数据挖掘与聚合，分享数据挖掘软件工具与开发技术。
----


用linux搭建ftp服务器的情况很常见，也很常见，最近一番在搭建云服务器，就用到了这个，这里总结一下，分享给需要的同学，一步一步按部就班即可，轻松搞定。  

## 在线安装  

> sudo apt-get install vsftpd

## 创建主目录，输入命令

> sudo mkdir /home/efonfighting

## 新建一个用户

> sudo useradd -d /home/efonfighting -s /bin/bash efonfighting

## 进行设置密码

> sudo passwd efonfighting

## 删除该文件夹中vsftpd  

因为这个vsftpd配置文件会使用户名登录 ftp 失败
> sudo rm /etc/pam.d/vsftpd

## 赋予用户只能使用ftp方式登录

> sudo usermod -s /sbin/nologin efonfighting

## 配置VSFTP  

先备份源配置文件，然后新建一个
> sudo mv /etc/vsftpd.conf /etc/sftpd.conf.orig  
> sudo touch /etc/vsftpd.conf

在该文件中，输入以下内容：

```txt
listen=NO
listen_ipv6=YES
anonymous_enable=NO
local_enable=YES
write_enable=YES
local_umask=022
dirmessage_enable=YES
use_localtime=YES
xferlog_enable=YES
connect_from_port_20=YES
chroot_local_user=YES
secure_chroot_dir=/var/run/vsftpd/empty
pam_service_name=vsftpd
rsa_cert_file=/etc/ssl/certs/ssl-cert-snakeoil.pem
rsa_private_key_file=/etc/ssl/private/ssl-cert-snakeoil.key
ssl_enable=NO
pasv_enable=Yes
pasv_min_port=10000
pasv_max_port=10100
allow_writeable_chroot=YES
```

## 创建vsftpd.user_list文件  

> sudo touch /etc/vsftpd.user_list  
> sudo chmod a+w /etc/vsftpd.user_list

## 编辑vsftpd.user_list文件，添加用户  

写入对应的用户名 efonfighting ，保存退出。
> vi /etc/vsftpd.user_list  

## 重新启动服务

> sudo service vsftpd restart

----
<div align=center><img src="http://efonfighting.imwork.net/blog_tail.jpg" width=50%\>