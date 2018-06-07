#pragma once
#include <node_api.h>
#include "../common.h"

class Person {
public:
  static napi_value say(napi_env env, napi_callback_info info);
  static void init(napi_env env, napi_value exports);
  static void destructor(napi_env env, void* nativeObject, void* finalizeHint);
private:
  explicit Person(char* name, int age);
  ~Person();
  char* name;
  short age;
  napi_env env_;
  napi_ref wrapper_;
  static napi_ref constructorRef;
  static napi_value constructor(napi_env env, napi_callback_info info);
};
