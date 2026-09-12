with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

vec4_typedef = """
  typedef struct Vec4 {
    f32 x, y, z, w;
  } Vec4, *Vec4Ptr;
"""
content = content.replace("  typedef struct Vec2 {", vec4_typedef + "\n  typedef struct Vec2 {")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
