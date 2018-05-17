const asyncPromise = require('bindings')('promise.node')

for (var i = 0; i < 5; i++) {
  console.log(i)
  console.log(asyncPromise(i + ' ').then(str => {
    console.log(i)
    console.log(new Date().getTime())
    console.log(str + 'z')
  }))
}
