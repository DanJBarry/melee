#include "melee_platform_adapter.h"

#include <borealis/io.hpp>
#include <borealis/log.hpp>

namespace {
struct MeleeHostState {
  bool initialized = false;
};
static MeleeHostState state;
constexpr borealis::Log kLog{"melee-platform"};
}

bool initialize_melee_host() {
  constexpr auto kGameDataPath = "orig/GALE01/sys/main.dol";
  if (borealis::io::check(kGameDataPath) != borealis::io::Status::Ok) {
    kLog.error("missing game data at {}", kGameDataPath);
    return false;
  }

  kLog.info("successfully initialized game data at {}", kGameDataPath);
  state.initialized = true;
  return true;
}

void update_melee_host() {
  if (!state.initialized) {
    return;
  }
}
