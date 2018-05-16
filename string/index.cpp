
#include "./nstring.h"

using namespace std;

static napi_value cJsString (napi_env env, napi_callback_info info) {
  const char* cstr = "(char*) Hello NAPI";
  return JS_STRING(cstr);
}

static napi_value cppJsString (napi_env env, napi_callback_info info) {
  string cppstr = "(string) Hello NAPI";
  return JS_STRING(cppstr);
}

static napi_value getJsString(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  NAPI_ASSERT(env, argc >= 1, "Wrong number of arguments");

  string cppstr = cppString(env, args[0]);
  char cstr[260];
  size_t length = cString(env, args[0], cstr);

  printf("cstr: %s\n", cstr);
  printf("strlen(cstr): %zu\n", strlen(cstr));
  printf("cString(env, args[0], cstr): %zu\n", length);
  printf("cppstr: %s\n", cppstr.c_str());
  printf("cppstr.length(): %zu\n", cppstr.length());

  return NULL;
}

NAPI_MODULE_INIT() {
  napi_property_descriptor exportsProperties[] = {
    DECLARE_NAPI_PROPERTY("cJsString", cJsString),
    DECLARE_NAPI_PROPERTY("cppJsString", cppJsString),
    DECLARE_NAPI_PROPERTY("getJsString", getJsString),
  };
  NAPI_CALL(env, napi_define_properties(env, exports, sizeof(exportsProperties) / sizeof(*exportsProperties), exportsProperties));
  return exports;
}
