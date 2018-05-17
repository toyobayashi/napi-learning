// const asyncFunction = require('bindings')('async.node')
const asyncFunction = require('../build/Release/async.node')

asyncFunction('JS, ', str => {
  console.log(new Date().getTime())
  console.log(str)
})
console.log('Sync.')
asyncFunction('JS222, ', str => {
  console.log(new Date().getTime())
  console.log(str + 'qqq')
})

