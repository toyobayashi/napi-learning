#pragma once
#include <node_api.h>
#include "../common.h"

napi_value jsObject (napi_env env);

napi_value jsGlobal (napi_env env);

napi_value jsGetProperty (napi_env env, napi_value obj, const char* key);

#define JS_OBJECT() jsObject(env)

#define JS_GLOBAL() jsGlobal(env)

#define DECLARE_NAPI_PROPERTY_CALLBACK DECLARE_NAPI_PROPERTY

#define DECLARE_NAPI_PROPERTY_VALUE(name, value) { name, 0, 0, 0, 0, value, napi_default, 0 }

#define SET_PROPERTY(obj, key, value) NAPI_CALL(env, napi_set_named_property(env, obj, key, value))

#define GET_PROPERTY(obj, key) jsGetProperty(env, obj, key)
