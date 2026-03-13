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
        float a = dot(ray.getDirection(), ray.getDirection());
        float b = 2 * dot(ray.getDirection(), ray.getOrigin() - center) - (radius*radius);
        float c = dot(ray.getOrigin() - center, ray.getOrigin() - center) - (radius*radius);

        float discriminant = (b*b) - 4*(a*c);
        if (discriminant < 0)
        {
            return std::nullopt;
        }

        float t = (-b - std::sqrt(discriminant)) / (a*a);
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