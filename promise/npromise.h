#pragma once
#include <node_api.h>
#include "../common.h"

typedef struct {
  napi_deferred deferred;
  napi_value promise;
} promise_struct;

promise_struct jsPromise (napi_env env);

void resolvePromise (napi_env env, promise_struct p, napi_value resolution);

void rejectPromise (napi_env env, promise_struct p, napi_value rejection);

#define JS_PROMISE() jsPromise(env)

#define RESOLVE_PROMISE(promiseStruct, resolution) resolvePromise(env, promiseStruct, resolution)

#define REJECT_PROMISE(promiseStruct, rejection) rejectPromise(env, promiseStruct, rejection)
