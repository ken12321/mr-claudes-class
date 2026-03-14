#ifndef HITRECORD_H
#define HITRECORD_H

#include "vec.h"

struct HitRecord
{
    Vec3d point;
    Vec3d normal;
    double t;

    HitRecord(Vec3d point, Vec3d normal, double t) : point(point), normal(normal), t(t) {} 
};

#endif