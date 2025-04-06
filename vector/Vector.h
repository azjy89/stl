#include <stdint.h>
#include <cstddef>
#include <stdexcept>
#include <limits>

template <class T>
class Vector
{
private:
    size_t _size;
    size_t _capacity;
    T *_data;

public:
    /*
    CONSTRUCTORS
    */

    // Default Constructor
    Vector();

    explicit Vector(uint32_t size);

    // Copy Constructor
    Vector(Vector const &other);

    // Copy Assignment
    Vector<T> &operator=(Vector<T> const &other);

    // Destructor
    ~Vector();

    /*
    *
    *
    CAPACITY
    *
    *
    */

    // Returns whether the vector is empty
    bool empty() const;

    // Returns the size of storage capacity
    size_t capacity() const;

    // Changes capacity to requested amount, does not change size;
    void reserve(size_t reservation_size);

    // Returns the number of elements in the vector
    size_t size() const;

    // Returns the maximum number of elements the Vector can hold
    size_t max_size() const;

    // Reduces the capacity to fit the size
    void shrink_to_fit();

    /*
    *
    *
    Modifiers
    *
    *
    */

    // Removes all elements from the Vector
    // but does not change capacity
    void clear();

    void push_back(T const &value);

    void pop_back();

    // void emplace_back(Args...)

    void resize(size_t size, T val);

    /*
    *
    *
    ELEMENT ACCESS
    *
    *
    */

    // Access element with bounds checking
    T &at(uint32_t idx);
};

/*
*
*
CONSTRUCTORS AND DESTRUCTORS
*
*
*/

// Default Constructor
template <class T>
Vector<T>::Vector() : _size(0), _data(0), _capacity(0) {}

// Size Constructor
template <class T>
inline Vector<T>::Vector(uint32_t size) : _size(size), _capacity(size), _data(new T[size])
{
    for (int i = 0; i < _size; ++i)
        _data[i] = T();
}

// Copy Constructor
template <class T>
inline Vector<T>::Vector(Vector<T> const &other) : _size(other._size), _capacity(other._capacity), _data(new T[other._size])
{
    for (size_t i = 0; i < other._size; ++i)
        _data[i] = other._data[i];
}

// Copy Assignment
template <class T>
inline Vector<T> &Vector<T>::operator=(Vector<T> const &other)
{
    if (this == &other)
        return *this;

    if (other._size <= _capacity)
    {
        for (size_t i = 0; i < other._size; ++i)
            _data[i] = other._data[i];
        _size = other._size;
        return *this;
    }

    T *ptr = new T[other._size];
    for (size_t i = 0; i < other._size; ++i)
        ptr[i] = other._data[i];

    delete[] _data;
    _size = other._size;
    _capacity = other._capacity;
    _data = ptr;
    return *this;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] _data;
}

/*
*
*
MODIFIERS
*
*
*/

template <class T>
inline void Vector<T>::clear()
{
    for (int i = 0; i < _size; ++i)
        _data[i].~T();
    _size = 0;
}

template <class T>
inline void Vector<T>::push_back(T const &value)
{
    if (_capacity == 0)
        reserve(8);
    else if (_size >= _capacity)
        reserve(2 * _capacity);

    _data[_size++] = value;
}

template <class T>
inline void Vector<T>::pop_back()
{
    if (_size > 0)
        _data[--_size].~T();
}

template <class T>
inline void Vector<T>::resize(size_t size, T value)
{
    if (size < _size)
    {
        for (size_t i = size; i < _size; ++i)
            _data[i].~T();
        _size = size;
    }
    else if (size > _size)
    {
        if (size > _capacity)
            reserve(size);

        for (size_t i = _size; i < size; ++i)
            _data[i] = value;
        _size = size;
    }
}

/*
*
*
CAPACITY
*
*
*/

template <class T>
inline bool Vector<T>::empty() const
{
    return (_size == 0);
}

template <class T>
inline size_t Vector<T>::capacity() const
{
    return _capacity;
}

template <class T>
inline void Vector<T>::reserve(size_t reservation_size)
{
    if (reservation_size <= _capacity)
        return;

    T *ptr = new T[reservation_size];

    for (int i = 0; i < _size; ++i)
        ptr[i] = _data[i];

    delete[] _data;
    _data = ptr;
    _capacity = reservation_size;
}

template <class T>
size_t Vector<T>::max_size() const
{
    return std::numeric_limits<size_t>::max();
}

template <class T>
inline size_t Vector<T>::size() const
{
    return _size;
}

template <class T>
inline void Vector<T>::shrink_to_fit()
{
    if (_capacity > _size)
    {
        T *new_data = new T[_size];

        for (int i = 0; i < _size; ++i)
            new_data[i] = _data[i];

        delete[] _data;
        _data = new_data;
        _capacity = _size;
    }
}

/*
*
*
ELEMENT ACCESS
*
*
*/

template <class T>
inline T &Vector<T>::at(uint32_t idx)
{
    if (static_cast<size_t>(idx) >= _size)
        throw std::out_of_range("Index out of range");
    return _data[idx];
}