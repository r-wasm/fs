#include "uv.h"
#include "internal.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>

int uv__platform_loop_init(uv_loop_t* loop) {
  return 0;
}

void uv__platform_loop_delete(uv_loop_t* loop) {
}

int uv__io_fork(uv_loop_t* loop) {
  uv__platform_loop_delete(loop);
  return uv__platform_loop_init(loop);
}

void uv__io_poll(uv_loop_t* loop, int timeout) {
  fprintf(stderr, "io_poll is not available under Emscripten\n");
  abort();
}
