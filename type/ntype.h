#pragma once
#include <node_api.h>
#include "../common.h"

napi_valuetype jsType (napi_env env, napi_value value);

#define JS_TYPE(value) jsType(env, value)
