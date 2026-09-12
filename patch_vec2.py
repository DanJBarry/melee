with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

# Add Vec2
vec2_typedef = """
  typedef struct Vec2 {
    f32 x, y;
  } Vec2, *Vec2Ptr;
"""
content = content.replace("  typedef struct Vec {", vec2_typedef + "\n  typedef struct Vec {")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
