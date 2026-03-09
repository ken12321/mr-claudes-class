#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>

struct Vec3 {
    double x, y, z;

    Vec3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other_vec) const
    {
        return Vec3(x + other_vec.x, y + other_vec.y, z + other_vec.z);
    }

    Vec3 operator-(const Vec3& other_vec) const
    {
        return Vec3(x - other_vec.x, y - other_vec.y, z - other_vec.z);
    }

    Vec3 operator*(const double scalar) const
    {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator-() const
    {
        return Vec3(-x , -y, -z);
    }

    double length() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    double dot(const Vec3& other_vec) const 
    {
        return ( (x * other_vec.x) + (y * other_vec.y) + (z * other_vec.z) );
    }
};

#endif



/*

  Module 2: Memory Model & Structs                                                                                                                                                
                  
  The Big Idea                                                                                                                                                                    
                                                                                                                                                                                  
  In C# and Python, you don't think much about where your data lives — the runtime handles that. 
  In C++, you decide whether data lives on the stack or the heap, and that choice  
  has real consequences for performance, lifetime, and safety.                                                                                                                    
                                                                                                                                                                                  
  We'll start with structs and the stack, since your raytracer needs a core building block:
  a 3D vector (used for points, colors, directions — everything).

  C# Comparison

  In C#, struct vs class controls value-type vs reference-type semantics.
  In C++, struct and class are almost identical — the only difference is default access (public vs private). 
  By convention, struct is used for simple data aggregates, class for things with complex behavior. But the compiler doesn't care.

  The bigger difference: in C++, both structs and classes live on the stack by default.
  Nothing goes to the heap unless you explicitly ask for it.

  Your Assignment

  Create a Vec3 struct in a new file called vec3.h that:

  1. Has three double members: x, y, z
  2. Has a constructor (what should the default values be for a vector?)
  3. Overloads these operators: +, -, * (scalar multiply), and unary -
  4. Has a length() method and a dot() method
  5. Update main.cpp to #include "vec3.h" and use Vec3 for your color output instead of raw ints

  A few things to think about as you write it:
  - What does const mean on a method, and which methods here should be const?
  - Should operators return by value or by reference?
  - What's sizeof(Vec3)? Try printing it — does the answer surprise you?

*/