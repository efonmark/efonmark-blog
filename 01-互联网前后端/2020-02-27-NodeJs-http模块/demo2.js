'use strict'
let http = require('http');
let fs = require('fs');

//创建Server
let server = http.createServer( (req, res)=>{
   console.log(req.url);
   res.writeHead(200, {"content-type": "text/html;charset=utf-8"});
   if(req.url === '/a'){
       let html = fs.readFileSync('a.html');
       res.end(html);
   }else if(req.url ==='/b'){
       let html = fs.readFileSync('b.html');
       res.end(html);
   }else if(req.url ==='/'){
       let html = fs.readFileSync('index.html');
       res.end(html);
   }
});
server.listen(4000);