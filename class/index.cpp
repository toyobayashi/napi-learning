#include "./nclass.h"

NAPI_MODULE_INIT() {
  Person::init(env, exports);
  return exports;
}
