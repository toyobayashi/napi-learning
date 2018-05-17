# napi-learning

流下了不会吸屁屁的泪水

Node.js version: Current

## MICRO

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

#define JS_PROMISE() jsPromise(env)
// => promise_struct: { deferred: napi_deferred; promise: (napi_value: Promise<any>) }

#define JS_OBJECT() jsObject(env)
// => napi_value: {}

#define JS_GLOBAL() jsGlobal(env)
// => napi_value: NodeJS.Global

#define CPP_STRING(str) cppString(env, str)
// => std::string

#define C_STRING(str, result) cString(env, str, result)
// => size_t

#define C_DOUBLE(number) cDouble(env, number)
// => double

#define DECLARE_NAPI_PROPERTY_CALLBACK DECLARE_NAPI_PROPERTY
// => napi_property_descriptor (method)

#define DECLARE_NAPI_PROPERTY_VALUE(name, value) { name, 0, 0, 0, 0, value, napi_default, 0 }
// => napi_property_descriptor (value)

#define SET_PROPERTY(obj, key, value) NAPI_CALL(env, napi_set_named_property(env, obj, key, value))
// => void

#define GET_PROPERTY(obj, key) jsGetProperty(env, obj, key)
// => napi_value: any

#define CREATE_REF(value, count) createRef(env, value, count)
// => napi_ref

#define GET_REF(ref) getRef(env, ref)
// => napi_value: any

#define DELETE_REF(ref) deleteRef(env, ref)
// => void

#define CREATE_ASYNC_WORK(name, execute, complete, data) createAsyncWork(env, name, execute, complete, data)
// => napi_async_work

#define QUEUE_ASYNC_WORK(work) queueAsyncWork(env, work)
// => void

#define DELETE_ASYNC_WORK(work) deleteAsyncWork(env, work)
// => void

#define ASYNC_EXECUTE(data) [](napi_env env, void* data)
// => lambda args

#define ASYNC_COMPLETE(data) [](napi_env env, napi_status status, void* data)
// => lambda args

#define RESOLVE_PROMISE(promiseStruct, resolution) resolvePromise(env, promiseStruct, resolution)
// => void

#define REJECT_PROMISE(promiseStruct, rejection) rejectPromise(env, promiseStruct, rejection)
// => void
```
