#include "./nobject.h"

napi_value jsObject (napi_env env) {
  napi_value jsObj;
  NAPI_CALL(env, napi_create_object(env, &jsObj));
  return jsObj;
}

napi_value jsGlobal (napi_env env) {
  napi_value global;
  NAPI_CALL(env, napi_get_global(env, &global));
  return global;
}

napi_value jsGetProperty (napi_env env, napi_value obj, const char* key) {
  napi_value value;
  NAPI_CALL(env, napi_get_named_property(env, obj, key, &value));
  return value;
}
