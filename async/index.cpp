#include "./nasync.h"
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
  the_carrier->_request = CREATE_ASYNC_WORK(
    JS_STRING("asyncFunction"),
    ASYNC_EXECUTE(data) {
      carrier* c = static_cast<carrier*>(data);
      c->_output = c->_input + "Async.";
    },
    ASYNC_COMPLETE(data) {
      if (status != napi_ok) {
        napi_throw_type_error(env, nullptr, "Execute callback failed.");
        return;
      }

      carrier* c = static_cast<carrier*>(data);

      napi_value argv[1] = { JS_STRING(c->_output) };
      napi_value callback = GET_REF(c->_cbref);

      NAPI_ASSERT_RETURN_VOID(env, JS_TYPE(callback) == napi_function, "c->_cbref is not function.");
      JS_FUNCTION_CALL(callback, 1, argv, JS_GLOBAL());
      DELETE_REF(c->_cbref);
      DELETE_ASYNC_WORK(c->_request);
      delete c;
    },
    the_carrier
  );

  QUEUE_ASYNC_WORK(the_carrier->_request);

  return nullptr;
}

NAPI_MODULE_INIT() {
  return JS_FUNCTION(asyncFunction);
}
