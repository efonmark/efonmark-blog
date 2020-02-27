'use strict'
let http = require('http');
let fs = require('fs');

http.get("http://www.baidu.com/", res=>{
    // res本质上是一个reader对象，可以监听data事件来拿数据
    let data = ''
    res.on('data', (chunk)=>{
        data += chunk.toString();
    });
    res.on('end', ()=>{
        console.log(data);
    })
});