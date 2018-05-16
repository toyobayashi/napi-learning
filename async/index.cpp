#include <node_api.h>
#include "../common.h"
#include "../string/nstring.h"
#include "../function/nfunction.h"
#include "../object/nobject.h"
#include "../type/ntype.h"

typedef struct {
  char* _input;
  char* _output;
  napi_ref _cbref;
  napi_value callback;
  napi_async_work _request;
} carrier;
carrier the_carrier;

void execute (napi_env env, void* data) {
  carrier* c = static_cast<carrier*>(data);
  c->_output = "Async.";
}

void complete (napi_env env, napi_status status, void* data) {
  if (status != napi_ok) {
    napi_throw_type_error(env, NULL, "Execute callback failed.");
    return;
  }

  carrier* c = static_cast<carrier*>(data);

  napi_value argv[1] = { JS_STRING(c->_output) };

  // napi_value callback;
  NAPI_CALL_RETURN_VOID(env, napi_get_reference_value(env, c->_cbref, &c->callback));
  NAPI_ASSERT_RETURN_VOID(env, JS_TYPE(c->callback) == napi_function, "c->_cbref is not function.");
  JS_FUNCTION_CALL(c->callback, 1, argv, JS_GLOBAL());

  NAPI_CALL_RETURN_VOID(env, napi_delete_reference(env, c->_cbref));
  NAPI_CALL_RETURN_VOID(env, napi_delete_async_work(env, c->_request));
}

static napi_value asyncFunction (napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  NAPI_ASSERT(env, argc >= 1, "Not enough arguments, expected 1.");
  NAPI_ASSERT(env, JS_TYPE(args[0]) == napi_function, "Wrong argument, function expected.");

  NAPI_CALL(env, napi_create_reference(env, args[0], 1, &the_carrier._cbref));
  NAPI_CALL(env, napi_create_async_work(env, JS_OBJECT(), JS_STRING("empty"), execute, complete, &the_carrier, &the_carrier._request));
  NAPI_CALL(env, napi_queue_async_work(env, the_carrier._request));

  return NULL;
}

/* static napi_value init (napi_env env, napi_value exports) {
  return JS_FUNCTION(asyncFunction);
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init) */

NAPI_MODULE_INIT() {
  return JS_FUNCTION(asyncFunction);
}
