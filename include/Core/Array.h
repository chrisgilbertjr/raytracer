
#ifndef ARRAY_H
#define ARRAY_H

/// templated dynamic array
template <typename T>
class Array
{
private:
    T* m_array;      /// array on the heap
    unsigned m_size; /// size of the array
    unsigned m_max;  /// max size of the arary

public:
    /// constructor. max is set to 8
    Array();

    /// copy constructor, raises an assert
    Array(const Array<T>& data);

    /// constructor, set a max
    Array(unsigned int max);

    /// destructor
    ~Array();

    /// assignment operator, raises an assert
    void operator=(const Array<T>& data);

    /// index operator
    T operator[](unsigned index) const;

    /// push object to the back of the array
    void Push(const T& object);

    /// pop an object from the back of the list
    T Pop();

    /// remove a specific object from the list
    void Remove(const T& object);

    /// remove an object at a specific index
    T Remove(unsigned index);

    /// check if an object is inside of an array
    bool Contains(const T& object);
};

#include "Array.inl"

#endif