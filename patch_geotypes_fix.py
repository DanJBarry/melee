with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

# I will just write it fresh
new_content = """#ifndef _DOLPHIN_GEOTYPES
#define _DOLPHIN_GEOTYPES

#include <dolphin/types.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct Vec4 {
    f32 x, y, z, w;
  } Vec4, *Vec4Ptr;

  typedef struct Vec2 {
    f32 x, y;
  } Vec2, *Vec2Ptr;

  typedef struct Vec {
    f32 x, y, z;
  } Vec, *VecPtr, Point3d, *Point3dPtr, Vec3;

  typedef struct S32Vec2 {
    s32 x, y;
  } S32Vec2, *S32Vec2Ptr;

  typedef struct S32Vec3 {
    s32 x, y, z;
  } S32Vec3, *S32Vec3Ptr;

  typedef struct U8Vec4 {
    u8 x, y, z, w;
  } U8Vec4, *U8Vec4Ptr;

  typedef struct {
    s16 x;
    s16 y;
    s16 z;
  } S16Vec, *S16VecPtr;

  typedef struct {
    f32 x, y, z, w;
  } Quaternion, *QuaternionPtr, Qtrn, *QtrnPtr;

  typedef f32 Mtx[3][4];

  typedef f32 (*MtxPtr)[4];

  typedef f32 ROMtx[4][3];

  typedef f32 (*ROMtxPtr)[3];

  typedef f32 Mtx44[4][4];

  typedef f32 (*Mtx44Ptr)[4];

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_GEOTYPES
"""

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(new_content)
