#ifndef MELEE_PLATFORM_LOOP_H
#define MELEE_PLATFORM_LOOP_H

#include <aurora/event.h>

using AuroraUpdateFunction = const AuroraEvent* (*)();
using AuroraBeginFrameFunction = bool (*)();
using AuroraEndFrameFunction = void (*)();
using AuroraShutdownFunction = void (*)();

class AuroraShutdownGuard {
 public:
    explicit AuroraShutdownGuard(AuroraShutdownFunction shutdown)
            : shutdown_(shutdown) {}

    ~AuroraShutdownGuard() { shutdown_(); }

 private:
    AuroraShutdownFunction shutdown_;
};

int run_aurora_frame_loop(AuroraUpdateFunction update,
                          AuroraBeginFrameFunction beginFrame,
                          AuroraEndFrameFunction endFrame);

#endif
