with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "r") as f:
    content = f.read()

content = content.replace("} Vec, *VecPtr, Point3d, *Point3dPtr;", "} Vec, *VecPtr, Point3d, *Point3dPtr, Vec3;")

with open("extern/aurora/include/dolphin/mtx/GeoTypes.h", "w") as f:
    f.write(content)
