
#ifndef ARRAY_H
#define ARRAY_H

/// @defgroup Array Array
/// @{

/// templated dynamic array
template <typename T>
class Array
{
private:
    T* m_array;      /// array on the heap
    unsigned m_size; /// size of the array
    unsigned m_max;  /// max size of the array

public:
    /// constructor. max is set to 8
    Array();

    /// copy constructor
    Array(const Array<T>& data);

    /// constructor, set a max
    Array(const unsigned max);

    /// destructor
    ~Array();

    /// assignment operator, uses copy-and-swap idiom
    Array<T>& operator=(Array<T> data);

    /// index operator
    T& operator[](unsigned index) const;

    /// resize the array. 
    /// data is retained if the array is larger or the same size.
    /// data can be lost if the array is smaller than before
    void Resize(const unsigned size);

    /// push object to the back of the array
    void Push(const T& object);

    /// pop an object from the back of the list
    T Pop();

    /// remove a specific object from the list
    /// operator== must be implemented
    void Remove(const T& object);

    /// remove an object at a specific index
    /// operator== must be implemented
    T Remove(const unsigned index);

    /// check if an object is inside of an array
    /// operator== must be implemented
    bool Contains(const T& object);

    /// gets the current size of the array
    inline unsigned GetSize() const { return m_size; }
};

/// random shuffle all array elements
template <typename T>
void ShuffleArray(Array<T>& array);

/// random shuffle array elements in range [start, end]
template <typename T>
void ShuffleArray(Array<T>& array, const unsigned start, const unsigned end);

/// inline implementation
#include "Array.inl"

/// @}

#endif