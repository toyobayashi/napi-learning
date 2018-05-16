const addon = require('bindings')('object.node')

addon.runCallback({ msg: 'fromjs' }, (obj, fromJS) => console.log(obj, fromJS))
console.log(addon.runCallback.toString())
