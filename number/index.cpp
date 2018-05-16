#include "./nnumber.h"
#include "../function/nfunction.h"

static napi_value add (napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  NAPI_ASSERT(env, argc >= 2, "Wrong number of arguments");

  return JS_NUMBER(C_DOUBLE(args[0]) + C_DOUBLE(args[1]));
}

NAPI_MODULE_INIT() {
  return JS_FUNCTION(add);
}
