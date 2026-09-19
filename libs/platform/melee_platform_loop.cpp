#include "melee_platform_loop.h"

int run_aurora_frame_loop(AuroraUpdateFunction update,
                          AuroraBeginFrameFunction beginFrame,
                          AuroraEndFrameFunction endFrame) {
  constexpr int kMaxFrameAttempts = 3;
  for (int frameAttempt = 0; frameAttempt < kMaxFrameAttempts; ++frameAttempt) {
    const AuroraEvent* event = update();
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

    if (!beginFrame()) {
      continue;
    }

    endFrame();
  }

  return 0;
}
