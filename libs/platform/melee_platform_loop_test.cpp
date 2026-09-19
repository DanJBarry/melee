#include "melee_platform_loop.h"

#include <cassert>

namespace {
AuroraEvent normalEvents[] = {{AURORA_NONE}};
AuroraEvent exitEvents[] = {{AURORA_EXIT}, {AURORA_NONE}};
const AuroraEvent* events = normalEvents;
int updateCalls = 0;
int beginCalls = 0;
int endCalls = 0;
bool beginResult = true;
int shutdownCalls = 0;

const AuroraEvent* update() {
  ++updateCalls;
  return events;
}

bool beginFrame() {
  ++beginCalls;
  return beginResult;
}

void endFrame() {
  ++endCalls;
}

void shutdown() {
  ++shutdownCalls;
}

void reset() {
  events = normalEvents;
  updateCalls = 0;
  beginCalls = 0;
  endCalls = 0;
  beginResult = true;
  shutdownCalls = 0;
}

bool expect(bool condition) {
  return condition;
}
}  // namespace

int main() {
  reset();
  {
    AuroraShutdownGuard shutdownGuard(shutdown);
    run_aurora_frame_loop(update, beginFrame, endFrame);
  }
  if (!expect(updateCalls == 3) || !expect(beginCalls == 3) ||
      !expect(endCalls == 3) || !expect(shutdownCalls == 1)) {
    return 1;
  }

  reset();
  events = exitEvents;
  {
    AuroraShutdownGuard shutdownGuard(shutdown);
    run_aurora_frame_loop(update, beginFrame, endFrame);
  }
  if (!expect(updateCalls == 1) || !expect(beginCalls == 0) ||
      !expect(endCalls == 0) || !expect(shutdownCalls == 1)) {
    return 1;
  }

  reset();
  beginResult = false;
  run_aurora_frame_loop(update, beginFrame, endFrame);
  if (!expect(updateCalls == 3) || !expect(beginCalls == 3) ||
      !expect(endCalls == 0)) {
    return 1;
  }

  return 0;
}
