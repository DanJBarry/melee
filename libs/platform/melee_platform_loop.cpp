#include "melee_platform_loop.h"

int run_aurora_frame_loop(const FrameLoopCallbacks& callbacks) {
  constexpr int kMaxFrameAttempts = 3;
  if (callbacks.bootstrap != nullptr && !callbacks.bootstrap()) {
    return 1;
  }

  for (int frameAttempt = 0; frameAttempt < kMaxFrameAttempts; ++frameAttempt) {
    const AuroraEvent* event = callbacks.update();
    bool exiting = false;
    while (event != nullptr && event->type != AURORA_NONE) {
      if (event->type == AURORA_EXIT) {
        exiting = true;
        break;
      }
      ++event;
    }

    if (exiting) {
      break;
    }

    if (!callbacks.beginFrame()) {
      continue;
    }

    if (callbacks.tick != nullptr) {
      callbacks.tick();
    }
    callbacks.endFrame();
  }

  return 0;
}
