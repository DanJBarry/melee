with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

more_typedefs = """
  typedef struct IntVec2 {
    int x, y;
  } IntVec2, *IntVec2Ptr;
"""
content = content.replace("  typedef struct {", more_typedefs + "\n  typedef struct {")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
