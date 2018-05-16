#include "./nnumber.h"
#include "../type/ntype.h"

napi_value jsNumber (napi_env env, int32_t number) {
  napi_value jsnum;
  NAPI_CALL(env, napi_create_int32(env, number, &jsnum));
  return jsnum;
}

napi_value jsNumber (napi_env env, int64_t number) {
  napi_value jsnum;
  NAPI_CALL(env, napi_create_int64(env, number, &jsnum));
  return jsnum;
}

napi_value jsNumber (napi_env env, uint32_t number) {
  napi_value jsnum;
  NAPI_CALL(env, napi_create_uint32(env, number, &jsnum));
  return jsnum;
}

napi_value jsNumber (napi_env env, double number) {
  napi_value jsnum;
  NAPI_CALL(env, napi_create_double(env, number, &jsnum));
  return jsnum;
}

double cDouble (napi_env env, napi_value jsnum) {
  NAPI_ASSERT(env, JS_TYPE(jsnum) == napi_number, "Wrong type of argument. Expects a number.");

  double result;
  NAPI_CALL(env, napi_get_value_double(env, jsnum, &result));
  return result;
}
