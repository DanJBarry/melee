with open("extern/aurora/include/dolphin/types.h", "r") as f:
    content = f.read()

import re
old_block = """#if defined(TARGET_PC)
#include <stdbool.h>
typedef int BOOL;
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#endif"""

new_block = """#if defined(TARGET_PC)
#include <stdbool.h>
#endif
typedef int BOOL;
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif"""

content = content.replace(old_block, new_block)

with open("extern/aurora/include/dolphin/types.h", "w") as f:
    f.write(content)
