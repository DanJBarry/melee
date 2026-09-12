with open("extern/aurora/include/dolphin/pad.h", "r") as f:
    content = f.read()

missing_macros = """
#define PAD_STICK_UP (1 << 16)       // 0x10000
#define PAD_STICK_DOWN (1 << 17)     // 0x20000
#define PAD_STICK_LEFT (1 << 18)     // 0x40000
#define PAD_STICK_RIGHT (1 << 19)    // 0x80000
#define PAD_SUBSTICK_UP (1 << 20)    // 0x100000
#define PAD_SUBSTICK_DOWN (1 << 21)  // 0x200000
#define PAD_SUBSTICK_LEFT (1 << 22)  // 0x400000
#define PAD_SUBSTICK_RIGHT (1 << 23) // 0x800000
#define PAD_TRIGGER_LR (1 << 31)     // 0x80000000
#define PAD_CONFIRM (1ULL << 32)        // 0x100000000
#define PAD_CANCEL (1ULL << 33)         // 0x200000000
#define PAD_LR_START (1ULL << 34)       // 0x400000000
#define PAD_LRA_START (1ULL << 35)      // 0x800000000
#define PAD_ANY_UP (1ULL << 36)         // 0x1000000000
#define PAD_ANY_DOWN (1ULL << 37)       // 0x2000000000
#define PAD_ANY_LEFT (1ULL << 38)       // 0x4000000000
#define PAD_ANY_RIGHT (1ULL << 39)      // 0x8000000000
"""

content = content.replace("#define PAD_BUTTON_START 0x1000", "#define PAD_BUTTON_START 0x1000\\n" + missing_macros)

with open("extern/aurora/include/dolphin/pad.h", "w") as f:
    f.write(content)
