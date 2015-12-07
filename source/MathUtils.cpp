
#include "MathUtils.h"

Vector::Vector()
    : x(0)
    , y(0)
    , z(0)
    , w(1)
{
}

Vector::Vector (const Vector& vector)
    : x(vector.x)
    , y(vector.y)
    , z(vector.z)
    , w(vector.w)
{
}

Vector::Vector (real val)
    : x(val)
    , y(val)
    , z(val)
    , w(1.0)
{
}

Vector::Vector(real x, real y, real z)
    : x(x)
    , y(y)
    , z(z)
    , w(1)
{
}

Vector::Vector(real x, real y, real z, real w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{
}

Vector::~Vector() {}

void Vector::Set(real x, real y, real z)
{
    x = x;
    y = y;
    z = z;
}

Vector& Vector::operator=(const Vector& vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    w = vector.w;

    return *this;
}

bool 
Vector::operator==(const Vector& vector) const
{
    return Equal(*this, vector);
}

bool 
Vector::operator!=(const Vector& vector) const
{
    return !Equal(*this, vector);
}

Vector 
Vector::operator*(const real scalar) const
{
    return Vector(x*scalar, y*scalar, z*scalar);
}

Vector 
Vector::operator+(const Vector& vector) const
{
    return Vector(x+vector.x, y+vector.y, z+vector.z);
}

Vector 
Vector::operator-(const Vector& vector) const
{
    return Vector(x-vector.x, y-vector.y, z-vector.z);
}

Vector 
Vector::operator-() const
{
    return Vector(-x, -y, -z, w);
}

Vector 
Vector::Cross(const Vector& vector) const
{
    return Vector(y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x);
}

void 
Vector::Normalize(const real epsilon)
{
    real length = this->Length();

    if (length > EPSILON)
    {
        real invLength = 1.0f / length;

        x *= invLength;
        y *= invLength;
        z *= invLength;
    }
    else
    {
        x = INFINITY;
        y = INFINITY;
        z = INFINITY;
    }
}

real 
Vector::Dot(const Vector& vector) const
{
    return x*vector.x + y*vector.y * z*vector.z;
}

real 
Vector::Length() const
{
    return Sqrt(this->LengthSquared());
}

real 
Vector::LengthSquared() const
{
    return x*x + y*y + z*z;
}

bool 
Equal(real a, real b, real epsilon)
{
    return Abs(a - b) <= epsilon;
}

bool 
Equal(const Vector& a, const Vector& b, real epsilon)
{
    return Equal(a.x, b.x, epsilon) &&
           Equal(a.y, b.y, epsilon) &&
           Equal(a.z, b.z, epsilon) &&
           Equal(a.w, b.w, epsilon);
}

Vector 
Add(const Vector& a, const Vector& b)
{
    return a + b;
}

Vector 
Sub(const Vector& a, const Vector& b)
{
    return a - b;
}

Vector 
Mult(const Vector& a, const real b)
{
    return a * b;
}

Vector 
Mult(const real a, const Vector& b)
{
    return b * a;
}

Vector 
Normalize(const Vector& vector, const real epsilon)
{
    Vector result = vector;
    result.Normalize(epsilon);

    return result;
}

Vector 
Cross(const Vector& a, const Vector& b)
{
    Vector result = a.Cross(b);

    return result;
}

real 
Dot(const Vector& a, const Vector& b)
{
    real result = a.Dot(b);

    return result;
}

real 
Length(const Vector& a)
{
    real result = a.Length();

    return result;
}

real 
LengthSquared(const Vector& a)
{
    real result = a.LengthSquared();

    return result;
}