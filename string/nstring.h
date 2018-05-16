#pragma once
#include <node_api.h>
#include <iostream>
#include "../common.h"

napi_value jsString (napi_env env, const char* cstr);

napi_value jsString (napi_env env, std::string cppstr);

std::string cppString (napi_env env, napi_value jsstr, size_t size = 259);

size_t cString (napi_env env, napi_value jsstr, char* result, size_t size = 259);

#define JS_STRING(str) jsString(env, (str))
