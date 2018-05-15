const string = require('bindings')('string.node')

console.log(string.cJsString())
console.log(string.cppJsString())
console.log(string.getJsString('MAX_PATH'))
