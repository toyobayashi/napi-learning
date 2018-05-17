#pragma once
#include <node_api.h>
#include "../common.h"

napi_value jsObject (napi_env env);

napi_value jsGlobal (napi_env env);

napi_value jsGetProperty (napi_env env, napi_value obj, const char* key);

napi_ref createRef (napi_env env, napi_value value, size_t initial_refcount);

napi_value getRef (napi_env env, napi_ref ref);

void deleteRef (napi_env env, napi_ref ref);

#define JS_OBJECT() jsObject(env)

#define JS_GLOBAL() jsGlobal(env)

#define DECLARE_NAPI_PROPERTY_CALLBACK DECLARE_NAPI_PROPERTY

#define DECLARE_NAPI_PROPERTY_VALUE(name, value) { name, 0, 0, 0, 0, value, napi_default, 0 }

#define SET_PROPERTY(obj, key, value) NAPI_CALL(env, napi_set_named_property(env, obj, key, value))

#define GET_PROPERTY(obj, key) jsGetProperty(env, obj, key)

#define CREATE_REF(value, count) createRef(env, value, count)

#define GET_REF(ref) getRef(env, ref)

#define DELETE_REF(ref) deleteRef(env, ref)
