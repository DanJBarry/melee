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

# Remove it from the end
content = content.replace(enum_def, "")

# Insert it before the #ifdef __cplusplus at the end
# I'll just find the last #ifdef __cplusplus
idx = content.rfind("#ifdef __cplusplus")
content = content[:idx] + enum_def + "\\n\\n" + content[idx:]

with open("extern/aurora/include/dolphin/gx/GXEnum.h", "w") as f:
    f.write(content)
