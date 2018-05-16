#pragma once
#include <node_api.h>
#include "../common.h"

napi_value jsFunction (napi_env env, const char* name, napi_callback cb, size_t length = -1, void* data = NULL);

napi_value jsFunctionCall (napi_env env, napi_value thisArg, napi_value fun, size_t argc, const napi_value* argv);

#define JS_FUNCTION(name) jsFunction(env, #name, name)

#define JS_FUNCTION_CALL(fn, argc, argv, thisArg) jsFunctionCall(env, thisArg, fn, argc, argv)
