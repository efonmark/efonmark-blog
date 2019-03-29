# python爬虫实战-爬取微信公众号所有历史文章 - (01) pycharm使用与工程搭建

> **风筝遇春风而起，春雨遇暖阳而至。精神食粮如期为你呈上。**  
> <img src="./pictures/微信图片_20190316215125.jpg" width = 50% height = 30% />


所谓工欲善其事必先利其器，为了使用python搞事情，那首先是搭好环境，写下程序员的开山题词“hello world！”。  
跟很多初入一门语言的小伙伴一样，刚开始一番也百度了“python开发工具”之类的问题，但选来选去，目前还是觉得python开发使用最广的IDE-pycharm（社区版）用着顺手，切入最快。pycharm基本是基于eclipse开发的，很多使用习惯和快捷键都和eclipse类似，所以开发过APP或者之前就用eclipse开发的小伙伴可以说是倍感亲切，无缝切换。（虽然一番只是自学java时用过一段时间eclipse）。  
一番所有的文章和环境，都以ubuntu18.04为基础，并且作为软件开发，ubuntu真的是超顺手啦。  
1. 下载安装  
直入主题，如果是ubuntu18.04的话，系统自带的软件软件管理工具“ubuntu软件”里可以直接搜索pycharm CE，就可以找到pycharm免费社区版。当然也可以去pycharm官网下载：https://www.jetbrains.com/pycharm/download/ 。一番这里的安装后没有汉化，如果小伙伴们看英文不习惯的话，可以选择汉化一下。贴个汉化教程[链接](https://mp.weixin.qq.com/s?src=11&timestamp=1552820095&ver=1490&signature=5xITg2CHgzhWMh*kLme2o5aJ2C1i6L*AYKp9yHVWu2XcUO*OIqMe1sAg985-0uTZ9ZupCrg998Bsdq2XN4Jxh14Um0mWZoQYHswA4lIDtUG7jRUjnJFyfNDSBG32Ja7R&new=1)。

2. 工程新建  
> 打开 pycharm后，选择“Create New Project”。  
> <img src="./pictures/深度截图_选择区域_20190317184507.png" width = 70% height = 30% >  
> **Location** ：选择工程文件存放目录。  
> **Interpreter**：  
> * 程序解释器：这里需要选择新建或者选择一个已有的python工程运行环境，也就是程序解释器。后面我们手动安装的各种python包（package、轮子）需要存放在这个目录(这里是venv这个目录)下。  
> * 解释器配置：一番为了保证每个工程的独立性和减少耦合，通常每个工程会用自己独立的程序解释器。并且不会继承全局包地址和使这个配置对所有工程可见，我们选择ubuntu默认带的比较新的3.6版本。配置如下图。  
> * 创建：配置好后我们点击创建"Create"既可以创建好了。这里有一个报错，现象与解决办法见文末"附录1"。  
> <img src="./pictures/深度截图_选择区域_20190317185143.png" width = 70% height = 30% >  
> * 其他问题：  
> <img src="./pictures/深度截图_选择区域_20190317203436.png" width = 70% height = 30% >  

>



3. hello world：开始干活啦！
> * 新建主文件：dangdangdang~ 。我们的主文件出现啦，写下我们的干活宣言。  
> 注意红框左上角的"Project Files"，这里是工程目录的展示方式，一番喜欢用"Project Files"的视角去查看整个工程的情况。  
> <img src="./pictures/深度截图_选择区域_20190317210107.png" width = 70% height = 30% >  
> * 新建并指定解释器：完成工程新建后发现python console里还有报错，我们需要为工程指定解释器，见“附录2”。
> * 运行：点击绿色运行按钮。啦啦啦，“hello world!”看世界对我们的友善回应。  
> <img src="./pictures/深度截图_选择区域_20190317212127.png" width = 70% height = 30% >  
>这样我们的工程就搭建结束啦，算是为后面工程的继续添砖加瓦打下了坚实的地基，所谓万行代码从"hello world"起。我们就可以在这个工程下继续添砖加瓦啦。
4. 其他使用技巧
> 对于一个IDE的使用，包括**快捷键、主题设置**等等，这些其实并不是很重要，哪怕我们只会鼠标键盘，基于前面的三步，已经可以完成我们的整个工程开发了。但为了提高效率和舒适度，我们还是可以掌握一下的，这里一番为小伙伴们找了几篇相关文章，可以供大家拓展学习。  
> * [手把手教你配置最漂亮的PyCharm界面,Python程序员必备!](https://mp.weixin.qq.com/s?src=11&timestamp=1552829715&ver=1490&signature=m7XTJ7XwLpKNN3hRod0INdCDlTx*mLG3iXNVR5Fo3Sfy04HmILJT*yj5RIWl-K04LSkVNG9HUySDznkIbCohdkHszdpdy46lSJjVJNSM44ApnLKZ68uz*aoJzAV*hT6F&new=1)  
> * [Pycharm快捷键大全 ](https://mp.weixin.qq.com/s?src=11&timestamp=1552829817&ver=1490&signature=EYkLCGAryx4NxP67Ya4u-2GkVDXhv*eEw94YJqsamXHLLNvAttgYbpUTOQhngzQb36xu4yaanGJ5cOZ44VgJjMTCTkKjxrJ*M28*6*TBl*eSDbjtIByvjZNit42daXP2&new=1)  
> * **其他**：当然，基于eclipse的IDE可谓功能极其强大，还有一些开发和调试的实用技能，一番会在后面文章用到时穿插在各个功能开发与调试的文章中，在潜移默化中完成对pycharm的驾驭。  
5. 呼 ~ 打完收工！  
<img src="./pictures/womenshixiongdi.png" width = 70% height = 30% >    


**附录**：
> 1. 报错：ModuleNotFoundError: No module named 'distutils.core'。  
> 原因：ubuntu默认没有安装pip安装器，这个会影响到我们安装python包（轮子）。  
> 解决：sudo apt-get install python3-pip  
> <img src="./pictures/深度截图_选择区域_20190317191425.png" width = 70% height = 30% >

> 2. 报错：Error:Python interpreter is not selected.Please setup Python interpreter first.  
> 原因：虽然我们创建工程的时候有新建解释器，但我们并没有完成指定，这需要我们给我们的工程指定解释器。  
> 解决：我们点击 “file” → “Setting” → “Project Interpreter” → "Add"，如下图，最后OK。  
> <img src="./pictures/深度截图_选择区域_20190317204146.png" width = 80% height = 30% >  
> <img src="./pictures/深度截图_选择区域_20190317204344.png" width = 80% height = 30% >  
> 选择我们刚新建的解释器。好啦，以后我们要为我们的工程添加新的依赖包时就点这里的“+”就可以啦，非常方便。    
> <img src="./pictures/深度截图_选择区域_20190317204450.png" width = 80% height = 30% >  
> 然后我们为本工程指定解释器，以后我们点击绿色小三角运行我们的工程时就是用的这里指定的**脚本入口**和**解释器**啦。  
> <img src="./pictures/深度截图_选择区域_20190317205709.png" width = 80% height = 30% >  
> <img src="./pictures/深度截图_选择区域_20190317211351.png" width = 80% height = 30% >  

> 下期预告：python爬虫实战-爬取微信公众号所有历史文章 - (02) python封装adb命令操作安卓手机

> 欢迎关注微信公众号“**一番码客**”获取**免费下载服务**与**源码**，并及时接收最新文章推送。点击“阅读原文”有惊喜。  
> ## efonfighting.imwork.net  
> **趋势不会因为个别的吝啬与懒惰而停止向前的车轮，所以迈开脚步，一起赶路。**  
