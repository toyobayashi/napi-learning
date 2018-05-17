#include "./npromise.h"

promise_struct jsPromise (napi_env env) {
  promise_struct p;
  napi_create_promise(env, &p.deferred, &p.promise);
  return p;
}

void resolvePromise (napi_env env, promise_struct p, napi_value resolution) {
  NAPI_CALL_RETURN_VOID(env, napi_resolve_deferred(env, p.deferred, resolution));
}

void rejectPromise (napi_env env, promise_struct p, napi_value rejection) {
  NAPI_CALL_RETURN_VOID(env, napi_reject_deferred(env, p.deferred, rejection));
}
