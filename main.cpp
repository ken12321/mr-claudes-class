#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "hittable.h"

std::optional<HitRecord> find_closest_hit(const Ray& ray, const std::vector<std::unique_ptr<Hittable>>& objects)
{
    std::optional<HitRecord> closest_hit;

    for (const std::unique_ptr<Hittable>& object : objects)
    {
        std::optional<HitRecord> hit_record = object->hit(ray);

        if (hit_record)
        {    
            if ( !(closest_hit) || hit_record->t < closest_hit->t )
            {
                closest_hit = hit_record;
            }
        }
    }
    return closest_hit;
};

int main()
{
    std::unique_ptr<Hittable> s1 = std::make_unique<Sphere>(Vec3d(-1,1,-2), 0.5);
    std::unique_ptr<Hittable> s2 = std::make_unique<Sphere>(Vec3d(5,0.5,-6), 1.5);
    std::unique_ptr<Hittable> s3 = std::make_unique<Sphere>(Vec3d(-1,-0.5,-5), 1.5);

    std::vector<std::unique_ptr<Hittable>> hittable_vector;
    hittable_vector.push_back(std::move(s1));
    hittable_vector.push_back(std::move(s2));
    hittable_vector.push_back(std::move(s3));

    int width = 800;
    int height = 400;

    std::string background_color = "255 255 255";

    Vec3d camera_origin(0, 0, 0);
    
    std::cout << "P3\n" << width << " " << height << "\n" << "255\n"; 


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            double u = (double)x / width;
            double v = (double)y / height;

            double world_x = -2 + u * 4;
            double world_y = 1 - v * 2;
            double world_z = -1;
            
            Vec3d direction(world_x, world_y, world_z);
            Ray ray(camera_origin, direction);
            std::optional<HitRecord> record = find_closest_hit(ray, hittable_vector);
            if (record)
            {
                Vec3d normal_vec = record->normal;
                normal_vec.normalise();
                double r = (normal_vec.x + 1) * 0.5 * 255;
                double g = (normal_vec.y + 1) * 0.5 * 255;
                double b = (normal_vec.z + 1) * 0.5 * 255;
                std::cout << (int)r << " " << (int)g << " " << (int)b << "\n";
            }
            else 
            {
                std::cout << background_color << "\n";
                //std::cout << y << " " << x << " 0" << "\n";
            }
        }
    }
    
    return 0;
}