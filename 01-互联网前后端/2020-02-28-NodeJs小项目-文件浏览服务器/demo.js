'use strict'
let http = require("http");
let fs = require('fs');
let path = require('path');


// 1.启动一个服务器
let server = http.createServer( (req, res)=>{
    if(req.url === '/favicon.ico'){
        res.end("")
        return
    }
    // console.log(req.url);
    res.writeHead(200, {'content-type': 'text/html;charset=utf-8'})
    showDir(req, res)

});

server.listen(5000);

function showDir(req, res) {
    // 默认是/，读取test目录下面的
    // 如果不是/根路径，说明是请求了其他路径

    let target = 'test';
    if(req.url !== '/'){
        //说明是其他的路径，不是根路径的请求
        target = req.url;
    }

    //1. 读取目标目录下的文件列表
    let s = target.substring(target.indexOf("/")+1);
    console.log(s);
    fs.readdir(s, (err, files)=>{
        // res.end(JSON.stringify(files))
        let listr = '';
        files.forEach( f=>{
            let fpath = path.join("./", target, f);
            console.log(fpath);
            let stat = fs.statSync(fpath);
            if(stat.isDirectory()){
                //应该拼上a标签
                // console.log(fpath);
                listr += `<li><a href="${fpath}">${f}</a></li>`
            }else {
                //不拼a标签
                listr += `<li>${f}</li>`
            }

        });

        res.end(makeHtml(listr))
    })
}

function makeHtml(lis) {
    return `<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>标题</title>
    <style type="text/css">
        *{padding: 0; margin: 0}
        ul>li{
            list-style: none;
        }
        
        li{
            padding: .6rem 1rem;
            background-color:#ddd;
            transition: all 1s;
        }
        li:not(:first-child){
             border-top: solid 1px #999;
        }
        li:hover{
            background-color:#aaa;
        }
    </style>
</head>
<body>
<div>
    <ul>
        ${lis}
    </ul>
</div>
</body>
</html>`
}