#pragma once
#include <node_api.h>
#include "../common.h"

napi_value jsNumber (napi_env env, int32_t number);

napi_value jsNumber (napi_env env, int64_t number);

napi_value jsNumber (napi_env env, uint32_t number);

napi_value jsNumber (napi_env env, double number);

double cDouble (napi_env env, napi_value jsnum);

#define JS_NUMBER(number) jsNumber(env, number)

#define C_DOUBLE(number) cDouble(env, number)
