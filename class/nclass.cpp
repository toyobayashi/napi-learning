#include "./nclass.h"
#include <stdio.h>

Person::Person(char* n, int a): name(n), age(a), env_(nullptr), wrapper_(nullptr) {}
Person::~Person() { napi_delete_reference(env_, wrapper_); delete name; }

napi_ref Person::constructorRef;

napi_value Person::say(napi_env env, napi_callback_info info) {
  napi_value _this;
  NAPI_CALL(env,
      napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr));

  Person* p;
  NAPI_CALL(env, napi_unwrap(env, _this, reinterpret_cast<void**>(&p)));
  printf("name: %s\n", p->name);
  printf("age: %d\n", p->age);
  return nullptr;
}

void Person::init(napi_env env, napi_value exports) {
  napi_property_descriptor properties[] = {
    DECLARE_NAPI_PROPERTY("say", say)
  };
  napi_value jsClassPerson;
  NAPI_CALL_RETURN_VOID(env, napi_define_class(
    env, "Person", -1, constructor, nullptr, 1, properties, &jsClassPerson));

  NAPI_CALL_RETURN_VOID(env, napi_create_reference(env, jsClassPerson, 1, &constructorRef));

  NAPI_CALL_RETURN_VOID(env, napi_set_named_property(env, exports, "Person", jsClassPerson));
}

napi_value Person::constructor(napi_env env, napi_callback_info info) {
  napi_value newTarget;
  NAPI_CALL(env, napi_get_new_target(env, info, &newTarget));
  bool isConstructor = (newTarget != nullptr);

  size_t argc = 2;
  napi_value args[2];
  napi_value _this;
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, &_this, nullptr));

  if (isConstructor) {
    char* name = new char[20];
    int age = 22;

    napi_valuetype valuetype0, valuetype1;
    NAPI_CALL(env, napi_typeof(env, args[0], &valuetype0));
    NAPI_CALL(env, napi_typeof(env, args[1], &valuetype1));

    if (valuetype0 == napi_string && valuetype1 == napi_number) {
      NAPI_CALL(env, napi_get_value_string_utf8(env, args[0], name, 20, nullptr));
      NAPI_CALL(env, napi_get_value_int32(env, args[1], &age));
    }

    Person* p = new Person(name, age);

    p->env_ = env;
    NAPI_CALL(env, napi_wrap(env,
                             _this,
                             p,
                             destructor,
                             nullptr,
                             &p->wrapper_));

    return _this;
  }

  argc = 2;
  napi_value argv[2] = { args[0], args[1] };

  napi_value cons;
  NAPI_CALL(env, napi_get_reference_value(env, constructorRef, &cons));

  napi_value instance;
  NAPI_CALL(env, napi_new_instance(env, cons, argc, argv, &instance));

  return instance;
}

void Person::destructor(napi_env env, void* nativeObject, void* finalizeHint) {
  Person* obj = static_cast<Person*>(nativeObject);
  delete obj;
}

