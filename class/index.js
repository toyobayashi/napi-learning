const c = require('bindings')('class.node')

let p1 = new c.Person('aaa', 66)
let p2 = new c.Person('bbb', 55)
p1.say()
p2.say()
