#include <node_api.h>
#include "../common.h"
#include "../string/nstring.h"
#include "../function/nfunction.h"
#include "../object/nobject.h"
#include "../type/ntype.h"

using namespace std;

typedef struct {
  string _input;
  string _output;
  napi_ref _cbref;
  napi_async_work _request;
} carrier;

static napi_value asyncFunction (napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, nullptr, nullptr));
  NAPI_ASSERT(env, argc >= 2, "Not enough arguments, expected 1.");
  NAPI_ASSERT(env, JS_TYPE(args[1]) == napi_function, "Wrong argument, function expected.");

  carrier* the_carrier = new carrier;

  the_carrier->_input = CPP_STRING(args[0]);
  the_carrier->_cbref = CREATE_REF(args[1], 1);

  NAPI_CALL(env, napi_create_async_work(
    env,
    nullptr,
    JS_STRING("asyncFunction"),
    [](napi_env env, void* data) -> void {
      carrier* c = static_cast<carrier*>(data);
      c->_output = c->_input + "Async.";
    },
    [](napi_env env, napi_status status, void* data) -> void {
      if (status != napi_ok) {
        napi_throw_type_error(env, nullptr, "Execute callback failed.");
        return;
      }

      carrier* c = static_cast<carrier*>(data);

      napi_value argv[1] = { JS_STRING(c->_output) };

      NAPI_ASSERT_RETURN_VOID(env, JS_TYPE(GET_REF(c->_cbref)) == napi_function, "c->_cbref is not function.");
      JS_FUNCTION_CALL(GET_REF(c->_cbref), 1, argv, JS_GLOBAL());
      DELETE_REF(c->_cbref);
      NAPI_CALL_RETURN_VOID(env, napi_delete_async_work(env, c->_request));
      delete c;
    },
    the_carrier,
    &the_carrier->_request
  ));

  NAPI_CALL(env, napi_queue_async_work(env, the_carrier->_request));

  return nullptr;
}

NAPI_MODULE_INIT() {
  return JS_FUNCTION(asyncFunction);
}
