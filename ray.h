#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "vec.h"

class Ray {
    private:
        Vec3d _origin, _direction;
    public:
        Ray(const Vec3d& origin, const Vec3d& direction) : _origin(origin), _direction(direction) 
        {
            _direction.normalise();
        }

        const Vec3d& getOrigin() const
        {
            return _origin;
        }

        const Vec3d& getDirection() const
        {
            return _direction;
        }

        Vec3d at (double t) const
        {
            return _origin + _direction * t;
        }
};

#endif