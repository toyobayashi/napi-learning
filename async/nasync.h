#pragma once
#include <node_api.h>
#include "../common.h"

napi_async_work createAsyncWork (
  napi_env env,
  napi_value resourceName,
  napi_async_execute_callback execute,
  napi_async_complete_callback complete,
  void* data,
  napi_value resource = nullptr
);

void queueAsyncWork (napi_env env, napi_async_work work);

void deleteAsyncWork (napi_env env, napi_async_work work);

#define CREATE_ASYNC_WORK(name, execute, complete, data) createAsyncWork(env, name, execute, complete, data)

#define QUEUE_ASYNC_WORK(work) queueAsyncWork(env, work)

#define DELETE_ASYNC_WORK(work) deleteAsyncWork(env, work)

#define ASYNC_EXECUTE(data) [](napi_env env, void* data)

#define ASYNC_COMPLETE(data) [](napi_env env, napi_status status, void* data)
