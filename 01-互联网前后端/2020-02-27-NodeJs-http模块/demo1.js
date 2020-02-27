'use strict'
let http = require('http');
let fs = require('fs');

//创建Server
let server = http.createServer( (req, res)=>{
   console.log(req.url);
   res.writeHead(200, {"content-type": "application/json;charset=utf-8"});
   let person = {
       name: "一番码客",
       tag: "实用小工具"
   };
   res.end(JSON.stringify(person))
});
server.listen(4000);