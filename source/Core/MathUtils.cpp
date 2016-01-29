
#include "Core\MathUtils.h"

real shadowEpsilon = 1e-5f;

/// Vector --------------------------------------------------------------------

Vector::Vector()
    : x(0)
    , y(0)
    , z(0)
    , w(1)
{}


Vector::Vector (const Vector& vector)
    : x(vector.x)
    , y(vector.y)
    , z(vector.z)
    , w(vector.w)
{}


Vector::Vector (real val)
    : x(val)
    , y(val)
    , z(val)
    , w(1.0)
{}


Vector::Vector(real x, real y, real z)
    : x(x)
    , y(y)
    , z(z)
    , w(1)
{}


Vector::Vector(real x, real y, real z, real w)
    : x(x)
    , y(y)
    , z(z)
    , w(w)
{}


Vector::~Vector() {}


void Vector::Set(real x, real y, real z)
{
    x = x;
    y = y;
    z = z;
}


Vector& Vector::operator=(Vector vector)
{
    Swap<real>(x, vector.x);
    Swap<real>(y, vector.y);
    Swap<real>(z, vector.z);
    Swap<real>(w, vector.w);
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
    return x*vector.x + y*vector.y + z*vector.z;
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

/// ---------------------------------------------------------------------------

/// --------------------------------------------------------------------------- Matrix

Matrix::Matrix()
{
}

Matrix::Matrix(real m00, real m01, real m02, real m03,
               real m10, real m11, real m12, real m13,
               real m20, real m21, real m22, real m23,
               real m30, real m31, real m32, real m33)
{
    m[ 0] = m00;  m[ 1] = m01;  m[ 2] = m02;  m[ 3] = m03;
    m[ 4] = m10;  m[ 5] = m11;  m[ 6] = m12;  m[ 7] = m13;
    m[ 8] = m20;  m[ 9] = m21;  m[10] = m22;  m[11] = m23;
    m[12] = m30;  m[13] = m31;  m[14] = m32;  m[15] = m33;
}


Matrix::Matrix(const Matrix& M)
{
    m[ 0] = M.m[ 0];  m[ 1] = M.m[ 1];  m[ 2] = M.m[ 2];  m[ 3] = M.m[ 3];
    m[ 4] = M.m[ 5];  m[ 5] = M.m[ 5];  m[ 6] = M.m[ 6];  m[ 7] = M.m[ 7];
    m[ 8] = M.m[ 8];  m[ 9] = M.m[ 9];  m[10] = M.m[10];  m[11] = M.m[11];
    m[12] = M.m[12];  m[13] = M.m[13];  m[14] = M.m[14];  m[15] = M.m[15];
}

Matrix::~Matrix() {}

Matrix& 
Matrix::operator=(Matrix matrix)
{
    for (int i = 0; i < 16; ++i)
    {
        Swap<real>(m[i], matrix.m[i]);
    }

    return *this;
}

Matrix& 
Matrix::operator*=(const Matrix& matrix)
{
    return *this;
}

Matrix& 
Matrix::operator+=(const Matrix& matrix)
{
    return *this;
}

Matrix& 
Matrix::operator-=(const Matrix& matrix)
{
    return *this;
}

Matrix 
Matrix::operator*=(real scalar) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator/=(real scalar) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator*(const Matrix& matrix) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator+(const Matrix& matrix) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator-(const Matrix& matrix) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator*(real scalar) const
{
    Matrix result;
    return result;
}

Matrix 
Matrix::operator/(real scalar) const
{
    Matrix result;
    return result;
}

Vector 
Matrix::operator*(const Vector& point) const
{
    Vector result;
    return result;
}

Matrix 
Matrix::operator-() const
{
    Matrix result;
    for (int i = 0; i < 16; ++i)
    {
        result.m[i] = -m[i];
    }

    return result;
}

Vector 
Matrix::TransformPoint(const Vector& point) const
{
    return Vector( m[0]*point.x + m[1]*point.y + m[ 2]*point.z + m[ 3],
                   m[4]*point.x + m[5]*point.y + m[ 6]*point.z + m[ 7],
                   m[8]*point.x + m[9]*point.y + m[10]*point.z + m[11]);
}

Vector 
Matrix::TransformVector(const Vector& vector) const
{
    return Vector( m[0]*vector.x + m[1]*vector.y + m[ 2]*vector.z,
                   m[4]*vector.x + m[5]*vector.y + m[ 6]*vector.z,
                   m[8]*vector.x + m[9]*vector.y + m[10]*vector.z);
}

Vector 
Matrix::InverseTransformPoint(const Vector& point) const
{
    Matrix inverse = this->Inverse();
    return inverse.TransformPoint(point);
}

Vector 
Matrix::InverseTransformVector(const Vector& vector) const
{
    Matrix inverse = this->Inverse();
    return inverse.TransformVector(vector);
}

real 
Matrix::Determinant() const
{
    /// 2x2 cofactor matrices calculated only once
    float s0 = m[ 0] * m[ 5] - m[ 1] * m[ 4];
    float s1 = m[ 0] * m[ 6] - m[ 2] * m[ 4];
    float s2 = m[ 0] * m[ 7] - m[ 3] * m[ 4];
    float s3 = m[ 1] * m[ 6] - m[ 2] * m[ 5];
    float s4 = m[ 1] * m[ 7] - m[ 3] * m[ 5];
    float s5 = m[ 2] * m[ 7] - m[ 3] * m[ 6];
    float c0 = m[ 8] * m[13] - m[ 9] * m[12];
    float c1 = m[ 8] * m[14] - m[10] * m[12];
    float c2 = m[ 8] * m[15] - m[11] * m[12];
    float c3 = m[ 9] * m[14] - m[10] * m[13];
    float c4 = m[ 9] * m[15] - m[11] * m[13];
    float c5 = m[10] * m[15] - m[11] * m[14];

    /// compute the determinant
    return s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;
}

Matrix 
Matrix::Transpose() const
{
    return Matrix( m[ 0],  m[ 4],  m[ 8],  m[12], 
                   m[ 1],  m[ 5],  m[ 9],  m[13],
                   m[ 2],  m[ 6],  m[10],  m[14],
                   m[ 3],  m[ 7],  m[11],  m[15]);
}

Matrix 
Matrix::Inverse() const
{
    // 2x2 cofactor matrices calculated only once 
    float s0 = m[ 0] * m[ 5] - m[ 1] * m[ 4];
    float s1 = m[ 0] * m[ 6] - m[ 2] * m[ 4];
    float s2 = m[ 0] * m[ 7] - m[ 3] * m[ 4];
    float s3 = m[ 1] * m[ 6] - m[ 2] * m[ 5];
    float s4 = m[ 1] * m[ 7] - m[ 3] * m[ 5];
    float s5 = m[ 2] * m[ 7] - m[ 3] * m[ 6];
    float c0 = m[ 8] * m[13] - m[ 9] * m[12];
    float c1 = m[ 8] * m[14] - m[10] * m[12];
    float c2 = m[ 8] * m[15] - m[11] * m[12];
    float c3 = m[ 9] * m[14] - m[10] * m[13];
    float c4 = m[ 9] * m[15] - m[11] * m[13];
    float c5 = m[10] * m[15] - m[11] * m[14];

    /// compute the determinant
    float determinant = s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;

    /// make sure it isnt zero
    if (Equal(determinant, 0.0f))
    {
        return Matrix::Zero();
    }

    /// * > /
    float invDeterminant = 1.0f/determinant;

    /// compute the inverse
    return Matrix(
        (+ m[ 5] * c5 - m[ 6] * c4 + m[ 7] * c3) * invDeterminant,
        (- m[ 1] * c5 - m[ 2] * c4 + m[ 3] * c3) * invDeterminant,
        (+ m[13] * s5 - m[14] * s4 + m[15] * s3) * invDeterminant,
        (- m[ 9] * s5 - m[10] * s4 + m[11] * s3) * invDeterminant,

        (- m[ 4] * c5 - m[ 6] * c2 + m[ 7] * c1) * invDeterminant,
        (+ m[ 0] * c5 - m[ 2] * c2 + m[ 3] * c1) * invDeterminant,
        (- m[12] * s5 - m[14] * s2 + m[15] * s1) * invDeterminant,
        (+ m[ 8] * s5 - m[10] * s2 + m[11] * s1) * invDeterminant,

        (+ m[ 4] * c4 - m[ 5] * c2 + m[ 7] * c0) * invDeterminant,
        (- m[ 0] * c4 - m[ 1] * c2 + m[ 3] * c0) * invDeterminant,
        (+ m[12] * s4 - m[13] * s2 + m[15] * s0) * invDeterminant,
        (- m[ 8] * s4 - m[ 9] * s2 + m[11] * s0) * invDeterminant,

        (- m[ 4] * c3 - m[ 5] * c1 + m[ 6] * c0) * invDeterminant,
        (+ m[ 0] * c3 - m[ 1] * c1 + m[ 2] * c0) * invDeterminant,
        (- m[12] * s3 - m[13] * s1 + m[14] * s0) * invDeterminant,
        (+ m[ 8] * s3 - m[ 9] * s1 + m[10] * s0) * invDeterminant);
}

void 
Matrix::Invert()
{
    *this = this->Inverse();
}

Matrix 
Matrix::Zero()
{
    return Matrix(0.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 0.0f, 0.0f);
}

Matrix 
Matrix::Identity()
{
    return Matrix(1.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, 1.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 1.0f, 0.0f,
                  0.0f, 0.0f, 0.0f, 1.0f);
}

/// ---------------------------------------------------------------------------

/// Ray -----------------------------------------------------------------------

Ray::Ray()
    : origin(0.f)
    , direction(0.f)
{}


Ray::Ray(const Ray& ray)
    : origin(ray.origin)
    , direction(ray.direction)
{}


Ray::Ray(const Vector& origin, const Vector& direction)
    : origin(origin)
    , direction(direction)
{}


Ray::~Ray() {}


Ray& 
Ray::operator=(Ray ray)
{
    Swap<Vector>(origin, ray.origin);
    Swap<Vector>(direction, ray.direction);

    return *this;
}


bool 
Ray::operator==(const Ray& ray)
{
    return (Equal(origin, ray.origin) && Equal(direction, ray.direction));
}


bool 
Ray::operator!=(const Ray& ray)
{
    return (!Equal(origin, ray.origin) || !Equal(direction, ray.direction));
}

/// ---------------------------------------------------------------------------


/// MathUtils -----------------------------------------------------------------

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
Normalize(Vector vector, const real epsilon)
{
    vector.Normalize(epsilon);

    return vector;
}


Vector 
Cross(const Vector& a, const Vector& b)
{
    return a.Cross(b);
}


real 
Dot(const Vector& a, const Vector& b)
{
    return a.Dot(b);
}


real 
Length(const Vector& a)
{
    return a.Length();
}


real 
LengthSquared(const Vector& a)
{
    return a.LengthSquared();
}

real 
Clamp(real val, real min, real max)
{
    if (val < min)
    {
        val = min;
    }
    if (val > max)
    {
        val = max;
    }

    return val;
}

real 
Saturate(real val)
{
    return Clamp(val, 0.f, 1.f);
}

/// ---------------------------------------------------------------------------