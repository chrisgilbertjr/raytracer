
#ifndef ARRAY_H
#define ARRAY_H

/// c style dynamic array container
/// uses just a standard array, and realloc's when it needs to grow
/// i had this lying around so i used this instead of creating a new templated dynamic array
class Array
{
private:
    void** m_data; /// array of object pointers
    int m_size;    /// number of elements in the array
    int m_max;     /// max number of elements in the array

public:
    /// constructor, default max is set to 8
    Array(); 

    /// constructor, causes an error, arrays shouldnt be copied.
    /// if you want to copy arrays, change this to do a
    /// deep copy and alloc a new pointer on the heap
    Array(const Array& array);

    /// constructor given a max number of elements
    Array(int max);

    /// destructor
    ~Array();

    /// assignment operator causes an error, array's shouldnt be copied.
    /// if you want to copy arrays, change this to do a
    /// deep copy and alloc a new pointer on the heap
    void operator=(const Array& array) const;

    /// index operator for easy access
    void* operator[](int index) const;

    /// push a new object to the back of the array
    void Push(void* obj);

    /// pop an object from the back of the array
    void* Pop();

    /// remove an object from the array
    void Remove(void* obj);

    /// remove an object at index from the array, returns the objects address
    void* Remove(int index);

    /// check if an array contains an object
    bool Contains(void* obj);
};

/// templated array wrapper for easier use
template <typename T>
class TArray
{
private:
    Array m_array;

public:
    /// constructor, max is set to 8
    TArray(); 

    /// constructor, causes an error, arrays shouldnt be copied.
    /// if you want to copy arrays, change this to do a
    /// deep copy and alloc a new pointer on the heap
    TArray(const TArray<T>& array);

    /// constructor given a max number of elements
    TArray(int max);

    /// destructor
    ~TArray();

    /// assignment operator causes an error, array's shouldnt be copied.
    /// if you want to copy arrays, change this to do a
    /// deep copy and alloc a new pointer on the heap
    void operator=(const TArray<T>& array) const;

    /// index operator for easy access
    T* operator[](int index) const;

    /// push a new object to the back of the array
    void Push(T* obj);

    /// pop an object from the back of the array
    T* Pop();

    /// remove an object from the array
    void Remove(T* obj);

    /// remove an object at index from the array, returns the objects address
    T* Remove(int index);

    /// check if an array contains an object
    bool Contains(T* obj);
};

#include "TArray.inl"

#endif