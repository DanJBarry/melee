with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

more_typedefs = """
  typedef struct S8Vec3 {
    s8 x, y, z;
  } S8Vec3, *S8Vec3Ptr;
"""
content = content.replace("  typedef struct IntVec2 {", more_typedefs + "\n  typedef struct IntVec2 {")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
