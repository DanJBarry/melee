#ifndef MELEE_PLATFORM_LOOP_H
#define MELEE_PLATFORM_LOOP_H

#include <aurora/event.h>

using AuroraUpdateFunction = const AuroraEvent* (*)();
using AuroraBeginFrameFunction = bool (*)();
using AuroraEndFrameFunction = void (*)();
using AuroraShutdownFunction = void (*)();
using MeleeBootstrapFunction = bool (*)();
using MeleeTickFunction = void (*)();

class AuroraShutdownGuard {
 public:
    explicit AuroraShutdownGuard(AuroraShutdownFunction shutdown)
            : shutdown_(shutdown) {}

    ~AuroraShutdownGuard() { shutdown_(); }

 private:
    AuroraShutdownFunction shutdown_;
};

struct FrameLoopCallbacks {
    AuroraUpdateFunction update;
    AuroraBeginFrameFunction beginFrame;
    AuroraEndFrameFunction endFrame;
    MeleeBootstrapFunction bootstrap = nullptr;
    MeleeTickFunction tick = nullptr;
};

int run_aurora_frame_loop(const FrameLoopCallbacks& callbacks);

#endif
