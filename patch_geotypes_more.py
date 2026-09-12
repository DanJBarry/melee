with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

more_typedefs = """
  typedef struct S32Vec2 {
    s32 x, y;
  } S32Vec2, *S32Vec2Ptr;

  typedef struct S32Vec3 {
    s32 x, y, z;
  } S32Vec3, *S32Vec3Ptr;

  typedef struct U8Vec4 {
    u8 x, y, z, w;
  } U8Vec4, *U8Vec4Ptr;
"""
content = content.replace("  typedef struct {", more_typedefs + "\n  typedef struct {")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
