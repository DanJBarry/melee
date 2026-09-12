with open("extern/aurora/include/dolphin/gx/GXEnum.h", "r") as f:
    content = f.read()

enum_def = """typedef enum _GXTevClampMode
{
    GX_TC_LINEAR,
    GX_TC_GE,
    GX_TC_EQ,
    GX_TC_LE,
    GX_MAX_TEVCLAMPMODE
} GXTevClampMode;"""

content = content.replace("typedef int GXTevClampMode;", enum_def)

with open("extern/aurora/include/dolphin/gx/GXEnum.h", "w") as f:
    f.write(content)
