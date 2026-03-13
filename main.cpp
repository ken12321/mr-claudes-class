#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "hittable.h"

int main()
{
    Sphere sphere(Vec3d(3,3,3), 1.5);

    Ray ray(Vec3d(0,0,0), Vec3d(-1,-1,-1));

    auto result = sphere.hit(ray);
    if (result)
    {
        std::cout << "A hit\n";
    }
    else
    {
        std::cout << "A miss\n";
    }

    return 0;
}
