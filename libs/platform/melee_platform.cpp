#include <aurora/aurora.h>
#include <aurora/event.h>
#include <borealis/app_info.hpp>

#include "melee_platform_loop.h"

int main(int argc, char** argv) {
  const AuroraConfig config = {
      .appName = "melee-platform",
      .userPath = ".",
      .cachePath = ".",
      .resourcesPath = ".",
      .desiredBackend = BACKEND_NULL,
      .msaa = 1,
      .maxTextureAnisotropy = 1,
      .vsync = false,
      .startFullscreen = false,
      .allowJoystickBackgroundEvents = false,
      .pauseOnFocusLost = false,
      .allowTextureDumps = false,
      .allowCpuAdapter = false,
      .windowPosX = 0,
      .windowPosY = 0,
      .windowWidth = 1280,
      .windowHeight = 720,
      .iconRGBA8 = nullptr,
      .iconWidth = 0,
      .iconHeight = 0,
      .logCallback = nullptr,
      .logLevel = LOG_INFO,
      .imGuiInitCallback = nullptr,
      .mem1Size = 0,
      .mem2Size = 0,
  };

  constexpr borealis::AppInfo AppInfo{
    .orgName = "Dan Barry",
    .appName = "melee-platform",
    .githubOwner = "DanJBarry",
    .githubRepo = "melee",
  };

  aurora_initialize(argc, argv, &config);
  AuroraShutdownGuard shutdownGuard(aurora_shutdown);

  run_aurora_frame_loop(aurora_update, aurora_begin_frame, aurora_end_frame);

  return 0;
}
