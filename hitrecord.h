#ifndef HITRECORD_H
#define HITRECORD_H

#include "vec.h"

struct HitRecord
{
    Vec3d point;
    Vec3d normal;
    double t;

    HitRecord(Vec3d _p, Vec3d _n, double _t) : point(_p), normal(_n), t(_t) {} 
};

#endif