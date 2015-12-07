
template <typename T>
TArray<T>::TArray()
    : m_array()
{
}

template <typename T>
TArray<T>::TArray(const TArray<T>& array)
{
    Error("Dynamic arrays should not be copied\n");
}

template <typename T>
TArray<T>::TArray(int max)
    : m_array(max)
{
}

template <typename T>
TArray<T>::~TArray()
{
}

template <typename T>
void TArray<T>::operator=(const TArray<T>& array) const
{
    Error("Dynamic arrays should not be copied\n");
}

template <typename T>
T* TArray<T>::operator[](int index) const
{
    return static_cast<T*>(m_array[index]);
}

template <typename T>
void TArray<T>::Push(T* obj)
{
    m_array.Push(static_cast<void*>(obj));
}

template <typename T>
T* TArray<T>::Pop()
{
    return static_cast<T*>(m_array.Pop());
}

template <typename T>
void TArray<T>::Remove(T* obj)
{
    m_array.Remove(static_cast<void*>(obj));
}

template <typename T>
T* TArray<T>::Remove(int index)
{
    m_array.Remove(index);
}

template <typename T>
bool TArray<T>::Contains(T* obj)
{
    m_array.Contains(static_cast<void*>(obj));
}