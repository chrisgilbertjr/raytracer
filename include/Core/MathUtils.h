
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <cmath>
#include "Core.h"

#ifdef SINGLE_PRECISION
    #define Abs  fabs
    #define Sqrt sqrtf
    #define Pow powf
#else
    #define Abs abs
    #define Sqrt sqrt
    #define Pow pow
#endif

/// vector/point in 3D space
struct Vector
{
    /// x, y, z 3D coords, and w (homogenous coord)
    real x, y, z, w;

    /// constructor
    Vector();

    /// constructor
    Vector (const Vector& vector);

    /// constructor
    explicit Vector (real val);

    /// constructor
    Vector(real x, real y, real z);

    /// constructor
    Vector(real x, real y, real z, real w);

    /// destructor
    ~Vector();

    /// set the vector with 3 floating point values
    void Set(real x, real y, real z);

    /// assignment operator
    Vector& operator=(const Vector& vector);

    /// equality operator
    bool operator==(const Vector& vector) const;

    /// inequality operator
    bool operator!=(const Vector& vector) const;

    /// multiply this vector with a scalar
    Vector operator*(const real scalar) const;

    /// add this vector with another vector
    Vector operator+(const Vector& vector) const;

    /// sub this vector with another vector
    Vector operator-(const Vector& vector) const;

    /// negate this vector and return a copy of it
    Vector operator-() const;

    /// cross product of this another vector
    Vector Cross(const Vector& vector) const;

    /// normalize this vector to be unit length
    void Normalize(const real epsilon = EPSILON);
    
    /// dot product of this vector another vector
    real Dot(const Vector& vector) const;

    /// return the length of this vector
    real Length() const;

    /// return the length squared of this vector
    real LengthSquared() const;
};

/// a ray in 3D space
struct Ray
{
    /// o - origin of the ray
    /// d - direction vector of the ray
    Vector o, d;

    /// constructor
    Ray();

    /// constructor
    Ray(const Ray& ray);

    /// constructor
    Ray(const Vector& origin, const Vector& direction);

    /// destructor
    ~Ray();

    /// assignment operator
    Vector& operator=(const Ray& ray);

    /// equality operator
    bool operator==(const Ray& ray);

    /// inequality operator
    bool operator!=(const Ray& ray);
};

/// check if two float values are equal within epsilon
bool Equal(real a, real b, real epsilon = EPSILON);

/// check if two vectors are equal within epsilon
bool Equal(const Vector& a, const Vector& b, real epsilon = EPSILON);

/// add two vectors together
Vector Add(const Vector& a, const Vector& b);

/// subtract vector a from vector b
Vector Sub(const Vector& a, const Vector& b);

/// multiply a vector and a floating point scalar
Vector Mult(const Vector& a, const real b);

/// multiply a floating point scalar and a vector
Vector Mult(const real a, const Vector& b);

/// normalize a vector and return a copy of the vector
Vector Normalize(const Vector& vector, const real epsilon = EPSILON);

/// cross product of two vectors
Vector Cross(const Vector& a, const Vector& b);

/// dot product of two vectors
real Dot(const Vector& a, const Vector& b);

/// get the length of a vector
real Length(const Vector& a);

/// get the squared length of a vector
real LengthSquared(const Vector& a);

#endif /// MATH_UTILS_H