const crypto = require('crypto');

// 加密
function genSign(src, key, iv) {
    let sign = '';
    const cipher = crypto.createCipheriv('aes-128-cbc', key, iv);
    sign += cipher.update(src, 'utf8', 'hex');
    sign += cipher.final('hex');
    return sign;
}

// 解密
function deSign(sign, key, iv) {
    let src = '';
    const cipher = crypto.createDecipheriv('aes-128-cbc', key, iv);
    src += cipher.update(sign, 'hex', 'utf8');
    src += cipher.final('utf8');
    return src;
}

// ase-128-cbc 加密算法要求key和iv长度都为16
const data = '一番码客：实用工具 = python + nodejs'

const key = Buffer.from('9vApxLk5G3PAsJrM', 'utf8');
const iv = Buffer.from('FnJL7EDzjqWjcaY9', 'utf8');

const sign = genSign(data, key, iv);
console.log(sign);


const src=deSign('3299dbc38361cc6d2d0a3f53774848aab6c660791d5714de4e8f0f685419dda4353c7ac25f9ccdb34d47687376d59fdc', key, iv);
console.log(src);