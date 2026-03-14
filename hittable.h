#ifndef HITTABLE_H
#define HITTABLE_H

#include <optional>
#include "ray.h"
#include "hitrecord.h"

struct Hittable
{
    virtual std::optional<HitRecord> hit(const Ray& ray) const = 0;

    virtual ~Hittable() = default;
};

#endif