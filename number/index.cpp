#include <node_api.h>
#include "../common.h"
#include <iostream>

using namespace std;

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

#define JS_NUMBER(number) jsNumber(env, number)
#define C_DOUBLE(number) cDouble(env, number)

double cDouble (napi_env env, napi_value jsnum) {
  napi_valuetype valuetype;
  NAPI_CALL(env, napi_typeof(env, jsnum, &valuetype));
  NAPI_ASSERT(env, valuetype == napi_number, "Wrong type of argument. Expects a number.");

  double result;
  NAPI_CALL(env, napi_get_value_double(env, jsnum, &result));
  return result;
}

static napi_value add (napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  NAPI_ASSERT(env, argc >= 2, "Wrong number of arguments");

  return JS_NUMBER(C_DOUBLE(args[0]) + C_DOUBLE(args[1]));
}

NAPI_MODULE_INIT() {
  NAPI_CALL(env, napi_create_function(env, "exports", -1, add, NULL, &exports));
  return exports;
}
