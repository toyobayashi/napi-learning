#include "./nobject.h"
#include "../string/nstring.h"
#include "../function/nfunction.h"
#include "../type/ntype.h"

static napi_value runCallback (napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  NAPI_ASSERT(env, argc == 2, "Wrong number of arguments");

  NAPI_ASSERT(env, JS_TYPE(args[0]) == napi_object, "Expect an object");
  NAPI_ASSERT(env, JS_TYPE(args[1]) == napi_function, "Expect a function");

  napi_value argv[2];

  napi_value obj = JS_OBJECT();
  SET_PROPERTY(obj, "napi", JS_STRING("hello napi"));
  argv[0] = obj;

  napi_value fromJs = GET_PROPERTY(args[0], "msg");
  argv[1] = fromJs;
  JS_FUNCTION_CALL(args[1], 2, argv, JS_GLOBAL());

  return NULL;
}

NAPI_MODULE_INIT() {
  SET_PROPERTY(exports, "runCallback", JS_FUNCTION(runCallback));
  return exports;
}
