
#include "Core\Array.h"
#include "Core\Core.h"

Array::Array()
    : m_data(0)
    , m_size(0)
    , m_max(8)
{
    m_data = (void**)calloc(m_max, sizeof(void*));
}

Array::Array(const Array& array)
{
    Error("Dynamic arrays should not be copied\n");
}

Array::Array(int max)
    : m_data(0)
    , m_size(0)
    , m_max(max)
{
    m_data = (void**)calloc(m_max, sizeof(void*));
}

Array::~Array()
{
    if (m_data)
    {
        free(m_data);
    }

    m_data = 0;
    m_size = 0;
    m_max = 0;
}

void 
Array::operator=(const Array& array) const
{
    Error("Dynamic arrays should not be copied\n");
}

void* 
Array::operator[](int index) const
{
    /// make sure the index is valid
    if (index >= m_size && index >= 0)
    {
        Error("Incorrect array index...\n");
    }

    /// return the object
    return m_data[index];
}

void 
Array::Push(void* obj)
{
    /// make sure the array isnt full
    if (m_size >= m_max)
    {
        /// the array is to big, resize the array and copy over memory
        m_max *= 2;
        void** data = (void**)realloc(&m_data, m_max);

        /// make sure new pointer is valid
        if (!data)
        {
            Error("realloc array failed in Array::Push(void* obj)...\n");
        }
        else
        {
            m_data = data;
            data = 0;
        }
    }

    /// push the obj to the back and inc the array size
    m_data[m_size++] = obj;
}

void*
Array::Pop()
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("Cannot pop an empty array...\n");
    }

    /// get the data in the array and dec the size
    void* obj = m_data[--m_size];

    /// set the old obj to 0
    m_data[m_size] = 0;
    int index = -1;


    /// return the obj
    return obj;
}

void 
Array::Remove(void* obj)
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("Cannot remove from an empty array...\n");
    }

    /// check if the object is in the array
    for (int i = 0; i < m_size; ++i)
    {
        if (m_data[i] == obj)
        {
            this->Remove(i);
            return;
        }
    }

    Error("The object is not in the array...\n");
}

void*
Array::Remove(int index)
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("Cannot remove from an empty array...\n");
    }

    /// make sure the index is valid
    if (index >= m_size && index >= 0)
    {
        Error("Incorrect array index, cannot remove  index %d...\n", index);
    }

    /// remove the object and reduce the size of the array
    void* ptr = m_data[index];
    m_data[index] = 0;
    m_size--;

    /// move the contents of the array
    for (int i = index; i < m_size-1; ++i)
    {
        m_data[i] = m_data[i+1];
    }

    /// return the obj ptr
    return ptr;
}

bool 
Array::Contains(void* obj)
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("The object cannot be in an empty array...\n");
    }

    /// check if the object is in the array
    for (int i = 0; i < m_size; ++i)
    {
        if (m_data[i] == obj)
        {
            return true;
        }
    }
    return false;
}