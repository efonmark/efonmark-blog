'use strict'
let EventEmitter = require('events');

class MyEmitter extends EventEmitter{

}

let myEmitter = new MyEmitter();
// 监听事件
myEmitter.on('registerSuccess', (p)=>{
    // console.log("我笑了, 参数是："+ JSON.stringify(p));
    console.log("用户注册成功了，我马上要发送邮件");
});

//触发事件
setTimeout(()=>{
    let person = {
        name: "赵四"
    };
    myEmitter.emit("registerSuccess", person);
}, 2000);