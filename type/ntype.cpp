#include "./ntype.h"

napi_valuetype jsType (napi_env env, napi_value value) {
  napi_valuetype type;
  if (napi_ok != napi_typeof(env, value, &type)) return napi_undefined;
  return type;
}
