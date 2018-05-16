// const asyncFunction = require('bindings')('async.node')
const asyncFunction = require('../build/Release/async.node')

asyncFunction(str => console.log(str))
console.log('Sync.')
