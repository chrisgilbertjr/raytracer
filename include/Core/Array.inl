
template <typename T>
Array<T>::Array()
    : m_array(static_cast<T*>(calloc(8, sizeof(T))))
    , m_size(0)
    , m_max(8)
{
    memcpy(m_array, 0, sizeof(T)*m_max);
}

template <typename T>
Array<T>::Array(const Array<T>& data)
{
    m_size = data.m_size;
    m_max  = data.m_max;

    if (data.m_array)
    {
        m_array = static_cast<T*>(calloc(m_max, sizeof(T)));
        if (m_size > 0 && m_max > 0 && m_array)
        {
            memcpy(m_array, data.m_array, sizeof(T)*m_max)
        }
        else if (m_max > 0)
        {
            memcpy(m_array, 0, sizeof(T)*m_max);
        }
        else
        {
            Error("Array max is 0.\n");
        }
    }
    else
    {
        m_array = NULL;
    }
}

template <typename T>
Array<T>::Array(const unsigned max)
    : m_array(static_cast<T*>(calloc((max > 0 ? max : 8), sizeof(T))))
    , m_size(0)
    , m_max(max > 0 ? max : 8)
{}

template <typename T>
Array<T>::~Array()
{
    if (m_array)
    {
        free(m_array);
    }

    m_array = NULL;
    m_size = 0;
    m_max = 0;
}

template <typename T> 
Array<T>& 
Array<T>::operator=(Array<T> data)
{
    Swap<unsigned>(m_size, data.m_size);
    Swap<unsigned>(m_max,  data.m_max);
    Swap<T*>(m_array, data.m_array);
    return *this;
}

template <typename T> 
T 
Array<T>::operator[](unsigned index) const
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
Array<T>::Resize(const unsigned size)
{
    T* resized = static_cast<T*>(realloc(m_array, sizeof(T)*size));
    if (!resized)
    {
        Error("realloc array failed in Array::Resize()...\n");
    }

    m_array = resized;
    m_size = m_size > size ? size : m_size;
    m_max = size;

    resized = 0;
}

template <typename T>
void 
Array<T>::Push(const T& object)
{
    if (m_max <= 0) this->Resize(8);

    /// make sure the array isnt full
    if (m_size >= m_max)
    {
        /// resize the array
        this->Resize(m_max*2);
    }

    /// push the obj to the back and inc the array size
    m_array[m_size++] = object;
}

template <typename T>
T 
Array<T>::Pop()
{
    /// check if there is something in the array
    if (m_size > 0 && m_max > 0)
    {
        Error("Cannot pop an empty array...\n");
    }

    /// get the data in the array and dec the size
    T obj = m_array[--m_size];

    /// set the old obj to 0
    m_array[m_size] = 0;

    /// return the obj
    return obj;
}

template <typename T>
void 
Array<T>::Remove(const T& object)
{
    /// check if there is something in the array
    if (m_size > 0 && m_max > 0)
    {
        Error("Cannot remove from an empty array...\n");
    }

    /// check if the object is in the array
    for (unsigned i = 0; i < m_size; ++i)
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
Array<T>::Remove(const unsigned index)
{
    /// check if there is something in the array
    if (m_size > 0 && m_max > 0)
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
    for (unsigned i = index; i < m_size-1; ++i)
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
    if (m_size > 0 && m_max > 0)
    {
        Error("The object cannot be in an empty array...\n");
    }

    /// check if the object is in the array
    for (unsigned i = 0; i < m_size; ++i)
    {
        if (m_array[i] == obj)
        {
            return true;
        }
    }
    return false;
}