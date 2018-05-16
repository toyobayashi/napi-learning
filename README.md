# napi-learning

流下了不会吸屁屁的泪水

Node.js version: Current

## Note

``` cpp
#define JS_TYPE(value) jsType(env, value)
// => napi_valuetype

#define JS_FUNCTION(name) jsFunction(env, #name, name)
// => napi_value: Function

#define JS_FUNCTION_CALL(fn, argc, argv, thisArg) jsFunctionCall(env, thisArg, fn, argc, argv)
// => napi_value: any

#define JS_STRING(str) jsString(env, str)
// => napi_value: string

#define JS_NUMBER(number) jsNumber(env, number)
// => napi_value: number

#define JS_OBJECT() jsObject(env)
// => napi_value: {}

#define JS_GLOBAL() jsGlobal(env)
// => napi_value: NodeJS.Global

#define DECLARE_NAPI_PROPERTY_CALLBACK DECLARE_NAPI_PROPERTY
// => napi_property_descriptor (method)

#define DECLARE_NAPI_PROPERTY_VALUE(name, value) { name, 0, 0, 0, 0, value, napi_default, 0 }
// => napi_property_descriptor (value)

#define SET_PROPERTY(obj, key, value) NAPI_CALL(env, napi_set_named_property(env, obj, key, value))
// => void

#define GET_PROPERTY(obj, key) jsGetProperty(env, obj, key)
// => napi_value: any
```
