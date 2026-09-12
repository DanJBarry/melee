with open("extern/aurora/include/dolphin/os.h", "r") as f:
    content = f.read()

import re

old_block = """extern uintptr_t OSBaseAddress;

#define OS_BASE_CACHED   (OSBaseAddress)
#define OS_BASE_UNCACHED (OSBaseAddress)"""

new_block = """#ifdef TARGET_PC
extern uintptr_t OSBaseAddress;
#define OS_BASE_CACHED   (OSBaseAddress)
#define OS_BASE_UNCACHED (OSBaseAddress)
#else
#define OS_BASE_CACHED   0x80000000
#define OS_BASE_UNCACHED 0xC0000000
#endif"""

content = content.replace(old_block, new_block)

with open("extern/aurora/include/dolphin/os.h", "w") as f:
    f.write(content)
