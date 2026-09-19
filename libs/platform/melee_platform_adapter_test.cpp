#include "melee_platform_adapter.h"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace {
bool expect(bool condition) {
  return condition;
}

void setup_test_env(bool create_file) {
  std::filesystem::path dir = "orig/GALE01/sys";
  std::filesystem::create_directories(dir);
  std::filesystem::path file = dir / "main.dol";
  
  if (create_file) {
    std::ofstream ofs(file);
    ofs << "dummy";
  } else {
    std::filesystem::remove(file);
  }
}
}  // namespace

int main() {
  // Test missing file
  setup_test_env(false);
  if (!expect(initialize_melee_host() == false)) {
    std::cerr << "Expected initialize_melee_host to return false when main.dol is missing" << '\n';
    return 1;
  }

  // Test existing file
  setup_test_env(true);
  if (!expect(initialize_melee_host() == true)) {
    std::cerr << "Expected initialize_melee_host to return true when main.dol exists" << '\n';
    return 1;
  }

  return 0;
}
