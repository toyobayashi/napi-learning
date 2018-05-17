#include "./nasync.h"

napi_async_work createAsyncWork (napi_env env, napi_value resourceName, napi_async_execute_callback execute, napi_async_complete_callback complete, void* data, napi_value resource) {
  napi_async_work asyncWork;
  NAPI_CALL(env, napi_create_async_work(env, resource, resourceName, execute, complete, data, &asyncWork));
  return asyncWork;
}

void queueAsyncWork (napi_env env, napi_async_work work) {
  NAPI_CALL_RETURN_VOID(env, napi_queue_async_work(env, work));
}

void deleteAsyncWork (napi_env env, napi_async_work work) {
  NAPI_CALL_RETURN_VOID(env, napi_delete_async_work(env, work));
}
