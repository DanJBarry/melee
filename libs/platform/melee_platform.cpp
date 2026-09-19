#include <aurora/aurora.h>
#include <aurora/event.h>

#include <cstdlib>

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

  aurora_initialize(argc, argv, &config);

  int frames = 0;
  while (frames < 3) {
    const AuroraEvent* event = aurora_update();
    while (event != nullptr && event->type != AURORA_NONE) {
      if (event->type == AURORA_EXIT) {
        aurora_shutdown();
        return 0;
      }
      ++event;
    }

    if (!aurora_begin_frame()) {
      continue;
    }

    aurora_end_frame();
    ++frames;
  }

  aurora_shutdown();
  return 0;
}
