
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <cmath>
#include "Core.h"

/// @ingroup Core
/// @{

#ifdef SINGLE_PRECISION
    #define Abs   fabs
    #define Sqrt  sqrtf
    #define Pow   powf
    #define Pi    3.1415926f
    #define InvPi 1.0f/3.1415926f
#else
    #define Abs   abs
    #define Sqrt  sqrt
    #define Pow   pow
    #define Pi    3.141592653589793
    #define InvPi 1.0/3.141592653589793
#endif

/// safe acos
real Acos(real val);

/// @}


/// @defgroup Vector Vector
/// @{

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
    Vector& operator=(Vector vector);

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

    /// x unit vector
    static Vector X();

    /// y unit vector
    static Vector Y();

    /// z unit vector
    static Vector Z();

};

/// @}


/// @defgroup Ray Ray
/// @{

/// a ray in 3D space
struct Ray
{
    Vector origin;    /// origin point of the ray
    Vector direction; /// direction of the ray

    /// constructor
    Ray();

    /// constructor
    Ray(const Ray& ray);

    /// constructor
    Ray(const Vector& origin, const Vector& direction);

    /// destructor
    ~Ray();

    /// assignment operator
    Ray& operator=(Ray ray);

    /// equality operator
    bool operator==(const Ray& ray);

    /// inequality operator
    bool operator!=(const Ray& ray);
};

/// struct for raycast results
struct Raycast
{
    Ray ray;
    real t;
    bool hit;
};

/// @}

/// @defgroup Matrix Matrix
/// @{

/// 4D matrix
class Matrix
{
public:
    /// 16 floats in row major order
    real m[16];

    /// constructor
    Matrix();

    /// constructor
    Matrix(real m00, real m01, real m02, real m03,
           real m10, real m11, real m12, real m13,
           real m20, real m21, real m22, real m23,
           real m30, real m31, real m32, real m33);

    /// copy constructor
    Matrix(const Matrix& matrix);

    /// destructor
    ~Matrix();

    /// copy assignment operator
    Matrix& operator=(Matrix matrix);

    /// multiply equal operator
    Matrix& operator*=(const Matrix& matrix);

    /// add equal operator
    Matrix& operator+=(const Matrix& matrix);

    /// subtract equal operator
    Matrix& operator-=(const Matrix& matrix);

    /// multiply equal operator
    Matrix operator*=(real scalar);

    /// division equal operator
    Matrix operator/=(real scalar);

    /// multiplication operator
    Matrix operator*(const Matrix& matrix) const;

    /// addition operator
    Matrix operator+(const Matrix& matrix) const;

    /// subtraction operator
    Matrix operator-(const Matrix& matrix) const;

    /// multiplication operator
    Matrix operator*(real scalar) const;

    /// division operator
    Matrix operator/(real scalar) const;

    /// transform point
    Vector operator*(const Vector& point) const;

    /// negatation operator
    Matrix operator-() const;

    /// transforms a point in 3d space
    Vector TransformPoint(const Vector& point) const;

    /// rotates a vector in 3d space
    Vector TransformVector(const Vector& vector) const;

    /// transforms a ray in 3d space
    Ray TransformRay(const Ray& ray) const;

    /// transforms a raycast in 3d space
    Ray TransformRaycast(const Ray& ray) const;

    /// inverse transform a point in 3d space
    Vector InverseTransformPoint(const Vector& point) const;

    /// inverse rotate a point in 3d space
    Vector InverseTransformVector(const Vector& vector) const;

    /// inverse transform a ray
    Ray InverseTransformRay(const Ray& ray) const;

    /// determinant of a matrix
    real Determinant() const;

    /// transpose this matrix and returns a copy
    Matrix Transpose() const;

    /// inverts the matrix and returns a copy
    Matrix Inverse() const;

    // invert this matrix
    void Invert();

    // sets the matrix position as a 3d coord system
    void SetPosition(const Vector& position);

    /// gets the position as a 3d coord system
    Vector GetPosition() const;

    /// the zero matrix
    static Matrix Zero();

    /// the identity matrix
    static Matrix Identity();

    /// a diagonal matrix
    static Matrix Diagonal(real val);

    /// axis-angle rotation matrix
    static Matrix Rotation(const Vector& axis, real angle);

    /// translation matrix
    static Matrix Translation(const Vector& translate);

    /// translation matrix
    static Matrix Translation(real x, real y, real z);

    /// scale matrix
    static Matrix Scale(real uniform);

    /// shear matrix
    static Matrix Shear(real x, real y, real z);

    /// transform matrix given a position, axis-angle, and scale
    static Matrix Transform(const Vector& translate, const Vector& axis, real angle, real scale = 1.f);
};

/// @}


/// @defgroup MathUtils MathUtils
/// @{

/// multiply operator
Matrix operator*(real scalar, const Matrix& matrix);

/// multiply operator
Vector operator*(const Vector& vector, const Matrix& matrix);

/// multiply operator
Vector operator*(real scalar, const Vector& vector);

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
Vector Normalize(Vector vector, const real epsilon = EPSILON);

/// cross product of two vectors
Vector Cross(const Vector& a, const Vector& b);

/// dot product of two vectors
real Dot(const Vector& a, const Vector& b);

/// get the length of a vector
real Length(const Vector& a);

/// get the squared length of a vector
real LengthSquared(const Vector& a);

/// clamp val between min and max
real Clamp(real val, real min, real max);

/// clamp val between [0, 1]
real Saturate(real val);

/// @}


#endif /// MATH_UTILS_H