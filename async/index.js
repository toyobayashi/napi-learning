const asyncFunction = require('bindings')('async.node')

for (var i = 0; i < 5; i++) {
  console.log(i)
  asyncFunction(i + ' ', str => {
    console.log(i)
    console.log(new Date().getTime())
    console.log(str + 'z')
  })
}
