'use strict'

let crypto = require('crypto')

let data = "一番码客：实用工具 = python + nodejs";

// md5 哈希算法
let md5 = crypto.createHash("md5");
let sha1 = crypto.createHash("sha1");
let sha256 = crypto.createHash("sha256");
let salt = "nodejs";
let hmac = crypto.createHmac("sha1", salt);

md5.update(data);
let result = md5.digest("hex");
console.log('md5:' + result);

sha1.update(data);
result = sha1.digest("hex");
console.log('sha1:' + result);

sha256.update(data);
result = sha256.digest("hex");
console.log('sha256:' + result);

// 随机数增强的hash算法
hmac.update(data);
result = hmac.digest("hex");
console.log('hmac:'+result);
