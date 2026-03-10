#include <iostream>
#include "vec.h"
#include "ray.h"

int main()
{
    Vec3 vector(5, 5, 2);
    Vec3 vectortwo(2, 2, 4);

    Ray ray(vector, vectortwo);

    const Vec3& origin = ray.getOrigin();
    const Vec3& direction = ray.getDirection();

    std::cout << "Origin: " << origin.x << ", " << origin.y << ", " << origin.z << "\n";
    std::cout << "Direction: " << direction.x << ", " << direction.y << ", " << direction.z << "\n";

    Vec3 rayatzero = ray.at(0);
    Vec3 rayatone = ray.at(1);
    Vec3 rayattwo = ray.at(2);
    std::cout << "Ray at 0: " << rayatzero.x << ", " << rayatzero.y << ", " << rayatzero.z << "\n";
    std::cout << "Ray at 1: " << rayatone.x << ", " << rayatone.y << ", " << rayatone.z << "\n";
    std::cout << "Ray at 2: " << rayattwo.x << ", " << rayattwo.y << ", " << rayattwo.z << "\n";

    std::cout << "Original Distance: " << vectortwo.x << ", " << vectortwo.y << ", " << vectortwo.z << "\n";
    std::cout << "Normalised Distance: " << direction.x << ", " << direction.y << ", " << direction.z << "\n";


    // int row = 256;
    // int col = 256;

    // std::cout << "P3\n" << col << " " << row << "\n" << "255\n"; 
    
    // for(int x = 0; x < row; x++)
    // {
    //     for(int i = 0; i < col; i ++)
    //     {
    //         Vec3 vect(i, x, 0);
    //         std::cout << vect.x << " " << vect.y << " " << vect.z << "\n";
    //     }
    // }
    
    return 0;
}

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
  In C++, struct and class are almost identical — the only difference is default access (public vs
  private). By convention, struct is used for simple data aggregates, class for things with complex behavior. But the compiler doesn't care.

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