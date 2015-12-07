
template <typename T>
Array<T>::Array()
    : m_array(static_cast<T*>(calloc(8, sizeof(T))))
    , m_size(0)
    , m_max(8)
{
}

template <typename T>
Array<T>::Array(const Array<T>& data)
{
    Error("Dynamic arrays should not be copied\n");
}

template <typename T>
Array<T>::Array(unsigned int max)
    : m_array(static_cast<T*>(calloc((max > 0 ? max : 8), sizeof(T))))
    , m_size(0)
    , m_max(max > 0 ? max : 8)
{
}

template <typename T>
Array<T>::~Array()
{
    if (m_array)
    {
        free(m_array);
    }

    m_array = 0;
    m_size = 0;
    m_max = 0;
}

template <typename T> 
void 
Array<T>::operator=(const Array<T>& data)
{
    Error("Dynamic arrays should not be copied\n");
}

template <typename T> 
T 
Array<T>::operator[](int index) const
{
    /// make sure the index is valid
    if (index >= m_size && index >= 0)
    {
        Error("Incorrect array index...\n");
    }

    /// return the object
    return m_array[index];
}

template <typename T>
void 
Array<T>::Push(const T& object)
{
    /// make sure the array isnt full
    if (m_size >= m_max)
    {
        /// the array is to big, resize the array and copy over memory
        m_max *= 2;
        T* data = (T*)realloc((void*)m_array, m_max);

        /// make sure new pointer is valid
        if (!data)
        {
            Error("realloc array failed in Array::Push()...\n");
        }
        else
        {
            m_array = data;
            data = 0;
        }
    }

    /// push the obj to the back and inc the array size
    m_array[m_size++] = object;
}

template <typename T>
T 
Array<T>::Pop()
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("Cannot pop an empty array...\n");
    }

    /// get the data in the array and dec the size
    T obj = m_array[--m_size];

    /// set the old obj to 0
    m_array[m_size] = 0;
    int index = -1;

    /// return the obj
    return obj;
}

template <typename T>
void 
Array<T>::Remove(const T& object)
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("Cannot remove from an empty array...\n");
    }

    /// check if the object is in the array
    for (int i = 0; i < m_size; ++i)
    {
        if (m_array[i] == object)
        {
            this->Remove(i);
            return;
        }
    }

    Error("The object is not in the array...\n");
}

template <typename T>
T 
Array<T>::Remove(int index)
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
    T ptr = m_array[index];
    m_array[index] = 0;
    m_size--;

    /// move the contents of the array
    for (int i = index; i < m_size-1; ++i)
    {
        m_array[i] = m_array[i+1];
    }

    /// return the obj ptr
    return ptr;
}

template <typename T>
bool 
Array<T>::Contains(const T& object)
{
    /// check if there is something in the array
    if (!m_size && !m_max)
    {
        Error("The object cannot be in an empty array...\n");
    }

    /// check if the object is in the array
    for (int i = 0; i < m_size; ++i)
    {
        if (m_array[i] == obj)
        {
            return true;
        }
    }
    return false
}