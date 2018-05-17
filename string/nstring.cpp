#include "./nstring.h"
#include "../type/ntype.h"

using namespace std;

napi_value jsString (napi_env env, const char* cstr) {
  napi_value jsstr;
  NAPI_CALL(env, napi_create_string_utf8(env, cstr, -1, &jsstr));
  return jsstr;
}

napi_value jsString (napi_env env, string cppstr) {
  napi_value jsstr;
  NAPI_CALL(env, napi_create_string_utf8(env, cppstr.c_str(), -1, &jsstr));
  return jsstr;
}

string cppString (napi_env env, napi_value jsstr, size_t size) {
  size = size + 1;

  NAPI_ASSERT(env, JS_TYPE(jsstr) == napi_string, "Wrong type of argument. Expects a string.");

  char *buffer = new char[size];
  NAPI_CALL(env, napi_get_value_string_utf8(env, jsstr, buffer, size, nullptr));
  string str = buffer;
  delete[] buffer;

  return str;
}

size_t cString (napi_env env, napi_value jsstr, char* result, size_t size) {
  size = size + 1;

  NAPI_ASSERT(env, JS_TYPE(jsstr) == napi_string, "Wrong type of argument. Expects a string.");

  size_t length;
  NAPI_CALL(env, napi_get_value_string_utf8(env, jsstr, result, size, &length));
  return length;
}
