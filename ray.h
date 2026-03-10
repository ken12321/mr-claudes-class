#ifndef RAY_H
#define RAY_H

#include "vec.h"

class Ray {
    private:
        Vec3 _origin, _direction;
    public:
        Ray(const Vec3& _o, const Vec3& _d) : _origin(_o), _direction(_d) 
        {
            _direction.normalise();
        }

        const Vec3& getOrigin() const
        {
            return _origin;
        }

        const Vec3& getDirection() const
        {
            return _direction;
        }

        Vec3 at (double t) const
        {
            return _origin + _direction * t;
        }
};

#endif

/*

⏺ Module 4: Classes & Destructors                                                                                                                                                 
                                                                                                                                                                                  
  You'll convert your Vec3 from a struct to a class, which introduces:                                                                                                            
                                                                                                                                                                                  
  - Access control — public vs private. Why would you want to hide data? (Hint: it's not just about security)                                                                     
  - Constructors in more depth — copy constructors, what the compiler generates for you automatically                                                                             
  - Destructors — the ~ClassName() method. In C#, you rarely write finalizers. In C++, destructors are deterministic and essential — they run the instant an object's lifetime    
  ends, not "whenever the GC gets around to it"
  - const correctness on constructors and member access

  Your Assignment (for next time)

  Build a Ray class in ray.h with:
  1. Private members: an origin (Vec3) and a direction (Vec3)
  2. Public accessor methods (getters)
  3. A method at(double t) that returns the point along the ray: origin + direction * t
  4. Think about: why might you make the members private instead of public like Vec3?

*/