#ifndef SPHERE_H
#define SPHERE_H

#include "vec.h"
#include "hittable.h"
#include <iostream>
#include <optional>
#include <cmath>

struct Sphere : public Hittable
{
    Vec3d center;
    double radius;

    Sphere(Vec3d c, double r) : center(c), radius(r) {}

    std::optional<HitRecord> hit(const Ray& ray) const override
    {
        Vec3d direction = ray.getDirection();
        Vec3d origin = ray.getOrigin();
        double a = dot(direction, direction);
        double b = 2 * dot(direction, origin - center);
        double c = dot(origin - center, origin - center) - (radius*radius);

        double discriminant = (b*b) - 4*(a*c);
        if (discriminant < 0)
        {
            return std::nullopt;
        }

        double t = (-b - std::sqrt(discriminant)) / (2*a);
        if (t > 0)
        {
            Vec3d point = ray.at(t);
            Vec3d normal = point - center;
            normal.normalise();

            return HitRecord(point, normal, t);
        }
        return std::nullopt;
    }
};

#endif