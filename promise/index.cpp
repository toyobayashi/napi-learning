#include "./npromise.h"
#include "../string/nstring.h"
#include "../function/nfunction.h"
#include "../type/ntype.h"

using namespace std;

static napi_value asyncPromise (napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, nullptr, nullptr));
  NAPI_ASSERT(env, argc >= 1, "Not enough arguments, expected 1.");
  NAPI_ASSERT(env, JS_TYPE(args[0]) == napi_string, "Wrong argument, string expected.");

  promise_struct p = JS_PROMISE();

  napi_value resolution = JS_STRING(CPP_STRING(args[0]) + "Async.");
  RESOLVE_PROMISE(p, resolution);

  return p.promise;
}

NAPI_MODULE_INIT() {
  return JS_FUNCTION(asyncPromise);
}
