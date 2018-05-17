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

napi_ref createRef (napi_env env, napi_value value, size_t initial_refcount) {
  napi_ref ref;
  NAPI_CALL(env, napi_create_reference(env, value, initial_refcount, &ref));
  return ref;
}

napi_value getRef (napi_env env, napi_ref ref) {
  napi_value result;
  NAPI_CALL(env, napi_get_reference_value(env, ref, &result));
  return result;
}

void deleteRef (napi_env env, napi_ref ref) {
  NAPI_CALL_RETURN_VOID(env, napi_delete_reference(env, ref));
}
