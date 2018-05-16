#include "./nfunction.h"

napi_value jsFunction (napi_env env, const char* name, napi_callback cb, size_t length, void* data) {
  napi_value fun;
  NAPI_CALL(env, napi_create_function(env, name, length, cb, data, &fun));
  return fun;
}

napi_value jsFunctionCall (napi_env env, napi_value thisArg, napi_value fn, size_t argc, const napi_value* argv) {
  napi_value result;
  NAPI_CALL(env, napi_call_function(env, thisArg, fn, argc, argv, &result));
  return result;
}
